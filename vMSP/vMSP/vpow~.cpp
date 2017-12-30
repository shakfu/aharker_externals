
/*
 *  vpow~
 *
 *	vpow~ is a vectorised version of pow~.
 *
 *  Copyright 2010 Alex Harker. All rights reserved.
 *
 */

#include "v_binary.hpp"
#include <SIMDExtended.hpp>

struct pow_functor
{
    SIMDType<float, 1> operator()(const SIMDType<float, 1> a, const SIMDType<float, 1> b) { return powf(b.mVal, a.mVal); }
    SIMDType<double, 1> operator()(const SIMDType<double, 1> a, const SIMDType<double, 1> b) { return pow(b.mVal, a.mVal); }
 
    void operator()(float *o, float *i1, float *i2, long size)
    {
        f32_pow_array(o, i1, i2, size);
    }
    
    void operator()(double *o, double *i1, double *i2, long size)
    {
        f64_pow_array(o, i1, i2, size);
    }
    
    // Empty Implementations
   
    template <class T>
    T operator()(const T a, const T b) { return a; }
};

typedef v_binary<pow_functor, kVectorArray, kVectorArray> vpow;

int C74_EXPORT main()
{
    vpow::setup<vpow>("vpow~");
}
