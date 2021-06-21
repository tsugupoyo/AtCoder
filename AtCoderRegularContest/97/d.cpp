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
   int n, m;
   cin >> n >> m;
   vector<int> table(n);
   rep(i,n)
   {
       cin >> table[i];
       table[i]--;
   }
   UnionFind ui(n);

   rep(i,m)
   {
      int x, y;
      cin >> x >> y;
      --x; --y;
      ui.unite(x,y);
   }

   int ans = 0;
   rep(i,n) if(table[i] == i || ui.same(i,table[i])) ans++;
   cout << ans << endl;
}