/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef BOOST_MPL2_CORE_TAG_HPP
#define BOOST_MPL2_CORE_TAG_HPP

namespace boost
{
    namespace mpl2
    {
        template<typename tagged>
        struct tag :
                tagged::tag
        {};
    }
}

#endif
