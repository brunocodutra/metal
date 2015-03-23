// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_COMPAT_SIZEOF_HPP
#define BOOST_MPL2_CORE_COMPAT_SIZEOF_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_VARIADIC_TEMPLATES)
    #define BOOST_MPL2_SEIZEOF(_, ARGS) \
        sizeof...(ARGS)
#else
    #include <boost/mpl2/core/limits/arity.hpp>
    #include <boost/mpl2/core/compat/numbered.hpp>

    #include <boost/config.hpp>
    #include <boost/preprocessor/dec.hpp>

    #include <cstddef>

    #define BOOST_MPL2_DETAIL_HEAD_DECL \
        BOOST_MPL2_OPTIONAL_PARAMS(1, h)

    #define BOOST_MPL2_DETAIL_TAIL_DECL \
        BOOST_MPL2_TRAILING_OPTIONAL_PARAMS( \
            BOOST_PP_DEC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY), \
            tail \
        )

    #define BOOST_MPL2_DETAIL_TAIL \
        BOOST_MPL2_ARGS( \
            BOOST_PP_DEC(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY), \
            tail \
        )

    namespace boost
    {
        namespace mpl2
        {
            namespace detail
            {
                template<BOOST_MPL2_DETAIL_HEAD_DECL BOOST_MPL2_DETAIL_TAIL_DECL>
                struct sizeof_ :
                        sizeof_<BOOST_MPL2_DETAIL_TAIL>
                {
                    BOOST_STATIC_CONSTEXPR std::size_t value = 1U +
                            sizeof_<BOOST_MPL2_DETAIL_TAIL>::value;
                };

                template<>
                struct sizeof_<>
                {
                    BOOST_STATIC_CONSTEXPR std::size_t value = 0U;
                };
            }
        }
    }

    #undef BOOST_MPL2_DETAIL_HEAD_DECL
    #undef BOOST_MPL2_DETAIL_TAIL_DECL
    #undef BOOST_MPL2_DETAIL_TAIL

    #define BOOST_MPL2_SEIZEOF(N, ARGS) \
        boost::mpl2::detail::sizeof_<BOOST_MPL2_ARGS(N, ARGS)>::value
#endif

#endif
