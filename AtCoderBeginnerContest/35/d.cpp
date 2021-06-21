#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

ll n, m, t;
ll A[200010];
ll a[100010], b[100010], c[100010];
vector<P> G[200010];

vector<ll> dijkstra(ll s)
{
   vector<ll> dist(200010, INF);
   dist[s] = 0;
   priority_queue<P, vector<P>, greater<P>> que;
   que.push(P(0, s));

   while(!que.empty())
   {
      ll cost, u;
      cost = que.top().first, u = que.top().second; que.pop();

      if(dist[u] < cost) continue;
      for(auto tmp : G[u])
      {
         ll v = tmp.first;
         ll time = tmp.second;
         if(dist[v] > dist[u] + time)
         {
            dist[v] = dist[u] + time;
            que.push(P(dist[v], v));
         }
      }
   }

   return dist;
}

int main()
{
   cin >> n >> m >> t;
   rep(i,n) cin >> A[i];
   rep(i,m)
   {
      cin >> a[i] >> b[i] >> c[i];
      a[i]--; b[i]--;
      G[a[i]].emplace_back(b[i],c[i]);
   }

   //ダイクストラ
   auto dist1 = dijkstra(0);
   rep(i,n) G[i].clear();

   //帰りを求める　0から遡るために　aとbを入れ替えて0から考える
   rep(i,m) G[b[i]].emplace_back(a[i], c[i]);
   auto dist2 = dijkstra(0);

   ll ans = 0;
   rep(i,n)
   {
      //tよりかかる所にはいけない
      if(dist1[i] + dist2[i] <= t)
      {
         ll tmp = (t  -dist1[i] - dist2[i]) * A[i];
         ans = max(ans, tmp);
      }
   }
   cout << ans << endl;
}