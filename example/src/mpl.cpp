// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>
#include <metal/external/mpl.hpp>

#include "example.hpp"

/// [number]
#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/integral_c.hpp>

IS_SAME(metal::from_mpl<boost::mpl::true_>, metal::true_);
IS_SAME(metal::from_mpl<boost::mpl::false_>, metal::false_);
IS_SAME(metal::from_mpl<boost::mpl::int_<42>>, metal::number<42>);
IS_SAME(metal::from_mpl<boost::mpl::integral_c<char, 'a'>>, metal::number<'a'>);
/// [number]

/// [list]
#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>

using vals_list = boost::mpl::list<int, float, char, bool>;
using nums_list = boost::mpl::list_c<int, 1, 2, 3, 5, 7, 12, 19, 31>;

IS_SAME(metal::from_mpl<vals_list>, metal::list<int, float, char, bool>);
IS_SAME(metal::from_mpl<nums_list>, metal::numbers<1, 2, 3, 5, 7, 12, 19, 31>);
/// [list]

/// [vector]
#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>

using vals_vec = boost::mpl::vector<int, float, char, bool>;
using nums_vec = boost::mpl::vector_c<int, 1, 2, 3, 5, 7, 12, 19, 31>;

IS_SAME(metal::from_mpl<vals_vec>, metal::list<int, float, char, bool>);
IS_SAME(metal::from_mpl<nums_vec>, metal::numbers<1, 2, 3, 5, 7, 12, 19, 31>);
/// [vector]

/// [map]
#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/integral_c.hpp>

using sizes_map = boost::mpl::map<
    boost::mpl::pair<int, boost::mpl::integral_c<std::size_t, sizeof(int)>>,
    boost::mpl::pair<float, boost::mpl::integral_c<std::size_t, sizeof(float)>>,
    boost::mpl::pair<char, boost::mpl::integral_c<std::size_t, sizeof(char)>>,
    boost::mpl::pair<bool, boost::mpl::integral_c<std::size_t, sizeof(bool)>>
>;

IS_SAME(
    metal::from_mpl<sizes_map>,
    metal::map<
        metal::pair<int, metal::number<sizeof(int)>>,
        metal::pair<float, metal::number<sizeof(float)>>,
        metal::pair<char, metal::number<sizeof(char)>>,
        metal::pair<bool, metal::number<sizeof(bool)>>
    >
);
/// [map]

/// [lambda]
#include <boost/mpl/int.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector.hpp>

using cons = boost::mpl::lambda<
    boost::mpl::push_back<boost::mpl::_1, boost::mpl::_2>
>::type;

using nil = boost::mpl::vector<>;
using one = boost::mpl::int_<1>;

IS_SAME(
    metal::invoke<metal::from_mpl<cons>, nil, one>,
    metal::list<metal::number<1>>
);
/// [lambda]

#if 0
/// [lazy_expression]
struct na {};

template<typename arg_1 = na, typename arg_2 = na, /*...*/ typename arg_n = na>
struct metafunction
{
    typedef /*...*/ type;
};

template<typename arg_1, typename arg_2, /*...*/ typename arg_n>
struct compound_metafunction
{
    typedef typename metafunction<
        typename metafunction<arg_1>::type,
        typename metafunction<arg_2>::type,
        /*...*/
        typename metafunction<arg_n>::type
    >::type type;
};
/// [lazy_expression]

/// [eager_expression]
template<typename... args>
using metafunction = /*...*/;

template<typename... args>
using compound_metafunction = metafunction<metafunction<args>...>;
/// [eager_expression]

/// [lazy_lambda]
struct first_class_metafunction
{
    template<typename arg_1, typename arg_2, /*...*/ typename arg_n>
    struct apply {
        typedef /*...*/ type;
    };
};
/// [lazy_lambda]

/// [eager_lambda]
template<typename... args>
using metafunction = /*...*/;

using first_class_metafunction = metal::lambda<metafunction>;
/// [eager_lambda]
#endif

/// [lazy_evaluation]
IS_SAME(metal::invoke<metal::lambda<std::add_pointer>, void>, std::add_pointer<void>);
IS_SAME(metal::invoke<metal::lambda<std::common_type>, void*, char[]>, std::common_type<void*, char[]>);
/// [lazy_evaluation]

/// [lazy_adaptor]
IS_SAME(metal::invoke<metal::lazy<std::add_pointer>, void>, void*);
IS_SAME(metal::invoke<metal::lazy<std::common_type>, void*, char[]>, void*);
/// [lazy_adaptor]

/// [eval]
IS_SAME(metal::eval<std::add_pointer<void>>, void*);
IS_SAME(metal::eval<std::common_type<void*, char[]>>, void*);
/// [eval]

/// [trait_adaptor]
IS_SAME(metal::invoke<metal::trait<std::is_pointer>, void*>, metal::true_);
IS_SAME(metal::invoke<metal::trait<std::is_pointer>, void()>, metal::false_);

IS_SAME(metal::invoke<metal::trait<std::is_convertible>, char[], void*>, metal::true_);
IS_SAME(metal::invoke<metal::trait<std::is_convertible>, void*, char[]>, metal::false_);
/// [trait_adaptor]

/// [as_number]
IS_SAME(metal::as_number<std::is_pointer<void*>>, metal::true_);
IS_SAME(metal::as_number<std::is_pointer<void()>>, metal::false_);

IS_SAME(metal::as_number<std::is_convertible<char[], void*>>, metal::true_);
IS_SAME(metal::as_number<std::is_convertible<void*, char[]>>, metal::false_);
/// [as_number]
