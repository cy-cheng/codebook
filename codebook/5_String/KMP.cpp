#include "include/common.h"
vector<int> pi(const string& s) {
	vector<int> p((int)s.size());
	for(int i=1; i<(int)s.size(); i++) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}
