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
   int n, q;
   cin >> n >> q;
   UnionFind ui(n);
   vector<string> ans;
   rep(i,q)
   {
      int p, a, b;
      cin >> p >> a >> b;
      if(p == 0) ui.unite(a,b);
      else
      {
         if(ui.same(a,b)) ans.push_back("Yes");
         else ans.push_back("No");
      }
   }

   rep(i,ans.size()) cout << ans[i] << endl;
}
