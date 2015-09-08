// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_PREPROCESSOR_HPP
#define METAL_TEST_PREPROCESSOR_HPP

#define LIMIT 10

#define ID_(...) __VA_ARGS__
#define ID(...) ID_(__VA_ARGS__)

#define CAT_(X, Y) X##Y
#define CAT(X, Y) CAT_(X, Y)

#define SIZEOF_(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, SIZE, ...) SIZE
#define SIZEOF(...) ID(SIZEOF_(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define INC_0() 1
#define INC_1() 2
#define INC_2() 3
#define INC_3() 4
#define INC_4() 5
#define INC_5() 6
#define INC_6() 7
#define INC_7() 8
#define INC_8() 9
#define INC_9() 10

#define INC(N) CAT(INC_, N)()

#define DEC_1()  0
#define DEC_2()  1
#define DEC_3()  2
#define DEC_4()  3
#define DEC_5()  4
#define DEC_6()  5
#define DEC_7()  6
#define DEC_8()  7
#define DEC_9()  8
#define DEC_10() 9

#define DEC(N) CAT(DEC_, N)()

#define NOT_0()  1
#define NOT_1()  0
#define NOT_2()  0
#define NOT_3()  0
#define NOT_4()  0
#define NOT_5()  0
#define NOT_6()  0
#define NOT_7()  0
#define NOT_8()  0
#define NOT_9()  0
#define NOT_10() 0

#define NOT(N) CAT(NOT_, N)()

#define AND_00() 0
#define AND_01() 0
#define AND_10() 0
#define AND_11() 1

#define AND(M, N) CAT(CAT(AND_, NOT(NOT(M))), NOT(NOT(N)))()

#define OR(M, N) NOT(AND(NOT(M), NOT(N)))

#define COMMA_0()
#define COMMA_1()  ,

#define COMMA(N) CAT(COMMA_, NOT(NOT(N)))()

#define BAR0
#define BAR1
#define BAR2
#define BAR3
#define BAR4
#define BAR5
#define BAR6
#define BAR7
#define BAR8
#define BAR9

#define SUFFIX_0(S)
#define SUFFIX_1(S,  _0) ID(CAT(_0, S))
#define SUFFIX_2(S,  _0, _1) SUFFIX_1(S, _0), ID(CAT(_1, S))
#define SUFFIX_3(S,  _0, _1, _2) SUFFIX_2(S, _0, _1), ID(CAT(_2, S))
#define SUFFIX_4(S,  _0, _1, _2, _3) SUFFIX_3(S, _0, _1, _2), ID(CAT(_3, S))
#define SUFFIX_5(S,  _0, _1, _2, _3, _4) SUFFIX_4(S, _0, _1, _2, _3), ID(CAT(_4, S))
#define SUFFIX_6(S,  _0, _1, _2, _3, _4, _5) SUFFIX_5(S, _0, _1, _2, _3, _4), ID(CAT(_5, S))
#define SUFFIX_7(S,  _0, _1, _2, _3, _4, _5, _6) SUFFIX_6(S, _0, _1, _2, _3, _4, _5), ID(CAT(_6, S))
#define SUFFIX_8(S,  _0, _1, _2, _3, _4, _5, _6, _7) SUFFIX_7(S, _0, _1, _2, _3, _4, _5, _6), ID(CAT(_7, S))
#define SUFFIX_9(S,  _0, _1, _2, _3, _4, _5, _6, _7, _8) SUFFIX_8(S, _0, _1, _2, _3, _4, _5, _6, _7), ID(CAT(_8, S))
#define SUFFIX_10(S,  _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) SUFFIX_9(S, _0, _1, _2, _3, _4, _5, _6, _7, _8), ID(CAT(_9, S))

#define SUFFIX(S, ...) ID(CAT(SUFFIX_, SIZEOF(__VA_ARGS__))(S, __VA_ARGS__))

#define ENUM_0(...)
#define ENUM_1(...)  SUFFIX(0, __VA_ARGS__)
#define ENUM_2(...)  ENUM_1(__VA_ARGS__), SUFFIX(1, __VA_ARGS__)
#define ENUM_3(...)  ENUM_2(__VA_ARGS__), SUFFIX(2, __VA_ARGS__)
#define ENUM_4(...)  ENUM_3(__VA_ARGS__), SUFFIX(3, __VA_ARGS__)
#define ENUM_5(...)  ENUM_4(__VA_ARGS__), SUFFIX(4, __VA_ARGS__)
#define ENUM_6(...)  ENUM_5(__VA_ARGS__), SUFFIX(5, __VA_ARGS__)
#define ENUM_7(...)  ENUM_6(__VA_ARGS__), SUFFIX(6, __VA_ARGS__)
#define ENUM_8(...)  ENUM_7(__VA_ARGS__), SUFFIX(7, __VA_ARGS__)
#define ENUM_9(...)  ENUM_8(__VA_ARGS__), SUFFIX(8, __VA_ARGS__)
#define ENUM_10(...) ENUM_9(__VA_ARGS__), SUFFIX(9, __VA_ARGS__)

#define ENUM(N, ...) CAT(ENUM_, N)(__VA_ARGS__)

#define FORWARD_0  (0)
#define FORWARD_1  (1)
#define FORWARD_2  (2)
#define FORWARD_3  (3)
#define FORWARD_4  (4)
#define FORWARD_5  (5)
#define FORWARD_6  (6)
#define FORWARD_7  (7)
#define FORWARD_8  (8)
#define FORWARD_9  (9)
#define FORWARD_10 (10)

#define FORWARD_(M) M FORWARD_
#define FORWARD(M) FORWARD_(M)

#define EXPAND_I0(I, _)
#define EXPAND_I1(I, _)  _(I, 0)
#define EXPAND_I2(I, _)  EXPAND_I1(I, _) _(I, 1)
#define EXPAND_I3(I, _)  EXPAND_I2(I, _) _(I, 2)
#define EXPAND_I4(I, _)  EXPAND_I3(I, _) _(I, 3)
#define EXPAND_I5(I, _)  EXPAND_I4(I, _) _(I, 4)
#define EXPAND_I6(I, _)  EXPAND_I5(I, _) _(I, 5)
#define EXPAND_I7(I, _)  EXPAND_I6(I, _) _(I, 6)
#define EXPAND_I8(I, _)  EXPAND_I7(I, _) _(I, 7)
#define EXPAND_I9(I, _)  EXPAND_I8(I, _) _(I, 8)
#define EXPAND_I10(I, _) EXPAND_I9(I, _) _(I, 9)

#define EXPAND_0J(J, _)
#define EXPAND_1J(J, _)  CAT(EXPAND_I, J)(0, _)
#define EXPAND_2J(J, _)  EXPAND_1J(J, _) CAT(EXPAND_I, J)(1, _)
#define EXPAND_3J(J, _)  EXPAND_2J(J, _) CAT(EXPAND_I, J)(2, _)
#define EXPAND_4J(J, _)  EXPAND_3J(J, _) CAT(EXPAND_I, J)(3, _)
#define EXPAND_5J(J, _)  EXPAND_4J(J, _) CAT(EXPAND_I, J)(4, _)
#define EXPAND_6J(J, _)  EXPAND_5J(J, _) CAT(EXPAND_I, J)(5, _)
#define EXPAND_7J(J, _)  EXPAND_6J(J, _) CAT(EXPAND_I, J)(6, _)
#define EXPAND_8J(J, _)  EXPAND_7J(J, _) CAT(EXPAND_I, J)(7, _)
#define EXPAND_9J(J, _)  EXPAND_8J(J, _) CAT(EXPAND_I, J)(8, _)
#define EXPAND_10J(J, _) EXPAND_9J(J, _) CAT(EXPAND_I, J)(9, _)

#define EXPAND(M, N, MATRIX) CAT(CAT(EXPAND_, M), J)(N, MATRIX)

#define GEN(MATRIX) EXPAND(LIMIT, LIMIT, MATRIX)

#endif
