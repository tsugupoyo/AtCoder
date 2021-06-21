#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

struct UnionFind {
  vector<int> d;
  UnionFind(int n): d(n,-1) {}
  int root(int x) {
    if (d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  int size(int x) { return -d[root(x)];}
};

int main()
{
   int n, k, l;
   cin >> n >> k >> l;
   UnionFind a(n), b(n);
   rep(i,k)
   {
      int p, q;
      cin >> p >> q;
      --p;--q;
      a.unite(p,q);
   }
   rep(i,l)
   {
      int r, s;
      cin >> r >> s;
      --r; --s;
      b.unite(r,s);
   }

   map<pair<int, int>, int> m;
   for (int i = 0; i < n; i++) {
      m[{a.root(i), b.root(i)}]++;
     // cout << a.root(i) << " " << b.root(i) << endl;
   }
   for (int i = 0; i < n; i++) {
      if (i) cout << ' ';
      cout << m[{a.root(i), b.root(i)}];
   }
   cout << endl;
}