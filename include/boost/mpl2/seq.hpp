/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL_SEQ_HPP_
#define _BOOST_MPL_SEQ_HPP_

#include <boost/mpl2/config.hpp>
#include <boost/mpl2/type.hpp>

#include <boost/mpl2/detail/preprocessor/variadic_args.hpp>
#include <boost/mpl2/detail/preprocessor/sizeof.hpp>

#include <boost/preprocessor/arithmetic/dec.hpp>

namespace boost
{
    namespace mpl2
    {
        template<
                BOOST_MPL_OPTIONAL_PARAMS(1, h)
                BOOST_MPL_TRAILING_VARIADIC_OPTIONAL_PARAMS(
                    BOOST_PP_DEC(BOOST_MPL_LIMIT_METAFUNCTION_ARITY),
                    tail
                )
            >
        struct seq :
                seq<BOOST_MPL_VARIADIC_ARGS(
                        BOOST_PP_DEC(BOOST_MPL_LIMIT_METAFUNCTION_ARITY),
                        tail
                    )
                    >
        {
            typedef seq type;
            enum
            {
                size = 1 + BOOST_MPL_SEIZEOF(
                        BOOST_PP_DEC(BOOST_MPL_LIMIT_METAFUNCTION_ARITY),
                        tail
                    )
            };
        };

        template<>
        struct seq<>
        {
            typedef seq<> type;
            enum {size = 0};
        };
    }
}

#endif
