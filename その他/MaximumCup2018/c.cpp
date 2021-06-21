#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
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
   int n;
   cin >> n;
   UnionFind uf(n);
   rep(i,n)
   {
      int a;
      cin >> a;
      --a;
      uf.unite(i,a);
   }
   rep(i,n)
   {
      if(uf.size(i) %2 == 1)
      {
         cout << -1 << endl;
         return 0;
      }
   }
   cout << n/2 << endl;
}
