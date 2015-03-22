/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#define BOOST_MPL2_LIMIT_METAFUNCTION_ARITY 5

#include <boost/mpl2/config/options/variadic_templates.hpp>
#include <boost/mpl2/core/compat/variadic.hpp>

#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/enum_params.hpp>
#include <boost/preprocessor/repeat_from_to.hpp>
#include <boost/preprocessor/repeat.hpp>
#include <boost/preprocessor/inc.hpp>

struct yes;
struct no;

template<typename>
struct abstain;

template<BOOST_MPL2_VARIADIC_OPTIONAL_PARAMS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)>
struct votes
{};

template<typename>
struct negate;

template<>
struct negate<no>
{
    typedef yes type;
};

template<>
struct negate<yes>
{
    typedef no type;
};

template<typename votes>
struct negate_all;

template<BOOST_MPL2_VARIADIC_PARAMS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)>
struct negate_all<votes<BOOST_MPL2_VARIADIC_ARGS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)> >
{
    typedef votes<
        BOOST_MPL2_APPLY_TO_EACH_VARIADIC_ARG(
            BOOST_MPL2_LIMIT_METAFUNCTION_ARITY,
            args,
            negate
        )
    > type;
};

template<BOOST_MPL2_VARIADIC_PARAMS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)>
bool unanimity(votes<BOOST_MPL2_VARIADIC_ARGS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)>)
{
    return false;
}

#define BOOST_MPL2_DETAIL_OVERLOAD_UNANIMITY(Z, N, _) \
    template<> \
    bool unanimity(votes<BOOST_PP_ENUM_PARAMS(N, yes BOOST_PP_INTERCEPT)>) \
    { \
        return true; \
    }

BOOST_PP_REPEAT(
    BOOST_PP_INC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY),
    BOOST_MPL2_DETAIL_OVERLOAD_UNANIMITY,
    _
)

#define BOOST_MPL2_DETAIL_OVERLOAD_ABSTENTION(Z, N, _) \
    template<BOOST_MPL2_VARIADIC_PARAMS(N, T)> \
    bool unanimity(votes<BOOST_MPL2_WRAP_EACH_VARIADIC_PARAM(N, T, abstain)>) \
    { \
        return true; \
    }

#if defined(BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES)
    BOOST_PP_REPEAT_FROM_TO(
        1,
        BOOST_MPL2_LIMIT_METAFUNCTION_ARITY,
        BOOST_MPL2_DETAIL_OVERLOAD_ABSTENTION,
        _
    )
#endif

BOOST_MPL2_DETAIL_OVERLOAD_ABSTENTION(
    _, BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, _
)

#define BOOST_MPL2_DETAIL_TEST_NEGATE(Z, N, _) \
    !unanimity(negate_all<votes< \
        BOOST_PP_ENUM_PARAMS( \
            N, no BOOST_PP_INTERCEPT \
        ) \
    > >::type()) ||

#define BOOST_MPL2_DETAIL_TEST_ABSTAIN(Z, N, _) \
    !unanimity(votes< \
        BOOST_PP_ENUM_PARAMS( \
            N, abstain<no> BOOST_PP_INTERCEPT \
        ) \
    >()) ||

int main()
{
    return
            BOOST_PP_REPEAT(
                BOOST_PP_INC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY),
                BOOST_MPL2_DETAIL_TEST_NEGATE,
                _
            )
            BOOST_PP_REPEAT_FROM_TO(
                1,
                BOOST_PP_INC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY),
                BOOST_MPL2_DETAIL_TEST_ABSTAIN,
                _
            )
            unanimity(votes<no>());
}

#undef BOOST_MPL2_DETAIL_OVERLOAD_UNANIMITY
#undef BOOST_MPL2_DETAIL_OVERLOAD_ABSTENTION
#undef BOOST_MPL2_DETAIL_TEST_NEGATE
#undef BOOST_MPL2_DETAIL_TEST_ABSTAIN

