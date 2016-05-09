// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/equal_to.hpp>
#include <metal/number/greater.hpp>
#include <metal/number/less.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [equal_to]
static_assert(std::is_same<metal::equal_to<metal::int_<-10>, metal::number<long, 10>>, metal::false_>::value, "");
static_assert(std::is_same<metal::equal_to<metal::number<short, 0>, metal::false_>, metal::true_>::value, "");
/// [equal_to]
}

HIDDEN(namespace)
{
/// [greater]
static_assert(std::is_same<metal::greater<metal::int_<-10>, metal::number<long, 10>>, metal::false_>::value, "");
static_assert(std::is_same<metal::greater<metal::number<short, 0>, metal::false_>, metal::false_>::value, "");
/// [greater]
}

HIDDEN(namespace)
{
/// [less]
static_assert(std::is_same<metal::less<metal::int_<-10>, metal::number<long, 10>>, metal::true_>::value, "");
static_assert(std::is_same<metal::less<metal::number<short, 0>, metal::false_>, metal::false_>::value, "");
/// [less]
}
