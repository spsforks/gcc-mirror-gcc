// { dg-do run { target c++17 } }

// Copyright (C) 2014-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// 8.4.9 path decomposition [path.decompose]

#include <filesystem>
#include <vector>
#include <testsuite_hooks.h>
#include <testsuite_fs.h>

using std::filesystem::path;

void
test01()
{
  VERIFY( path("/foo/bar.txt").stem() == path("bar") );
  path p = "foo.bar.baz.tar";
  std::vector<std::string> v;
  for (; !p.extension().empty(); p = p.stem())
    v.push_back(p.extension().string());
  VERIFY( v.at(0) == ".tar" );
  VERIFY( v.at(1) == ".baz" );
  VERIFY( v.at(2) == ".bar" );

  VERIFY( path(".profile").stem() == path(".profile") );
  VERIFY( path(".profile.old").stem() == path(".profile") );
  VERIFY( path("..abc").stem() == path(".") );
  VERIFY( path("...abc").stem() == path("..") );
  VERIFY( path("abc..def").stem() == path("abc.") );
  VERIFY( path("abc...def").stem() == path("abc..") );
  VERIFY( path("abc.").stem() == path("abc") );
  VERIFY( path("abc..").stem() == path("abc.") );
  VERIFY( path("abc.d.").stem() == path("abc.d") );
  VERIFY( path("..").stem() == path("..") );
  VERIFY( path(".").stem() == path(".") );

  VERIFY( path().stem() == path() );
}

int
main()
{
  test01();
}
