// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_CALL_HPP
#define BOOST_MPL2_METAFUNCTIONAL_CALL_HPP

#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename function, typename... args>
            struct call_impl
            {
            private:
                struct empty{};

                template<typename>
                static empty eval(...);
                template<typename f>
                static identity<typename f::template call<args...>::type> eval(int);

            public:
                using type = decltype(eval<function>(0));
            };

        }

        template<typename...>
        struct call
        {};

        template<typename function, typename... args>
        struct call<function, args...> :
                detail::call_impl<function, args...>::type
        {};
    }
}

#endif
