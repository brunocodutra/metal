// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

struct a_model_of_identity
{
    using type = a_model_of_identity;
};

struct not_a_model_of_identity {};

struct uncallable
{
    template<typename...>
    struct call;
};

struct unevaluable
{
    template<typename...>
    struct call
    {};
};

struct uncallable_function :
        identity<uncallable_function>
{
    template<typename...>
    struct call;
};

struct unevaluable_function :
        identity<uncallable_function>
{
    template<typename...>
    struct call
    {};
};

BOOST_MPL2_ASSERT(not_<is_identity<void> >);
BOOST_MPL2_ASSERT(is_identity<a_model_of_identity>);
BOOST_MPL2_ASSERT(not_<is_identity<not_a_model_of_identity> >);
BOOST_MPL2_ASSERT(not_<is_identity<identity<void> > >);
BOOST_MPL2_ASSERT((not_<is_identity<uncallable> >));
BOOST_MPL2_ASSERT((not_<is_identity<unevaluable> >));
BOOST_MPL2_ASSERT((is_identity<uncallable_function>));
BOOST_MPL2_ASSERT((not_<is_identity<unevaluable_function> >));
BOOST_MPL2_ASSERT((is_identity<function<std::add_pointer> >));
BOOST_MPL2_ASSERT((is_identity<bind<function<std::add_pointer> > >));

BOOST_MPL2_ASSERT((not_<is_callable<void> >));
BOOST_MPL2_ASSERT((not_<is_callable<a_model_of_identity> >));
BOOST_MPL2_ASSERT((not_<is_callable<not_a_model_of_identity> >));
BOOST_MPL2_ASSERT((not_<is_callable<identity<void> > >));
BOOST_MPL2_ASSERT((not_<is_callable<uncallable> >));
BOOST_MPL2_ASSERT((is_callable<unevaluable>));
BOOST_MPL2_ASSERT((not_<is_callable<uncallable_function> >));
BOOST_MPL2_ASSERT((is_callable<unevaluable_function>));
BOOST_MPL2_ASSERT((is_callable<function<std::add_pointer>, void>));
BOOST_MPL2_ASSERT((is_callable<bind<function<std::add_pointer>, void> >));

BOOST_MPL2_ASSERT((not_<is_evaluable<void> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<a_model_of_identity> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<not_a_model_of_identity> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<identity<void> > >));
BOOST_MPL2_ASSERT((not_<is_evaluable<uncallable> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<unevaluable> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<uncallable_function> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<unevaluable_function> >));
BOOST_MPL2_ASSERT((is_evaluable<function<std::add_pointer>, void>));
BOOST_MPL2_ASSERT((is_evaluable<bind<function<std::add_pointer>, void> >));

BOOST_MPL2_ASSERT((not_<is_function<void> >));
BOOST_MPL2_ASSERT((not_<is_function<a_model_of_identity> >));
BOOST_MPL2_ASSERT((not_<is_function<not_a_model_of_identity> >));
BOOST_MPL2_ASSERT((not_<is_function<identity<void> > >));
BOOST_MPL2_ASSERT((not_<is_function<uncallable> >));
BOOST_MPL2_ASSERT((not_<is_function<unevaluable> >));
BOOST_MPL2_ASSERT((is_function<uncallable_function>));
BOOST_MPL2_ASSERT((is_function<unevaluable_function>));
BOOST_MPL2_ASSERT((is_function<function<std::add_pointer> >));
BOOST_MPL2_ASSERT((is_function<bind<function<std::add_pointer> > >));

int main()
{
    return 0;
}
