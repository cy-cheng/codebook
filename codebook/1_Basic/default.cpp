#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ll long long
#define ld long double
#define i128 __int128

#define all(x) x.begin(), x.end()
#define pb emplace_back

#ifdef LOCAL
#define px(args...) LKJ("\033[1;32m(" #args "):\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ' ', LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#define pv(v) cerr << "\033[1;31m[" << #v << "]: \033[0m"; OI(all(v))
#else
#define px(...) 
#define OI(...) 
#define pv(v)
#endif

template<class A, class B> ostream& operator<<(ostream &os, pair<A, B> p) { return os << '(' << p.F << ", " << p.S << ')'; }

void solve() {}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;

  // cin >> T;
  while (T--) solve();
}
