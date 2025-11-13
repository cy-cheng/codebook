#include "include/common.h"
vector<int> Z(const string& S) {
	vector<int> z((int)S.size());
    z[0] = (int)S.size(); // or 0
	int l = -1, r = -1;
	for(int i=1; i<(int)S.size(); i++) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < (int)S.size() && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}
