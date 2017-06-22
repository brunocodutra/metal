// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

#include <forward_list>
#include <list>
#include <utility>
#include <vector>

/// [test_case]
template<typename Container, typename Type, typename Size>
struct test_case {
    metal::invoke<Container, Type, std::allocator<Type>> sequence;

    test_case() : sequence(Size{}) { /* set-up */ }
    ~test_case() { /* tear-down */ }

    void operator ()() { /* algorithm(this->sequence) */ }
};
/// [test_case]

struct A {};
struct Z {};

constexpr std::size_t MIN_SIZE = 0;
constexpr std::size_t MAX_SIZE = 1;

/// [automatic]
template<typename... Cases>
struct test_cases : Cases... {
    void operator()() {
        // call operator () on every base class
        void(std::initializer_list<int>{(static_cast<Cases*>(this)->operator()(), 0)...});
    }
};

template<typename Containers, typename Types, typename Sizes>
auto generate_test_cases()
    -> metal::apply<
        metal::lambda<test_cases>,
        metal::transform<
            metal::partial<metal::lambda<metal::apply>, metal::lambda<test_case>>,
            metal::cartesian<Containers, Types, Sizes>
        >
    > {
    return {};
}

using containers = metal::list<
    metal::lambda<std::forward_list>,
    metal::lambda<std::list>,
    metal::lambda<std::vector>
>;

using types = metal::list<A, /* ..., */ Z>;
using sizes = metal::numbers<0, /* ..., */ MAX_SIZE>;


void test() {
    auto cases = generate_test_cases<containers, types, sizes>(); // generate all test cases
    cases(); // run
}
/// [automatic]

/// [inspect]
IS_SAME(
    decltype(generate_test_cases<containers, types, sizes>()),
    test_cases<
        test_case<metal::lambda<std::forward_list>, A, metal::number<MIN_SIZE>>,
        /* ... */
        test_case<metal::lambda<std::forward_list>, A, metal::number<MAX_SIZE>>,
        /* ... */
        test_case<metal::lambda<std::forward_list>, Z, metal::number<MIN_SIZE>>,
        /* ... */
        test_case<metal::lambda<std::forward_list>, Z, metal::number<MAX_SIZE>>,

        test_case<metal::lambda<std::list>, A, metal::number<MIN_SIZE>>,
        /* ... */
        test_case<metal::lambda<std::list>, A, metal::number<MAX_SIZE>>,
        /* ... */
        test_case<metal::lambda<std::list>, Z, metal::number<MIN_SIZE>>,
        /* ... */
        test_case<metal::lambda<std::list>, Z, metal::number<MAX_SIZE>>,

        test_case<metal::lambda<std::vector>, A, metal::number<MIN_SIZE>>,
        /* ... */
        test_case<metal::lambda<std::vector>, A, metal::number<MAX_SIZE>>,
        /* ... */
        test_case<metal::lambda<std::vector>, Z, metal::number<MIN_SIZE>>,
        /* ... */
        test_case<metal::lambda<std::vector>, Z, metal::number<MAX_SIZE>>
    >
);
/// [inspect]
