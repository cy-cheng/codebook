#include "include/common.h"
vector<int> manacher(const string& s) {
	int n = s.size();
	array<vector<int>,2> p = {vector<int>(n+1), vector<int>(n)};
	for(int z=0; z<2; z++) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	vector<int> res(n*2+1);
	for(int i=0; i<n; i++){
		res[2*i]=p[0][i];
		res[2*i+1]=p[1][i];
	}
	res[2*n]=p[0][n];
	return res;
}
