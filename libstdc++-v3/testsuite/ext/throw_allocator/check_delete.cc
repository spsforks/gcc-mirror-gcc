//
// Copyright (C) 2007-2025 Free Software Foundation, Inc.
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

// { dg-require-time "" }
// { dg-require-cstdint "" }
// { dg-require-effective-target std_allocator_new }

#include <cstdlib>
#include <ext/throw_allocator.h>
#include <replacement_memory_operators.h>

int main()
{ 
  typedef __gnu_cxx::throw_allocator_random<unsigned int> allocator_type;
  __gnu_test::check_delete<allocator_type, true>(); 
  return 0;
}
