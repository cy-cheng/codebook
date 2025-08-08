#include "Convex_hull.cpp"
vector<pll> Minkowski(vector<pll> A, vector<pll> B) { // |A|,|B|>=3
  A = hull(A), B = hull(B);
  vector<pll> C(1, A[0] + B[0]), s1, s2; 
  for (int i = 0; i < A.size(); ++i) 
    s1.emplace_back(A[(i + 1) % A.size()] - A[i]);
  for (int i = 0; i < B.size(); i++) 
    s2.emplace_back(B[(i + 1) % B.size()] - B[i]);
  for (int i = 0, j = 0; i < A.size() || j < B.size();)
    if (j >= B.size() || (i < A.size() && cross(s1[i], s2[j]) >= 0))
      C.emplace_back(B[j % B.size()] + A[i++]);
    else
      C.emplace_back(A[i % A.size()] + B[j++]);
  return hull(C); // dis(A, B) = dis(Minkowski(A, -B), 0)
}
