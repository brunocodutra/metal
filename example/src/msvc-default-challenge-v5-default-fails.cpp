#include "example.hpp"

#include <cstdint>
#include <memory>
#include <metal.hpp>
#include <tuple>

namespace metal {
    namespace v5 {
        namespace detail {
        template<class lbd>
        struct _sort {};

        template<template<class...> class expr>
        struct _sort<lambda<expr>> {
          template<class>
          using type = void;
        };
        } // detail

    using default_comp = metal::lambda<metal::less>;

    template<class seq, class lbd = default_comp>
    using sort = metal::detail::call<detail::_sort<lbd>::template type,
                                     if_<is_list<seq>, seq>>;
    } // v?
} // metal

HIDE(
/// [iota]
IS_SAME(
  metal::v5::sort<metal::numbers<7, -4, 2>, metal::lambda<metal::less>>,
  void
);

IS_SAME(
  metal::v5::sort<metal::numbers<7, -4, 2>>,
  void
);

static_assert(!metal::is_invocable<metal::lambda<metal::v5::sort>, metal::numbers<7, -4, 2>, void>{}, "");
/// [iota]
)
