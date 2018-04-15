#ifndef METAL_EXAMPLE_HPP
#define METAL_EXAMPLE_HPP

#include <type_traits>

#define CAT_IMPL(X, Y) X##Y
#define CAT(X, Y) CAT_IMPL(X, Y)

#define HIDE(...) struct CAT(anonymous, __LINE__) {__VA_ARGS__};

#define IS_SAME_IMPL(...) static_assert(__VA_ARGS__, #__VA_ARGS__)
#define IS_SAME(...) IS_SAME_IMPL(std::is_same<__VA_ARGS__>::value)

int main() {
    return 0;
}

#endif
