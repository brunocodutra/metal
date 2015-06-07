// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/logical.hpp>

#include "test/main.hpp"

using namespace boost::mpl2;

struct undefined;

BOOST_MPL2_ASSERT((or_<std::false_type, std::true_type>));
BOOST_MPL2_ASSERT((or_<std::false_type, std::false_type, std::true_type>));
BOOST_MPL2_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::true_type>));
BOOST_MPL2_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>));
BOOST_MPL2_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>));
BOOST_MPL2_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>));
BOOST_MPL2_ASSERT((or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::true_type>));

BOOST_MPL2_ASSERT((not_<or_<std::false_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<or_<std::false_type, std::false_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<or_<std::false_type, std::false_type, std::false_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<or_<std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type, std::false_type>>));

BOOST_MPL2_ASSERT((and_<std::true_type, std::true_type>));
BOOST_MPL2_ASSERT((and_<std::true_type, std::true_type, std::true_type>));
BOOST_MPL2_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type>));
BOOST_MPL2_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>));
BOOST_MPL2_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>));
BOOST_MPL2_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>));
BOOST_MPL2_ASSERT((and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type>));

BOOST_MPL2_ASSERT((not_<and_<std::true_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<and_<std::true_type, std::true_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<and_<std::true_type, std::true_type, std::true_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<and_<std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>>));
BOOST_MPL2_ASSERT((not_<and_<std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::true_type, std::false_type>>));

BOOST_MPL2_ASSERT((or_<std::true_type, undefined>));
BOOST_MPL2_ASSERT((or_<std::true_type, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<std::true_type, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<std::true_type, undefined, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<std::true_type, undefined, undefined, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<std::true_type, undefined, undefined, undefined, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<std::true_type, undefined, undefined, undefined, undefined, undefined, undefined, undefined>));

BOOST_MPL2_ASSERT((not_<and_<std::false_type, undefined>>));
BOOST_MPL2_ASSERT((not_<and_<std::false_type, undefined, undefined>>));
BOOST_MPL2_ASSERT((not_<and_<std::false_type, undefined, undefined, undefined>>));
BOOST_MPL2_ASSERT((not_<and_<std::false_type, undefined, undefined, undefined, undefined>>));
BOOST_MPL2_ASSERT((not_<and_<std::false_type, undefined, undefined, undefined, undefined, undefined>>));
BOOST_MPL2_ASSERT((not_<and_<std::false_type, undefined, undefined, undefined, undefined, undefined, undefined>>));
BOOST_MPL2_ASSERT((not_<and_<std::false_type, undefined, undefined, undefined, undefined, undefined, undefined, undefined>>));
