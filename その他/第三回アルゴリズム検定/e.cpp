#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n, m, q;
   cin >> n >> m >> q;
   vector<int> table[n];
   vector<int> color(n);
   rep(i,m)
   {
      int u, v;
      cin >> u >> v;
      --u; --v;
      table[u].push_back(v);
      table[v].push_back(u);
   }
   rep(i, n) cin >> color[i];
   vector<int> ans;
   rep(i,q)
   {
      int option, s; cin >> option >> s;
      --s;
      if(option == 1)
      {
         ans.push_back(color[s]);
         for(auto tmp : table[s]) color[tmp] = color[s];
      }
      else
      {
         ans.push_back(color[s]);
         int ss; cin >> ss;
         color[s] = ss;
      }
   }

   rep(i,ans.size()) cout << ans[i] << endl;
}
