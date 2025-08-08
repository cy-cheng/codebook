#include "GeometryDefaultFloat.h"
pair<pdd, double> min_enc_circ(vector<pdd>& pt) {
    double D = 1e9, d = 1e9, r = 0.98, mx;
    pdd ans = pt[0];
    while (d > 1e-8) {
        pdd far = pt[0];
        mx = abs2(ans - far);
        for (auto& p: pt) if (abs2(ans - p) > mx) 
            far = p, mx = abs2(ans - p);
        ans = ans + (far - ans) * (d / D), d *= r;
    } 
    return {ans, sqrt(mx) / 2}; // cent, rad
}
