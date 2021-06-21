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
  //偶数ならtrue
  UnionFind ui(2*n);
  vector<string> ans;
  rep(i,q)
  {
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    --x; --y;
    if(w == 1)
    {
      if(z%2 == 0)
      {
        ui.unite(2*x,2*y);
        ui.unite(2*x+1,2*y+1);
        // printf("x: %d y:%d\n",2*x, 2*y);
        // printf("x: %d y:%d\n",2*x+1, 2*y+1);
      }
      else 
      {
        ui.unite(2*x,2*y +1);
        ui.unite(2*x+1,2*y);
        // printf("x: %d y:%d\n",2*x, 2*y+1);
        // printf("x: %d y:%d\n",2*x+1, 2*y);
      }
    }
    else
    {
      //偶数か奇数かを判定する
      if(ui.same(2*x, 2*y)) ans.push_back("YES");
      else ans.push_back("NO");
    }
  }
  rep(i,ans.size()) cout << ans[i] << endl;
}