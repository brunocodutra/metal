// The MIT License (MIT)
// 
// Copyright (c) 2018 Bruno Dutra
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef METAL_HPP
#define METAL_HPP
#ifndef METAL_CONFIG_HPP
#define METAL_CONFIG_HPP
#ifndef METAL_CONFIG_CONFIG_HPP
#define METAL_CONFIG_CONFIG_HPP
#if !defined(METAL_WORKAROUND)
#if (defined(__GNUC__) && !defined(__clang__) && (__GNUC__ < 5)) || (defined(_MSC_VER) && !defined(__clang__))
#define METAL_WORKAROUND
#endif
#endif
#endif
#ifndef METAL_CONFIG_VERSION_HPP
#define METAL_CONFIG_VERSION_HPP
/// \ingroup config
///
/// ### Description
/// Expands to the major version of Metal.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_MAJOR 2
/// \ingroup config
///
/// ### Description
/// Expands to the minor version of Metal.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_MINOR 1
/// \ingroup config
///
/// ### Description
/// Expands to the patch version of Metal.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_PATCH 4
/// \ingroup config
/// \hideinitializer
///
/// ### Description
/// Given a `{major, minor, patch}` triple, expands to an implementation defined
/// integral constant that is guaranteed to be comparable according to
/// [Semantic Versioning](http://semver.org/) rules.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_SEMVER(MAJOR, MINOR, PATCH) (((MAJOR)*1000000) + ((MINOR)*10000) + (PATCH))
/// \ingroup config
/// Expands to the full version of Metal.
///
/// ### See Also
/// \see [Semantic Versioning](http://semver.org/)
#define METAL_VERSION METAL_SEMVER(METAL_MAJOR, METAL_MINOR, METAL_PATCH)
#endif
/// \defgroup config Config
/// \ingroup metal
#endif
#ifndef METAL_LAMBDA_HPP
#define METAL_LAMBDA_HPP
#ifndef METAL_LAMBDA_ALWAYS_HPP
#define METAL_LAMBDA_ALWAYS_HPP
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _always;
}
/// \endcond
/// \ingroup lambda
///
/// ### Description
/// Lifts a \value to an n-ary \lambda that always evaluates to that \value,
/// regardless of the argument(s) it's [invoked](\ref invoke) with.
///
/// ### Usage
/// For any and \value `val`
/// \code
///     using result = metal::always<val>;
/// \endcode
///
/// \returns: \lambda
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::lambda<expr>;
///     \endcode
///     where `expr` is an \expression such that
///     \code
///         template<class...>
///         using expr = val;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp always
///
/// ### See Also
/// \see lambda, invoke, partial, bind
template <class val>
using always = typename detail::_always<val>::type;
}
#ifndef METAL_LAMBDA_LAMBDA_HPP
#define METAL_LAMBDA_LAMBDA_HPP
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_lambda;
    template <class val>
    struct _as_lambda;
}
/// \endcond
/// \ingroup lambda
///
/// ### Description
/// Checks whether some \value is a \lambda.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::is_lambda<val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `val` is a \lambda, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp is_lambda
///
/// ### See Also
/// \see lambda, is_value, is_number, is_pair, is_list, is_map
template <class val>
using is_lambda = typename detail::_is_lambda<val>::type;
/// \ingroup lambda
///
/// ### Description
/// Given any \value that is a specialization of a template class or union
/// whose template parameters are all themselves \values, constructs a
/// \lambda that contains that template.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::as_lambda<val>;
/// \endcode
///
/// \returns: \lambda
///
/// ### Example
/// \snippet lambda.cpp as_lambda
///
/// ### See Also
/// \see lambda, as_list
template <class val>
using as_lambda = typename detail::_as_lambda<val>::type;
/// \ingroup lambda
///
/// ### Description
/// Constructs a \lambda out of an \expression.
///
/// ### Usage
/// For any \expression `expr`
/// \code
///     using result = metal::lambda<expr>;
/// \endcode
///
/// \returns: \lambda
///
/// ### See Also
/// \see is_lambda
template <template <class...> class expr>
#if defined(METAL_DOXYGENATING)
using lambda = struct {
};
#else
struct lambda {
};
#endif
}
#ifndef METAL_NUMBER_NUMBER_HPP
#define METAL_NUMBER_NUMBER_HPP
#include <cstdint>
#include <type_traits>
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_number;
    template <class val>
    struct _as_number;
    using int_ = std::intmax_t;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Checks whether some \value is a \number.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::is_number<val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `val` is a \number, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet number.cpp is_number
///
/// ### See Also
/// \see number, is_value, is_lambda, is_pair, is_list, is_map
template <class val>
using is_number = typename detail::_is_number<val>::type;
/// \ingroup number
///
/// ### Description
/// The underlying integral representation of \numbers.
///
/// ### See Also
/// \see number
using int_ = detail::int_;
/// \ingroup number
///
/// ### Description
/// Constructs a \number out of an integral value.
///
/// ### Usage
/// For any integral constant `N`
/// \code
///     using result = metal::number<N>;
/// \endcode
///
/// \returns: \number
///
/// ### See Also
/// \see int_, true_, false_, is_number
template <int_ v>
using number = std::integral_constant<metal::int_, v>;
/// \ingroup number
///
/// ### Description
/// A \number that represents the boolean constant `true`.
///
/// ### See Also
/// \see number, int_
using true_ = metal::number<true>;
/// \ingroup number
///
/// ### Description
/// A \number that represents the boolean constant `false`.
///
/// ### See Also
/// \see number
using false_ = metal::number<false>;
/// \ingroup number
///
/// ### Description
/// Constructs a \number out of any \value that defines a nested integral
/// constant `value` convertible to metal::int_.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::as_number<val>;
/// \endcode
///
/// \returns: \number
///
/// ### Example
/// \snippet number.cpp as_number
///
/// ### See Also
/// \see number
template <class val>
using as_number = typename detail::_as_number<val>::type;
/// \cond
namespace detail {
    template <class val>
    struct _is_number : false_ {
    };
    template <int_ value>
    struct _is_number<number<value>> : true_ {
    };
    template <class val, class = std::true_type>
    struct has_enum_value : std::false_type {
    };
    template <class val>
    struct has_enum_value<val, typename std::is_enum<decltype(val::value)>::type>
        : std::true_type {
    };
    template <class val>
    struct is_pointer_to_const_integral : std::false_type {
    };
    template <class val>
    struct is_pointer_to_const_integral<val const*>
        : std::is_integral<val> {
    };
    template <class val, class = std::true_type>
    struct has_integral_value_impl : has_enum_value<val> {
    };
    template <class val>
    struct has_integral_value_impl<val,
        typename is_pointer_to_const_integral<decltype(&val::value)>::type>
        : std::true_type {
    };
    template <class val>
    struct has_integral_value_impl<
        val, typename std::is_member_pointer<decltype(&val::value)>::type>
        : std::false_type {
    };
    template <class val, class = std::true_type>
    struct has_integral_value : has_integral_value_impl<val> {
    };
    template <class val>
    struct has_integral_value<val, typename std::is_enum<val>::type>
        : has_enum_value<val> {
    };
    template <class val, class = std::true_type>
    struct _as_number_impl {
    };
    template <class val>
    struct _as_number_impl<val, typename has_integral_value<val>::type> {
        using type = number<val::value>;
    };
    template <class val>
    struct _as_number : _as_number_impl<val> {
    };
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_lambda : false_ {
    };
    template <template <class...> class expr>
    struct _is_lambda<lambda<expr>> : true_ {
    };
    template <class val>
    struct _as_lambda {
    };
    template <template <class...> class expr, class... vals>
    struct _as_lambda<expr<vals...>> {
        using type = lambda<expr>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_VALUE_IDENTITY_HPP
#define METAL_VALUE_IDENTITY_HPP
#ifndef METAL_VALUE_EVAL_HPP
#define METAL_VALUE_EVAL_HPP
namespace metal {
/// \ingroup value
///
/// ### Description
/// Evaluates _lazy_ constructs by retrieving their nested typename `type`.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::eval<val>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     Equivalent to
///     \code
///         using result = typename val::type;
///     \endcode
///
/// ### Example
/// \snippet value.cpp eval
///
/// ### See Also
/// \see value, lazy, id
template <class val>
using eval = typename val::type;
}
#endif
#ifndef METAL_VALUE_VALUE_HPP
#define METAL_VALUE_VALUE_HPP
namespace metal {
/// \cond
namespace detail {
    struct na;
    template <class val>
    struct maybe;
#if defined(METAL_WORKAROUND)
    template <class val>
    struct _is_value;
#endif
}
/// \endcond
/// \ingroup value
///
/// ### Description
/// A tautological predicate that checks whether some type is a \value.
///
/// \tip{Use `metal::is_value` to trigger \SFINAE.}
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::is_value<val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::true_;
///     \endcode
///
/// ### Example
/// \snippet value.cpp is_value
///
/// ### See Also
/// \see value, nil, is_number, is_lambda, is_pair, is_list, is_map
template <class val>
using is_value =
#if defined(METAL_WORKAROUND)
    typename detail::_is_value<val>::type;
#else
    metal::true_;
#endif
/// \ingroup value
///
/// ### Description
/// Constructs a \value that is guaranteed not to be a \number, or a
/// \lambda or a \list, out of any other \value.
///
/// The original \value may be retrieved back by naming the nested typename
/// `type`, unless `metal::value` is [empty](\ref nil), in which case `type`
/// is undefined.
///
/// \tip{Use `metal::value` to prevent undesired template pattern matching.}
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::value<val>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     Equivalent to
///     \code
///         using result = { using type = val; };
///     \endcode
///
/// ### Example
/// \snippet value.cpp value
///
/// ### See Also
/// \see is_value, nil
template <class val = detail::na>
#if defined(METAL_DOXYGENATING)
using value = struct {
    using type = val;
};
#else
using value = detail::maybe<val>;
#endif
/// \ingroup value
///
/// ### Description
/// An *empty* `metal::value`.
///
/// ### Usage
///
/// \code
///     using result = metal::nil;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     Equivalent to
///     \code
///         using result = {};
///     \endcode
///
/// ### See Also
/// \see is_value, value
using nil = metal::value<>;
/// \cond
namespace detail {
    template <class val>
    struct maybe {
        using type = val;
    };
    template <>
    struct maybe<detail::na> {
    };
#if defined(METAL_WORKAROUND)
    template <class val>
    struct _is_value {
        using type = true_;
    };
#endif
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup value
///
/// ### Description
/// The identity \expression.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::identity<val>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     Equivalent to
///     \code
///         using result = val;
///     \endcode
///
/// ### Example
/// \snippet value.cpp identity
///
/// ### See Also
/// \see value, eval
template <class val>
using identity =
#if defined(METAL_WORKAROUND)
    eval<value<val>>;
#else
    val;
#endif
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _always {
        template <class...>
        using impl = identity<val>;
        using type = lambda<impl>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP
namespace metal {
/// \cond
namespace detail {
    template <class lbd, class seq>
    struct _apply;
}
/// \endcond
/// \ingroup lambda
///
/// ### Description
/// [Invokes](\ref invoke) a \lambda with the \values contained in a \list.
///
/// ### Usage
/// For any \lambda `lbd` and \list `l`
/// \code
///     using result = metal::apply<lbd, l>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::invoke<lbd, l[0], ..., l[m-1]>;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp apply
///
/// ### See Also
/// \see lambda, invoke, list
template <class lbd, class seq>
using apply = typename detail::_apply<lbd, seq>::type;
}
#ifndef METAL_DETAIL_SFINAE_HPP
#define METAL_DETAIL_SFINAE_HPP
#ifndef METAL_DETAIL_DECLPTR_HPP
#define METAL_DETAIL_DECLPTR_HPP
namespace metal {
/// \cond
namespace detail {
    template <class T>
    T* declptr();
}
/// \endcond
}
#endif
#include <type_traits>
namespace metal {
/// \cond
namespace detail {
    template <template <template <class...> class...> class, template <class...> class...>
    struct forwarder;
    template <template <template <class...> class...> class tmpl, template <class...> class... exprs,
        eval<std::enable_if<is_value<tmpl<exprs...>>::value>>* = nullptr>
    value<tmpl<exprs...>> sfinae(forwarder<tmpl, exprs...>*);
    template <template <class...> class expr, class... vals>
    struct caller;
    template <template <class...> class expr, class... vals,
        eval<std::enable_if<is_value<expr<vals...>>::value>>* = nullptr>
    value<expr<vals...>> sfinae(caller<expr, vals...>*);
    value<> sfinae(...);
    template <template <template <class...> class...> class tmpl, template <class...> class... exprs>
    struct forwarder
        : decltype(sfinae(declptr<forwarder<tmpl, exprs...>>())) {
    };
    template <template <class...> class expr, class... vals>
    struct caller : decltype(sfinae(declptr<caller<expr, vals...>>())) {
    };
#if defined(METAL_WORKAROUND)
    template <
        template <template <class...> class...> class tmpl,
        template <class...> class... exprs>
    using forward = typename forwarder<tmpl, exprs...>::type;
    template <template <class...> class expr, class... vals>
    using call = typename caller<expr, vals...>::type;
#else
    template <template <template <class...> class...> class tmpl, template <class...> class... exprs>
    using forward = tmpl<exprs...>;
    template <template <class...> class expr, class... vals>
    using call = expr<vals...>;
#endif
}
/// \endcond
}
#endif
#ifndef METAL_LIST_LIST_HPP
#define METAL_LIST_LIST_HPP
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_list;
    template <class val>
    struct _as_list;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Checks whether some \value is a \list.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::is_list<val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `val` is a \list, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet list.cpp is_list
///
/// ### See Also
/// \see list, is_value, is_number, is_lambda, is_pair, is_map
template <class val>
using is_list = typename detail::_is_list<val>::type;
/// \ingroup list
///
/// ### Description
/// Given any \value that is a specialization of a template class or union
/// whose template parameters are all themselves \values, constructs a \list
/// that contains all those \values.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::as_list<val>;
/// \endcode
///
/// \returns: \list
///
/// ### Example
/// \snippet list.cpp as_list
///
/// ### See Also
/// \see list, as_lambda
template <class val>
using as_list = typename detail::_as_list<val>::type;
/// \ingroup list
///
/// ### Description
/// Constructs a \list out of a sequence of \values.
///
/// ### Usage
/// For any \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::list<val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \list
///
/// ### See Also
/// \see is_list
template <class... vals>
#if defined(METAL_DOXYGENATING)
using list = struct {
};
#else
struct list {
};
#endif
}
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_list : false_ {
    };
    template <class... vals>
    struct _is_list<list<vals...>> : true_ {
    };
    template <class val>
    struct _as_list {
    };
    template <template <class...> class seq, class... vals>
    struct _as_list<seq<vals...>> {
        using type = list<vals...>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class lbd, class seq, class = true_>
    struct _apply_impl {
    };
    template <template <class...> class expr, class... vals>
    struct _apply_impl<lambda<expr>, list<vals...>, is_value<call<expr, vals...>>> {
        using type = expr<vals...>;
    };
    template <class lbd, class seq>
    struct _apply : _apply_impl<lbd, seq> {
    };
}
/// \endcond
}
#endif
#ifndef METAL_LAMBDA_ARG_HPP
#define METAL_LAMBDA_ARG_HPP
#include <cstddef>
namespace metal {
/// \cond
namespace detail {
    template <std::size_t n>
    struct _arg;
}
/// \endcond
/// \ingroup lambda
///
/// ### Description
/// A parametric \lambda that selects the n-th argument it is invoked with.
///
/// ### Usage
/// For any nonzero positive integral value `n`
/// \code
///     using result = metal::arg<n>;
/// \endcode
///
/// \returns: \lambda
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::lambda<expr>;
///     \endcode
///     where `expr` is an \expression such that
///     `expr<val_0, ..., val_n-1, ..., val_m-1>` yields `val_n-1`.
///
/// ### Example
/// \snippet lambda.cpp arg
///
/// ### See Also
/// \see lambda, invoke, bind, always
template <std::size_t n>
using arg = typename detail::_arg<n>::type;
}
#ifndef METAL_LIST_AT_HPP
#define METAL_LIST_AT_HPP
namespace metal {
/// \cond
namespace detail {
    template <class seq>
    struct _at;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Retrieves an element of a \list at an arbitrary position.
///
/// ### Usage
/// For any \list `l` and \number `num`
/// \code
///     using result = metal::at<l, num>;
/// \endcode
///
/// \pre: `metal::number<0>{} &le; num{} < metal::size<l>{}`
/// \returns: \value
/// \semantics:
///     If `l` contains elements `l[0], ..., l[i], ..., l[m-1]` and
///     `num{} == i`, then
///     \code
///         using result = l[i];
///     \endcode
///
/// ### Example
/// \snippet list.cpp at
///
/// ### See Also
/// \see list, front, back
template <class seq, class num>
using at = detail::call<detail::_at<seq>::template type, num>;
}
#if defined(__has_builtin)
#if __has_builtin(__type_pack_element)
#define METAL_USE_BUILTIN_TYPE_PACK_ELEMENT
#endif
#endif
namespace metal {
/// \cond
namespace detail {
    template <class... vals>
    struct prepender {
        template <class... _>
        using prepend = prepender<_..., vals...>;
        using type = list<vals...>;
    };
    template <std::size_t n>
    struct grouper
        /* clang-format off */
        : grouper<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {
        /* clang-format on */
    };
    template <>
    struct grouper<100> {
        template <
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class _10, class _11, class _12, class _13, class _14,
            class _15, class _16, class _17, class _18, class _19,
            class _20, class _21, class _22, class _23, class _24,
            class _25, class _26, class _27, class _28, class _29,
            class _30, class _31, class _32, class _33, class _34,
            class _35, class _36, class _37, class _38, class _39,
            class _40, class _41, class _42, class _43, class _44,
            class _45, class _46, class _47, class _48, class _49,
            class _50, class _51, class _52, class _53, class _54,
            class _55, class _56, class _57, class _58, class _59,
            class _60, class _61, class _62, class _63, class _64,
            class _65, class _66, class _67, class _68, class _69,
            class _70, class _71, class _72, class _73, class _74,
            class _75, class _76, class _77, class _78, class _79,
            class _80, class _81, class _82, class _83, class _84,
            class _85, class _86, class _87, class _88, class _89,
            class _90, class _91, class _92, class _93, class _94,
            class _95, class _96, class _97, class _98, class _99,
            class... tail>
        using type = typename grouper<sizeof...(tail)>::
            template type<tail...>::
                template prepend<
                    _at<list<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09>>,
                    _at<list<_10, _11, _12, _13, _14, _15, _16, _17, _18, _19>>,
                    _at<list<_20, _21, _22, _23, _24, _25, _26, _27, _28, _29>>,
                    _at<list<_30, _31, _32, _33, _34, _35, _36, _37, _38, _39>>,
                    _at<list<_40, _41, _42, _43, _44, _45, _46, _47, _48, _49>>,
                    _at<list<_50, _51, _52, _53, _54, _55, _56, _57, _58, _59>>,
                    _at<list<_60, _61, _62, _63, _64, _65, _66, _67, _68, _69>>,
                    _at<list<_70, _71, _72, _73, _74, _75, _76, _77, _78, _79>>,
                    _at<list<_80, _81, _82, _83, _84, _85, _86, _87, _88, _89>>,
                    _at<list<_90, _91, _92, _93, _94, _95, _96, _97, _98, _99>>>;
    };
    template <>
    struct grouper<10> {
        template <
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class... tail>
        using type = typename grouper<sizeof...(tail)>::
            template type<tail...>::
                template prepend<_at<list<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09>>>;
    };
    template <>
    struct grouper<1> {
        template <class... vals>
        using type = prepender<_at<list<vals...>>>;
    };
    template <>
    struct grouper<0> {
        template <class...>
        using type = prepender<>;
    };
    template <class... vals>
    using group = typename grouper<sizeof...(vals)>::template type<vals...>::type;
    template <class groups, class m, class n>
    using select = typename _at<groups>::template type<m>::template type<n>;
    template <class num, class = true_>
    struct _at_impl {
    };
    template <int_ n>
    struct _at_impl<number<n>, number<(n > 9)>> {
        template <class... vals>
        using type = select<call<group, vals...>, number<n / 10>, number<n % 10>>;
    };
    template <>
    struct _at_impl<number<9>> {
        template <class, class, class, class, class, class, class, class, class, class val, class...>
        using type = val;
    };
    template <>
    struct _at_impl<number<8>> {
        template <class, class, class, class, class, class, class, class, class val, class...>
        using type = val;
    };
    template <>
    struct _at_impl<number<7>> {
        template <class, class, class, class, class, class, class, class val, class...>
        using type = val;
    };
    template <>
    struct _at_impl<number<6>> {
        template <class, class, class, class, class, class, class val, class...>
        using type = val;
    };
    template <>
    struct _at_impl<number<5>> {
        template <class, class, class, class, class, class val, class...>
        using type = val;
    };
    template <>
    struct _at_impl<number<4>> {
        template <class, class, class, class, class val, class...>
        using type = val;
    };
    template <>
    struct _at_impl<number<3>> {
        template <class, class, class, class val, class...>
        using type = val;
    };
    template <>
    struct _at_impl<number<2>> {
        template <class, class, class val, class...>
        using type = val;
    };
    template <>
    struct _at_impl<number<1>> {
        template <class, class val, class...>
        using type = val;
    };
    template <>
    struct _at_impl<number<0>> {
        template <class val, class...>
        using type = val;
    };
    template <class seq>
    struct _at {
    };
    template <class... vals>
    struct _at<list<vals...>> {
#if defined(METAL_USE_BUILTIN_TYPE_PACK_ELEMENT)
        template <class, class = true_>
        struct impl {
        };
        template <int_ n>
        struct impl<number<n>, number<(n >= 0 && n < sizeof...(vals))>> {
            using type = __type_pack_element<n, vals...>;
        };
        template <class... num>
        using type = typename impl<num...>::type;
#else
        template <class... num>
        using type = call<_at_impl<num...>::template type, vals...>;
#endif
    };
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <std::size_t n>
    struct _arg {
        template <class... vals>
        using impl = at<list<vals...>, number<n - 1>>;
        using type = lambda<impl>;
    };
    template <>
    struct _arg<0U> {
    };
}
/// \endcond
/// \ingroup lambda
///
/// ### Description
/// Predefined placeholder.
/// \{
using _1 = metal::arg<1U>;
using _2 = metal::arg<2U>;
using _3 = metal::arg<3U>;
using _4 = metal::arg<4U>;
using _5 = metal::arg<5U>;
using _6 = metal::arg<6U>;
using _7 = metal::arg<7U>;
using _8 = metal::arg<8U>;
using _9 = metal::arg<9U>;
/// \}
}
#endif
#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP
namespace metal {
/// \cond
namespace detail {
    template <class lbd, class... vals>
    struct _bind;
}
/// \endcond
/// \ingroup lambda
///
/// ### Description
/// Provides higher-order composition of \lambdas.
///
/// \tip{Use metal::arg<n> as a placeholder for the n-th argument.}
///
/// ### Usage
/// For any \lambdas `lbd` and `lbd_0, ..., lbd_n-1`
/// \code
///     using result = metal::bind<lbd, lbd_0, ..., lbd_n-1>;
/// \endcode
///
/// \returns: \lambda
/// \semantics:
///     If `lbd` holds \expression `f` and, likewise, `lbd_0, ..., lbd_n-1`
///     hold \expressions `f_0, ..., f_n-1`, then
///     \code
///         using result = metal::lambda<g>;
///     \endcode
///     where `g` is an \expression such that
///     \code
///         template<class... args>
///         using g = f<f_0<args...>, ...<args...>, f_n-1<args...>>;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp bind
///
/// ### See Also
/// \see lambda, invoke, arg, always
template <class lbd, class... vals>
using bind = typename detail::_bind<lbd, vals...>::type;
}
namespace metal {
/// \cond
namespace detail {
    template <class... vals>
    struct _bind_impl {
        template <template <class...> class expr, template <class...> class... params>
        using type =
#if defined(METAL_WORKAROUND)
            call<expr, call<params, vals...>...>;
#else
            expr<params<vals...>...>;
#endif
    };
    template <class lbd, class... vals>
    struct _bind {
    };
    template <template <class...> class expr, template <class...> class... params>
    struct _bind<lambda<expr>, lambda<params>...> {
        template <class... vals>
        using impl = forward<_bind_impl<vals...>::template type, expr, params...>;
        using type = lambda<impl>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP
namespace metal {
/// \ingroup lambda
///
/// ### Description
/// Invokes a \lambda with the given \values as arguments.
///
/// ### Usage
/// For any \lambda `lbd` and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::invoke<lbd, val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `lbd` holds \expression `expr`, then
///     \code
///         using result = expr<val_0, ..., val_n-1>;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp invoke
///
/// ### See Also
/// \see lambda, is_invocable
template <class lbd, class... vals>
using invoke = metal::apply<lbd, metal::list<vals...>>;
}
#endif
#ifndef METAL_LAMBDA_IS_INVOCABLE_HPP
#define METAL_LAMBDA_IS_INVOCABLE_HPP
#ifndef METAL_VALUE_SAME_HPP
#define METAL_VALUE_SAME_HPP
namespace metal {
/// \cond
namespace detail {
    template <class... vals>
    struct _same;
}
/// \endcond
/// \ingroup value
///
/// ### Description
/// Checks whether all \values are identical.
///
/// ### Usage
/// For any \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::same<val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If at least two \values in `val_0, ..., val_n-1` are not identical
///     to each other, then
///     \code
///         using result = metal::false_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::true_;
///     \endcode
///
/// ### Example
/// \snippet value.cpp same
///
/// ### See Also
/// \see distinct
template <class... vals>
using same = typename detail::_same<vals...>::type;
}
namespace metal {
/// \cond
namespace detail {
    template <class...>
    struct _same_impl : false_ {
    };
    template <template <class> class... _, class val>
    struct _same_impl<_<val>...> : true_ {
    };
    template <class... vals>
    struct _same : _same_impl<maybe<vals>...> {
    };
    template <class x, class y>
    struct _same<x, y> : false_ {
    };
    template <class x>
    struct _same<x, x> : true_ {
    };
    template <class x>
    struct _same<x> : true_ {
    };
    template <>
    struct _same<> : true_ {
    };
}
/// \endcond
}
#endif
#include <type_traits>
namespace metal {
/// \ingroup lambda
///
/// ### Description
/// Checks whether a \lambda is [invocable](\ref invoke) with some \values.
///
/// ### Usage
/// For any \lambda `lbd` and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::is_invocable<lbd, val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `lbd` holds \expression `expr`, and `expr<val_0, ..., val_n-1>`
///     is well defined after template substitution, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp is_invocable
///
/// ### See Also
/// \see lambda, invoke
template <class lbd, class... vals>
using is_invocable = same<std::false_type, typename std::is_base_of<value<>, detail::caller<invoke, lbd, vals...>>::type>;
}
#endif
#ifndef METAL_LAMBDA_LAZY_HPP
#define METAL_LAMBDA_LAZY_HPP
namespace metal {
/// \ingroup lambda
///
/// ### Description
/// Constructs a \lambda out of a _lazy expression_, that is, an
/// \expression whose return \value is defined as a nested typename `type`.
///
/// ### Usage
/// For any \expression `expr`
/// \code
///     using result = metal::lazy<expr>;
/// \endcode
///
/// \returns: \lambda
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::lambda<eager>;
///     \endcode
///     where `eager` is an \expression such that
///     \code
///         template<class... args>
///         using eager = typename expr<args...>::type;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp lazy
///
/// ### See Also
/// \see lambda, eval
template <template <class...> class expr>
using lazy = metal::bind<metal::lambda<metal::eval>, metal::lambda<expr>>;
}
#endif
#ifndef METAL_LAMBDA_PARTIAL_HPP
#define METAL_LAMBDA_PARTIAL_HPP
namespace metal {
/// \cond
namespace detail {
    template <class lbd, class... vals>
    struct _partial;
}
/// \endcond
/// \ingroup lambda
///
/// ### Description
/// Partially [invokes](\ref invoke) a \lambda with some \values.
///
/// ### Usage
/// For any \lambda `lbd` and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::partial<lbd, val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \lambda
/// \semantics:
///     If `lbd` holds \expression `f`, then
///     \code
///         using result = metal::lambda<g>;
///     \endcode
///     where `g` is an \expression such that
///     \code
///         template<class... args>
///         using g = f<val_0, ..., val_n-1, args...>;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp partial
///
/// ### See Also
/// \see lambda, invoke, bind, always
template <class lbd, class... vals>
using partial = typename detail::_partial<lbd, vals...>::type;
}
namespace metal {
/// \cond
namespace detail {
    template <class lbd, class... leading>
    struct _partial {
    };
    template <template <class...> class expr, class... leading>
    struct _partial<lambda<expr>, leading...> {
        template <class... trailing>
        using impl = invoke<lambda<expr>, leading..., trailing...>;
        using type = lambda<impl>;
    };
    template <class x>
    struct _partial<lambda<same>, x> {
        template <class y>
        using impl = same<x, y>;
        using type = lambda<impl>;
    };
    template <template <class...> class expr>
    struct _partial<lambda<expr>> {
        using type = lambda<expr>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_LAMBDA_TRAIT_HPP
#define METAL_LAMBDA_TRAIT_HPP
namespace metal {
/// \ingroup lambda
///
/// ### Description
/// Constructs a _predicate_ out of a _trait_, that is a \lambda that
/// evaluates to a \number, out of an \expression that defines a nested
/// integral constant `value` convertible to metal::int_.
///
/// ### Usage
/// For any \expression `expr`
/// \code
///     using result = metal::trait<expr>;
/// \endcode
///
/// \returns: \lambda
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::lambda<pred>;
///     \endcode
///     where `pred` is an \expression such that
///     \code
///         template<class... args>
///         using pred = metal::number<expr<args...>::value>;
///     \endcode
///
/// ### Example
/// \snippet lambda.cpp trait
///
/// ### See Also
/// \see lambda, number
template <template <class...> class expr>
using trait = metal::bind<metal::lambda<metal::as_number>, metal::lambda<expr>>;
}
#endif
/// \defgroup lambda Lambda
/// \ingroup metal
#endif
#ifndef METAL_LIST_HPP
#define METAL_LIST_HPP
#ifndef METAL_LIST_ACCUMULATE_HPP
#define METAL_LIST_ACCUMULATE_HPP
#ifndef METAL_LIST_SIZE_HPP
#define METAL_LIST_SIZE_HPP
namespace metal {
/// \cond
namespace detail {
    template <class seq>
    struct _size;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Returns the number of elements in a \list.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::size<l>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::number<m>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp size
///
/// ### See Also
/// \see list, empty
template <class seq>
using size = typename detail::_size<seq>::type;
}
namespace metal {
/// \cond
namespace detail {
    template <class seq>
    struct _size {
    };
    template <class... vals>
    struct _size<list<vals...>> : number<sizeof...(vals)> {
    };
}
/// \endcond
}
#endif
#ifndef METAL_NUMBER_IF_HPP
#define METAL_NUMBER_IF_HPP
namespace metal {
/// \cond
namespace detail {
    template <class cond>
    struct _if_;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// A conditional expression.
///
/// ### Usage
/// For any \number `num` and \values `x, y`
/// \code
///     using result = metal::if<num, x, y>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `num{} != false`, then
///     \code
///         using result = x;
///     \endcode
///     otherwise
///     \code
///         using result = y;
///     \endcode
///
/// \tip{If `num{} != false`, `y` may be omitted.}
///
/// ### Example
/// \snippet number.cpp if_
///
/// ### See Also
/// \see number
template <class cond, class... then>
using if_ = detail::call<detail::_if_<cond>::template type, then...>;
}
namespace metal {
/// \cond
namespace detail {
    template <class>
    struct _if_ {
    };
    template <int_ v>
    struct _if_<number<v>> {
        template <class val, class = void>
        using type = val;
    };
    template <>
    struct _if_<false_> {
        template <class, class val>
        using type = val;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class lbd>
    struct _accumulate;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Computes the recursive invocation of a binary \lambda with the result of
/// the previous invocation and each element of one or more \lists traversed
/// in parallel from the beginning to the end.
///
/// ### Usage
/// For any \lambda `lbd`, \value `val` and \lists `l_0, ..., l_n-1`
/// \code
///     using result = metal::accumulate<lbd, val, l_0, ..., l_n-1>;
/// \endcode
///
/// \pre: `metal::size<l_0>{} == metal::size<>{}... == metal::size<l_n-1>{}`
/// \returns: \value
/// \semantics:
///     Equivalent to
///     \code
///         using result =
///             lbd(... lbd(lbd(val, l[0]...), l[1]...), ..., l[m-1]...)
///     \endcode
///     where `l[N]...` stands for `l_0[N], ...[N], l_n-1[N]` and
///     `lbd(x, y)` stands for `metal::invoke<lbd, x, y>`.
///
/// ### Example
/// \snippet list.cpp accumulate
///
/// ### See Also
/// \see list, transform, fold_left
template <class lbd, class state, class... seqs>
using accumulate = detail::call<
    if_<same<size<seqs>...>, detail::_accumulate<lbd>>::template type,
    state, seqs...>;
}
#ifndef METAL_LIST_TRANSPOSE_HPP
#define METAL_LIST_TRANSPOSE_HPP
#ifndef METAL_LIST_TRANSFORM_HPP
#define METAL_LIST_TRANSFORM_HPP
namespace metal {
/// \cond
namespace detail {
    template <class lbd>
    struct _transform;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Transforms one or more \lists into a new \list through an arbitrary
/// n-ary \lambda.
///
/// ### Usage
/// For any \lambda `lbd` and \lists `l_0, ..., l_n-1`
/// \code
///     using result = metal::transform<lbd, l_0, ..., l_n-1>;
/// \endcode
///
/// \pre: `metal::size<l_0>{} == metal::size<>{}... == metal::size<l_n-1>{}`
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<
///             metal::invoke<lbd, l[0]...>,
///             metal::invoke<lbd, l[1]...>,
///             ...,
///             metal::invoke<lbd, l[m-1]...>,
///         >;
///     \endcode
///     where `l[N]...` stands for `l_0[N], ...[N], l_n-1[N]`.
///
/// ### Example
/// \snippet list.cpp transform
///
/// ### See Also
/// \see list, accumulate
template <class lbd, class... seqs>
using transform = detail::call<if_<same<size<seqs>...>, detail::_transform<lbd>>::template type, seqs...>;
}
#ifndef METAL_LIST_INDICES_HPP
#define METAL_LIST_INDICES_HPP
#ifndef METAL_NUMBER_IOTA_HPP
#define METAL_NUMBER_IOTA_HPP
namespace metal {
/// \cond
namespace detail {
    template <class, class, class>
    struct _iota;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Generates a sequence of \numbers.
///
/// ### Usage
/// For any \numbers `st`, `sz` and `sd`
/// \code
///     using result = metal::iota<st, sz, sd>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `sz` is positive, then
///     \code
///         using result = metal::numbers<
///             st{}, st{} + sd{}, ..., st{} + (sz{} - 1)*sd{}
///         >;
///     \endcode
///     otherwise, if `sz` is negative, then
///     \code
///         using result = metal::numbers<
///             st{}, st{} - sd{}, ..., st{} - (1 - sz{})*sd{}
///         >;
///     \endcode
///     otherwise
///     \code
///         using result = metal::numbers<>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp iota
///
/// ### See Also
/// \see list, repeat, numbers
template <class start, class size, class stride = number<1>>
using iota = typename detail::_iota<start, size, stride>::type;
}
#ifndef METAL_NUMBER_NUMBERS_HPP
#define METAL_NUMBER_NUMBERS_HPP
#include <type_traits>
namespace metal {
/// \cond
namespace detail {
#if defined(METAL_WORKAROUND)
    template <int_... vs>
    struct _numbers;
#endif
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Constructs a \list of \numbers out of a sequence of integral values.
///
/// ### Example
/// \snippet number.cpp numbers
///
/// ### See Also
/// \see int_, number, list
template <int_... vs>
using numbers =
#if defined(METAL_WORKAROUND)
    typename detail::_numbers<vs...>::type;
#else
    metal::list<metal::number<vs>...>;
#endif
/// \cond
namespace detail {
#if defined(METAL_WORKAROUND)
    template <int_... vs>
    struct _numbers {
        using type = list<std::integral_constant<int_, vs>...>;
    };
#endif
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <int_... ns>
    struct enumeration {
    };
    template <class ns>
    struct _even {
    };
    template <int_... ns>
    struct _even<enumeration<ns...>> {
        using type = enumeration<ns..., (sizeof...(ns) + ns)...>;
    };
    template <class ns>
    struct _odd {
    };
    template <int_... ns>
    struct _odd<enumeration<ns...>> {
        using type = enumeration<ns..., (sizeof...(ns) + ns)..., 2 * sizeof...(ns)>;
    };
    template <int_ n>
    struct _enumerate;
    template <int_ n>
    using enumerate = typename _enumerate<n>::type;
    template <int_ n>
    struct _enumerate
        : if_<number<n % 2>, _odd<enumerate<n / 2>>, _even<enumerate<n / 2>>> {
    };
    template <>
    struct _enumerate<0> {
        using type = enumeration<>;
    };
    template <class, int_ a, int_ b>
    struct _iota_impl {
    };
    template <int_... vs, int_ a, int_ b>
    struct _iota_impl<enumeration<vs...>, a, b> {
        using type = numbers<(b + a * vs)...>;
    };
    template <class, class, class>
    struct _iota {
    };
    template <int_ st, int_ sz, int_ sd>
    struct _iota<number<st>, number<sz>, number<sd>>
        : _iota_impl<enumerate<(sz < 0) ? (0 - sz) : sz>, (sz < 0) ? (0 - sd) : sd, st> {
    };
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Replaces each element of a \list by its corresponding index.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::indices<l>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::list<
///             metal::number<0>, metal::number<>..., metal::number<m-1>
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp indices
///
/// ### See Also
/// \see list, iota
template <class seq>
using indices = metal::iota<metal::number<0>, metal::size<seq>>;
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class num, class... seqs>
    struct transformer_impl {
        template <template <class...> class expr>
        using type = expr<at<seqs, num>...>;
    };
    template <template <class...> class expr, class... seqs>
    struct transformer {
        template <class num>
        using type = forward<transformer_impl<num, seqs...>::template type, expr>;
    };
    template <class head, class... tail>
    struct _transform_impl {
        template <template <class...> class expr>
        using type = forward<
            _transform_impl<indices<head>>::template type,
            transformer<expr, head, tail...>::template type>;
    };
    template <class... xs, class... ys, class... zs>
    struct _transform_impl<list<xs...>, list<ys...>, list<zs...>> {
        template <template <class...> class expr>
        using type = list<expr<xs, ys, zs>...>;
    };
    template <class... xs, class... ys>
    struct _transform_impl<list<xs...>, list<ys...>> {
        template <template <class...> class expr>
        using type = list<expr<xs, ys>...>;
    };
    template <class... xs>
    struct _transform_impl<list<xs...>> {
        template <template <class...> class expr>
        using type = list<expr<xs>...>;
    };
    template <class lbd>
    struct _transform {
    };
    template <template <class...> class expr>
    struct _transform<lambda<expr>> {
        template <class... seqs>
        using type = forward<_transform_impl<seqs...>::template type, expr>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Transposes a \list of \lists.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::transpose<l>;
/// \endcode
///
/// \pre: If `l` contains elements `l[0], ..., l[m-1]`,
/// `metal::size<l[0]>{} == metal::size<>{}... == metal::size<l[n-1]>{}`
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<
///             metal::list<l[0][0], ...[0], l[m-1][0]>,
///             ...,
///             metal::list<l[0][n-1], ...[n-1], l[m-1][n-1]>
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp transpose
///
/// ### See Also
/// \see list, cartesian
template <class seq>
using transpose = metal::apply<
    metal::partial<metal::lambda<metal::transform>, metal::lambda<metal::list>>,
    seq>;
}
#endif
#ifndef METAL_VALUE_FOLD_LEFT_HPP
#define METAL_VALUE_FOLD_LEFT_HPP
namespace metal {
/// \cond
namespace detail {
    template <class lbd>
    struct _fold_left;
}
/// \endcond
/// \ingroup value
///
/// ### Description
/// Computes the recursive invocation of a binary \lambda with the result of
/// the previous invocation and each \value, from the first to the last.
///
/// ### Usage
/// For any \lambda `lbd`, and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::fold_left<lbd, val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     Equivalent to
///     \code
///         using result =
///             lbd(... lbd(lbd(val_0, val_1), val_2), ..., val_n-1)
///     \endcode
///     where `lbd(x, y)` stands for `metal::invoke<lbd, x, y>`.
///
/// ### Example
/// \snippet value.cpp fold_left
///
/// ### See Also
/// \see fold_right
template <class lbd, class... vals>
using fold_left = detail::call<detail::_fold_left<lbd>::template type, vals...>;
}
#include <cstddef>
namespace metal {
/// \cond
namespace detail {
    template <
        class state,
        class _00, class _01, class _02, class _03, class _04, class _05,
        class _06, class _07, class _08, class _09, class _10, class _11,
        class _12, class _13, class _14, class _15, class _16, class _17,
        class _18, class _19, class _20, class _21, class _22, class _23,
        class _24, class _25, class _26, class _27, class _28, class _29,
        class _30, class _31, class _32, class _33, class _34, class _35,
        class _36, class _37, class _38, class _39, class _40, class _41,
        class _42, class _43, class _44, class _45, class _46, class _47,
        class _48, class _49, class _50, class _51, class _52, class _53,
        class _54, class _55, class _56, class _57, class _58, class _59,
        class _60, class _61, class _62, class _63, class _64, class _65,
        class _66, class _67, class _68, class _69, class _70, class _71,
        class _72, class _73, class _74, class _75, class _76, class _77,
        class _78, class _79, class _80, class _81, class _82, class _83,
        class _84, class _85, class _86, class _87, class _88, class _89,
        class _90, class _91, class _92, class _93, class _94, class _95,
        class _96, class _97, class _98, class _99>
    struct left_folder_100 {
            template<template<class...> class expr>
            using type =
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                    forward<state::template type, expr>,
                _00>, _01>, _02>, _03>, _04>, _05>, _06>, _07>, _08>, _09>,
                _10>, _11>, _12>, _13>, _14>, _15>, _16>, _17>, _18>, _19>,
                _20>, _21>, _22>, _23>, _24>, _25>, _26>, _27>, _28>, _29>,
                _30>, _31>, _32>, _33>, _34>, _35>, _36>, _37>, _38>, _39>,
                _40>, _41>, _42>, _43>, _44>, _45>, _46>, _47>, _48>, _49>,
                _50>, _51>, _52>, _53>, _54>, _55>, _56>, _57>, _58>, _59>,
                _60>, _61>, _62>, _63>, _64>, _65>, _66>, _67>, _68>, _69>,
                _70>, _71>, _72>, _73>, _74>, _75>, _76>, _77>, _78>, _79>,
                _80>, _81>, _82>, _83>, _84>, _85>, _86>, _87>, _88>, _89>,
                _90>, _91>, _92>, _93>, _94>, _95>, _96>, _97>, _98>, _99>;
    };
    template <
        class state,
        class _00, class _01, class _02, class _03, class _04,
        class _05, class _06, class _07, class _08, class _09>
    struct left_folder_10 {
        template <template <class...> class expr>
        /* clang-format off */
            using type =
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                    forward<state::template type, expr>,
                _00>, _01>, _02>, _03>, _04>, _05>, _06>, _07>, _08>, _09>;
        /* clang-format on */
    };
    template <class state, class _00>
    struct left_folder_1 {
        template <template <class...> class expr>
        using type = expr<forward<state::template type, expr>, _00>;
    };
    template <class state>
    struct left_folder_0 {
        template <template <class...> class>
        using type = identity<state>;
    };
    template <std::size_t n>
    struct _fold_left_impl
        /* clang-format off */
        : _fold_left_impl<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {
        /* clang-format on */
    };
    template <>
    struct _fold_left_impl<100> {
        template <
            class state,
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class _10, class _11, class _12, class _13, class _14,
            class _15, class _16, class _17, class _18, class _19,
            class _20, class _21, class _22, class _23, class _24,
            class _25, class _26, class _27, class _28, class _29,
            class _30, class _31, class _32, class _33, class _34,
            class _35, class _36, class _37, class _38, class _39,
            class _40, class _41, class _42, class _43, class _44,
            class _45, class _46, class _47, class _48, class _49,
            class _50, class _51, class _52, class _53, class _54,
            class _55, class _56, class _57, class _58, class _59,
            class _60, class _61, class _62, class _63, class _64,
            class _65, class _66, class _67, class _68, class _69,
            class _70, class _71, class _72, class _73, class _74,
            class _75, class _76, class _77, class _78, class _79,
            class _80, class _81, class _82, class _83, class _84,
            class _85, class _86, class _87, class _88, class _89,
            class _90, class _91, class _92, class _93, class _94,
            class _95, class _96, class _97, class _98, class _99,
            class... tail>
        using type = typename _fold_left_impl<sizeof...(tail)>::
            template type<
                left_folder_100<
                    state,
                    _00, _01, _02, _03, _04, _05, _06, _07, _08, _09, _10,
                    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21,
                    _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32,
                    _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43,
                    _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54,
                    _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65,
                    _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76,
                    _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87,
                    _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98,
                    _99>,
                tail...>;
    };
    template <>
    struct _fold_left_impl<10> {
        template <
            class state,
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class... tail>
        using type = typename _fold_left_impl<sizeof...(tail)>::
            template type<left_folder_10<state, _00, _01, _02, _03, _04, _05, _06, _07, _08, _09>, tail...>;
    };
    template <>
    struct _fold_left_impl<1> {
        template <class state, class _00, class... tail>
        using type = typename _fold_left_impl<sizeof...(tail)>::
            template type<left_folder_1<state, _00>, tail...>;
    };
    template <>
    struct _fold_left_impl<0> {
        template <class state, class...>
        using type = state;
    };
    template <class state, class... vals>
    struct left_folder
        : _fold_left_impl<sizeof...(vals)>::
              template type<left_folder_0<state>, vals...> {
    };
    template <class lbd>
    struct _fold_left {
    };
    template <template <class...> class expr>
    struct _fold_left<lambda<expr>> {
        template <class... vals>
        using type = forward<left_folder<vals...>::template type, expr>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class state, class vals>
    struct accumulator_impl {
    };
    template <class state, class... vals>
    struct accumulator_impl<state, list<vals...>> {
        template <template <class...> class expr>
        using type = expr<state, vals...>;
    };
    template <template <class...> class expr>
    struct accumulator {
        template <class state, class vals>
        using type = forward<accumulator_impl<state, vals>::template type, expr>;
    };
    template <class state, class... seqs>
    struct _accumulate_impl {
        template <template <class...> class expr>
        using type = forward<
            _accumulate_impl<state, transpose<list<seqs...>>>::template type,
            accumulator<expr>::template type>;
    };
    template <class state, class... vals>
    struct _accumulate_impl<state, list<vals...>> {
        template <template <class...> class expr>
        using type = fold_left<lambda<expr>, state, vals...>;
    };
    template <class state>
    struct _accumulate_impl<state> {
        template <template <class...> class expr>
        using type = state;
    };
    template <class lbd>
    struct _accumulate {
    };
    template <template <class...> class expr>
    struct _accumulate<lambda<expr>> {
        template <class state, class... seqs>
        using type = forward<_accumulate_impl<state, seqs...>::template type, expr>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_LIST_ALL_OF_HPP
#define METAL_LIST_ALL_OF_HPP
#ifndef METAL_NUMBER_AND_HPP
#define METAL_NUMBER_AND_HPP
#ifndef METAL_NUMBER_NOT_HPP
#define METAL_NUMBER_NOT_HPP
namespace metal {
/// \ingroup number
///
/// ### Description
/// Computes the logical inverse of a \number.
///
/// ### Usage
/// For any \number `num`
/// \code
///     using result = metal::not_<num>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<!num{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp not_
///
/// ### See Also
/// \see number, and_, or_
template <class num>
using not_ = metal::if_<num, metal::false_, metal::true_>;
}
#endif
namespace metal {
/// \ingroup number
///
/// ### Description
/// Computes the logical conjunction of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::and_<num_0, ..., num_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num_0{} && ... && num_n-1{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp and_
///
/// ### See Also
/// \see number, not_, or_
template <class... nums>
using and_ = metal::same<metal::false_, metal::not_<nums>...>;
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Checks whether a predicate holds for all elements of a \list.
///
/// ### Usage
/// For any \list `l` and \lambda `lbd`
/// \code
///     using result = metal::all_of<l, lbd>;
/// \endcode
///
/// \pre: For any element `l[i]` contained in `l`,
/// `metal::invoke<lbd, l[i]>` returns a \number
/// \returns: \number
/// \semantics:
///     If `metal::invoke<lbd, l[i]>{} != false` for all `l[i]` contained in
///     `l`, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet list.cpp all_of
///
/// ### See Also
/// \see list, any_of, none_of
template <class seq, class lbd>
using all_of = metal::apply<metal::lambda<metal::and_>, metal::transform<lbd, seq>>;
}
#endif
#ifndef METAL_LIST_ANY_OF_HPP
#define METAL_LIST_ANY_OF_HPP
#ifndef METAL_NUMBER_OR_HPP
#define METAL_NUMBER_OR_HPP
namespace metal {
/// \ingroup number
///
/// ### Description
/// Computes the logical disjunction of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::or_<num_0, ..., num_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num_0{} || ... || num_n-1{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp or_
///
/// ### See Also
/// \see number, not_, and_
template <class... nums>
using or_ = metal::not_<metal::same<metal::true_, metal::not_<nums>...>>;
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Checks whether a predicate holds for at least some element of a \list.
///
/// ### Usage
/// For any \list `l` and \lambda `lbd`
/// \code
///     using result = metal::any_of<l, lbd>;
/// \endcode
///
/// \pre: For any element `l[i]` contained in `l`,
/// `metal::invoke<lbd, l[i]>` returns a \number
/// \returns: \number
/// \semantics:
///     If `metal::invoke<lbd, l[i]>{} != false` for at least some `l[i]`
///     contained in `l`, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet list.cpp any_of
///
/// ### See Also
/// \see list, all_of, none_of
template <class seq, class lbd>
using any_of = metal::apply<metal::lambda<metal::or_>, metal::transform<lbd, seq>>;
}
#endif
#ifndef METAL_LIST_APPEND_HPP
#define METAL_LIST_APPEND_HPP
#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP
#include <cstddef>
namespace metal {
/// \cond
namespace detail {
    template <std::size_t n>
    struct joiner;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Concatenates \lists.
///
/// ### Usage
/// For any \lists `l_0, ..., l_n-1`
/// \code
///     using result = metal::join<l_0, ..., l_n-1>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<l_0[:], ...[:], l_n-1[:]>;
///     \endcode
///     where `l[:]` stands for the expansion of all elements contained in
///     `l`.
///
/// ### Example
/// \snippet list.cpp join
///
/// ### See Also
/// \see list, flatten
template <class... seqs>
using join = detail::call<detail::joiner<sizeof...(seqs)>::template type, seqs...>;
}
namespace metal {
/// \cond
namespace detail {
    template <
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>, class = list<>, class = list<>, class = list<>, class = list<>,
        class = list<>>
    struct _join_impl {
    };
    template <
        class... _00, class... _01, class... _02, class... _03, class... _04,
        class... _05, class... _06, class... _07, class... _08, class... _09,
        class... _10, class... _11, class... _12, class... _13, class... _14,
        class... _15, class... _16, class... _17, class... _18, class... _19,
        class... _20, class... _21, class... _22, class... _23, class... _24,
        class... _25, class... _26, class... _27, class... _28, class... _29,
        class... _30, class... _31, class... _32, class... _33, class... _34,
        class... _35, class... _36, class... _37, class... _38, class... _39,
        class... _40, class... _41, class... _42, class... _43, class... _44,
        class... _45, class... _46, class... _47, class... _48, class... _49,
        class... _50, class... _51, class... _52, class... _53, class... _54,
        class... _55, class... _56, class... _57, class... _58, class... _59,
        class... _60, class... _61, class... _62, class... _63, class... _64,
        class... _65, class... _66, class... _67, class... _68, class... _69,
        class... _70, class... _71, class... _72, class... _73, class... _74,
        class... _75, class... _76, class... _77, class... _78, class... _79,
        class... _80, class... _81, class... _82, class... _83, class... _84,
        class... _85, class... _86, class... _87, class... _88, class... _89,
        class... _90, class... _91, class... _92, class... _93, class... _94,
        class... _95, class... _96, class... _97, class... _98, class... _99,
        class... _>
    struct _join_impl<
        list<_00...>, list<_01...>, list<_02...>, list<_03...>, list<_04...>,
        list<_05...>, list<_06...>, list<_07...>, list<_08...>, list<_09...>,
        list<_10...>, list<_11...>, list<_12...>, list<_13...>, list<_14...>,
        list<_15...>, list<_16...>, list<_17...>, list<_18...>, list<_19...>,
        list<_20...>, list<_21...>, list<_22...>, list<_23...>, list<_24...>,
        list<_25...>, list<_26...>, list<_27...>, list<_28...>, list<_29...>,
        list<_30...>, list<_31...>, list<_32...>, list<_33...>, list<_34...>,
        list<_35...>, list<_36...>, list<_37...>, list<_38...>, list<_39...>,
        list<_40...>, list<_41...>, list<_42...>, list<_43...>, list<_44...>,
        list<_45...>, list<_46...>, list<_47...>, list<_48...>, list<_49...>,
        list<_50...>, list<_51...>, list<_52...>, list<_53...>, list<_54...>,
        list<_55...>, list<_56...>, list<_57...>, list<_58...>, list<_59...>,
        list<_60...>, list<_61...>, list<_62...>, list<_63...>, list<_64...>,
        list<_65...>, list<_66...>, list<_67...>, list<_68...>, list<_69...>,
        list<_70...>, list<_71...>, list<_72...>, list<_73...>, list<_74...>,
        list<_75...>, list<_76...>, list<_77...>, list<_78...>, list<_79...>,
        list<_80...>, list<_81...>, list<_82...>, list<_83...>, list<_84...>,
        list<_85...>, list<_86...>, list<_87...>, list<_88...>, list<_89...>,
        list<_90...>, list<_91...>, list<_92...>, list<_93...>, list<_94...>,
        list<_95...>, list<_96...>, list<_97...>, list<_98...>, list<_99...>,
        list<_...>> {
        using type = list<
            _00..., _01..., _02..., _03..., _04..., _05..., _06..., _07..., _08..., _09...,
            _10..., _11..., _12..., _13..., _14..., _15..., _16..., _17..., _18..., _19...,
            _20..., _21..., _22..., _23..., _24..., _25..., _26..., _27..., _28..., _29...,
            _30..., _31..., _32..., _33..., _34..., _35..., _36..., _37..., _38..., _39...,
            _40..., _41..., _42..., _43..., _44..., _45..., _46..., _47..., _48..., _49...,
            _50..., _51..., _52..., _53..., _54..., _55..., _56..., _57..., _58..., _59...,
            _60..., _61..., _62..., _63..., _64..., _65..., _66..., _67..., _68..., _69...,
            _70..., _71..., _72..., _73..., _74..., _75..., _76..., _77..., _78..., _79...,
            _80..., _81..., _82..., _83..., _84..., _85..., _86..., _87..., _88..., _89...,
            _90..., _91..., _92..., _93..., _94..., _95..., _96..., _97..., _98..., _99...,
            _...>;
    };
    template <class... seqs>
    using join_impl = typename _join_impl<seqs...>::type;
    template <std::size_t n>
    struct joiner : joiner<(n > 100) ? 100 : 0> {
    };
    template <>
    struct joiner<100> {
        template <
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class _10, class _11, class _12, class _13, class _14,
            class _15, class _16, class _17, class _18, class _19,
            class _20, class _21, class _22, class _23, class _24,
            class _25, class _26, class _27, class _28, class _29,
            class _30, class _31, class _32, class _33, class _34,
            class _35, class _36, class _37, class _38, class _39,
            class _40, class _41, class _42, class _43, class _44,
            class _45, class _46, class _47, class _48, class _49,
            class _50, class _51, class _52, class _53, class _54,
            class _55, class _56, class _57, class _58, class _59,
            class _60, class _61, class _62, class _63, class _64,
            class _65, class _66, class _67, class _68, class _69,
            class _70, class _71, class _72, class _73, class _74,
            class _75, class _76, class _77, class _78, class _79,
            class _80, class _81, class _82, class _83, class _84,
            class _85, class _86, class _87, class _88, class _89,
            class _90, class _91, class _92, class _93, class _94,
            class _95, class _96, class _97, class _98, class _99,
            class... tail>
        using type = join_impl<
            _00, _01, _02, _03, _04, _05, _06, _07, _08, _09,
            _10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
            _20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
            _30, _31, _32, _33, _34, _35, _36, _37, _38, _39,
            _40, _41, _42, _43, _44, _45, _46, _47, _48, _49,
            _50, _51, _52, _53, _54, _55, _56, _57, _58, _59,
            _60, _61, _62, _63, _64, _65, _66, _67, _68, _69,
            _70, _71, _72, _73, _74, _75, _76, _77, _78, _79,
            _80, _81, _82, _83, _84, _85, _86, _87, _88, _89,
            _90, _91, _92, _93, _94, _95, _96, _97, _98, _99,
            typename joiner<sizeof...(tail)>::template type<tail...>>;
    };
    template <>
    struct joiner<0> {
        template <class... seqs>
        using type = join_impl<seqs...>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Inserts \values at the end of a \list.
///
/// ### Usage
/// For any \list `l` and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::append<l, val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::list<
///             l[0], ..., l[m-1], val_0, ..., val_n-1
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp append
///
/// ### See Also
/// \see list, insert, prepend
template <class seq, class... vals>
using append = metal::join<seq, metal::list<vals...>>;
}
#endif
#ifndef METAL_LIST_BACK_HPP
#define METAL_LIST_BACK_HPP
#ifndef METAL_NUMBER_DEC_HPP
#define METAL_NUMBER_DEC_HPP
#ifndef METAL_NUMBER_SUB_HPP
#define METAL_NUMBER_SUB_HPP
namespace metal {
/// \cond
namespace detail {
    template <class x, class y>
    struct _sub;
    template <class x, class y>
    using sub = typename _sub<x, y>::type;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Computes the arithmetic subtraction of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::sub<num_0, ..., num_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num_0{} - ... - num_n-1{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp sub
///
/// ### See Also
/// \see number, abs, inc, dec, neg, add, mul, div, mod, pow
template <class... nums>
using sub = fold_left<lambda<detail::sub>, nums..., number<0>>;
/// \cond
namespace detail {
    template <class x, class y>
    struct _sub {
    };
    template <int_ x, int_ y>
    struct _sub<number<x>, number<y>> {
        using type = number<x - y>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup number
///
/// ### Description
/// Decrements a \number.
///
/// ### Usage
/// For any \number `num`
/// \code
///     using result = metal::dec<num>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num{} - 1>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp dec
///
/// ### See Also
/// \see number, abs, inc, neg, add, sub, mul, div, mod, pow
template <class num>
using dec = metal::sub<num, metal::number<1>>;
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Retrieves the last element of a \list.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::back<l>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = l[m-1];
///     \endcode
///
/// ### Example
/// \snippet list.cpp back
///
/// ### See Also
/// \see list, at, front
template <class seq>
using back = metal::at<seq, metal::dec<metal::size<seq>>>;
}
#endif
#ifndef METAL_LIST_CARTESIAN_HPP
#define METAL_LIST_CARTESIAN_HPP
namespace metal {
/// \cond
namespace detail {
    template <class, class>
    struct _product;
    template <class seqs, class seq>
    using product = typename _product<seqs, seq>::type;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Computes the cartesian product of \lists.
///
/// ### Usage
/// For any \lists `l_0, ..., l_n-1`
/// \code
///     using result = metal::cartesian<l_0, ..., l_n-1>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<
///             metal::list<l_0[x_0], ...[...], l_n-1[x_n-1]>,
///         >;
///     \endcode
///     where each `x` in `x_0, ..., x_n-1` varies independently from `0` to
///     `n-1`.
///
/// ### Example
/// \snippet list.cpp cartesian
///
/// ### See Also
/// \see list, transpose
template <class... seqs>
using cartesian = fold_left<lambda<detail::product>, list<list<>>, seqs...>;
}
namespace metal {
/// \cond
namespace detail {
    template <class, class>
    struct _product_impl {
    };
    template <class... xs, class... ys>
    struct _product_impl<list<xs...>, list<ys...>> {
        using type = list<list<xs..., ys>...>;
    };
    template <class seqs, class seq>
    using product_impl = typename _product_impl<seqs, seq>::type;
    template <class, class>
    struct _product {
    };
    template <class... seqs, class... vals>
    struct _product<list<seqs...>, list<vals...>> {
        using type = join<product_impl<seqs, list<vals...>>...>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_LIST_CASCADE_HPP
#define METAL_LIST_CASCADE_HPP
#ifndef METAL_VALUE_FOLD_RIGHT_HPP
#define METAL_VALUE_FOLD_RIGHT_HPP
namespace metal {
/// \cond
namespace detail {
    template <class lbd>
    struct _fold_right;
}
/// \endcond
/// \ingroup value
///
/// ### Description
/// Computes the recursive invocation of a binary \lambda with the result of
/// the previous invocation and each \value, from the last to the first.
///
/// ### Usage
/// For any \lambda `lbd`, and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::fold_right<lbd, val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     Equivalent to
///     \code
///         using result =
///             lbd(val_0, ..., lbd(val_n-3, lbd(val_n-2, val_n-1)), ...)
///     \endcode
///     where `lbd(x, y)` stands for `metal::invoke<lbd, x, y>`.
///
/// ### Example
/// \snippet value.cpp fold_right
///
/// ### See Also
/// \see fold_right
template <class lbd, class... vals>
using fold_right = detail::call<detail::_fold_right<lbd>::template type, vals...>;
}
#include <cstddef>
namespace metal {
/// \cond
namespace detail {
    template <
        class state,
        class _00, class _01, class _02, class _03, class _04, class _05,
        class _06, class _07, class _08, class _09, class _10, class _11,
        class _12, class _13, class _14, class _15, class _16, class _17,
        class _18, class _19, class _20, class _21, class _22, class _23,
        class _24, class _25, class _26, class _27, class _28, class _29,
        class _30, class _31, class _32, class _33, class _34, class _35,
        class _36, class _37, class _38, class _39, class _40, class _41,
        class _42, class _43, class _44, class _45, class _46, class _47,
        class _48, class _49, class _50, class _51, class _52, class _53,
        class _54, class _55, class _56, class _57, class _58, class _59,
        class _60, class _61, class _62, class _63, class _64, class _65,
        class _66, class _67, class _68, class _69, class _70, class _71,
        class _72, class _73, class _74, class _75, class _76, class _77,
        class _78, class _79, class _80, class _81, class _82, class _83,
        class _84, class _85, class _86, class _87, class _88, class _89,
        class _90, class _91, class _92, class _93, class _94, class _95,
        class _96, class _97, class _98, class _99>
    struct right_folder_100 {
            template<template<class...> class expr>
            using type =
                expr<_00, expr<_01, expr<_02, expr<_03, expr<_04,
                expr<_05, expr<_06, expr<_07, expr<_08, expr<_09,
                expr<_10, expr<_11, expr<_12, expr<_13, expr<_14,
                expr<_15, expr<_16, expr<_17, expr<_18, expr<_19,
                expr<_20, expr<_21, expr<_22, expr<_23, expr<_24,
                expr<_25, expr<_26, expr<_27, expr<_28, expr<_29,
                expr<_30, expr<_31, expr<_32, expr<_33, expr<_34,
                expr<_35, expr<_36, expr<_37, expr<_38, expr<_39,
                expr<_40, expr<_41, expr<_42, expr<_43, expr<_44,
                expr<_45, expr<_46, expr<_47, expr<_48, expr<_49,
                expr<_50, expr<_51, expr<_52, expr<_53, expr<_54,
                expr<_55, expr<_56, expr<_57, expr<_58, expr<_59,
                expr<_60, expr<_61, expr<_62, expr<_63, expr<_64,
                expr<_65, expr<_66, expr<_67, expr<_68, expr<_69,
                expr<_70, expr<_71, expr<_72, expr<_73, expr<_74,
                expr<_75, expr<_76, expr<_77, expr<_78, expr<_79,
                expr<_80, expr<_81, expr<_82, expr<_83, expr<_84,
                expr<_85, expr<_86, expr<_87, expr<_88, expr<_89,
                expr<_90, expr<_91, expr<_92, expr<_93, expr<_94,
                expr<_95, expr<_96, expr<_97, expr<_98, expr<_99,
                    forward<state::template type, expr>
                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>;
    };
    template <
        class state,
        class _00, class _01, class _02, class _03, class _04, class _05,
        class _06, class _07, class _08, class _09>
    struct right_folder_10 {
        template <template <class...> class expr>
        /* clang-format off */
            using type =
                expr<_00, expr<_01, expr<_02, expr<_03, expr<_04,
                expr<_05, expr<_06, expr<_07, expr<_08, expr<_09,
                    forward<state::template type, expr>
                >>>>>>>>>>;
        /* clang-format on */
    };
    template <class state, class _00>
    struct right_folder_1 {
        template <template <class...> class expr>
        using type = expr<_00, forward<state::template type, expr>>;
    };
    template <class state>
    struct right_folder_0 {
        template <template <class...> class>
        using type = identity<state>;
    };
    template <std::size_t n>
    struct _fold_right_impl
        /* clang-format off */
        : _fold_right_impl<(n > 100) ? 100 : (n > 10) ? 10: (n > 1)> {
        /* clang-format on */
    };
    template <>
    struct _fold_right_impl<100> {
        template <
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class _10, class _11, class _12, class _13, class _14,
            class _15, class _16, class _17, class _18, class _19,
            class _20, class _21, class _22, class _23, class _24,
            class _25, class _26, class _27, class _28, class _29,
            class _30, class _31, class _32, class _33, class _34,
            class _35, class _36, class _37, class _38, class _39,
            class _40, class _41, class _42, class _43, class _44,
            class _45, class _46, class _47, class _48, class _49,
            class _50, class _51, class _52, class _53, class _54,
            class _55, class _56, class _57, class _58, class _59,
            class _60, class _61, class _62, class _63, class _64,
            class _65, class _66, class _67, class _68, class _69,
            class _70, class _71, class _72, class _73, class _74,
            class _75, class _76, class _77, class _78, class _79,
            class _80, class _81, class _82, class _83, class _84,
            class _85, class _86, class _87, class _88, class _89,
            class _90, class _91, class _92, class _93, class _94,
            class _95, class _96, class _97, class _98, class _99,
            class... tail>
        using type = right_folder_100<
            typename _fold_right_impl<sizeof...(tail) - 1>::template type<tail...>,
            _00, _01, _02, _03, _04, _05, _06, _07, _08, _09,
            _10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
            _20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
            _30, _31, _32, _33, _34, _35, _36, _37, _38, _39,
            _40, _41, _42, _43, _44, _45, _46, _47, _48, _49,
            _50, _51, _52, _53, _54, _55, _56, _57, _58, _59,
            _60, _61, _62, _63, _64, _65, _66, _67, _68, _69,
            _70, _71, _72, _73, _74, _75, _76, _77, _78, _79,
            _80, _81, _82, _83, _84, _85, _86, _87, _88, _89,
            _90, _91, _92, _93, _94, _95, _96, _97, _98, _99>;
    };
    template <>
    struct _fold_right_impl<10> {
        template <
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class... tail>
        using type = right_folder_10<
            typename _fold_right_impl<sizeof...(tail) - 1>::template type<tail...>,
            _00, _01, _02, _03, _04, _05, _06, _07, _08, _09>;
    };
    template <>
    struct _fold_right_impl<1> {
        template <class _00, class... tail>
        using type = right_folder_1<typename _fold_right_impl<sizeof...(tail) - 1>::template type<tail...>, _00>;
    };
    template <>
    struct _fold_right_impl<0> {
        template <class _00>
        using type = right_folder_0<_00>;
    };
    template <class state, class... vals>
    struct right_folder
        : _fold_right_impl<sizeof...(vals)>::template type<state, vals...> {
    };
    template <class lbd>
    struct _fold_right {
    };
    template <template <class...> class expr>
    struct _fold_right<lambda<expr>> {
        template <class... vals>
        using type = forward<right_folder<vals...>::template type, expr>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class outer, class inner>
    struct _cascader;
    template <class outer, class inner>
    using cascader = typename _cascader<outer, inner>::type;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Recursively applies \lambdas to nested \lists of \lists.
///
/// ### Usage
/// For any \list `l` and \lambdas `lbd_0, ..., lbd_n-1`, where `n > 0`,
/// \code
///     using result = metal::cascade<l, lbd_0, ..., lbd_n-1>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `n == 1`, then
///     \code
///         using result = metal::apply<lbd_0, l>;
///     \endcode
///     otherwise, if `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::invoke<
///             lbd_0,
///             metal::cascade<l[0], lbd_1, ..., lbd_n-1>>,
///             metal::cascade<l[1], lbd_1, ..., lbd_n-1>>,
///             ...,
///             metal::cascade<l[m-1], lbd_1, ..., lbd_n-1>>
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp cascade
///
/// ### See Also
/// \see list, cartesian
template <class seq, class... lbds>
using cascade = apply<fold_right<lambda<detail::cascader>, lbds...>, seq>;
}
namespace metal {
/// \cond
namespace detail {
    template <class outer, class inner>
    struct _cascader {
    };
    template <template <class...> class outer, template <class...> class inner>
    struct _cascader<lambda<outer>, lambda<inner>> {
        template <class... seqs>
        using impl = invoke<lambda<outer>, apply<lambda<inner>, seqs>...>;
        using type = lambda<impl>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_LIST_COMBINE_HPP
#define METAL_LIST_COMBINE_HPP
#ifndef METAL_LIST_REPEAT_HPP
#define METAL_LIST_REPEAT_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Returns a \list that contains a \number of copies of the same \value.
///
/// ### Usage
/// For any \value `val` and \number `num`
/// \code
///     using result = metal::repeat<val, num>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `num` holds the constant `n`, then
///     \code
///         using result = metal::list<val_0, ..., val_n-1>;
///     \endcode
///     where `val_0, ..., val_n-1` are all identical to `val`.
///
/// ### Example
/// \snippet list.cpp repeat
///
/// ### See Also
/// \see list, iota
template <class val, class num>
using repeat = metal::transform<
    metal::always<val>,
    metal::iota<metal::number<0>, num, metal::number<0>>>;
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Computes all possible combinations (with repetition) from the
/// elements in a \list.
///
/// ### Usage
/// For any \list `l` and \number `num`
/// \code
///     using result = metal::combine<l, num>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]` and `num` holds the
///     constant `n`, then
///     \code
///         using result = metal::list<
///             metal::list<l[x_0], ...[...], l[x_n-1]>,
///         >;
///     \endcode
///     where each `x` in `x_0, ..., x_n-1` varies independently from `0` to
///     `m-1`.
///
/// ### Example
/// \snippet list.cpp combine
///
/// ### See Also
/// \see list, powerset, cartesian, cascade
template <class seq, class num = metal::size<seq>>
using combine = metal::apply<
    metal::lambda<metal::cartesian>,
    metal::repeat<metal::if_<metal::is_list<seq>, seq>, num>>;
}
#endif
#ifndef METAL_LIST_CONTAINS_HPP
#define METAL_LIST_CONTAINS_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Checks whether a \value is contained in a \list.
///
/// ### Usage
/// For any \list `l` and \value `val`
/// \code
///     using result = metal::contains<l, val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `val` is contained in `l`, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet list.cpp contains
///
/// ### See Also
/// \see list, count, find
template <class seq, class val>
using contains = metal::any_of<seq, metal::partial<metal::lambda<metal::same>, val>>;
}
#endif
#ifndef METAL_LIST_COPY_HPP
#define METAL_LIST_COPY_HPP
#ifndef METAL_LIST_COPY_IF_HPP
#define METAL_LIST_COPY_IF_HPP
#ifndef METAL_LIST_REMOVE_IF_HPP
#define METAL_LIST_REMOVE_IF_HPP
#ifndef METAL_LIST_REPLACE_IF_HPP
#define METAL_LIST_REPLACE_IF_HPP
namespace metal {
/// \cond
namespace detail {
    template <class, class, class...>
    struct _replace_if;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Replaces every element in a \list that satisfies a predicate by some
/// \value.
///
/// ### Usage
/// For any \list `l`, \lambda `lbd` and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::replace_if<l, lbd, val_0, ..., val_n-1>;
/// \endcode
///
/// \pre: For any element `l[i]` contained in `l`,
/// `metal::invoke<lbd, l[i]>` returns a \number
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<...>;
///     \endcode
///     where `result` contains all and only the elements in `l`, except
///     that every element `l[i]` for which
///     `metal::invoke<lbd, l[i]>{} != false` has been replaced by
///     `val_0, ..., val_n-1`.
///
/// ### Example
/// \snippet list.cpp replace_if
///
/// ### See Also
/// \see list, replace, copy_if, remove_if
template <class seq, class lbd, class... vals>
using replace_if = typename detail::_replace_if<seq, transform<lbd, seq>, vals...>::type;
}
namespace metal {
/// \cond
namespace detail {
    template <class vals, class vs, class...>
    struct _replace_if {
    };
    template <class... vals, int_... vs, class x, class y, class... t>
    struct _replace_if<list<vals...>, list<number<vs>...>, x, y, t...> {
        using type = call<join, if_<number<vs>, list<x, y, t...>, list<vals>>...>;
    };
    template <class... vals, int_... vs, class x>
    struct _replace_if<list<vals...>, list<number<vs>...>, x> {
        using type = list<if_<number<vs>, x, vals>...>;
    };
    template <class... vals, int_... vs>
    struct _replace_if<list<vals...>, list<number<vs>...>> {
        using type = call<join, if_<number<vs>, list<>, list<vals>>...>;
    };
    template <class x, class y, class... t>
    struct _replace_if<list<>, list<>, x, y, t...> {
        using type = list<>;
    };
    template <class x>
    struct _replace_if<list<>, list<>, x> {
        using type = list<>;
    };
    template <>
    struct _replace_if<list<>, list<>> {
        using type = list<>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Removes all elements from a \list that satisfy a predicate.
///
/// ### Usage
/// For any \list `l` and \lambda `lbd`
/// \code
///     using result = metal::remove_if<l, lbd>;
/// \endcode
///
/// \pre: For any element `l[i]` contained in `l`,
/// `metal::invoke<lbd, l[i]>` returns a \number
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<...>;
///     \endcode
///     where `result` contains all and only the elements `l[i]` in `l` for
///     which `metal::invoke<lbd, l[i]>{} == false`.
///
/// ### Example
/// \snippet list.cpp remove_if
///
/// ### See Also
/// \see list, remove, copy_if, replace_if
template <class seq, class lbd>
using remove_if = metal::replace_if<seq, lbd>;
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Removes all elements from a \list except for those that satisfy a
/// predicate.
///
/// ### Usage
/// For any \list `l` and \lambda `lbd`
/// \code
///     using result = metal::copy_if<l, lbd>;
/// \endcode
///
/// \pre: For any element `l[i]` contained in `l`,
/// `metal::invoke<lbd, l[i]>` returns a \number
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<...>;
///     \endcode
///     where `result` contains all and only the elements `l[i]` in `l` for
///     which `metal::invoke<lbd, l[i]>{} != false`.
///
/// ### Example
/// \snippet list.cpp copy_if
///
/// ### See Also
/// \see list, copy, remove_if, replace_if
template <class seq, class lbd>
using copy_if = metal::remove_if<seq, metal::bind<metal::lambda<metal::not_>, lbd>>;
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Removes all elements from a \list except for those that are the same as
/// some \value.
///
/// ### Usage
/// For any \list `l` and \value `val`
/// \code
///     using result = metal::copy<l, val>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<...>;
///     \endcode
///     where `result` contains all and only the occurrences of `val` in
///     `l`.
///
/// ### Example
/// \snippet list.cpp copy
///
/// ### See Also
/// \see list, copy_if, remove, replace
template <class seq, class val>
using copy = metal::copy_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}
#endif
#ifndef METAL_LIST_COUNT_HPP
#define METAL_LIST_COUNT_HPP
#ifndef METAL_LIST_COUNT_IF_HPP
#define METAL_LIST_COUNT_IF_HPP
#ifndef METAL_NUMBER_ADD_HPP
#define METAL_NUMBER_ADD_HPP
namespace metal {
/// \cond
namespace detail {
    template <class x, class y>
    struct _add;
    template <class x, class y>
    using add = typename _add<x, y>::type;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Computes the arithmetic addition of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::add<num_0, ..., num_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num_0{} + ... + num_n-1{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp add
///
/// ### See Also
/// \see number, abs, inc, dec, neg, sub, mul, div, mod, pow
template <class... nums>
using add = fold_left<lambda<detail::add>, nums..., number<0>>;
/// \cond
namespace detail {
    template <class x, class y>
    struct _add {
    };
    template <int_ x, int_ y>
    struct _add<number<x>, number<y>> {
        using type = number<x + y>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Counts the elements in a \list that satisfy a predicate.
///
/// ### Usage
/// For any \list `l` and \lambda `lbd`
/// \code
///     using result = metal::count_if<l, lbd>;
/// \endcode
///
/// \pre: For any element `l[i]` contained in `l`,
/// `metal::invoke<lbd, l[i]>` returns a \number
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<n>;
///     \endcode
///     where `n` is the number of occurrences of some `l[i]` in `l`, such
///     that `metal::invoke<lbd, l[i]>{} != false`.
///
/// ### Example
/// \snippet list.cpp count_if
///
/// ### See Also
/// \see list, count, all, any, none, find_if
template <class seq, class lbd>
using count_if = metal::apply<metal::lambda<metal::add>, metal::transform<lbd, seq>>;
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Counts the occurrences of a \value in a \list.
///
/// ### Usage
/// For any \list `l` and \value `val`
/// \code
///     using result = metal::count<l, val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<n>;
///     \endcode
///     where `n` is the number of occurrences of `val` in `l`.
///
/// ### Example
/// \snippet list.cpp count
///
/// ### See Also
/// \see list, count_if, contains, find
template <class seq, class val>
using count = metal::count_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}
#endif
#ifndef METAL_LIST_DROP_HPP
#define METAL_LIST_DROP_HPP
#ifndef METAL_LIST_RANGE_HPP
#define METAL_LIST_RANGE_HPP
#ifndef METAL_NUMBER_GREATER_HPP
#define METAL_NUMBER_GREATER_HPP
#ifndef METAL_NUMBER_LESS_HPP
#define METAL_NUMBER_LESS_HPP
namespace metal {
/// \cond
namespace detail {
    template <class x, class y>
    struct _less;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Checks whether a \number is less than another.
///
/// ### Usage
/// For any \numbers `x` and `y`
/// \code
///     using result = metal::less<x, y>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<(x{} < y{})>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp less
///
/// ### See Also
/// \see number, greater, max, min
template <class x, class y>
using less = typename detail::_less<x, y>::type;
}
namespace metal {
/// \cond
namespace detail {
    template <class x, class y>
    struct _less {
    };
    template <int_ x, int_ y>
    struct _less<number<x>, number<y>> : number<(x < y)> {
    };
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup number
///
/// ### Description
/// Checks whether a \number is greater than another.
///
/// ### Usage
/// For any \numbers `x` and `y`
/// \code
///     using result = metal::greater<x, y>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<(x{} > y{})>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp greater
///
/// ### See Also
/// \see number, less, max, min
template <class x, class y>
using greater = metal::less<y, x>;
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class seq, class beg, class end>
    struct _range;
    template <class seq, class beg, class end>
    using range = typename detail::_range<seq, beg, end>::type;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Returns a contiguous subsequence of a \list.
///
/// ### Usage
/// For any \list `l` and \numbers `beg` and `end`
/// \code
///     using result = metal::range<l, beg, end>;
/// \endcode
///
/// \pre: `metal::number<0>{} &le; beg{} &le; metal::size<l>{}` and
/// `metal::number<0>{} &le; end{} &le; metal::size<l>{}`
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[i], ..., l[j], ..., l[m-1]`,
///     `beg{} == i` and `end{} == j`, then
///     \code
///         using result = metal::list<l[i], ..., l[j-1]>;
///     \endcode
///     otherwise, if `beg{} == j` and `end{} == i`, then
///     \code
///         using result = metal::list<l[j-1], ..., l[i]>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp range
///
/// ### See Also
/// \see list, erase, take, drop
template <class seq, class beg, class end>
using range = detail::range<
    seq,
    if_<not_<or_<greater<number<0>, beg>, greater<beg, size<seq>>>>, beg>,
    if_<not_<or_<greater<number<0>, end>, greater<end, size<seq>>>>, end>>;
}
#ifndef METAL_LIST_REVERSE_HPP
#define METAL_LIST_REVERSE_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Reverses the order of the elements of a \list.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::reverse<l>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::list<l[m-1], ..., l[0]>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp reverse
///
/// ### See Also
/// \see list, rotate, sort
template <class seq>
using reverse = metal::range<seq, metal::size<seq>, metal::number<0>>;
}
#endif
#ifndef METAL_LIST_ROTATE_HPP
#define METAL_LIST_ROTATE_HPP
namespace metal {
/// \cond
namespace detail {
    template <class seq, class num>
    struct _rotate;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Rotates the elements of a \list around a pivot.
///
/// ### Usage
/// For any \list `l` and \number `num`
/// \code
///     using result = metal::rotate<l, num>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[i-1], l[i], ..., l[m-1]` and
///     `num{} % m == i`, then
///     \code
///         using result = metal::list<
///             l[i], ..., l[m-1], l[0], ..., l[i-1]
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp rotate
///
/// ### See Also
/// \see list, reverse, sort
template <class seq, class num>
using rotate = typename detail::_rotate<seq, num>::type;
}
namespace metal {
/// \cond
namespace detail {
    template <int_ n>
    struct rotator
        /* clang-format off */
        : rotator<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {
        /* clang-format on */
    };
    template <>
    struct rotator<100> {
        template <int_ n,
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class _10, class _11, class _12, class _13, class _14,
            class _15, class _16, class _17, class _18, class _19,
            class _20, class _21, class _22, class _23, class _24,
            class _25, class _26, class _27, class _28, class _29,
            class _30, class _31, class _32, class _33, class _34,
            class _35, class _36, class _37, class _38, class _39,
            class _40, class _41, class _42, class _43, class _44,
            class _45, class _46, class _47, class _48, class _49,
            class _50, class _51, class _52, class _53, class _54,
            class _55, class _56, class _57, class _58, class _59,
            class _60, class _61, class _62, class _63, class _64,
            class _65, class _66, class _67, class _68, class _69,
            class _70, class _71, class _72, class _73, class _74,
            class _75, class _76, class _77, class _78, class _79,
            class _80, class _81, class _82, class _83, class _84,
            class _85, class _86, class _87, class _88, class _89,
            class _90, class _91, class _92, class _93, class _94,
            class _95, class _96, class _97, class _98, class _99,
            class... tail>
        using type = typename rotator<(n - 100)>::template type<
            (n - 100), tail...,
            _00, _01, _02, _03, _04, _05, _06, _07, _08, _09,
            _10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
            _20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
            _30, _31, _32, _33, _34, _35, _36, _37, _38, _39,
            _40, _41, _42, _43, _44, _45, _46, _47, _48, _49,
            _50, _51, _52, _53, _54, _55, _56, _57, _58, _59,
            _60, _61, _62, _63, _64, _65, _66, _67, _68, _69,
            _70, _71, _72, _73, _74, _75, _76, _77, _78, _79,
            _80, _81, _82, _83, _84, _85, _86, _87, _88, _89,
            _90, _91, _92, _93, _94, _95, _96, _97, _98, _99>;
    };
    template <>
    struct rotator<10> {
        template <int_ n,
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class... tail>
        using type = typename rotator<(n - 10)>::
            template type<(n - 10), tail..., _00, _01, _02, _03, _04, _05, _06, _07, _08, _09>;
    };
    template <>
    struct rotator<1> {
        template <int_ n, class head, class... tail>
        using type = typename rotator<(n - 1)>::template type<(n - 1), tail..., head>;
    };
    template <>
    struct rotator<0> {
        template <int_, class... vals>
        using type = list<vals...>;
    };
    template <class seq, class num>
    struct _rotate {
    };
    template <class... vals, int_ n>
    struct _rotate<list<vals...>, number<n>> {
        enum : int_ { size = sizeof...(vals) };
        enum : std::size_t { m = ((n % size) + size * (n < 0)) };
        using type = typename rotator<m>::template type<m, vals...>;
    };
    template <int_ n>
    struct _rotate<list<>, number<n>> {
        using type = list<>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_NUMBER_MAX_HPP
#define METAL_NUMBER_MAX_HPP
namespace metal {
/// \cond
namespace detail {
    template <class x, class y>
    using max = if_<greater<x, y>, x, y>;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Computes the maximum of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::max<num_0, ..., num_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `M` the maximum between all \numbers in `num_0, ..., num_n-1`,
///     then
///     \code
///         using result = M;
///     \endcode
///
/// ### Example
/// \snippet number.cpp max
///
/// ### See Also
/// \see number, greater, less, min
template <class... nums>
using max = fold_left<lambda<detail::max>, if_<is_number<nums>, nums>...>;
}
#endif
#ifndef METAL_NUMBER_MIN_HPP
#define METAL_NUMBER_MIN_HPP
namespace metal {
/// \cond
namespace detail {
    template <class x, class y>
    using min = if_<less<x, y>, x, y>;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Computes the minimum of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::min<num_0, ..., num_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `m` the minimum between all \numbers in `num_0, ..., num_n-1`,
///     then
///     \code
///         using result = m;
///     \endcode
///
/// ### Example
/// \snippet number.cpp min
///
/// ### See Also
/// \see number, greater, less, max
template <class... nums>
using min = fold_left<lambda<detail::min>, if_<is_number<nums>, nums>...>;
}
#endif
#include <cstddef>
namespace metal {
/// \cond
namespace detail {
    template <class... vals>
    struct appender {
        template <class... _>
        using append = appender<vals..., _...>;
        using type = list<vals...>;
    };
    template <std::size_t n>
    struct reverser
        /* clang-format off */
        : reverser<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {
        /* clang-format on */
    };
    template <>
    struct reverser<100> {
        template <
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class _10, class _11, class _12, class _13, class _14,
            class _15, class _16, class _17, class _18, class _19,
            class _20, class _21, class _22, class _23, class _24,
            class _25, class _26, class _27, class _28, class _29,
            class _30, class _31, class _32, class _33, class _34,
            class _35, class _36, class _37, class _38, class _39,
            class _40, class _41, class _42, class _43, class _44,
            class _45, class _46, class _47, class _48, class _49,
            class _50, class _51, class _52, class _53, class _54,
            class _55, class _56, class _57, class _58, class _59,
            class _60, class _61, class _62, class _63, class _64,
            class _65, class _66, class _67, class _68, class _69,
            class _70, class _71, class _72, class _73, class _74,
            class _75, class _76, class _77, class _78, class _79,
            class _80, class _81, class _82, class _83, class _84,
            class _85, class _86, class _87, class _88, class _89,
            class _90, class _91, class _92, class _93, class _94,
            class _95, class _96, class _97, class _98, class _99,
            class... tail>
        using type = typename reverser<sizeof...(tail)>::
            template type<tail...>::template append<
                _99, _98, _97, _96, _95, _94, _93, _92, _91, _90,
                _89, _88, _87, _86, _85, _84, _83, _82, _81, _80,
                _79, _78, _77, _76, _75, _74, _73, _72, _71, _70,
                _69, _68, _67, _66, _65, _64, _63, _62, _61, _60,
                _59, _58, _57, _56, _55, _54, _53, _52, _51, _50,
                _49, _48, _47, _46, _45, _44, _43, _42, _41, _40,
                _39, _38, _37, _36, _35, _34, _33, _32, _31, _30,
                _29, _28, _27, _26, _25, _24, _23, _22, _21, _20,
                _19, _18, _17, _16, _15, _14, _13, _12, _11, _10,
                _09, _08, _07, _06, _05, _04, _03, _02, _01, _00>;
    };
    template <>
    struct reverser<10> {
        template <
            class _00, class _01, class _02, class _03, class _04,
            class _05, class _06, class _07, class _08, class _09,
            class... tail>
        using type = typename reverser<sizeof...(tail)>::
            template type<tail...>::
                template append<_09, _08, _07, _06, _05, _04, _03, _02, _01, _00>;
    };
    template <>
    struct reverser<1> {
        template <class _00, class... tail>
        using type = typename reverser<sizeof...(tail)>::
            template type<tail...>::
                template append<_00>;
    };
    template <>
    struct reverser<0> {
        template <class...>
        using type = appender<>;
    };
    template <class seq>
    struct _reverse {
    };
    template <class... vals>
    struct _reverse<list<vals...>> {
        using type = typename reverser<sizeof...(vals)>::template type<vals...>::type;
    };
    template <class seq>
    using reverse = typename _reverse<seq>::type;
    template <int_ n>
    struct dropper
        /* clang-format off */
        : dropper<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {
        /* clang-format on */
    };
    template <>
    struct dropper<100> {
        template <
            int_ n,
            class, class, class, class, class, class, class, class, class, class,
            class, class, class, class, class, class, class, class, class, class,
            class, class, class, class, class, class, class, class, class, class,
            class, class, class, class, class, class, class, class, class, class,
            class, class, class, class, class, class, class, class, class, class,
            class, class, class, class, class, class, class, class, class, class,
            class, class, class, class, class, class, class, class, class, class,
            class, class, class, class, class, class, class, class, class, class,
            class, class, class, class, class, class, class, class, class, class,
            class, class, class, class, class, class, class, class, class, class,
            class... tail>
        using type = typename dropper<(n - 100)>::template type<(n - 100), tail...>;
    };
    template <>
    struct dropper<10> {
        template <int_ n, class, class, class, class, class, class, class, class, class, class, class... tail>
        using type = typename dropper<(n - 10)>::template type<(n - 10), tail...>;
    };
    template <>
    struct dropper<1> {
        template <int_ n, class, class... tail>
        using type = typename dropper<(n - 1)>::template type<(n - 1), tail...>;
    };
    template <>
    struct dropper<0> {
        template <int_, class... vals>
        using type = list<vals...>;
    };
    template <class seq, class num>
    struct _drop {
    };
    template <class... vals, int_ n>
    struct _drop<list<vals...>, number<n>> {
        using type = typename dropper<n>::template type<n, vals...>;
    };
    template <class seq, class num>
    using drop = typename _drop<seq, num>::type;
    template <class seq, class num>
    using take = drop<rotate<seq, num>, sub<size<seq>, num>>;
    template <class seq, class beg, class end>
    struct _range {
        using b = min<beg, end>;
        using e = max<beg, end>;
        using type = range<range<range<seq, number<0>, e>, b, e>, sub<beg, b>, sub<end, b>>;
    };
    template <class seq, class num>
    struct _range<seq, number<0>, num> {
        using type = take<seq, num>;
    };
    template <class seq, class num>
    struct _range<seq, num, size<seq>> {
        using type = drop<seq, num>;
    };
    template <class seq>
    struct _range<seq, number<0>, size<seq>> {
        using type = seq;
    };
    template <class seq>
    struct _range<seq, size<seq>, number<0>> {
        using type = reverse<seq>;
    };
    template <>
    struct _range<list<>, number<0>, number<0>> {
        using type = list<>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Removes all elements from the beginning up to an arbitrary index of a
/// \list.
///
/// ### Usage
/// For any \list `l` and \number `num`
/// \code
///     using result = metal::drop<l, num>;
/// \endcode
///
/// \pre: `metal::number<0>{} &le; num{} &le; metal::size<l>{}`
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[i], ..., l[m-1]` and
///     `num{} == i`, then
///     \code
///         using result = metal::list<l[i], ..., l[m-1]>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp drop
///
/// ### See Also
/// \see list, range, erase, take
template <class seq, class n>
using drop = metal::range<seq, n, metal::size<seq>>;
}
#endif
#ifndef METAL_LIST_EMPTY_HPP
#define METAL_LIST_EMPTY_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Checks whether a \list has no elements.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::empty<l>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `l` contains at least one element, then
///     \code
///         using result = metal::false_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::true_;
///     \endcode
///
/// ### Example
/// \snippet list.cpp empty
///
/// ### See Also
/// \see list, size
template <class seq>
using empty = metal::not_<metal::size<seq>>;
}
#endif
#ifndef METAL_LIST_ERASE_HPP
#define METAL_LIST_ERASE_HPP
#ifndef METAL_LIST_TAKE_HPP
#define METAL_LIST_TAKE_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Removes all elements from the end down to an arbitrary index of a \list.
///
/// ### Usage
/// For any \list `l` and \number `num`
/// \code
///     using result = metal::take<l, num>;
/// \endcode
///
/// \pre: `metal::number<0>{} &le; num{} &le; metal::size<l>{}`
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[i], ..., l[m-1]` and
///     `num{} == i`, then
///     \code
///         using result = metal::list<l[0], ..., l[i-1]>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp take
///
/// ### See Also
/// \see list, range, erase, drop
template <class seq, class n>
using take = metal::range<seq, metal::number<0>, n>;
}
#endif
#ifndef METAL_NUMBER_INC_HPP
#define METAL_NUMBER_INC_HPP
namespace metal {
/// \ingroup number
///
/// ### Description
/// Increments a \number.
///
/// ### Usage
/// For any \number `num`
/// \code
///     using result = metal::inc<num>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num::{} + 1>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp inc
///
/// ### See Also
/// \see number, abs, dec, neg, add, sub, mul, div, mod, pow
template <class num>
using inc = metal::add<num, metal::number<1>>;
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Removes all elements between two arbitrary indices of a \list.
///
/// ### Usage
/// For any \list `l` and \numbers `beg` and `end`
/// \code
///     using result = metal::erase<l, beg, end>;
/// \endcode
///
/// \pre: `metal::number<0>{} &le; beg{} &le; metal::size<l>{}` and
/// `metal::number<0>{} &le; end{} &le; metal::size<l>{}`
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[i], ..., l[j], ..., l[m-1]`
///     and either `beg{} == i` and `end{} == j` or
///     `beg{} == j` and `end{} == i`, then
///     \code
///         using result = metal::list<
///             l[0], ..., l[i-1], l[j], ..., l[m-1]
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp erase
///
/// ### See Also
/// \see list, range, take, drop
template <class seq, class beg, class end = inc<beg>>
using erase = metal::join<
    metal::take<seq, metal::min<beg, end>>,
    metal::drop<seq, metal::max<beg, end>>>;
}
#endif
#ifndef METAL_LIST_FIND_HPP
#define METAL_LIST_FIND_HPP
#ifndef METAL_LIST_FIND_IF_HPP
#define METAL_LIST_FIND_IF_HPP
namespace metal {
/// \cond
namespace detail {
    template <class seq>
    struct _find_if;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Returns the index of the first element of a \list that satisfy a
/// predicate.
///
/// ### Usage
/// For any \list `l` and \lambda `lbd`
/// \code
///     using result = metal::find_if<l, lbd>;
/// \endcode
///
/// \pre: For any element `l[i]` contained in `l`,
/// `metal::invoke<lbd, l[i]>` returns a \number
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<i>;
///     \endcode
///     where `i` is such that `l[i]` is the first element in `l` for which
///     `metal::invoke<lbd, l[i]>{} != false`, otherwise
///     \code
///         using result = metal::size<l>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp find_if
///
/// ### See Also
/// \see list, find, all, any, none, count_if
template <class seq, class lbd>
using find_if = typename detail::_find_if<transform<lbd, seq>>::type;
}
#ifndef METAL_LIST_FRONT_HPP
#define METAL_LIST_FRONT_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Retrieves the first element of a \list.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::front<l>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = l[0];
///     \endcode
///
/// ### Example
/// \snippet list.cpp front
///
/// ### See Also
/// \see list, at, back
template <class seq>
using front = metal::at<seq, metal::number<0>>;
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class seq, class = indices<seq>>
    struct _find_index {
    };
    template <int_... vs, class... is>
    struct _find_index<list<number<vs>...>, list<is...>> {
        using type = front<call<join, if_<number<vs>, list<is>, list<>>...>>;
    };
    template <class seq>
    struct _find_if {
    };
    template <>
    struct _find_if<list<>> : number<0> {
    };
    template <int_... vs>
    struct _find_if<list<number<vs>...>>
        : _find_index<list<number<vs>..., true_>> {
    };
}
/// \endcond
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Returns the index of the first occurrence of a \value in a \list.
///
/// ### Usage
/// For any \list `l` and \value `val`
/// \code
///     using result = metal::find<l, val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<i>;
///     \endcode
///     where `i` is index of the first occurrence of `val` in `l`,
///     otherwise
///     \code
///         using result = metal::size<l>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp find
///
/// ### See Also
/// \see list, find_if, count, contains
template <class seq, class val>
using find = metal::find_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}
#endif
#ifndef METAL_LIST_FLATTEN_HPP
#define METAL_LIST_FLATTEN_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Collapses a \list of \lists into a flat \list that contains all the
/// elements of the inner \lists preserving their order.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::flatten<l>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::list<l[0][:], ...[:], l[n-1][:]>;
///     \endcode
///     where `l[:]` stands for the expansion of all elements contained in
///     `l`.
///
/// ### Example
/// \snippet list.cpp flatten
///
/// ### See Also
/// \see list, join
template <class seq>
using flatten = metal::apply<metal::lambda<metal::join>, seq>;
}
#endif
#ifndef METAL_LIST_INSERT_HPP
#define METAL_LIST_INSERT_HPP
#ifndef METAL_LIST_SPLICE_HPP
#define METAL_LIST_SPLICE_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Splices one \list into another at an arbitrary position.
///
/// ### Usage
/// For any \lists `l_1` and `l_2` and \number `num`
/// \code
///     using result = metal::splice<l_1, num, l_2>;
/// \endcode
///
/// \pre: `metal::number<0>{} &le; num{} &le; metal::size<l_1>{}`
/// \returns: \list
/// \semantics:
///     If `l_1` contains elements `l_1[0], ..., l_1[i], ..., l_1[m-1]`,
///     `l_2` contains elements `l_2[0], ..., l_2[n-1]` and `num{} == i`, then
///     \code
///         using result = metal::list<
///             l_1[0], ..., l_2[0], ..., l_2[n-1], l_1[i], ..., l_1[m-1]
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp splice
///
/// ### See Also
/// \see list, insert
template <class seq, class num, class other>
using splice = metal::join<metal::take<seq, num>, other, metal::drop<seq, num>>;
}
#endif
namespace metal {
/// \ingroup list
///
/// ### Description
/// Inserts a \value in a \list at an arbitrary position.
///
/// ### Usage
/// For any \list `l`, \number `num` and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::insert<l, num, val_0, ..., val_n-1>;
/// \endcode
///
/// \pre: `metal::number<0>{} &le; num{} &le; metal::size<l>{}`
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[i], ..., l[m-1]` and
///     `num{} == i`, then
///     \code
///         using result = metal::list<
///             l[0], ..., val_0, ..., val_n-1, l[i], ..., l[m-1]
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp insert
///
/// ### See Also
/// \see list, prepend, append, splice
template <class seq, class num, class... vals>
using insert = metal::splice<seq, num, metal::list<vals...>>;
}
#endif
#ifndef METAL_LIST_NONE_OF_HPP
#define METAL_LIST_NONE_OF_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Checks whether a predicate does not hold for any element of a \list.
///
/// ### Usage
/// For any \list `l` and \lambda `lbd`
/// \code
///     using result = metal::none_of<l, lbd>;
/// \endcode
///
/// \pre: For any element `l[i]` contained in `l`,
/// `metal::invoke<lbd, l[i]>` returns a \number
/// \returns: \number
/// \semantics:
///     If `metal::invoke<lbd, l[i]>{} == false` for all `l[i]` contained in
///     `l`, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet list.cpp none_of
///
/// ### See Also
/// \see list, all_of, any_of
template <class seq, class lbd>
using none_of = metal::not_<metal::any_of<seq, lbd>>;
}
#endif
#ifndef METAL_LIST_PARTITION_HPP
#define METAL_LIST_PARTITION_HPP
namespace metal {
/// \cond
namespace detail {
    template <class lbd>
    struct _partition;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Splits a \list in two according to a predicate.
///
/// ### Usage
/// For any \list `l` and \lambda `lbd`
/// \code
///     using result = metal::partition<l, lbd>;
/// \endcode
///
/// \pre: For any element `l[i]` contained in `l`,
/// `metal::invoke<lbd, l[i]>` returns a \number
/// \returns: \pair
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::pair<l_1, l_2>;
///     \endcode
///     where `l_1` contains all and only the elements `l[i]` in `l` for
///     which `metal::invoke<lbd, l[i]>{} != false` and `l_2` contains the
///     remaining elements.
///
/// ### Example
/// \snippet list.cpp partition
///
/// ### See Also
/// \see list, copy_if, remove_if
template <class seq, class lbd>
using partition = detail::call<detail::_partition<lbd>::template type, seq>;
}
#ifndef METAL_PAIR_PAIR_HPP
#define METAL_PAIR_PAIR_HPP
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_pair;
}
/// \endcond
/// \ingroup pair
///
/// ### Description
/// Checks whether some \value is a \pair.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::is_pair<val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `val` is a \pair, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet pair.cpp is_pair
///
/// ### See Also
/// \see pair, is_value, is_number, is_lambda, is_list, is_map
template <class val>
using is_pair = typename detail::_is_pair<val>::type;
/// \ingroup pair
///
/// ### Description
/// Constructs a \pair out of a pair of \values.
///
/// ### Usage
/// For any pair of \values `x` and `y`
/// \code
///     using result = metal::pair<x, y>;
/// \endcode
///
/// \returns: \pair
///
/// ### See Also
/// \see is_pair
template <class x, class y>
using pair = metal::list<x, y>;
/// \ingroup pair
///
/// ### Description
/// Constructs a \pair out of any \value that is a specialization of a
/// template class or union that takes exactly two template parameters that
/// are themselves \values.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::as_pair<val>;
/// \endcode
///
/// \returns: \pair
///
/// ### Example
/// \snippet pair.cpp as_pair
///
/// ### See Also
/// \see pair
template <class val>
using as_pair = metal::apply<metal::lambda<metal::pair>, metal::as_list<val>>;
}
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_pair : false_ {
    };
    template <class x, class y>
    struct _is_pair<list<x, y>> : true_ {
    };
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class...>
    struct _partition_joiner {
    };
    template <class... left, class... right>
    struct _partition_joiner<list<left, right>...> {
        using type = pair<join<left...>, join<right...>>;
    };
    template <bool cond>
    struct _partition_filter {
        template <class val>
        using type = list<list<val>, list<>>;
    };
    template <>
    struct _partition_filter<false> {
        template <class val>
        using type = list<list<>, list<val>>;
    };
    template <class conds, class seq>
    struct _partitioner {
    };
    template <int_... ns, class... vals>
    struct _partitioner<list<number<ns>...>, list<vals...>>
        : _partition_joiner<typename _partition_filter<ns>::template type<vals>...> {
    };
    template <class seq>
    struct _partition_impl {
    };
    template <>
    struct _partition_impl<list<>> {
        template <template <class...> class>
        using type = pair<list<>, list<>>;
    };
    template <class... vals>
    struct _partition_impl<list<vals...>> {
        template <template <class...> class expr>
        using type = typename _partitioner<list<expr<vals>...>, list<vals...>>::type;
    };
    template <class lbd>
    struct _partition {
    };
    template <template <class...> class expr>
    struct _partition<lambda<expr>> {
        template <class seq>
        using type = forward<_partition_impl<seq>::template type, expr>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_LIST_POWERSET_HPP
#define METAL_LIST_POWERSET_HPP
namespace metal {
/// \cond
namespace detail {
    template <class, class>
    struct _power;
    template <class seqs, class val>
    using power = typename _power<seqs, val>::type;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Computes the powerset of a \list.
///
/// ### Usage
/// For any \list `l`
/// \code
///     using result = metal::powerset<l>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::list<metal::list<l[2^m]>...>;
///     \endcode
///     where the notation `l[2^m]` stands for the expansion of all elements
///     in `l`, whose indices correspond to _1-bits_ of the number `2^m`
///     written in binary base and `metal::list<l[2^m]>...` stands for the
///     expansion for all numbers in `0...2^m`.
///
/// ### Example
/// \snippet list.cpp powerset
///
/// ### See Also
/// \see list, combine, cartesian, cascade
template <class seq>
using powerset = accumulate<lambda<detail::power>, list<list<>>, metal::reverse<seq>>;
}
namespace metal {
/// \cond
namespace detail {
    template <class, class>
    struct _power_impl {
    };
    template <class... xs, class y>
    struct _power_impl<list<xs...>, y> {
        using type = list<list<xs...>, list<y, xs...>>;
    };
    template <class xs, class y>
    using power_impl = typename _power_impl<xs, y>::type;
    template <class, class>
    struct _power {
    };
    template <class... seqs, class val>
    struct _power<list<seqs...>, val> {
        using type = join<power_impl<seqs, val>...>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_LIST_PREPEND_HPP
#define METAL_LIST_PREPEND_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Inserts \values at the beginning of a \list.
///
/// ### Usage
/// For any \list `l` and \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::prepend<l, val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `l` contains elements `l[0], ..., l[m-1]`, then
///     \code
///         using result = metal::list<
///             val_0, ..., val_n-1, l[0], ..., l[m-1]
///         >;
///     \endcode
///
/// ### Example
/// \snippet list.cpp prepend
///
/// ### See Also
/// \see list, insert, append
template <class seq, class... vals>
using prepend = metal::join<metal::list<vals...>, seq>;
}
#endif
#ifndef METAL_LIST_REMOVE_HPP
#define METAL_LIST_REMOVE_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Removes all elements from a \list that are the same as some \value.
///
/// ### Usage
/// For any \list `l` and \value `val`
/// \code
///     using result = metal::remove<l, val>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<...>;
///     \endcode
///     where `result` contains all and only the elements in `l` which are
///     distinct from `val`.
///
/// ### Example
/// \snippet list.cpp remove
///
/// ### See Also
/// \see list, remove_if, copy, replace
template <class seq, class val>
using remove = metal::remove_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}
#endif
#ifndef METAL_LIST_REPLACE_HPP
#define METAL_LIST_REPLACE_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Replaces every occurrence of a \value in a \list by another \value.
///
/// ### Usage
/// For any \list `l` and \values `val` and `val_0, ..., val_n-1`
/// \code
///     using result = metal::replace<l, val, val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<...>;
///     \endcode
///     where `result` contains all and only the elements in `l`, except
///     that every occurrence of `val` has been replaced by
///     `val_0, ..., val_n-1`.
///
/// ### Example
/// \snippet list.cpp replace
///
/// ### See Also
/// \see list, replace_if, copy, remove
template <class seq, class val, class... vals>
using replace = metal::replace_if<seq, metal::partial<metal::lambda<metal::same>, val>, vals...>;
}
#endif
#ifndef METAL_LIST_SLICE_HPP
#define METAL_LIST_SLICE_HPP
namespace metal {
/// \ingroup list
///
/// ### Description
/// Returns a subset of elements in a \list picked at regular intervals in a
/// range.
///
/// ### Usage
/// For any \list `l` and \numbers `st`, `sz` and `sd`
/// \code
///     using result = metal::slice<l, st, sz, sd>;
/// \endcode
///
/// \pre: `metal::number<0>{} &le; n{} &le; metal::size<l>{}` for all `n` in
/// `metal::iota<st, sz, sd>`
/// \returns: \list
/// \semantics:
///     If `metal::iota<st, sz, sd>` contains \numbers
///     `num_0, ..., num_n-1`, then
///     \code
///         using result = metal::list<l[num_0], ..., l[num_n-1]>;
///     \endcode
///
/// ### Example
/// \snippet list.cpp slice
///
/// ### See Also
/// \see list, range
template <class seq, class start, class size, class stride = number<1>>
using slice = metal::transform<
    metal::partial<metal::lambda<metal::at>, metal::if_<metal::is_list<seq>, seq>>,
    metal::iota<start, size, stride>>;
}
#endif
#ifndef METAL_LIST_SORT_HPP
#define METAL_LIST_SORT_HPP
namespace metal {
/// \cond
namespace detail {
    template <class lbd = metal::lambda<metal::less>>
    struct _sort;
}
/// \endcond
/// \ingroup list
///
/// ### Description
/// Sorts the elements of a \list according to an ordering relation.
///
/// \note{The sorting is [stable] if the ordering relation is [strict].}
/// [stable]: https://en.wikipedia.org/wiki/Sorting_algorithm#Stability
/// [strict]: https://en.wikipedia.org/wiki/Weak_ordering#Strict_weak_orderings
///
/// ### Usage
/// For any \list `l` and \lambda `lbd`
/// \code
///     using result = metal::sort<l, lbd>;
/// \endcode
///
/// \pre: For any two \values `val_i` and `val_j` contained in `l`
/// `metal::invoke<lbd, val_i, val_j>` returns a \number
/// \returns: \list
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::list<val_0, ..., val_m-1>;
///     \endcode
///     where `val_0, ..., val_m-1` is a permutation of the elements in `l`
///     such that `metal::invoke<lbd, val_i, val_i+1>{} != false` for all
///     `i` in `[0, m-2]`.
///
/// \tip{`lbd` may be omitted, in which case it defaults to `metal::lambda<metal::less>`.}
///
/// ### Example
/// \snippet list.cpp sort
///
/// ### See Also
/// \see list, reverse, rotate
#if !defined(METAL_WORKAROUND)
template <class seq, class lbd = metal::lambda<metal::less>>
using sort = detail::call<
    detail::_sort<lbd>::template type,
    metal::if_<metal::is_list<seq>, seq>>;
#else
// MSVC 14 has shabby SFINAE support in case of default alias template args
template <class seq, class... lbd>
using sort = detail::call<
    detail::_sort<lbd...>::template type,
    metal::if_<metal::is_list<seq>, seq>>;
#endif
}
#ifndef METAL_NUMBER_DIV_HPP
#define METAL_NUMBER_DIV_HPP
namespace metal {
/// \cond
namespace detail {
    template <class x, class y>
    struct _div;
    template <class x, class y>
    using div = typename _div<x, y>::type;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Computes the quotient of the arithmetic division of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::div<num_0, ..., num_n-1>;
/// \endcode
///
/// \pre: All \numbers in `num_1, ..., num_n-1` are nonzero
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num_0{} / ... / num_n-1{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp div
///
/// ### See Also
/// \see number, abs, inc, dec, neg, add, sub, mul, mod, pow
template <class... nums>
using div = fold_left<lambda<detail::div>, nums..., number<1>>;
/// \cond
namespace detail {
    template <class x, class y>
    struct _div {
    };
    template <int_ x>
    struct _div<number<x>, number<0>> {
    };
    template <int_ x, int_ y>
    struct _div<number<x>, number<y>> {
        using type = number<x / y>;
    };
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class x, class y, class z = list<>, class = true_>
    struct _merge;
    template <class, class, class, template <class...> class, class = true_>
    struct _merge_impl {
    };
    template <
        class xh, class... xt, class yh, class... yt, class... zs,
        template <class...> class e>
    struct _merge_impl<list<xh, xt...>, list<yh, yt...>, list<zs...>, e, if_<call<e, yh, xh>, true_, false_>>
        : _merge_impl<list<xh, xt...>, list<yt...>, list<zs..., yh>, e> {
    };
    template <
        class xh, class... xt, class yh, class... yt, class... zs,
        template <class...> class e>
    struct _merge_impl<list<xh, xt...>, list<yh, yt...>, list<zs...>, e, if_<call<e, yh, xh>, false_, true_>>
        : _merge_impl<list<xt...>, list<yh, yt...>, list<zs..., xh>, e> {
    };
    template <class... xs, class... zs, template <class...> class e>
    struct _merge_impl<list<xs...>, list<>, list<zs...>, e> {
        template <class x, class y>
        using part = typename _merge<prepend<x, xs...>, y, list<zs...>>::template type<e>;
        using type = list<zs..., xs...>;
    };
    template <class... ys, class... zs, template <class...> class e>
    struct _merge_impl<list<>, list<ys...>, list<zs...>, e> {
        template <class x, class y>
        using part = typename _merge<x, prepend<y, ys...>, list<zs...>>::template type<e>;
        using type = list<zs..., ys...>;
    };
    template <class x, class y, class z, class>
    struct _merge {
        using xe = size<x>;
        using ye = size<y>;
        using xm = div<inc<xe>, number<2>>;
        using ym = div<inc<ye>, number<2>>;
        using xl = range<x, number<0>, xm>;
        using yl = range<y, number<0>, ym>;
        using xr = range<x, xm, xe>;
        using yr = range<y, ym, ye>;
        using l = _merge<xl, yl, z>;
        template <template <class...> class expr>
        using type = typename l::template type<expr>::template part<xr, yr>;
    };
    template <class x, class y, class z>
    struct _merge<x, y, z, less<add<size<x>, size<y>>, number<100>>> {
        template <template <class...> class expr>
        using type = _merge_impl<x, y, z, expr>;
    };
    template <class seq>
    struct _sort_impl {
        using beg = number<0>;
        using end = size<seq>;
        using mid = div<end, number<2>>;
        using l = _sort_impl<range<seq, beg, mid>>;
        using r = _sort_impl<range<seq, mid, end>>;
        template <template <class...> class expr>
        using type = typename _merge<
            forward<l::template type, expr>,
            forward<r::template type, expr>>::template type<expr>::type;
    };
    template <class x, class y>
    struct _sort_impl<list<x, y>> {
        template <template <class...> class expr>
        using type = if_<expr<y, x>, list<y, x>, list<x, y>>;
    };
    template <class x>
    struct _sort_impl<list<x>> {
        template <template <class...> class>
        using type = list<x>;
    };
    template <>
    struct _sort_impl<list<>> {
        template <template <class...> class>
        using type = list<>;
    };
    template <class lbd>
    struct _sort {
    };
    template <template <class...> class expr>
    struct _sort<lambda<expr>> {
        template <class... seq>
        using type = forward<_sort_impl<seq...>::template type, expr>;
    };
}
/// \endcond
}
#endif
/// \defgroup list List
/// \ingroup metal
#endif
#ifndef METAL_MAP_HPP
#define METAL_MAP_HPP
#ifndef METAL_MAP_AT_KEY_HPP
#define METAL_MAP_AT_KEY_HPP
namespace metal {
/// \cond
namespace detail {
    template <class seq, class key>
    struct _at_key;
}
/// \endcond
/// \ingroup map
///
/// ### Description
/// Retrieves the value associated with some key in a \map.
///
/// ### Usage
/// For any \map `m` and \value `k`
/// \code
///     using result = metal::at_key<m, k>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `m` associates keys `k_1, ..., k, ..., k_n` to values
///     `v_1, ..., v, ..., v_n`, then
///     \code
///         using result = v;
///     \endcode
///
/// ### Example
/// \snippet map.cpp at_key
///
/// ### See Also
/// \see map, has_key, insert_key, erase_key
template <class seq, class key>
using at_key = typename detail::_at_key<seq, key>::type;
}
#ifndef METAL_VALUE_DISTINCT_HPP
#define METAL_VALUE_DISTINCT_HPP
namespace metal {
/// \cond
namespace detail {
    template <class... vals>
    struct _distinct;
}
/// \endcond
/// \ingroup value
///
/// ### Description
/// Checks whether no \values are identical.
///
/// ### Usage
/// For any \values `val_0, ..., val_n-1`
/// \code
///     using result = metal::distinct<val_0, ..., val_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If at least two \values in `val_0, ..., val_n-1` are identical to
///     each other, then
///     \code
///         using result = metal::false_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::true_;
///     \endcode
///
/// ### Example
/// \snippet value.cpp distinct
///
/// ### See Also
/// \see same
template <class... vals>
using distinct = typename detail::_distinct<vals...>::type;
}
namespace metal {
/// \cond
namespace detail {
    template <class, class base>
    struct inherit_second : base {
    };
    template <class, class...>
    struct inherit_impl {
    };
    template <class... _, class... bases>
    struct inherit_impl<list<_...>, bases...>
        : inherit_second<_, bases>... {
    };
    template <class... bases>
    struct inherit : inherit_impl<indices<list<bases...>>, bases...> {
    };
    template <class... bases>
    true_ disambiguate(bases*...);
    template <class derived, class... bases>
    auto _distinct_impl(derived* _) -> decltype(
        disambiguate<bases...>((declptr<bases>(), void(), _)...));
    template <class...>
    false_ _distinct_impl(...);
    template <class... vals>
    struct _distinct
        : decltype(
              _distinct_impl<inherit<maybe<vals>...>, maybe<vals>...>(0)) {
    };
}
/// \endcond
}
#endif
namespace metal {
/// \cond
namespace detail {
    template <class, class = true_>
    struct table {
    };
    template <class... keys, class... vals>
    struct table<list<list<keys, vals>...>, distinct<list<keys, vals>...>>
        : list<keys, vals>... {
    };
    template <>
    struct table<list<>> {
    };
    template <class key, class val>
    value<val> lookup(list<key, val>*);
    template <class>
    value<> lookup(...);
    template <class seq, class key>
    struct _at_key : decltype(lookup<key>(declptr<table<seq>>())) {
    };
}
/// \endcond
}
#endif
#ifndef METAL_MAP_ERASE_KEY_HPP
#define METAL_MAP_ERASE_KEY_HPP
#ifndef METAL_MAP_ORDER_HPP
#define METAL_MAP_ORDER_HPP
#ifndef METAL_MAP_KEYS_HPP
#define METAL_MAP_KEYS_HPP
#ifndef METAL_MAP_MAP_HPP
#define METAL_MAP_MAP_HPP
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_map;
}
/// \endcond
/// \ingroup map
///
/// ### Description
/// Checks whether some \value is a \map.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::is_map<val>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `val` is a \map, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet map.cpp is_map
///
/// ### See Also
/// \see map, is_value, is_number, is_lambda, is_pair, is_list
template <class val>
using is_map = typename detail::_is_map<val>::type;
/// \ingroup map
///
/// ### Description
/// Constructs a \map out of a sequence of \pairs.
///
/// ### Usage
/// For any \pairs `pair_0, ..., pair_n-1`
/// \code
///     using result = metal::map<pair_0, ..., pair_n-1>;
/// \endcode
///
/// \pre: No two \pairs have the same key
/// \returns: \map
///
/// ### See Also
/// \see is_map
template <class... pairs>
using map = metal::if_<metal::is_map<metal::list<pairs...>>, metal::list<pairs...>>;
/// \ingroup map
///
/// ### Description
/// Constructs a \map out of any \value that is a specialization of a
/// template class or union whose template parameters are all themselves
/// specializations of template classes or unions that take exactly two
/// template parameters, the first \values of which are all distinct.
///
/// ### Usage
/// For any \value `val`
/// \code
///     using result = metal::as_map<val>;
/// \endcode
///
/// \returns: \map
///
/// ### Example
/// \snippet map.cpp as_map
///
/// ### See Also
/// \see map
template <class val>
using as_map = metal::apply<
    metal::lambda<metal::map>,
    metal::transform<metal::lambda<metal::as_pair>, metal::as_list<val>>>;
}
namespace metal {
/// \cond
namespace detail {
    template <class val>
    struct _is_map : false_ {
    };
    template <>
    struct _is_map<list<>> : true_ {
    };
    template <class... keys, class... vals>
    struct _is_map<list<list<keys, vals>...>> : distinct<keys...> {
    };
}
/// \endcond
}
#endif
#ifndef METAL_PAIR_FIRST_HPP
#define METAL_PAIR_FIRST_HPP
namespace metal {
/// \ingroup pair
///
/// ### Description
/// Retrieves the first element of a \pair.
///
/// ### Usage
/// For any \pair `p`
/// \code
///     using result = metal::first<p>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `p` contains \values `p_0` and `p_1` in that order, then
///     \code
///         using result = p_0;
///     \endcode
///
/// ### Example
/// \snippet pair.cpp first
///
/// ### See Also
/// \see pair, second
template <class seq>
using first = metal::if_<metal::is_pair<seq>, metal::front<seq>>;
}
#endif
namespace metal {
/// \ingroup map
///
/// ### Description
/// Returns a \list of keys contained in a \map.
///
/// ### Usage
/// For any \map `m`
/// \code
///     using result = metal::keys<m>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `m` associates keys `k_1, ..., k_n` to values `v_1, ..., v_n`,
///     then
///     \code
///         using result = metal::list<k_1, ..., k_n>;
///     \endcode
///
/// ### Example
/// \snippet map.cpp keys
///
/// ### See Also
/// \see map, values
template <class seq>
using keys = metal::if_<metal::is_map<seq>, metal::transform<metal::lambda<metal::first>, seq>>;
}
#endif
namespace metal {
/// \ingroup map
///
/// ### Description
/// Returns the index of a key in a \map.
///
/// ### Usage
/// For any \map `m` and \value `k`
/// \code
///     using result = metal::order<m, k>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `m` contains an entry with key `k` at index `idx`, then
///     \code
///         using result = idx;
///     \endcode
///
/// ### Example
/// \snippet map.cpp order
///
/// ### See Also
/// \see map
template <class seq, class key>
using order = metal::at_key<metal::transpose<metal::pair<metal::keys<seq>, metal::indices<seq>>>, key>;
}
#endif
namespace metal {
/// \ingroup map
///
/// ### Description
/// Removes the entry associated with some key in a \map.
///
/// ### Usage
/// For any \map `m` and \value `k`
/// \code
///     using result = metal::erase_key<m, k>;
/// \endcode
///
/// \returns: \map
/// \semantics:
///     If `m` associates keys `k_1, ..., k, ..., k_n` to values
///     `v_1, ..., v, ..., v_n`, then
///     \code
///         using result = metal::map<
///             metal::pair<k_1, v_1>, ..., metal::pair<k_n, v_n>
///         >;
///     \endcode
///
/// ### Example
/// \snippet map.cpp erase_key
///
/// ### See Also
/// \see map, has_key, at_key, insert_key
template <class seq, class key>
using erase_key = metal::erase<seq, metal::order<seq, key>>;
}
#endif
#ifndef METAL_MAP_HAS_KEY_HPP
#define METAL_MAP_HAS_KEY_HPP
namespace metal {
/// \ingroup map
///
/// ### Description
/// Checks whether a \map contains an entry with some key.
///
/// ### Usage
/// For any \map `m` and \value `k`
/// \code
///     using result = metal::has_key<m, k>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     If `m` contains an entry with key `k`, then
///     \code
///         using result = metal::true_;
///     \endcode
///     otherwise
///     \code
///         using result = metal::false_;
///     \endcode
///
/// ### Example
/// \snippet map.cpp has_key
///
/// ### See Also
/// \see map, at_key, insert_key, erase_key
template <class seq, class key>
using has_key = metal::contains<metal::keys<seq>, key>;
}
#endif
#ifndef METAL_MAP_INSERT_KEY_HPP
#define METAL_MAP_INSERT_KEY_HPP
namespace metal {
/// \ingroup map
///
/// ### Description
/// Inserts a new entry in a \map.
///
/// ### Usage
/// For any \map `m` and \values `k` and `v`
/// \code
///     using result = metal::erase_key<m, k, v>;
/// \endcode
///
/// \pre: `k` is not contained in `metal::keys<m>`
/// \returns: \map
/// \semantics:
///     If `m` associates keys `k_1, ..., k_n` to values `v_1, ..., v_n`,
///     then
///     \code
///         using result = metal::map<
///             metal::pair<k_1, v_1>,
///             ...,
///             metal::pair<k_n, v_n>,
///             metal::pair<k, v>
///         >;
///     \endcode
///
/// ### Example
/// \snippet map.cpp insert_key
///
/// ### See Also
/// \see map, has_key, at_key, erase_key
template <class seq, class key, class val>
using insert_key = metal::if_<
    metal::not_<metal::has_key<seq, key>>,
    metal::append<seq, metal::pair<key, val>>>;
}
#endif
#ifndef METAL_MAP_VALUES_HPP
#define METAL_MAP_VALUES_HPP
#ifndef METAL_PAIR_SECOND_HPP
#define METAL_PAIR_SECOND_HPP
namespace metal {
/// \ingroup pair
///
/// ### Description
/// Retrieves the second element of a \pair.
///
/// ### Usage
/// For any \pair `p`
/// \code
///     using result = metal::second<p>;
/// \endcode
///
/// \returns: \value
/// \semantics:
///     If `p` contains \values `p_0` and `p_1` in that order, then
///     \code
///         using result = p_1;
///     \endcode
///
/// ### Example
/// \snippet pair.cpp second
///
/// ### See Also
/// \see pair, first
template <class seq>
using second = metal::if_<metal::is_pair<seq>, metal::back<seq>>;
}
#endif
namespace metal {
/// \ingroup map
///
/// ### Description
/// Returns a \list of values contained in a \map.
///
/// ### Usage
/// For any \map `m`
/// \code
///     using result = metal::values<m>;
/// \endcode
///
/// \returns: \list
/// \semantics:
///     If `m` associates keys `k_1, ..., k_n` to values `v_1, ..., v_n`,
///     then
///     \code
///         using result = metal::list<v_1, ..., v_n>;
///     \endcode
///
/// ### Example
/// \snippet map.cpp values
///
/// ### See Also
/// \see map, keys
template <class seq>
using values = metal::if_<metal::is_map<seq>, metal::transform<metal::lambda<metal::second>, seq>>;
}
#endif
/// \defgroup map Map
/// \ingroup metal
#endif
#ifndef METAL_NUMBER_HPP
#define METAL_NUMBER_HPP
#ifndef METAL_NUMBER_ABS_HPP
#define METAL_NUMBER_ABS_HPP
#ifndef METAL_NUMBER_NEG_HPP
#define METAL_NUMBER_NEG_HPP
namespace metal {
/// \ingroup number
///
/// ### Description
/// Computes the additive inverse of a \number.
///
/// ### Usage
/// For any \number `num`
/// \code
///     using result = metal::neg<num>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<-num{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp neg
///
/// ### See Also
/// \see number, abs, inc, dec, add, sub, mul, div, mod, pow
template <class num>
using neg = metal::sub<metal::number<0>, num>;
}
#endif
namespace metal {
/// \ingroup number
///
/// ### Description
/// Computes absolute value of a \number.
///
/// ### Usage
/// For any \number `num`
/// \code
///     using result = metal::abs<num>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<(num{} > 0) ? num{} : -num{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp abs
///
/// ### See Also
/// \see number, inc, dec, neg, add, sub, mul, div, mod, pow
template <class num>
using abs = metal::max<num, metal::neg<num>>;
}
#endif
#ifndef METAL_NUMBER_MOD_HPP
#define METAL_NUMBER_MOD_HPP
namespace metal {
/// \cond
namespace detail {
    template <class x, class y>
    struct _mod;
    template <class x, class y>
    using mod = typename _mod<x, y>::type;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Computes the remainder of the arithmetic division of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::mod<num_0, ..., num_n-1>;
/// \endcode
///
/// \pre: All \numbers in `num_1, ..., num_n-1` are nonzero
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num_0{} % ... % num_n-1{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp mod
///
/// ### See Also
/// \see number, abs, inc, dec, neg, add, sub, mul, div, pow
template <class... nums>
using mod = fold_left<lambda<detail::mod>, if_<is_number<nums>, nums>...>;
/// \cond
namespace detail {
    template <class x, class y>
    struct _mod {
    };
    template <int_ x>
    struct _mod<number<x>, number<0>> {
    };
    template <int_ x, int_ y>
    struct _mod<number<x>, number<y>> {
        using type = number<x % y>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_NUMBER_MUL_HPP
#define METAL_NUMBER_MUL_HPP
namespace metal {
/// \cond
namespace detail {
    template <class x, class y>
    struct _mul;
    template <class x, class y>
    using mul = typename _mul<x, y>::type;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Computes the arithmetic multiplication of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::mul<num_0, ..., num_n-1>;
/// \endcode
///
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num_0{} * ... * num_n-1{}>;
///     \endcode
///
/// ### Example
/// \snippet number.cpp mul
///
/// ### See Also
/// \see number, abs, inc, dec, neg, add, sub, div, mod, pow
template <class... nums>
using mul = fold_left<lambda<detail::mul>, nums..., number<1>>;
/// \cond
namespace detail {
    template <class x, class y>
    struct _mul {
    };
    template <int_ x, int_ y>
    struct _mul<number<x>, number<y>> {
        using type = number<x * y>;
    };
}
/// \endcond
}
#endif
#ifndef METAL_NUMBER_POW_HPP
#define METAL_NUMBER_POW_HPP
namespace metal {
/// \cond
namespace detail {
    template <class base, class exp, class ret = number<1>>
    struct _pow;
    template <class base, class exp>
    using pow = typename _pow<base, exp>::type;
}
/// \endcond
/// \ingroup number
///
/// ### Description
/// Computes the arithmetic exponentiation of \numbers.
///
/// ### Usage
/// For any \numbers `num_0, ..., num_n-1`
/// \code
///     using result = metal::pow<num_0, ..., num_n-1>;
/// \endcode
///
/// \pre: `metal::pow<num_0, ..., num_m-1> != metal::number<0>` for all
/// negative `num_m`
/// \returns: \number
/// \semantics:
///     Equivalent to
///     \code
///         using result = metal::number<num_0{} ** ... ** num_n-1{}>;
///     \endcode
///     Where `x**y` stands for `x` raised to the power of `y`
///     \warning{
///         `x**y` is always null for `y < 0` and `|x| > 1`
///         due to inherent limitations of integer arithmetic.
///     }
///
/// ### Example
/// \snippet number.cpp pow
///
/// ### See Also
/// \see number, abs, inc, dec, neg, add, sub, mul, div, mod
template <class... nums>
using pow = fold_left<lambda<detail::pow>, nums..., number<1>>;
/// \cond
namespace detail {
    template <class base, class exp, class ret>
    struct _pow {
    };
    template <int_ b, int_ e, int_ r>
    struct _pow<number<b>, number<e>, number<r>>
        : _pow<number<b * b>, number<e / 2>, number<(e % 2 ? b * r : r)>> {
    };
    template <int_ b, int_ r>
    struct _pow<number<b>, number<0>, number<r>> : number<1> {
    };
    template <int_ b, int_ r>
    struct _pow<number<b>, number<1>, number<r>> : number<b * r> {
    };
    template <int_ b, int_ r>
    struct _pow<number<b>, number<-1>, number<r>> : number<1 / (b * r)> {
    };
    template <int_ r>
    struct _pow<number<0>, number<-1>, number<r>> {
    };
}
/// \endcond
}
#endif
/// \defgroup number Number
/// \ingroup metal
#endif
#ifndef METAL_PAIR_HPP
#define METAL_PAIR_HPP
/// \defgroup pair Pair
/// \ingroup metal
#endif
#ifndef METAL_VALUE_HPP
#define METAL_VALUE_HPP
/// \defgroup value Value
/// \ingroup metal
#endif
/// \defgroup metal Metal
/// \namespace metal
/// \brief Metal
#endif
