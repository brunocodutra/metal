// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

/// [empty]
using l0 = metal::list<>;
/// [empty]

/// [insert]
union x;
class y;
struct z;

using l1 = metal::prepend<l0, x>;
using l2 = metal::append<l1, z>;
using l3 = metal::insert<l2, metal::number<1>, y>;

static_assert(metal::same<l1, metal::list<x>>::value, "");
static_assert(metal::same<l2, metal::list<x, z>>::value, "");
static_assert(metal::same<l3, metal::list<x, y, z>>::value, "");
/// [insert]

/// [size]
static_assert(metal::size<l0>::value == 0, "");
static_assert(metal::size<l1>::value == 1, "");
static_assert(metal::size<l2>::value == 2, "");
static_assert(metal::size<l3>::value == 3, "");
/// [size]

/// [access]
static_assert(metal::same<metal::front<l3>, x>::value, "");
static_assert(metal::same<metal::back<l3>, z>::value, "");
static_assert(metal::same<metal::at<l3, metal::number<1>>, y>::value, "");
/// [access]

/// [erase]
using l0_ = metal::drop<l3, metal::number<3>>;
using l1_ = metal::take<l3, metal::number<1>>;
using l2_ = metal::erase<l3, metal::number<1>>;

static_assert(metal::same<l0, l0_>::value, "");
static_assert(metal::same<l1, l1_>::value, "");
static_assert(metal::same<l2, l2_>::value, "");
/// [erase]

/// [count]
template<typename T>
using is_class = metal::as_number<std::is_class<T>>;

template<typename T>
using is_union = metal::as_number<std::is_union<T>>;

static_assert(metal::count_if<l3, metal::lambda<is_class>>::value == 2, "");
static_assert(metal::count_if<l3, metal::lambda<is_union>>::value == 1, "");
/// [count]

/// [reverse]
static_assert(metal::same<metal::reverse<l0>, metal::list<>>::value, "");
static_assert(metal::same<metal::reverse<l1>, metal::list<x>>::value, "");
static_assert(metal::same<metal::reverse<l2>, metal::list<z, x>>::value, "");
static_assert(metal::same<metal::reverse<l3>, metal::list<z, y, x>>::value, "");
/// [reverse]

/// [transform]
using l2ptrs = metal::transform<metal::lambda<std::add_pointer_t>, l2>;
using l3refs = metal::transform<metal::lambda<std::add_lvalue_reference_t>, l3>;

static_assert(metal::same<l2ptrs, metal::list<x*, z*>>::value, "");
static_assert(metal::same<l3refs, metal::list<x&, y&, z&>>::value, "");
/// [transform]
