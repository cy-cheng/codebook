#include "PointSegDist.cpp"
double PointToHull(const vector<pdd>& C, pdd p) {
    bool flg = (cross(C[0] - C.back(), p - C.back()) > 0);
    double ans = PointSegDist(C.back(), C[0], p);
    for (int i = 1; i < (int)C.size(); ++i) {
        ans = min(ans, PointSegDist(C[i - 1], C[i], p));
        if ((cross(C[i] - C[i - 1], p - C[i - 1]) <= 0)) flg = 0;
    }
    return (flg ? 0 : ans);
}

