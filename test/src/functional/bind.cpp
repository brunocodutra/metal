/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/bind.hpp>
#include <boost/metal/functional/placeholders.hpp>
#include <boost/metal/functional/protect.hpp>
#include <boost/metal/functional/evaluator.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/traits.hpp>

#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace boost::metal;
using namespace boost::metal::placeholders;

BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper>, void, void*>, test::wrap<>>));

BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1>, short, int, long, long long>, test::wrap<short>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2>, short, int, long, long long>, test::wrap<short, int>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, _3>, short, int, long, long long>, test::wrap<short, int, long>>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<test::wrapper, _1, _2, _3, _4>, short, int, long, long long>, test::wrap<short, int, long, long long>>));

using compose = protect<bind<_1, bind<_2, _3>>>;
BOOST_METAL_ASSERT((is_function<compose>));
BOOST_METAL_ASSERT((std::is_same<call_t<compose, evaluator<std::add_pointer>, evaluator<std::add_const>, void>, void const*>));
BOOST_METAL_ASSERT((std::is_same<call_t<compose, evaluator<std::add_const>, evaluator<std::add_pointer>, void>, void* const>));

using once = protect<bind<compose, protect<_1>, _1, _2>>;
BOOST_METAL_ASSERT((is_function<once>));
BOOST_METAL_ASSERT((std::is_same<call_t<once, evaluator<std::add_pointer>, void>, void*>));

using twice = protect<bind<compose, _1, _1, _2>>;
BOOST_METAL_ASSERT((is_function<twice>));
BOOST_METAL_ASSERT((std::is_same<call_t<twice, evaluator<std::add_pointer>, void>, void**>));

using thrice = protect<bind<once, _1, bind<twice, _1, _2>>>;
BOOST_METAL_ASSERT((is_function<thrice>));
BOOST_METAL_ASSERT((std::is_same<call_t<thrice, evaluator<std::add_pointer>, void>, void***>));

using ptr2ptr2ptr = protect<bind<thrice, evaluator<std::add_pointer>, _1>>;
BOOST_METAL_ASSERT((is_function<ptr2ptr2ptr>));
BOOST_METAL_ASSERT((std::is_same<call_t<ptr2ptr2ptr, void>, void***>));
BOOST_METAL_ASSERT((std::is_same<call_t<bind<ptr2ptr2ptr, void>>, void***>));
