
#ifndef _GESTURE_CURVE_HPP_
#define _GESTURE_CURVE_HPP_

#include <ext.h>

class gesture_curve
{
    enum class curve_type
    {
        power_sin_forward,
        power_sin_reverse,
        power_recip_sin_reverse,
        power_recip_sin_forward,
        power_asin_forward,
        power_asin_reverse,
        power_recip_asin_reverse,
        power_recip_asin_forward
    };
    
public:
    
    void reset();
    
    double operator()(double val);

    void params(t_atom *specifiers);
    
private:
    
    curve_type get_type(int band);
    
    double scurve_sin(double val) const;
    double scurve_asin(double val) const;

    // Curve values
    
    double power_val;
    double scurve_val;
    curve_type type;
};

#endif /* _GESTURE_CURVE_HPP_ */
