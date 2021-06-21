#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll=long long;
using P = pair<int,int>;
using T = tuple<ll,ll,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

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
   vector<T> p(n);
   rep(i,n)
   {
      ll x, y;
      cin >> x >> y;
      p[i] = T(x,y, i);
   }
   vector<pair<int,ll>> E[n];
   vector<pair<ll, P>> memo;
   //xから見ていく
   sort(p.begin(), p.end());
   rep(i,n-1)
   {
      auto now = p[i];
      auto next = p[i+1];
      ll e = get<0>(next) - get<0>(now);
      E[get<2>(now)].push_back(make_pair(get<2>(next),e));
      E[get<2>(next)].push_back(make_pair(get<2>(now),e));
      memo.push_back(make_pair(e,P(get<2>(now), get<2>(next))));
   }

   //xとyを入れ替える
   rep(i,n) 
   {
      ll x = get<0>(p[i]);
      ll y = get<1>(p[i]);
      p[i] = T(y,x,get<2>(p[i]));
   }

   sort(p.begin(), p.end());
   rep(i,n-1)
   {
      auto now = p[i];
      auto next = p[i+1];
      ll e = get<0>(next) - get<0>(now);
      E[get<2>(now)].push_back(make_pair(get<2>(next),e));
      E[get<2>(next)].push_back(make_pair(get<2>(now),e));
      memo.push_back(make_pair(e,P(get<2>(now), get<2>(next))));
   }
   UnionFind uf(n);
   //全ての辺を含むグラフE完成行こう　クラスカル法で解く
   sort(memo.begin(), memo.end());
   //小さい順に
   ll ans = 0;
   rep(i,memo.size())
   {
      int point1 = memo[i].second.first;
      int point2 = memo[i].second.second;
      if(uf.same(point1, point2)) continue;
      uf.unite(point1, point2);
      ll target = INF;
      for(auto tmp : E[point1]) if(tmp.first == point2) target = min(target,tmp.second);
      if(target != INF) ans += target;
   }

   cout << ans << endl;
}