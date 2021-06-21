#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

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

int main(void) 
{
    int n, m;
    cin >> n >> m;
    UnionFind tree(n);
    rep(i,m)
    {
        int a, b;
        cin >> a >> b;
        tree.unite(a,b);
    }
    int ans = 0;
    rep(i,n) ans = max(ans, tree.size(i));
    cout << ans << endl;

}