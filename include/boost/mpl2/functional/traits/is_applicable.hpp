// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_FUNCTIONAL_TRAITS_IS_APPLICABLE_HPP
#define BOOST_MPL2_FUNCTIONAL_TRAITS_IS_APPLICABLE_HPP

#include <boost/mpl2/functional/apply.hpp>
#include <boost/mpl2/functional/traits/is_evaluable.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename... _>
        struct is_applicable :
                is_evaluable<apply, _...>
        {};

        template<typename... _>
        using is_applicable_t = typename is_applicable<_...>::type;
    }
}

#endif
