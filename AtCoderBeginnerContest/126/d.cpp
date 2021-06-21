#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int, ll>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n;
   cin >> n;
   vector<int> color(n,-1);
   vector<P> dist[n];
   color[0] = 1;
   rep(i,n-1)
   {
      int u, v;
      ll w;
      cin >> u >> v >> w;
      --u; --v;
     dist[u].push_back(P(v,w));
     dist[v].push_back(P(u,w));
   }
   
   queue<ll> que;
   que.push(0);
   while(!que.empty())
   {
      int target = que.front(); que.pop();

      for(auto d : dist[target])
      {
         int num = d.first;
         ll len = d.second;
         if(color[num] != -1) continue;
         if(len%2 == 0) color[num] = color[target];
         else color[num] = 1 - color[target];
         que.push(num);
      }
   }
   rep(i,n) cout << color[i] << endl;
}