#ifndef METAL_LIST_NTH_ELEMENT_V1_HPP
#define METAL_LIST_NTH_ELEMENT_V1_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"
#include "../lambda/lambda.hpp"
#include "../list/join.hpp"
#include "../list/list.hpp"
#include "../list/partition.hpp"
#include "../list/size.hpp"
#include "../number/greater.hpp"
#include "../number/if.hpp"
#include "../number/less.hpp"
#include "../number/number.hpp"
#include "../number/sub.hpp"
#include "../value/same.hpp"

namespace metal {
    namespace v1 {
        namespace detail {
            template<class seq, class num, class = true_>
            struct _nth_element_impl {};

            template<class lohi, class piv, class num, class = true_>
            struct _quickselect;

            template<class lo, class hi, class piv, class num>
            struct _quickselect<
                list<lo, hi>, piv, num, greater<size<lo>, num>> {
                template<template<class> class is_lo>
                using type = join<
                    metal::detail::forward<
                        _nth_element_impl<lo, num>::template type, is_lo>,
                    piv, hi>;
            };

            template<class lo, class hi, class piv, class num>
            struct _quickselect<list<lo, hi>, piv, num, same<size<lo>, num>> {
                template<template<class> class>
                using type = join<lo, piv, hi>;
            };

            template<class lo, class hi, class piv, class num>
            struct _quickselect<list<lo, hi>, piv, num, less<size<lo>, num>> {
                using num_in_hi = sub<num, size<lo>, number<1>>;

                template<template<class> class is_lo>
                using type = join<
                    lo, piv,
                    metal::detail::forward<
                        _nth_element_impl<hi, num_in_hi>::template type,
                        is_lo>>;
            };

            template<class piv, class... vals, int_ n>
            struct _nth_element_impl<
                list<piv, vals...>, number<n>,
                number<(n >= 0 && n < 1 + sizeof...(vals))>> {
                template<template<class> class is_lo>
                using type = metal::detail::forward<
                    _quickselect<
                        partition<
                            list<vals...>, lambda<is_lo<piv>::template type>>,
                        list<piv>, number<n>>::template type,
                    is_lo>;
            };

            template<class lbd>
            struct _nth_element {
                template<class piv>
                struct is_lo {
                    template<class val>
                    using type = invoke<lbd, val, piv>;
                };

                template<class seq, class num>
                using type = metal::detail::forward<
                    _nth_element_impl<seq, num>::template type, is_lo>;
            };

        } // detail

        template<class seq, class num, class lbd>
        using nth_element = metal::detail::call<
            detail::_nth_element<lbd>::template type, seq, num>;
    }
} // metal

#endif
