#include <metal.hpp>

#include <cstdint>
#include <memory>
#include <tuple>

#include "example.hpp"

HIDE(
/// [list1]
using list = metal::list<>; // an empty list
/// [list1]

IS_SAME(metal::is_list<list>, metal::true_);
)

HIDE(
/// [list2]
using list = metal::list<int, int*, int&>;
/// [list2]

IS_SAME(metal::is_list<list>, metal::true_);
)

HIDE(
/// [not_a_list1]
using not_a_list = std::tuple<int, int*, int&>; // not a specialization of metal::list
/// [not_a_list1]

IS_SAME(metal::is_list<not_a_list>, metal::false_);
)

HIDE(
/// [is_list]
IS_SAME(metal::is_list<void>, metal::false_);
IS_SAME(metal::is_list<std::tuple<int, float, void>>, metal::false_);
IS_SAME(metal::is_list<metal::list<int, float, void>>, metal::true_);
IS_SAME(metal::is_list<metal::pair<int, int*>>, metal::true_);
IS_SAME(metal::is_list<metal::map<metal::pair<int, int*>>>, metal::true_);
/// [is_list]
)

HIDE(
/// [as_list]
IS_SAME(metal::as_list<std::shared_ptr<int>>, metal::list<int>);

IS_SAME(
    metal::as_list<std::unique_ptr<int>>,
    metal::list<int, std::default_delete<int>>
);

IS_SAME(
    metal::as_list<std::tuple<int, char, float>>,
    metal::list<int, char, float>
);
/// [as_list]
)

HIDE(
/// [size]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::size<l>, metal::number<6>);
IS_SAME(metal::size<metal::list<>>, metal::number<0>);
/// [size]
)

HIDE(
/// [empty]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::empty<l>, metal::false_);
IS_SAME(metal::empty<metal::list<>>, metal::true_);
/// [empty]
)

HIDE(
/// [indices]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::indices<l>,
    metal::list<
        metal::number<0>, metal::number<1>, metal::number<2>,
        metal::number<3>, metal::number<4>, metal::number<5>
    >
);
/// [indices]
)

HIDE(
/// [at]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::at<l, metal::number<0>>, short);
IS_SAME(metal::at<l, metal::number<1>>, int);
IS_SAME(metal::at<l, metal::number<2>>, long);
IS_SAME(metal::at<l, metal::number<3>>, float);
IS_SAME(metal::at<l, metal::number<4>>, double);
IS_SAME(metal::at<l, metal::number<5>>, void);
/// [at]
)

HIDE(
/// [front]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::front<l>, short);
/// [front]
)

HIDE(
/// [back]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::back<l>, void);
/// [back]
)

HIDE(
/// [contains]
using l = metal::list<int, int, float, int, void, float>;

IS_SAME(metal::contains<l, int>, metal::true_);
IS_SAME(metal::contains<l, float>, metal::true_);
IS_SAME(metal::contains<l, void>, metal::true_);
IS_SAME(metal::contains<l, char>, metal::false_);
/// [contains]
)

HIDE(
/// [count]
using l = metal::list<int, int, float, int, void, float>;

IS_SAME(metal::count<l, int>, metal::number<3>);
IS_SAME(metal::count<l, float>, metal::number<2>);
IS_SAME(metal::count<l, void>, metal::number<1>);
IS_SAME(metal::count<l, char>, metal::number<0>);
/// [count]
)

HIDE(
/// [find]
using l = metal::list<int, int, float, int, void, float>;

IS_SAME(metal::find<l, int>, metal::number<0>);
IS_SAME(metal::find<l, float>, metal::number<2>);
IS_SAME(metal::find<l, void>, metal::number<4>);
IS_SAME(metal::find<l, char>, metal::number<6>);
/// [find]
)

HIDE(
/// [copy]
using l = metal::list<int, int, float, int, void, float>;

IS_SAME(metal::copy<l, int>, metal::list<int, int, int>);
IS_SAME(metal::copy<l, float>, metal::list<float, float>);
IS_SAME(metal::copy<l, void>, metal::list<void>);
IS_SAME(metal::copy<l, char>, metal::list<>);
/// [copy]
)

HIDE(
/// [remove]
using l = metal::list<int, int, float, int, void, float>;

IS_SAME(metal::remove<l, int>, metal::list<float, void, float>);
IS_SAME(metal::remove<l, float>, metal::list<int, int, int, void>);
IS_SAME(metal::remove<l, void>, metal::list<int, int, float, int, float>);
IS_SAME(metal::remove<l, char>, metal::list<int, int, float, int, void, float>);
/// [remove]
)

HIDE(
/// [replace]
using l = metal::list<int, int, float, int, void, float>;

IS_SAME(
    metal::replace<l, float>,
    metal::list<int, int, int, void>
);

IS_SAME(
    metal::replace<l, float, char>,
    metal::list<int, int, char, int, void, char>
);

IS_SAME(
    metal::replace<l, float, char, char*>,
    metal::list<int, int, char, char*, int, void, char, char*>
);
/// [replace]
)

HIDE(
/// [all_of]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::all_of<l, metal::trait<std::is_fundamental>>, metal::true_);
IS_SAME(metal::all_of<l, metal::trait<std::is_floating_point>>, metal::false_);
IS_SAME(metal::all_of<l, metal::trait<std::is_class>>, metal::false_);
/// [all_of]
)

HIDE(
/// [any_of]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::any_of<l, metal::trait<std::is_fundamental>>, metal::true_);
IS_SAME(metal::any_of<l, metal::trait<std::is_floating_point>>, metal::true_);
IS_SAME(metal::any_of<l, metal::trait<std::is_class>>, metal::false_);
/// [any_of]
)

HIDE(
/// [none_of]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::none_of<l, metal::trait<std::is_fundamental>>, metal::false_);
IS_SAME(metal::none_of<l, metal::trait<std::is_floating_point>>, metal::false_);
IS_SAME(metal::none_of<l, metal::trait<std::is_class>>, metal::true_);
/// [none_of]
)

HIDE(
/// [count_if]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::count_if<l, metal::trait<std::is_fundamental>>, metal::number<6>);
IS_SAME(metal::count_if<l, metal::trait<std::is_floating_point>>, metal::number<2>);
IS_SAME(metal::count_if<l, metal::trait<std::is_class>>, metal::number<0>);
/// [count_if]
)

HIDE(
/// [find_if]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::find_if<l, metal::trait<std::is_fundamental>>, metal::number<0>);
IS_SAME(metal::find_if<l, metal::trait<std::is_floating_point>>, metal::number<3>);
IS_SAME(metal::find_if<l, metal::trait<std::is_class>>, metal::number<6>);
/// [find_if]
)

HIDE(
/// [partition]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::partition<l, metal::trait<std::is_fundamental>>,
    metal::pair<metal::list<short, int, long, float, double, void>, metal::list<>>
);

IS_SAME(
    metal::partition<l, metal::trait<std::is_floating_point>>,
    metal::pair<metal::list<float, double>, metal::list<short, int, long, void>>
);

IS_SAME(
    metal::partition<l, metal::trait<std::is_class>>,
    metal::pair<metal::list<>, metal::list<short, int, long, float, double, void>>
);
/// [partition]
)

HIDE(
/// [copy_if]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::copy_if<l, metal::trait<std::is_fundamental>>,
    metal::list<short, int, long, float, double, void>
);

IS_SAME(
    metal::copy_if<l, metal::trait<std::is_floating_point>>,
    metal::list<float, double>
);

IS_SAME(metal::copy_if<l, metal::trait<std::is_class>>, metal::list<>);
/// [copy_if]
)

HIDE(
/// [remove_if]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::remove_if<l, metal::trait<std::is_fundamental>>, metal::list<>);

IS_SAME(
    metal::remove_if<l, metal::trait<std::is_floating_point>>,
    metal::list<short, int, long, void>
);

IS_SAME(
    metal::remove_if<l, metal::trait<std::is_class>>,
    metal::list<short, int, long, float, double, void>
);
/// [remove_if]
)

HIDE(
/// [replace_if]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::replace_if<l, metal::trait<std::is_fundamental>, char>,
    metal::list<char, char, char, char, char, char>
);

IS_SAME(
    metal::replace_if<l, metal::trait<std::is_floating_point>, char>,
    metal::list<short, int, long, char, char, void>
);

IS_SAME(
    metal::replace_if<l, metal::trait<std::is_class>, char>,
    metal::list<short, int, long, float, double, void>
);
/// [replace_if]
)

HIDE(
/// [flatten]
using character = metal::list<char, wchar_t, char16_t, char32_t>;
using integral = metal::list<short, int, long, long long>;
using floating = metal::list<float, double, long double>;

IS_SAME(
    metal::flatten<metal::list<character, integral, floating>>,
    metal::list<
        char, wchar_t, char16_t, char32_t,
        short, int, long, long long,
        float, double, long double
    >
);
/// [flatten]
)

HIDE(
/// [join]
using character = metal::list<char, wchar_t, char16_t, char32_t>;
using integral = metal::list<short, int, long, long long>;
using floating = metal::list<float, double, long double>;

IS_SAME(
    metal::join<character, integral, floating>,
    metal::list<
        char, wchar_t, char16_t, char32_t,
        short, int, long, long long,
        float, double, long double
    >
);
/// [join]
)

HIDE(
/// [splice]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::splice<l, metal::number<2>, metal::list<char, char[]>>,
    metal::list<short, int, char, char[], long, float, double, void>
);
/// [splice]
)

HIDE(
/// [insert]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::insert<l, metal::number<2>, unsigned>,
    metal::list<short, int, unsigned, long, float, double, void>
);
/// [insert]
)

HIDE(
/// [append]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::append<l, char, char[]>,
    metal::list<short, int, long, float, double, void, char, char[]>
);
/// [append]
)

HIDE(
/// [prepend]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::prepend<l, char, char[]>,
    metal::list<char, char[], short, int, long, float, double, void>
);
/// [prepend]
)

HIDE(
/// [iota]
IS_SAME(
    metal::iota<metal::number<'a'>, metal::number<3>>,
    metal::list<metal::number<'a'>, metal::number<'b'>, metal::number<'c'>>
);

IS_SAME(
    metal::iota<metal::number<2>, metal::number<3>, metal::number<-5>>,
    metal::list<metal::number<2>, metal::number<-3>, metal::number<-8>>
);

IS_SAME(
    metal::iota<metal::number<2>, metal::number<-3>, metal::number<-5>>,
    metal::list<metal::number<2>, metal::number<7>, metal::number<12>>
);
/// [iota]
)

HIDE(
/// [repeat]
IS_SAME(metal::repeat<void, metal::number<0>>, metal::list<>);
IS_SAME(metal::repeat<void, metal::number<3>>, metal::list<void, void, void>);
/// [repeat]
)

HIDE(
/// [slice]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::slice<l, metal::number<2>, metal::number<3>>,
    metal::list<long, float, double>
);

IS_SAME(
    metal::slice<l, metal::number<1>, metal::number<2>, metal::number<3>>,
    metal::list<int, double>
);

IS_SAME(
    metal::slice<l, metal::number<5>, metal::number<-3>, metal::number<2>>,
    metal::list<void, float, int>
);
/// [slice]
)

HIDE(
/// [range]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::range<l, metal::number<2>, metal::number<5>>,
    metal::list<long, float, double>
);

IS_SAME(
    metal::range<l, metal::number<5>, metal::number<2>>,
    metal::list<double, float, long>
);
/// [range]
)

HIDE(
/// [erase]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::erase<l, metal::number<2>, metal::number<5>>,
    metal::list<short, int, void>
);

IS_SAME(
    metal::erase<l, metal::number<5>, metal::number<2>>,
    metal::list<short, int, void>
);
/// [erase]
)

HIDE(
/// [drop]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::drop<l, metal::number<3>>, metal::list<float, double, void>);
/// [drop]
)

HIDE(
/// [take]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::take<l, metal::number<3>>, metal::list<short, int, long>);
/// [take]
)

HIDE(
/// [reverse]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(metal::reverse<l>, metal::list<void, double, float, long, int, short>);
/// [reverse]
)

HIDE(
/// [rotate]
using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    metal::rotate<l, metal::number<2>>,
    metal::list<long, float, double, void, short, int>
);

IS_SAME(
    metal::rotate<l, metal::number<-2>>,
    metal::list<double, void, short, int, long, float>
);
/// [rotate]
)

HIDE(
/// [sort]
using l = metal::list<int16_t, int8_t, uint16_t, int32_t, uint32_t, uint8_t>;

template<typename x, typename y> // strict ordering
using smaller = metal::number<sizeof(x) < sizeof(y)>;

IS_SAME(
    metal::sort<l, metal::lambda<smaller>>, // stable sorting
    metal::list<int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t>
);

template<typename x, typename y> // partial ordering
using not_bigger = metal::number<sizeof(x) <= sizeof(y)>;

IS_SAME(
    metal::sort<l, metal::lambda<not_bigger>>, // non-stable sorting
    metal::list<uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t>
);
/// [sort]
)

HIDE(
/// [cartesian]
struct a; struct b; struct c;
struct d; struct e;
struct f; struct g;

using x = metal::list<a, b>;
using y = metal::list<c, d>;
using z = metal::list<e, f, g>;

IS_SAME(
    metal::cartesian<x, y, z>,
    metal::list<
        metal::list<a, c, e>, metal::list<a, c, f>, metal::list<a, c, g>,
        metal::list<a, d, e>, metal::list<a, d, f>, metal::list<a, d, g>,
        metal::list<b, c, e>, metal::list<b, c, f>, metal::list<b, c, g>,
        metal::list<b, d, e>, metal::list<b, d, f>, metal::list<b, d, g>
    >
);
/// [cartesian]
)

HIDE(
/// [cascade]
struct a; struct b; struct c; struct d;

template<typename...> struct f {};
template<typename...> struct g {};
template<typename...> struct h {};

using tree = metal::list<
    metal::list<metal::list<a>, metal::list<b>>,
    metal::list<metal::list<c>, metal::list<d>>
>;

IS_SAME(
    metal::cascade<tree, metal::lambda<f>, metal::lambda<g>, metal::lambda<h>>,
    f<g<h<a>, h<b>>, g<h<c>, h<d>>>
);
/// [cascade]
)

HIDE(
/// [combine]
struct a; struct b; struct c; struct d;

IS_SAME(
    metal::combine<metal::list<a, b, c, d>, metal::number<2>>,
    metal::list<
        metal::list<a, a>, metal::list<a, b>, metal::list<a, c>, metal::list<a, d>,
        metal::list<b, a>, metal::list<b, b>, metal::list<b, c>, metal::list<b, d>,
        metal::list<c, a>, metal::list<c, b>, metal::list<c, c>, metal::list<c, d>,
        metal::list<d, a>, metal::list<d, b>, metal::list<d, c>, metal::list<d, d>
    >
);
/// [combine]
)

HIDE(
/// [powerset]
struct a; struct b; struct c; struct d;

IS_SAME(
    metal::powerset<metal::list<a, b, c, d>>,
    metal::list<
        metal::list<>, metal::list<a>, metal::list<b>, metal::list<a, b>,
        metal::list<c>, metal::list<a, c>, metal::list<b, c>, metal::list<a, b, c>,
        metal::list<d>, metal::list<a, d>, metal::list<b, d>, metal::list<a, b, d>,
        metal::list<c, d>, metal::list<a, c, d>, metal::list<b, c, d>,
        metal::list<a, b, c, d>
    >
);
/// [powerset]
)

#if !defined(METAL_WORKAROUND)

HIDE(
/// [transform]
using a = metal::list<void(),    int,   bool, void*>;
using b = metal::list<void(*)(), int& , char, char*>;
using c = metal::list<void(&)(), int&&, long, long*>;

IS_SAME(
    metal::transform<metal::lazy<std::common_type>, a, b, c>,
    metal::list<void(*)(), int, long, void*>
);
/// [transform]
)

#endif

HIDE(
/// [transpose]
using l = metal::list<
    metal::list<int, int&, int*, int[]>,
    metal::list<char, char&, char*, char[]>,
    metal::list<float, float&, float*, float[]>
>;

IS_SAME(
    metal::transpose<l>,
    metal::list<
        metal::list<int, char, float>,
        metal::list<int&, char&, float&>,
        metal::list<int*, char*, float*>,
        metal::list<int[], char[], float[]>
    >
);
/// [transpose]
)

#if !defined(METAL_WORKAROUND)
HIDE(
/// [accumulate]
template<typename val, typename num>
using add_extent = val[num::value];

using ext = metal::numbers<3, 5, 2>;

IS_SAME(metal::accumulate<metal::lambda<add_extent>, char, ext>, char[2][5][3]);

using a = metal::list<int, int&, int*, int[]>;
using b = metal::list<char, char&, char*, char[]>;
using c = metal::list<float, float&, float*, float[]>;

IS_SAME(
    metal::accumulate<metal::lambda<metal::append>, metal::list<>, a, b, c>,
    metal::list<
        int, char, float,
        int&, char&, float&,
        int*, char*, float*,
        int[], char[], float[]
    >
);
/// [accumulate]
)
#endif
