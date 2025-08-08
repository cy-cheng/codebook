#include "include/common.h"
void solve(int l, int r, vector<Point> &a) { // 三維偏序
    if (l == r) return;
    int mid = (l+r)>>1;
    solve(l,mid,a), solve(mid+1,r,a);
    int lp = l, rp = mid+1;
    vector<Point> tmp;
    while(lp <= mid && rp <= r) {
        if (a[lp].y > a[rp].y) {
            bit.upd(a[lp].z,1);
            tmp.pb(a[lp++]);
        } else {
            ans[a[rp].id] += (bit.sum(maxn)-bit.sum(a[rp].z));
            tmp.pb(a[rp++]);
        }
    }
    while(lp <= mid) {
        bit.upd(a[lp].z,1);
        tmp.pb(a[lp++]);
    }
    while(rp <= r) {
        ans[a[rp].id] += (bit.sum(maxn)-bit.sum(a[rp].z));
        tmp.pb(a[rp++]);
    }
    for (int i = l; i <= mid; ++i) bit.upd(a[i].z,-1);
    for (int i = l; i <= r; ++i) a[i] = tmp[i-l];
}
