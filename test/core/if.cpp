// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/integrals/boolean.hpp>
#include <boost/mpl2/integrals/integer.hpp>
#include <boost/mpl2/integrals/character.hpp>
#include <boost/mpl2/integrals/logical/not.hpp>
#include <boost/mpl2/core/if.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

int main()
{
    using boost::mpl2::if_;
    using boost::mpl2::true_;
    using boost::mpl2::false_;

    struct x;
    struct y;

    using tautology = boost::mpl2::char_<'c'>;
    using contradiction = boost::mpl2::ulong_<0UL>;

    BOOST_MPL2_ASSERT((std::is_same<if_<true_, x, y>::type, x>));
    BOOST_MPL2_ASSERT((std::is_same<if_<false_, x, y>::type, y>));
    BOOST_MPL2_ASSERT((if_<tautology, true_, false_>::type));
    BOOST_MPL2_ASSERT((if_<contradiction, false_, true_>::type));

    return 0;
}
