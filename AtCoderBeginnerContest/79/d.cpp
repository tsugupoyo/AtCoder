#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int h, w;
   cin >> h >> w;
   vector<vector<int>> dp(10,vector<int>(10,INF));
   rep(i,10) dp[i][i] = 0;

   rep(i,10) rep(j,10) 
   {
      int c;
      cin >> c;
      dp[i][j] = c;
   }

   rep(k,10)
   {
      rep(i,10)
      {
         rep(j,10) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
   }
   ll ans = 0;
   rep(i,h) rep(j,w)
   {
      int a;
      cin >> a;
      if(a == -1) continue;
      ans += dp[a][1];
   }
   cout << ans << endl;
}