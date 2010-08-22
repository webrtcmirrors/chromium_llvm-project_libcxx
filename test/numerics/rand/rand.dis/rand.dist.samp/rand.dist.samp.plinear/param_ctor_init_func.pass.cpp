//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class piecewise_linear_distribution

// param_type(initializer_list<result_type> bl, UnaryOperation fw);

#include <random>
#include <cassert>

double f(double x)
{
    return x*2;
}

int main()
{
#ifdef _LIBCPP_MOVE
    {
        typedef std::piecewise_linear_distribution<> D;
        typedef D::param_type P;
        P pa({}, f);
        std::vector<double> iv = pa.intervals();
        assert(iv.size() == 2);
        assert(iv[0] == 0);
        assert(iv[1] == 1);
        std::vector<double> dn = pa.densities();
        assert(dn.size() == 2);
        assert(dn[0] == 1);
        assert(dn[1] == 1);
    }
    {
        typedef std::piecewise_linear_distribution<> D;
        typedef D::param_type P;
        P pa({12}, f);
        std::vector<double> iv = pa.intervals();
        assert(iv.size() == 2);
        assert(iv[0] == 0);
        assert(iv[1] == 1);
        std::vector<double> dn = pa.densities();
        assert(dn.size() == 2);
        assert(dn[0] == 1);
        assert(dn[1] == 1);
    }
    {
        typedef std::piecewise_linear_distribution<> D;
        typedef D::param_type P;
        P pa({10, 12}, f);
        std::vector<double> iv = pa.intervals();
        assert(iv.size() == 2);
        assert(iv[0] == 10);
        assert(iv[1] == 12);
        std::vector<double> dn = pa.densities();
        assert(dn.size() == 2);
        assert(dn[0] == 20./44);
        assert(dn[1] == 24./44);
    }
    {
        typedef std::piecewise_linear_distribution<> D;
        typedef D::param_type P;
        P pa({6, 10, 14}, f);
        std::vector<double> iv = pa.intervals();
        assert(iv.size() == 3);
        assert(iv[0] == 6);
        assert(iv[1] == 10);
        assert(iv[2] == 14);
        std::vector<double> dn = pa.densities();
        assert(dn.size() == 3);
        assert(dn[0] == 0.075);
        assert(dn[1] == 0.125);
        assert(dn[2] == 0.175);
    }
#endif  // _LIBCPP_MOVE
}
