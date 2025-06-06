// { dg-require-namedlocale "is_IS.ISO8859-1" }
// { dg-require-namedlocale "en_US.ISO8859-1" }

// 2004-02-09  Petur Runolfsson  <peturr02@ru.is>

// Copyright (C) 2004-2025 Free Software Foundation, Inc.
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

// 22.1.1.5 locale static members [lib.locale.statics]

#include <locale>
#include <clocale>
#include <testsuite_hooks.h>

// libstdc++/14071
void test01()
{
  using namespace std;

  const locale loc_is = locale(ISO_8859(1,is_IS));
  const locale loc_en = locale(ISO_8859(1,en_US));

  const locale loc(loc_is, loc_en, locale::monetary);

  if (loc.name() != "*")
    {
      locale::global(loc);
      VERIFY( loc.name() == setlocale(LC_ALL, 0) );
    }
}

int main()
{
  test01();
  return 0;
}
