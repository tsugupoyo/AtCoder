#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n, W;
   cin >> n >> W;
   vector<int> w(n);
   vector<ll> v(n);
   rep(i,n) cin >> w[i] >> v[i];
   //dp[i][j] i番目までで、価値jを選ぶ場合の最小の重さ
   vvl dp(n+1, vector<ll>(100001, INF));
   rep(i,n+1) dp[i][0] = 0;
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j <= 100000 ; j++)
      {
         if(j - v[i] >= 0) dp[i+1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
         else dp[i+1][j] = dp[i][j];
      }
   }
   int ans = 0;
   rep(i,100001) if(dp[n][i] <= W) ans = max(ans, i);
   cout << ans << endl;
}
