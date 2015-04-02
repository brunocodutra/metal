// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/void.hpp>
#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/integrals/logical/not.hpp>

int main()
{
    using boost::mpl2::void_;
    using boost::mpl2::is_void_;
    using boost::mpl2::not_;

    BOOST_MPL2_ASSERT(is_void_<void_>);
    BOOST_MPL2_ASSERT(is_void_<void_::type>);
    BOOST_MPL2_ASSERT(not_<is_void_<void> >);


    return is_void_<void>();
}
