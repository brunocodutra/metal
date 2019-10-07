#ifndef METAL_LIST_CASCADE_HPP
#define METAL_LIST_CASCADE_HPP

#include "../config.hpp"
#include "../lambda/apply.hpp"
#include "../lambda/lambda.hpp"
#include "../value/fold_right.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class outer, class inner>
        struct _cascader;

        template<class outer, class inner>
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
    template<class seq, class... lbds>
    using cascade = apply<fold_right<lambda<detail::cascader>, lbds...>, seq>;
}

#include "../lambda/invoke.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class outer, class inner>
        struct _cascader {};

        template<
            template<class...> class outer,
            template<class...> class inner>
        struct _cascader<lambda<outer>, lambda<inner>> {
            template<class... seqs>
            using impl = invoke<lambda<outer>, apply<lambda<inner>, seqs>...>;

            using type = lambda<impl>;
        };
    }
    /// \endcond
}

#endif
