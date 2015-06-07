// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_SIZE_HPP
#define BOOST_MPL2_SEQUENCES_SIZE_HPP

#include <boost/mpl2/core/traits_factory.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/sequences/tag.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        template<typename tag>
        struct size_impl
        {
        private:
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_size, size);

        public:
            template<typename x, typename = has_size_t<x>>
            struct call :
                    x::size
            {};

            template<typename x>
            struct call<x, std::false_type>
            {};
        };

        template<typename x>
        struct size :
                call<size_impl<typename tag<x>::type>, x>
        {};

        template<typename x>
        using size_t = typename size<x>::type;
    }
}

#endif
