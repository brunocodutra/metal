// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_CALL_HPP
#define BOOST_MPL2_LAMBDA_CALL_HPP

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename... args>
            struct args_pack;
        }

        template<typename function, typename... args>
        struct call :
                call<function, typename detail::args_pack<args...> >
        {};

        template<typename function, typename... args>
        struct call<function, detail::args_pack<args...> >  :
                function::template call<args...>
        {};
    }
}

#endif
