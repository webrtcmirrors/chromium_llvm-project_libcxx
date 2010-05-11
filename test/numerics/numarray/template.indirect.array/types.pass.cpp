//===----------------------------------------------------------------------===//
//
// ΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚΚThe LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <valarray>

// template <class T>
// class indirect_array
// {
// public:
//     typedef T value_type;

#include <valarray>
#include <type_traits>

int main()
{
    static_assert((std::is_same<std::indirect_array<int>::value_type, int>::value), "");
}
