// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/integrals/logical/not.hpp>
#include <boost/mpl2/core/call.hpp>
#include <boost/mpl2/core/function.hpp>
#include <boost/mpl2/core/bind.hpp>
#include <boost/mpl2/core/traits.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((is_evaluable<function<std::add_pointer>, void>));
BOOST_MPL2_ASSERT((is_evaluable<bind<function<std::add_pointer>, void> >));

BOOST_MPL2_ASSERT((std::is_same<eval<function<std::add_pointer>, void>, void*>));
BOOST_MPL2_ASSERT((std::is_same<eval<bind<function<std::add_pointer>, void> >, void*>));

struct unevaluable
{
    template<typename...>
    struct call;
};

BOOST_MPL2_ASSERT(not_<is_evaluable<void> >);
BOOST_MPL2_ASSERT(not_<is_evaluable<identity<void> > >);
BOOST_MPL2_ASSERT(not_<is_evaluable<unevaluable> >);

int main()
{
    return 0;
}
