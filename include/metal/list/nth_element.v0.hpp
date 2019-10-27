#ifndef METAL_LIST_NTH_ELEMENT_V0_HPP
#define METAL_LIST_NTH_ELEMENT_V0_HPP

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
    namespace v0 {
        namespace detail {
            template<class seq, class num, class = true_>
            struct _nth_element_impl {};

            template<class lo, class piv, class hi, class num, class = true_>
            struct _quickselect;

            template<class lo, class piv, class hi, class num>
            struct _quickselect<lo, piv, hi, num, greater<size<lo>, num>> {
                template<template<class...> class comp>
                using type = join<
                    metal::detail::forward<
                        _nth_element_impl<lo, num>::template type, comp>,
                    piv, hi>;
            };

            template<class lo, class piv, class hi, class num>
            struct _quickselect<lo, piv, hi, num, same<size<lo>, num>> {
                template<template<class...> class>
                using type = join<lo, piv, hi>;
            };

            template<class lo, class piv, class hi, class num>
            struct _quickselect<lo, piv, hi, num, less<size<lo>, num>> {
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
                        join<if_<comp<vals, piv>, list<vals>, list<>>...>,
                        list<piv>,
                        join<if_<comp<vals, piv>, list<>, list<vals>>...>,
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
