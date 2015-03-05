/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL_SEQ_HPP_
#define _BOOST_MPL_SEQ_HPP_

#include <boost/mpl2/config.hpp>

#include <boost/mpl2/detail/preprocessor.hpp>

//#include <boost/preprocessor/arithmetic/dec.hpp>

namespace boost
{
    namespace mpl2
    {
        template<BOOST_MPL_VARIADIC_OPTIONAL_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, items)>
        struct seq
        {

        };
    }
}

#endif
