#include<common.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mod=998244353;
long long divide(long long a, long long b = mod - 2) {
	long long ret = 1;
	for (a %= mod; b; b >>= 1, a = a * a % mod)
		if (b & 1) ret = ret * a % mod;
	return ret;
}
struct modint {int x; modint(const int& _ = 0): x(mod + _) {x %= mod;} operator bool() {return x;}};
modint operator+(const modint& a, const modint& b) {return (a.x + b.x) % mod;}
modint operator-(const modint& a, const modint& b) {return (a.x - b.x + mod) % mod;}
modint operator*(const modint& a, const modint& b) {return 1LL * a.x * b.x % mod;}
modint operator/(const modint& a, const modint& b) {return 1LL * a.x * divide(b.x) % mod;}
modint& operator+=(modint& a, const modint& b) {return a = a + b;}
modint& operator-=(modint& a, const modint& b) {return a = a - b;}
modint& operator*=(modint& a, const modint& b) {return a = a * b;}
modint& operator/=(modint& a, const modint& b) {return a = a / b;}
istream& operator>>(istream& is, modint& n) {is >> n.x; return is;}
ostream& operator<<(ostream& os, const modint& n) {os << n.x; return os;}
