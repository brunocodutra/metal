#include "example.hpp"

#include <cstdint>
#include <memory>
#include <metal.hpp>
#include <tuple>

namespace metal {
    namespace v3 {
        namespace detail {
        template<class lbd>
        struct _sort_impl {};

        template<template<class...> class expr>
        struct _sort_impl<lambda<expr>> {
          template<class...>
          using type = void;
        };

        template<class seq>
        struct _sort {};

        template<class... vals>
        struct _sort<list<vals...>> {
          template<class lbd>
          using type = metal::detail::call<_sort_impl<lbd>::template type, vals...>;
        };
        } // detail

    using default_comp = metal::lambda<metal::less>;

    template<class seq, class lbd = default_comp>
    using sort = metal::detail::call<detail::_sort<seq>::template type, lbd>;
    } // v?
} // metal

HIDE(
/// [iota]
IS_SAME(
  metal::v3::sort<metal::numbers<7, -4, 2>, metal::lambda<metal::less>>,
  void
);

IS_SAME(
  metal::v3::sort<metal::numbers<7, -4, 2>>,
  void
);

static_assert(!metal::is_invocable<metal::lambda<metal::v3::sort>, metal::numbers<7, -4, 2>, void>{}, "");
/// [iota]
)
