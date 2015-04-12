// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((std::is_same<identity<void>::type, void>));

struct a_model_of_identity
{
    using type = a_model_of_identity;
};

struct another_model_of_identity :
        identity<another_model_of_identity>
{};

BOOST_MPL2_ASSERT(is_identity<a_model_of_identity>);
BOOST_MPL2_ASSERT(is_identity<another_model_of_identity>);

struct not_a_model_of_identity
{};

struct not_a_model_of_identity_either
{
    using type = void;
};

BOOST_MPL2_ASSERT(not_<is_identity<not_a_model_of_identity> >);
BOOST_MPL2_ASSERT(not_<is_identity<not_a_model_of_identity_either> >);
BOOST_MPL2_ASSERT(not_<is_identity<identity<void> > >);


int main()
{
    return 0;
}
