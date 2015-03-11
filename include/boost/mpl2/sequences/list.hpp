/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_SEQUENCES_LIST_HPP_
#define _BOOST_MPL2_SEQUENCES_LIST_HPP_

#include <boost/mpl2/config/limits/arity.hpp>
#include <boost/mpl2/core/integral/size_t.hpp>
#include <boost/mpl2/sequences/detail/link.hpp>
#include <boost/mpl2/detail/preprocessor/variadic_args.hpp>
#include <boost/mpl2/detail/preprocessor/sizeof.hpp>

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
    BOOST_MPL2_SEIZEOF( \
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
        {};

        template<>
        struct list<> :
                detail::nil
        {};
    }
}

#undef BOOST_MPL2_DETAIL_HEAD_DECL
#undef BOOST_MPL2_DETAIL_TAIL_DECL
#undef BOOST_MPL2_DETAIL_TAIL
#undef BOOST_MPL2_DETAIL_SIZEOF_TAIL

#endif
