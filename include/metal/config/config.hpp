#ifndef METAL_CONFIG_CONFIG_HPP
#define METAL_CONFIG_CONFIG_HPP

#if !defined(METAL_WORKAROUND)
#if(defined(__GNUC__) && !defined(__clang__) && (__GNUC__ < 5)) \
    || (defined(_MSC_VER) && !defined(__clang__))
#define METAL_WORKAROUND
#endif
#endif

#endif
