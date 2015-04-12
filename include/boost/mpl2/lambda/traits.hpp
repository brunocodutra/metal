// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_TRAITS_HPP
#define BOOST_MPL2_LAMBDA_TRAITS_HPP

#include <boost/mpl2/lambda/logical/and.hpp>
#include <boost/mpl2/lambda/logical/or.hpp>
#include <boost/mpl2/lambda/nested_type_trait.hpp>
#include <boost/mpl2/lambda/nested_template_trait.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/function.hpp>
#include <boost/mpl2/lambda/bind.hpp>
#include <boost/mpl2/lambda/call.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_type, type);
            BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(has_call, call);
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

        namespace detail
        {
            template<typename x, typename... args>
            struct is_call_defined :
                    std::is_constructible<typename x::template call<args...> >
            {};
        }

        template<typename x, typename... args>
        using is_callable = and_<
            detail::has_call<x>,
            detail::is_call_defined<x, args...>
        >;

        template<typename x, typename... args>
        using is_evaluable = and_<
            is_callable<x, args...>,
            detail::has_type<call<x, args...> >
        >;

        template<typename x>
        struct is_function :
                and_<
                    detail::has_call<x>,
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
    }
}

#endif
