#include "include/common.h"
#define INF 4e18
struct Line {
    ll a, b;
    Line(ll _a = 0, ll _b = INF) : a(_a), b(_b) {}
    ll f(ll x) const { return a * x + b; }
};
struct Node {
    Line line;
    Node *left = nullptr, *right = nullptr;
    Node(Line l) : line(l) {}
};
struct LiChaoTree {
    const ll MIN_X = -1e9;
    const ll MAX_X = 1e9;
    Node* root = nullptr;
    void insert(Line new_line, ll L, ll R) {
        insert(root, MIN_X, MAX_X, new_line, L, R);
    }
    ll query(ll x) const {
        return query(root, MIN_X, MAX_X, x);
    }
private:
    void insert(Node*& node, ll l, ll r, Line new_line, ll L, ll R) {
        if (r < L || R <= l) return;
        if (!node) node = new Node(Line());
        // don't use (l + r) / 2, it may overflow
        ll mid = (l + r) >> 1;
        if (L <= l && r < R) {
            bool left_better = new_line.f(l) < node->line.f(l);
            bool mid_better  = new_line.f(mid) < node->line.f(mid);
            if (mid_better) swap(node->line, new_line);
            if (r == l) return;
            if (left_better != mid_better) insert(node->left, l, mid, new_line, L, R);
            else insert(node->right, mid + 1, r, new_line, L, R);
            return;
        }
        insert(node->left,  l, mid, new_line, L, R);
        insert(node->right, mid + 1, r, new_line, L, R);
    }
    ll query(Node* node, ll l, ll r, ll x) const {
        if (!node) return INF;
        ll res = node->line.f(x);
        if (l == r) return res;
        ll mid = (l + r) >> 1;
        if (x <= mid) return min(res, query(node->left, l, mid, x));
        else return min(res, query(node->right, mid + 1, r, x));
    }
} seg;
