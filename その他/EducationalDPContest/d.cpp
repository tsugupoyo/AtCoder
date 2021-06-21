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
   //dp[i][j] i番目までで、重さWを選ぶ場合の最大価値
   vvl dp(n+1, vector<ll>(W+1, 0));

   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j <= W ; j++)
      {
         if(j - w[i] >= 0) dp[i + 1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
         else dp[i+1][j] = dp[i][j];
      }
   }
   cout << dp[n][W] << endl;
}
