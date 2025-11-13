#include "include/common.h"
#define base ll // complex<double>
// const double PI = acosl(-1);
const ll mod = 998244353, g = 3;
base omega[4 * N], omega_[4 * N];
int rev[4 * N];

ll fpow(ll b, ll p);
ll inverse(ll a) { return fpow(a, mod - 2); }

void calcW(int n) {
  ll r = fpow(g, (mod - 1) / n), invr = inverse(r);
  omega[0] = omega_[0] = 1;
  for (int i = 1; i < n; i++) {
    omega[i] = omega[i - 1] * r % mod;
    omega_[i] = omega_[i - 1] * invr % mod;
  }
  // double arg = 2.0 * PI / n;
  // for (int i = 0; i < n; i++)
  // {
  //   omega[i] = base(cos(i * arg), sin(i * arg));
  //   omega_[i] = base(cos(-i * arg), sin(-i * arg));
  // }
}

void calcrev(int n) {
  int k = __lg(n);
  for (int i = 0; i < n; i++) rev[i] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++)
      if (i & (1 << j)) rev[i] ^= 1 << (k - j - 1);
}

vector<base> NTT(vector<base> poly, bool inv) {
  base *w = (inv ? omega_ : omega);
  int n = (int)poly.size();
  for (int i = 0; i < n; i++)
    if (rev[i] > i) swap(poly[i], poly[rev[i]]);

  for (int len = 1; len < n; len <<= 1) {
    int arg = n / len / 2;
    for (int i = 0; i < n; i += 2 * len)
      for (int j = 0; j < len; j++) {
        base odd =
          w[j * arg] * poly[i + j + len] % mod;
        poly[i + j + len] =
          (poly[i + j] - odd + mod) % mod;
        poly[i + j] = (poly[i + j] + odd) % mod;
      }
  }
  if (inv)
    for (auto &a : poly) a = a * inverse(n) % mod;
  return poly;
}

vector<base> mul(vector<base> f, vector<base> g) {
  int sz = 1 << (__lg(f.size() + g.size() - 1) + 1);
  f.resize(sz), g.resize(sz);
  calcrev(sz);
  calcW(sz);
  f = NTT(f, 0), g = NTT(g, 0);
  for (int i = 0; i < sz; i++)
    f[i] = f[i] * g[i] % mod;
  return NTT(f, 1);
}
