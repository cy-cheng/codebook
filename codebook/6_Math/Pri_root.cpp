#include "include/common.h"
int find_root(int p) {
    if (p == 2) return 1;
    vector<int> fac;
    int tmp = p - 1;
    for (int i = 2; i * i <= p - 1; ++i) {
        if (tmp % i == 0) {
            fac.push_back(i);
            while (tmp % i == 0) tmp /= i;
        }
    }
    if (tmp > 1) fac.push_back(tmp);
    for (int i = 2; i < p; ++i) {
        int flg = 1;
        for (auto &j : fac) {
            if (fp(i, (p - 1) / j, p) == 1) {
                flg = 0;
                break;
            }
        }
        if (flg) return i;
    }
    return -1; // not possible
}
