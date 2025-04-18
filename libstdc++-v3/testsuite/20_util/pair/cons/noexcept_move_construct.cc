// { dg-do compile { target c++11 } }

// 2011-05-20  Paolo Carlini  <paolo.carlini@oracle.com>
//
// Copyright (C) 2011-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <utility>
#include <testsuite_tr1.h>

using namespace __gnu_test;

typedef std::pair<int, int>                                 tt1;
typedef std::pair<int, double>                              tt2;
typedef std::pair<NoexceptMoveConsClass,
		  NoexceptMoveConsClass>                    tt3;
typedef std::pair<ExceptMoveConsClass, ExceptMoveConsClass> tt4;
typedef std::pair<ExceptMoveConsClass, double>              tt5;
typedef std::pair<NoexceptMoveConsClass,
		  ExceptMoveConsClass>                      tt6;

static_assert(std::is_nothrow_move_constructible<tt1>::value, "Error");
static_assert(std::is_nothrow_move_constructible<tt2>::value, "Error");
static_assert(std::is_nothrow_move_constructible<tt3>::value, "Error");
static_assert(!std::is_nothrow_move_constructible<tt4>::value, "Error");
static_assert(!std::is_nothrow_move_constructible<tt5>::value, "Error");
static_assert(!std::is_nothrow_move_constructible<tt6>::value, "Error");
