#ifndef METAL_LIST_NTH_ELEMENT_V2_HPP
#define METAL_LIST_NTH_ELEMENT_V2_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"
#include "../lambda/lambda.hpp"
#include "../list/join.hpp"
#include "../list/list.hpp"
#include "../list/size.hpp"
#include "../number/greater.hpp"
#include "../number/if.hpp"
#include "../number/less.hpp"
#include "../number/number.hpp"
#include "../number/sub.hpp"
#include "../value/same.hpp"

namespace metal {
    namespace v2 {
        namespace detail {
            template<class piv, template<class...> class comp>
            struct _fast_partition_helper {
                template<class val>
                using type =
                    if_<comp<val, piv>, list<list<val>, list<>>,
                        list<list<>, list<val>>>;
            };

            template<class...>
            struct _transposing_fast_partition_joiner;

            template<class... los, class... his>
            struct _transposing_fast_partition_joiner<list<los, his>...> {
                using type = list<join<los...>, join<his...>>;
            };

            template<class piv, template<class...> class comp, class... vals>
            using _fast_partition = typename _transposing_fast_partition_joiner<
                typename _fast_partition_helper<piv, comp>::template type<
                    vals>...>::type;

            template<class seq, class num, class = true_>
            struct _nth_element_impl {};

            template<class lohi, class piv, class num, class = true_>
            struct _quickselect;

            template<class lo, class hi, class piv, class num>
            struct _quickselect<
                list<lo, hi>, piv, num, greater<size<lo>, num>> {
                template<template<class...> class comp>
                using type = join<
                    metal::detail::forward<
                        _nth_element_impl<lo, num>::template type, comp>,
                    piv, hi>;
            };

            template<class lo, class hi, class piv, class num>
            struct _quickselect<list<lo, hi>, piv, num, same<size<lo>, num>> {
                template<template<class...> class>
                using type = join<lo, piv, hi>;
            };

            template<class lo, class hi, class piv, class num>
            struct _quickselect<list<lo, hi>, piv, num, less<size<lo>, num>> {
                using num_in_hi = sub<num, size<lo>, number<1>>;

                template<template<class...> class comp>
                using type = join<
                    lo, piv,
                    metal::detail::forward<
                        _nth_element_impl<hi, num_in_hi>::template type, comp>>;
            };

            template<class piv, class... vals, int_ n>
            struct _nth_element_impl<
                list<piv, vals...>, number<n>,
                number<(n >= 0 && n < 1 + sizeof...(vals))>> {
                template<template<class...> class comp>
                using type = metal::detail::forward<
                    _quickselect<
                        _fast_partition<piv, comp, vals...>, list<piv>,
                        number<n>>::template type,
                    comp>;
            };

            template<class lbd>
            struct _nth_element {};

            template<template<class...> class comp>
            struct _nth_element<lambda<comp>> {
                template<class seq, class num>
                using type = metal::detail::forward<
                    _nth_element_impl<seq, num>::template type, comp>;
            };

        } // detail

        template<class seq, class num, class lbd>
        using nth_element = metal::detail::call<
            detail::_nth_element<lbd>::template type, seq, num>;
    }
} // metal

#endif
