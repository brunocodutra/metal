// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_PREPROCESSOR_HPP
#define METAL_TEST_PREPROCESSOR_HPP

#define _limit 10

#define _strip(...) __VA_ARGS__

#define _cat_(X, Y) X##Y
#define _cat(X, Y) _cat_(X, Y)

#define _inc_0() 1
#define _inc_1() 2
#define _inc_2() 3
#define _inc_3() 4
#define _inc_4() 5
#define _inc_5() 6
#define _inc_6() 7
#define _inc_7() 8
#define _inc_8() 9
#define _inc_9() 10

#define _inc_(N) _inc_##N()
#define _inc(N) _inc_(N)

#define _dec_1()  0
#define _dec_2()  1
#define _dec_3()  2
#define _dec_4()  3
#define _dec_5()  4
#define _dec_6()  5
#define _dec_7()  6
#define _dec_8()  7
#define _dec_9()  8
#define _dec_10() 9

#define _dec_(N) _dec_##N()
#define _dec(N) _dec_(N)

#define _comma_0()
#define _comma_1()  ,
#define _comma_2()  ,
#define _comma_3()  ,
#define _comma_4()  ,
#define _comma_5()  ,
#define _comma_6()  ,
#define _comma_7()  ,
#define _comma_8()  ,
#define _comma_9()  ,
#define _comma_10() ,

#define _comma_(N) _comma_##N()
#define _comma(N) _comma_(N)

#define _enum_0(PREFIX)
#define _enum_1(PREFIX)  PREFIX##0
#define _enum_2(PREFIX)  _enum_1(PREFIX), PREFIX##1
#define _enum_3(PREFIX)  _enum_2(PREFIX), PREFIX##2
#define _enum_4(PREFIX)  _enum_3(PREFIX), PREFIX##3
#define _enum_5(PREFIX)  _enum_4(PREFIX), PREFIX##4
#define _enum_6(PREFIX)  _enum_5(PREFIX), PREFIX##5
#define _enum_7(PREFIX)  _enum_6(PREFIX), PREFIX##6
#define _enum_8(PREFIX)  _enum_7(PREFIX), PREFIX##7
#define _enum_9(PREFIX)  _enum_8(PREFIX), PREFIX##8
#define _enum_10(PREFIX) _enum_9(PREFIX), PREFIX##9

#define _enum_(N, PREFIX) _enum_##N(PREFIX)
#define _enum(N, PREFIX) _enum_(N, PREFIX)

#define _bar0
#define _bar1
#define _bar2
#define _bar3
#define _bar4
#define _bar5
#define _bar6
#define _bar7
#define _bar8
#define _bar9

#define _cartesian_I0(I, _)
#define _cartesian_I1(I, _)  _(I, 0)
#define _cartesian_I2(I, _)  _cartesian_I1(I, _) _(I, 1)
#define _cartesian_I3(I, _)  _cartesian_I2(I, _) _(I, 2)
#define _cartesian_I4(I, _)  _cartesian_I3(I, _) _(I, 3)
#define _cartesian_I5(I, _)  _cartesian_I4(I, _) _(I, 4)
#define _cartesian_I6(I, _)  _cartesian_I5(I, _) _(I, 5)
#define _cartesian_I7(I, _)  _cartesian_I6(I, _) _(I, 6)
#define _cartesian_I8(I, _)  _cartesian_I7(I, _) _(I, 7)
#define _cartesian_I9(I, _)  _cartesian_I8(I, _) _(I, 8)
#define _cartesian_I10(I, _) _cartesian_I9(I, _) _(I, 9)

#define _cartesian_0J(J, _)
#define _cartesian_1J(J, _)  _cartesian_I##J(0, _)
#define _cartesian_2J(J, _)  _cartesian_1J(J, _) _cartesian_I##J(1, _)
#define _cartesian_3J(J, _)  _cartesian_2J(J, _) _cartesian_I##J(2, _)
#define _cartesian_4J(J, _)  _cartesian_3J(J, _) _cartesian_I##J(3, _)
#define _cartesian_5J(J, _)  _cartesian_4J(J, _) _cartesian_I##J(4, _)
#define _cartesian_6J(J, _)  _cartesian_5J(J, _) _cartesian_I##J(5, _)
#define _cartesian_7J(J, _)  _cartesian_6J(J, _) _cartesian_I##J(6, _)
#define _cartesian_8J(J, _)  _cartesian_7J(J, _) _cartesian_I##J(7, _)
#define _cartesian_9J(J, _)  _cartesian_8J(J, _) _cartesian_I##J(8, _)
#define _cartesian_10J(J, _) _cartesian_9J(J, _) _cartesian_I##J(9, _)

#define _cartesian_(M, N, _) _cartesian_##M##J(N, _)
#define _cartesian(M, N, _) _cartesian_(M, N, _)

#define _gen(_) _cartesian(_limit, _limit, _)

#endif
