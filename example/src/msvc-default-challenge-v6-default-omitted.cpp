#include "example.hpp"

#include <cstdint>
#include <memory>
#include <metal.hpp>
#include <tuple>

namespace metal {
    namespace v6 {
    using metal::detail::call;
    using metal::detail::forward;

        namespace detail {
        template<class x, class y, class z = list<>, class = true_>
        struct _merge;

        template<class, class, class, template<class...> class, class = true_>
        struct _merge_impl {};

        template<
            class xh, class... xt, class yh, class... yt, class... zs,
            template<class...> class e>
        struct _merge_impl<
            list<xh, xt...>, list<yh, yt...>, list<zs...>, e,
            if_<call<e, yh, xh>, true_, false_>>
            : _merge_impl<list<xh, xt...>, list<yt...>, list<zs..., yh>, e> {};

        template<
            class xh, class... xt, class yh, class... yt, class... zs,
            template<class...> class e>
        struct _merge_impl<
            list<xh, xt...>, list<yh, yt...>, list<zs...>, e,
            if_<call<e, yh, xh>, false_, true_>>
            : _merge_impl<list<xt...>, list<yh, yt...>, list<zs..., xh>, e> {};

        template<class... xs, class... zs, template<class...> class e>
        struct _merge_impl<list<xs...>, list<>, list<zs...>, e> {
            template<class x, class y>
            using part = typename _merge<
                prepend<x, xs...>, y, list<zs...>>::template type<e>;

            using type = list<zs..., xs...>;
        };

        template<class... ys, class... zs, template<class...> class e>
        struct _merge_impl<list<>, list<ys...>, list<zs...>, e> {
            template<class x, class y>
            using part = typename _merge<
                x, prepend<y, ys...>, list<zs...>>::template type<e>;

            using type = list<zs..., ys...>;
        };

        template<class x, class y, class z, class>
        struct _merge {
            using xe = size<x>;
            using ye = size<y>;

            using xm = div<inc<xe>, number<2>>;
            using ym = div<inc<ye>, number<2>>;

            using xl = range<x, number<0>, xm>;
            using yl = range<y, number<0>, ym>;

            using xr = range<x, xm, xe>;
            using yr = range<y, ym, ye>;

            using l = _merge<xl, yl, z>;

            template<template<class...> class expr>
            using type = typename l::template type<expr>::template part<xr, yr>;
        };

        template<class x, class y, class z>
        struct _merge<x, y, z, less<add<size<x>, size<y>>, number<100>>> {
            template<template<class...> class expr>
            using type = _merge_impl<x, y, z, expr>;
        };

        template<class x, class z>
        struct _merge<x, list<>, z> {
            template<template<class...> class expr>
            using type = _merge_impl<x, list<>, z, expr>;
        };

        template<class y, class z>
        struct _merge<list<>, y, z> {
            template<template<class...> class expr>
            using type = _merge_impl<list<>, y, z, expr>;
        };

        template<class seq>
        struct _sort_impl {
            using beg = number<0>;
            using end = size<seq>;
            using mid = div<end, number<2>>;

            using l = _sort_impl<range<seq, beg, mid>>;
            using r = _sort_impl<range<seq, mid, end>>;

            template<template<class...> class expr>
            using type = typename _merge<
                forward<l::template type, expr>,
                forward<r::template type, expr>>::template type<expr>::type;
        };

        template<class x, class y>
        struct _sort_impl<list<x, y>> {
            template<template<class...> class expr>
            using type = if_<expr<y, x>, list<y, x>, list<x, y>>;
        };

        template<class x>
        struct _sort_impl<list<x>> {
            template<template<class...> class>
            using type = list<x>;
        };

        template<>
        struct _sort_impl<list<>> {
            template<template<class...> class>
            using type = list<>;
        };

        template<class lbd>
        struct _sort {};

        template<template<class...> class expr>
        struct _sort<lambda<expr>> {
            template<class... seq>
            using type = forward<_sort_impl<seq...>::template type, expr>;
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
  metal::v6::sort<metal::numbers<7, -4, 2>, metal::lambda<metal::less>>,
  metal::numbers<-4, 2, 7>
);

IS_SAME(
  metal::v6::sort<metal::numbers<7, -4, 2>>,
  metal::numbers<-4, 2, 7>
);

static_assert(!metal::is_invocable<metal::lambda<metal::v6::sort>, void>{}, "");
/// [iota]
)
