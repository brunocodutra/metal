#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [val1]
using val = int;
/// [val1]

IS_SAME(metal::is_value<val>, metal::true_);
)

HIDE(
/// [val2]
using val = decltype(3.14);
/// [val2]

IS_SAME(metal::is_value<val>, metal::true_);
)

HIDE(
/// [val3]
struct val { /*...*/ };
/// [val3]

IS_SAME(metal::is_value<val>, metal::true_);
)

HIDE(
/// [not_a_val1]
int not_a_val;
/// [not_a_val1]
)

#if !defined(METAL_WORKAROUND)

HIDE(
static constexpr
/// [not_a_val2]
auto not_a_val = 3.14;
/// [not_a_val2]
)

#endif

HIDE(
/// [not_a_val3]
template<class...>
struct not_a_val { /*...*/ };
/// [not_a_val3]
)

HIDE(
/// [value]
using num = metal::number<42>;
IS_SAME(metal::is_number<metal::value<num>>, metal::false_);
IS_SAME(metal::value<num>::type, num);

using lbd = metal::lambda<metal::identity>;
IS_SAME(metal::is_lambda<metal::value<lbd>>, metal::false_);
IS_SAME(metal::value<lbd>::type, lbd);

using list = metal::list<>;
IS_SAME(metal::is_list<metal::value<list>>, metal::false_);
IS_SAME(metal::value<list>::type, list);
/// [value]
)

HIDE(
/// [is_value]
template<class T, class = metal::true_>
struct has_type_impl :
    metal::false_
{};

template<class T>
struct has_type_impl<T, metal::is_value<typename T::type>> :
    metal::true_
{};

template<class T>
using has_type = typename has_type_impl<T>::type;


IS_SAME(has_type<metal::value<void>>, metal::true_);
IS_SAME(has_type<metal::value<>>, metal::false_);
/// [is_value]
)

HIDE(
/// [eval]
IS_SAME(metal::eval<metal::value<void>>, void);
IS_SAME(metal::eval<std::add_pointer<void>>, void*);
/// [eval]
)

HIDE(
/// [identity]
IS_SAME(metal::identity<void>, void);
IS_SAME(metal::invoke<metal::lambda<metal::identity>, void>, void);

template<class pred, class lbd, class seq>
using transform_if = metal::transform<
    metal::bind<metal::lambda<metal::if_>, pred, lbd, metal::lambda<metal::identity>>,
    seq
>;

using l = metal::list<short, int, long, float, double, void>;

IS_SAME(
    transform_if<metal::trait<std::is_integral>, metal::lazy<std::add_pointer>, l>,
    metal::list<short*, int*, long*, float, double, void>
);
/// [identity]
)

HIDE(
/// [same]
IS_SAME(metal::same<>, metal::true_);
IS_SAME(metal::same<void>, metal::true_);
IS_SAME(metal::same<void, void, void, void, void>, metal::true_);
IS_SAME(metal::same<void, void*, void, void, void>, metal::false_);
IS_SAME(metal::same<void, void*, void**, void***, void****>, metal::false_);
/// [same]
)

HIDE(
/// [distinct]
IS_SAME(metal::distinct<>, metal::true_);
IS_SAME(metal::distinct<void>, metal::true_);
IS_SAME(metal::distinct<void, void, void, void, void>, metal::false_);
IS_SAME(metal::distinct<void, void*, void, void, void>, metal::false_);
IS_SAME(metal::distinct<void, void*, void**, void***, void****>, metal::true_);
/// [distinct]
)

#if !defined(METAL_WORKAROUND)
HIDE(
/// [fold_left]
template<class x, class y>
struct f {};

using lbd = metal::lambda<f>;

IS_SAME(
    metal::fold_left<lbd, short, int, long, float, double, void>,
    f<f<f<f<f<short, int>, long>, float>, double>, void>
);
/// [fold_left]
)

HIDE(
/// [fold_right]
template<class x, class y>
struct f {};

using lbd = metal::lambda<f>;

IS_SAME(
    metal::fold_right<lbd, short, int, long, float, double, void>,
    f<short, f<int, f<long, f<float, f<double, void>>>>>
);
/// [fold_right]
)
#endif
