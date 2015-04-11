// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_TRAITS_HPP
#define BOOST_MPL2_CORE_TRAITS_HPP

#include <boost/mpl2/integrals/logical/and.hpp>
#include <boost/mpl2/integrals/logical/or.hpp>
#include <boost/mpl2/core/nested_type_trait.hpp>
#include <boost/mpl2/core/nested_template_trait.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/function.hpp>
#include <boost/mpl2/core/bind.hpp>
#include <boost/mpl2/core/call.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_type, type);
            BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(has_template_call, call);
        }

        template<typename x>
        using is_identity = and_<
            detail::has_type<x>,
            call<
                bind<
                    function<std::is_same>,
                    bind<nullary<identity<x> > >,
                    bind<nullary<x> >
                >
            >
        >;

        template<typename x>
        struct is_function :
                and_<
                    detail::has_template_call<x>,
                    detail::has_type<x>,
                    or_<
                        is_identity<x>,
                        call<
                            bind<
                                function<is_function>,
                                bind<nullary<x> >
                            >
                        >
                    >
                >
        {};

        template<typename function, typename... args>
        using is_callable = and_<
            is_function<function>,
            std::is_default_constructible<call<function, args...> >
        >;

        template<typename function, typename... args>
        using is_evaluable = and_<
            is_callable<function, args...>,
            detail::has_type<call<function, args...> >
        >;
    }
}

#endif
