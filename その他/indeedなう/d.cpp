#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

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

struct edge
{
   int u;
   int v;
   int cost;
   edge(int u=0, int v=0, int64_t cost=0):u(u), v(v), cost(cost) {} 
   bool operator<(const edge& o)
   {
      return cost < o.cost;
   }
};

vector<edge> es;

int kruskal(int n)
{
   int ans = 0;
   sort(es.rbegin(), es.rend());
   UnionFind uf(n);
 
   for(auto tmp: es)
   {
      if(!uf.same(tmp.u, tmp.v))
      {
         uf.unite(tmp.u,tmp.v);
         ans += tmp.cost;
      }
   }
   return ans;
}

int main()
{
   int h, w;
   cin >> h >> w;
   P s; cin >> s.first >> s.second;
   P g; cin >> g.first >> g.second;

   vector<vector<int>> p(h, vector<int>(w));
   vector<P> dist[h*w];
   ll ans = 0;
   rep(i,h) rep(j,w) 
   {
      cin >> p[i][j];
      ans += p[i][j];
   }

   rep(i,h)
   {
      rep(j,w)
      {
         rep(k,4)
         {
            int nx = j + dx[k];
            int ny = i + dy[k];

            if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            es.push_back(edge(i*w + j,nx + w*ny,p[i][j] * p[ny][nx]));
         }
      }
   }

   cout << ans + kruskal(h*w) << endl;
}
