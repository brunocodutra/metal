/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#define BOOST_MPL2_LIMIT_METAFUNCTION_ARITY 5

#include <boost/mpl2/config/switches/variadic_templates.hpp>
#include <boost/mpl2/compat/variadic.hpp>

#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/enum_params.hpp>
#include <boost/preprocessor/repeat_from_to.hpp>
#include <boost/preprocessor/repeat.hpp>
#include <boost/preprocessor/inc.hpp>

struct yes;
struct no;

template<typename>
struct ignore;

template<BOOST_MPL2_VARIADIC_OPTIONAL_PARAMS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)>
struct pack
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

template<typename pack>
struct negate_all;

template<BOOST_MPL2_VARIADIC_PARAMS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)>
struct negate_all<pack<BOOST_MPL2_VARIADIC_ARGS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)> >
{
    typedef pack<
        BOOST_MPL2_APPLY_TO_EACH_VARIADIC_ARG(
            BOOST_MPL2_LIMIT_METAFUNCTION_ARITY,
            args,
            negate
        )
    > type;
};

template<BOOST_MPL2_VARIADIC_PARAMS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)>
bool unanimity(pack<BOOST_MPL2_VARIADIC_ARGS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, args)>
)
{
    return false;
}

#define __BOOST_MPL2_DEFINE_UNANIMITY(Z, N, _) \
    bool unanimity(pack<BOOST_PP_ENUM_PARAMS(N, yes BOOST_PP_INTERCEPT)>) \
    { \
        return true; \
    }

BOOST_PP_REPEAT(
    BOOST_PP_INC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY),
    __BOOST_MPL2_DEFINE_UNANIMITY,
    _
)

#define __BOOST_MPL2_DEFINE_UNANIMITY_IGNORE(Z, N, _) \
    template<BOOST_MPL2_VARIADIC_PARAMS(N, T)> \
    bool unanimity(pack<BOOST_MPL2_WRAP_EACH_VARIADIC_PARAM(N, T, ignore)>) \
    { \
        return true; \
    }

#if defined(BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES)
    BOOST_PP_REPEAT_FROM_TO(
        1,
        BOOST_MPL2_LIMIT_METAFUNCTION_ARITY,
        __BOOST_MPL2_DEFINE_UNANIMITY_IGNORE,
        _
    )
#endif

__BOOST_MPL2_DEFINE_UNANIMITY_IGNORE(
    _, BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, _
)

#define __BOOST_MPL2_TEST_NEGATE(Z, N, _) \
    !unanimity(negate_all<pack< \
        BOOST_PP_ENUM_PARAMS( \
            N, no BOOST_PP_INTERCEPT \
        ) \
    > >::type()) ||

#define __BOOST_MPL2_TEST_IGNORE(Z, N, _) \
    !unanimity(pack< \
        BOOST_PP_ENUM_PARAMS( \
            N, ignore<no> BOOST_PP_INTERCEPT \
        ) \
    >()) ||

int main()
{
    return
            BOOST_PP_REPEAT(
                BOOST_PP_INC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY),
                __BOOST_MPL2_TEST_NEGATE,
                _
            )
            BOOST_PP_REPEAT(
                BOOST_PP_INC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY),
                __BOOST_MPL2_TEST_NEGATE,
                _
            )
            BOOST_PP_REPEAT_FROM_TO(
                1,
                BOOST_PP_INC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY),
                __BOOST_MPL2_TEST_IGNORE,
                _
            )
            unanimity(pack<no>());
}

#undef __BOOST_MPL2_DEFINE_UNANIMITY
#undef __BOOST_MPL2_DEFINE_UNANIMITY_IGNORE
#undef __BOOST_MPL2_TEST_NEGATE
#undef __BOOST_MPL2_TEST_IGNORE

