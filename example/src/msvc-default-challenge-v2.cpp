#include "example.hpp"

#include <cstdint>
#include <memory>
#include <metal.hpp>
#include <tuple>

namespace metal {
    namespace v2 {
        namespace detail {
        template<class seq, class lbd>
        struct _sort {};

        template<class... vals, class lbd>
        struct _sort<list<vals...>, lbd> {
          using type = void;
        };
        } // detail

    using default_comp = metal::lambda<metal::less>;

    template<class seq, class lbd = default_comp>
    using sort = typename detail::_sort<seq, lbd>::type;
    } // v?
} // metal

HIDE(
/// [iota]
IS_SAME(
  metal::v2::sort<metal::numbers<7, -4, 2>, metal::lambda<metal::less>>,
  void
);

IS_SAME(
  metal::v2::sort<metal::numbers<7, -4, 2>>,
  void
);
/// [iota]
)
