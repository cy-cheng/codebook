#include "Minkowski_Sum.cpp"
#include "PointToHull.cpp"
double ConvexHullDist(vector<pdd>& A, vector<pdd>& B, vector<pdd>& C) {
    Minkowski(A, B, C); // assert (int)C.size() > 0
    return PointToHull(C, pdd(0, 0));
}
