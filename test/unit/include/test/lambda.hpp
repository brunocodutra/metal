#ifndef METAL_TEST_LAMBDA_HPP
#define METAL_TEST_LAMBDA_HPP

#include "test/expressions.hpp"
#include "test/preprocessor.hpp"

#define LAMBDA(...) metal::lambda<EXPR(__VA_ARGS__)>
#define LAMBDAS(N) ENUM(N, LAMBDA)

#endif
