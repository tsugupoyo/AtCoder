#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main()
{
   int n, m;
   cin >> n >> m;
   int a[m], b[m], t[m];
   vector<vector<ll>> dp(n,vector<ll>(n,INF));

   rep(i,m)
   {
      cin >> a[i] >> b[i] >> t[i];
      dp[a[i] -1][b[i] -1] =   dp[b[i] -1][a[i] -1] = t[i];
   }
   rep(i,n) dp[i][i] = 0;

   rep(k,n)
   {
      rep(i,n)
      {
         rep(j,n)
         {
            dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
         }
      }
   }
 //  rep(i,n)rep(j,n) cout << dp[i][j] <<endl;

   ll ans = INF;
   rep(i,n) 
   {
      ll target = 0;
      rep(j,n)
      {
         target = max(target, dp[i][j]);
      }
      ans = min(ans, target);
   }

   cout << ans << endl;
}