/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include <boost/mpl2/compat/variadic.hpp>

struct yes;
struct no;

template<BOOST_MPL2_VARIADIC_OPTIONAL_PARAMS(5, args)>
struct pack
{};

template<typename>
struct negate;

template<>
struct negate<no>
{
    typedef yes type;
};

template<>
struct negate<yes>
{
    typedef no type;
};

template<typename pack>
struct negate_all;

template<BOOST_MPL2_VARIADIC_PARAMS(5, args)>
struct negate_all<pack<BOOST_MPL2_VARIADIC_ARGS(5, args)> >
{
    typedef pack<BOOST_MPL2_CALL_FOR_EACH_VARIADIC_ARG(5, args, negate)> type;
};

bool unanimity(...)
{
    return false;
}

bool unanimity(pack<yes>)
{
    return true;
}

bool unanimity(pack<yes, yes>)
{
    return true;
}

bool unanimity(pack<yes, yes, yes>)
{
    return true;
}

bool unanimity(pack<yes, yes, yes, yes>)
{
    return true;
}

bool unanimity(pack<yes, yes, yes, yes, yes>)
{
    return true;
}

int main()
{
    return
            !unanimity(negate_all<pack<no> >::type()) ||
            !unanimity(negate_all<pack<no, no> >::type()) ||
            !unanimity(negate_all<pack<no, no, no> >::type()) ||
            !unanimity(negate_all<pack<no, no, no, no> >::type()) ||
            !unanimity(negate_all<pack<no, no, no, no, no> >::type());
}
