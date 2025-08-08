#include "Convex_hull.cpp"
void shift(vector<pdd>& h) {
    int p = 0; // must be convex hull
    for (int i = 1; i < h.size(); i++) {
        if (h[i].S < h[p].S) p = i;
        if (h[i].S == h[p].S && h[i].F < h[p].F) p = i;
    }
    rotate(h.begin(), h.begin() + p, h.end());
}
void Minkowski(vector<pdd>& a, vector<pdd>& b, vector<pdd>& c) {
    shift(a), shift(b); c = {}; // |A|,|B|>=3
    int A = a.size(), B = b.size(), i = 0, j = 0;
    a.pb(a[0]), a.pb(a[1]), b.pb(b[0]), b.pb(b[1]);
    while (i < A || j < B) {
        c.pb(a[i] + b[j]);
        ll c = cross(a[i + 1] - a[i], b[j + 1] - b[j]);
        if (c >= 0 && i < A) i++;
        if (c <= 0 && j < B) j++;
    }
    for (int i = 0; i < 2; i++) a.pop_back(), b.pop_back();
}
