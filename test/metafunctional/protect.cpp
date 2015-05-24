// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/protect.hpp>
#include <boost/mpl2/metafunctional/function.hpp>
#include <boost/mpl2/metafunctional/bind.hpp>
#include <boost/mpl2/metafunctional/invoke.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using bound = bind<function<std::add_pointer>, void>;

BOOST_MPL2_ASSERT(is_function<bound>);
BOOST_MPL2_ASSERT(is_function<protect<bound> >);
BOOST_MPL2_ASSERT(is_evaluable<protect<bound> >);

BOOST_MPL2_ASSERT((std::is_same<invoke<bound>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<invoke<protect<bound> >::type, void*>));

BOOST_MPL2_ASSERT((std::is_same<invoke<bind<function<std::add_pointer>, bound> >::type, void**>));
BOOST_MPL2_ASSERT((std::is_same<invoke<bind<function<std::add_pointer>, protect<bound> > >::type, protect<bound>*>));

int main()
{
    return 0;
}
