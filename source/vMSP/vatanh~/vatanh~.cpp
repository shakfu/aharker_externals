
/*
 *  vatanh~
 *
 *  vatanh~ is a vectorised version of atanh~.
 *
 *  Copyright 2010-22 Alex Harker. All rights reserved.
 *
 */


#include "v_unary.hpp"
#include "vector_loop.hpp"
#include <SIMDExtended.hpp>


// Functor

struct atanh_functor
{
    // Input Limiting Functor

    struct zero_functor
    {
        template <class T>
        T operator()(const T& a) { return and_not(abs(a) >= T(1.0), a); }
    };
    
    // Ops + Array Operators

    SIMDType<double, 1> operator()(const SIMDType<double, 1> a)
    {
        return abs(a).mVal >= 1.0 ? 0.0 : atanh(a.mVal);
    }
    
    template <class T>
    void operator()(T *o, T *i, long size)
    {
        vector_loop<zero_functor>(o, i, size);
        atanh_array(o, o, size);
    }
};

// Type Alias

using vatanh = v_unary<atanh_functor, calculation_type::vector_array>;

// Main

int C74_EXPORT main()
{
    vatanh::setup<vatanh>("vatanh~");
}
