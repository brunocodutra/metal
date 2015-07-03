/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_VERBATIM_HPP
#define BOOST_METAL_FUNCTIONAL_VERBATIM_HPP

namespace boost
{
    namespace metal
    {
        namespace detail
        {
            template<typename, int = 0>
            struct verbatim
            {
                using type = verbatim;
            };
        }

        template<typename atom>
        using verbatim = detail::verbatim<atom>;
    }
}

#endif
