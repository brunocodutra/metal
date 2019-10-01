#ifndef METAL_LIST_NTH_ELEMENT_BRUTEFORCE_HPP
#define METAL_LIST_NTH_ELEMENT_BRUTEFORCE_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"
#include "../lambda/lambda.hpp"
#include "../list/append.hpp"
#include "../list/at.hpp"
#include "../list/drop.hpp"
#include "../list/join.hpp"
#include "../list/list.hpp"
#include "../list/prepend.hpp"
#include "../list/size.hpp"
#include "../number/greater.hpp"
#include "../number/if.hpp"
#include "../number/less.hpp"
#include "../number/mod.hpp"
#include "../number/number.hpp"
#include "../number/or.hpp"
#include "../number/sub.hpp"
#include "../pair/first.hpp"
#include "../pair/pair.hpp"
#include "../pair/second.hpp"

namespace metal {
namespace nth_element_bruteforce {
    namespace detail {

        template<class seq, class num, class = true_>
        struct _nth_element_impl {};

        template<class... vals, int_ n>
        struct _nth_element_impl<
            list<vals...>, number<n>, number<(n >= 0 && n < sizeof...(vals))>> {
            using num = number<n>;

            template<class val, template<class...> class comp>
            using count_lt = add<comp<vals, val>...>;

            template<class val, template<class...> class comp>
            using too_large = greater<count_lt<val, comp>, num>;

            template<class val, template<class...> class comp>
            using count_gt = add<comp<val, vals>...>;

            using rev_num = number<sizeof...(vals) - n - 1>;

            template<class val, template<class...> class comp>
            using too_small = greater<count_gt<val, comp>, rev_num>;

            template<template<class...> class comp>
            using eq = join<
                if_<or_<too_small<vals, comp>, too_large<vals, comp>>, list<>,
                    list<vals>>...>;

            template<template<class...> class comp>
            using type = at<eq<comp>, number<0>>;
        };

        template<class lbd>
        struct _nth_element {};

        template<template<class...> class comp>
        struct _nth_element<lambda<comp>> {
            template<class seq, class num>
            using type = ::metal::detail::forward<
                _nth_element_impl<seq, num>::template type, comp>;
        };

    } // detail

    template<class seq, class num, class lbd>
    using nth_element = ::metal::detail::call<
        detail::_nth_element<lbd>::template type, seq, num>;
}
} // metal

#endif
