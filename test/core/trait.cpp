/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#include <boost/mpl2/config/limits/arity.hpp>
#include <boost/mpl2/compat/variadic.hpp>
#include <boost/mpl2/core/trait.hpp>

struct test01;
struct test02 {};
struct test03 {void nested();};
struct test04 {int nested;};
struct test05 {static void nested();};
struct test06 {static int nested;};
struct test07 {typedef int nested;};
struct test08 {struct nested;};
struct test09 {typedef struct {} nested;};
struct test10 {typedef void (nested)();};
struct test11 {typedef void (*nested)();};
struct test12 {typedef void (&nested)();};
struct test13 {typedef char nested[1];};
struct test14 {typedef char (&nested)[1];};
struct test15 {template<typename> void nested();};
struct test16 {template<typename> struct nested;};
struct test17 {template<BOOST_MPL2_VARIADIC_PARAMS(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY, _)> struct nested;};
struct test18 {template<bool> struct nested;};
struct test19 {template<typename T, T> struct nested;};
struct test20 {template<template<typename> class> struct nested;};

BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_nested, nested)

int main()
{
    return  has_nested<test01>() ||
            has_nested<test02>() ||
            has_nested<test03>() ||
            has_nested<test04>() ||
            has_nested<test05>() ||
            has_nested<test06>() ||
           !has_nested<test07>() ||
           !has_nested<test08>() ||
           !has_nested<test09>() ||
           !has_nested<test10>() ||
           !has_nested<test11>() ||
           !has_nested<test12>() ||
           !has_nested<test13>() ||
           !has_nested<test14>() ||
            has_nested<test15>() ||
            has_nested<test16>() ||
            has_nested<test17>() ||
            has_nested<test18>() ||
            has_nested<test19>() ||
            has_nested<test20>();
}
