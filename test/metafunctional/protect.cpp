// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/protect.hpp>
#include <boost/mpl2/metafunctional/evaluator.hpp>
#include <boost/mpl2/metafunctional/bind.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>

#include "test.hpp"

using namespace boost::mpl2;

using bound = bind<evaluator<std::add_pointer>, void>;

BOOST_MPL2_ASSERT((is_function<bound>));
BOOST_MPL2_ASSERT((is_function<protect<bound>>));

BOOST_MPL2_ASSERT((std::is_same<bound::call<>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<protect<bound>::call<>::type, void*>));

BOOST_MPL2_ASSERT((std::is_same<bind<evaluator<std::add_pointer>, bound>::call<>::type, void**>));
BOOST_MPL2_ASSERT((std::is_same<bind<evaluator<std::add_pointer>, protect<bound>>::call<>::type, protect<bound>*>));

int main()
{
    return 0;
}
