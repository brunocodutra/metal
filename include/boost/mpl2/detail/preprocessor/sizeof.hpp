/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL_DETAIL_PREPROCESSOR_SIZEOF_HPP_
#define _BOOST_MPL_DETAIL_PREPROCESSOR_SIZEOF_HPP_

#include <boost/mpl2/config/switches/variadic.hpp>

#if !defined(BOOST_MPL_CFG_NO_VARIADIC_TEMPLATES)
    #define BOOST_MPL_SEIZEOF(_, ARGS) \
        sizeof...(ARGS)
#else
    #include <boost/mpl2/config/limits/arity.hpp>
    #include <boost/mpl2/detail/preprocessor/args.hpp>

    #include <boost/preprocessor/repeat.hpp>

    #define BOOST_MPL_DETAIL_SPECIALIZE_SEIZEOF(Z, N, _) \
        template<BOOST_MPL_PARAMS(N, items)> \
        struct sizeof_<BOOST_MPL_ARGS(N, items)> \
        { \
            enum {value = N}; \
        };


    namespace boost
    {
        namespace mpl2
        {
            namespace detail
            {
                template<
                        BOOST_MPL_OPTIONAL_PARAMS(
                            BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
                            items
                        )
                    >
                struct sizeof_
                {
                    enum {value = BOOST_MPL_LIMIT_METAFUNCTION_ARITY};
                };

                BOOST_PP_REPEAT(
                        BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
                        BOOST_MPL_DETAIL_SPECIALIZE_SEIZEOF,
                        _
                    )
            }
        }
    }

    #define BOOST_MPL_SEIZEOF(N, ARGS) \
        boost::mpl2::detail::sizeof_<BOOST_MPL_ARGS(N,ARGS)>::value
#endif

#endif
