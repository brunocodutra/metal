/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL2_DETAIL_PREPROCESSOR_SIZEOF_HPP_
#define _BOOST_MPL2_DETAIL_PREPROCESSOR_SIZEOF_HPP_

#include <boost/mpl2/config/switches/variadic.hpp>

#if !defined(BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES)
    #define BOOST_MPL2_SEIZEOF(_, ARGS) \
        sizeof...(ARGS)
#else
    #include <boost/mpl2/config/limits/arity.hpp>
    #include <boost/mpl2/detail/preprocessor/args.hpp>

    #include <boost/preprocessor/dec.hpp>

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
                    enum
                    {
                        value = 1U +
                            sizeof_<BOOST_MPL2_DETAIL_TAIL>::value
                    };
                };

                template<>
                struct sizeof_<>
                {
                    enum {value = 0U};
                };
            }
        }
    }

    #undef BOOST_MPL2_DETAIL_HEAD_DECL
    #undef BOOST_MPL2_DETAIL_TAIL_DECL
    #undef BOOST_MPL2_DETAIL_TAIL

    #define BOOST_MPL2_SEIZEOF(N, ARGS) \
        boost::mpl2::detail::sizeof_<BOOST_MPL2_ARGS(N,ARGS)>::value
#endif

#endif
