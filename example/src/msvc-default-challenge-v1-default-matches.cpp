#include "example.hpp"

#include <cstdint>
#include <memory>
#include <metal.hpp>
#include <tuple>

namespace metal {
    namespace v1 {
        namespace detail {
            template<int_... ns>
            struct enumeration {};

            template<class ns>
            struct _even {};

            template<int_... ns>
            struct _even<enumeration<ns...>> {
                using type = enumeration<ns..., (sizeof...(ns) + ns)...>;
            };

            template<class ns>
            struct _odd {};

            template<int_... ns>
            struct _odd<enumeration<ns...>> {
                using type = enumeration<
                    ns..., (sizeof...(ns) + ns)..., 2 * sizeof...(ns)>;
            };

            template<int_ n>
            struct _enumerate;

            template<int_ n>
            using enumerate = typename _enumerate<n>::type;

            template<int_ n>
            struct _enumerate
                : if_<number<n % 2>, _odd<enumerate<n / 2>>,
                      _even<enumerate<n / 2>>> {};

            template<>
            struct _enumerate<0> {
                using type = enumeration<>;
            };

            template<class, int_ a, int_ b>
            struct _iota_impl {};

            template<int_... vs, int_ a, int_ b>
            struct _iota_impl<enumeration<vs...>, a, b> {
                using type = numbers<(b + a * vs)...>;
            };

            template<class, class, class>
            struct _iota {};

            template<int_ st, int_ sz, int_ sd>
            struct _iota<number<st>, number<sz>, number<sd>>
                : _iota_impl<
                      enumerate<(sz < 0) ? (0 - sz) : sz>,
                      (sz < 0) ? (0 - sd) : sd, st> {};
        } // detail

        template<class start, class size, class stride = number<1>>
        using iota = typename metal::detail::_iota<start, size, stride>::type;
    } // v?
} // metal

HIDE(
/// [iota]
IS_SAME(
    metal::v1::iota<metal::number<'a'>, metal::number<3>>,
    metal::list<metal::number<'a'>, metal::number<'b'>, metal::number<'c'>>
);

static_assert(!metal::is_invocable<metal::lambda<metal::v1::iota>, void, void, metal::number<1>>{}, "");
/// [iota]
)
