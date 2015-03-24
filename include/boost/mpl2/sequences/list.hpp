// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_LIST_HPP
#define BOOST_MPL2_SEQUENCES_LIST_HPP

#include <boost/mpl2/core/limits/arity.hpp>
#include <boost/mpl2/core/compat/variadic.hpp>
#include <boost/mpl2/core/compat/sizeof.hpp>
#include <boost/mpl2/core/integral/size_t.hpp>
#include <boost/mpl2/sequences/detail/link.hpp>

#include <boost/preprocessor/arithmetic/dec.hpp>

#define BOOST_MPL2_DETAIL_HEAD_DECL \
    BOOST_MPL2_OPTIONAL_PARAMS(1, h)

#define BOOST_MPL2_DETAIL_HEAD \
    BOOST_MPL2_ARGS(1, h)

#define BOOST_MPL2_DETAIL_TAIL_DECL \
    BOOST_MPL2_TRAILING_VARIADIC_OPTIONAL_PARAMS( \
        BOOST_PP_DEC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY), \
        tail \
    )

#define BOOST_MPL2_DETAIL_TAIL \
    BOOST_MPL2_VARIADIC_ARGS( \
        BOOST_PP_DEC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY), \
        tail \
    )

#define BOOST_MPL2_DETAIL_SIZEOF_TAIL \
    BOOST_MPL2_SEIZEOF_VARIADIC_ARGS( \
        BOOST_PP_DEC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY), \
        tail \
    )

namespace boost
{
    namespace mpl2
    {
        template<BOOST_MPL2_DETAIL_HEAD_DECL BOOST_MPL2_DETAIL_TAIL_DECL>
        struct list :
                detail::link<
                    size_t_<BOOST_MPL2_DETAIL_SIZEOF_TAIL>,
                    BOOST_MPL2_DETAIL_HEAD,
                    list<BOOST_MPL2_DETAIL_TAIL>
                >
        {
            typedef list type;
        };

        template<>
        struct list<> :
                detail::nil
        {
            typedef list type;
        };
    }
}

#undef BOOST_MPL2_DETAIL_HEAD_DECL
#undef BOOST_MPL2_DETAIL_TAIL_DECL
#undef BOOST_MPL2_DETAIL_TAIL
#undef BOOST_MPL2_DETAIL_SIZEOF_TAIL

#endif
