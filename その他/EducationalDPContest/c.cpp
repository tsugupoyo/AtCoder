#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
using vvi = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n;
   cin >> n;
   vector<int>a(n), b(n), c(n);
   rep(i,n) cin >> a[i] >> b[i] >> c[i];
   vvi table = {a,b,c};
   vvi dp(n+1,vector<int>(3,INF));
   rep(i,3) dp[0][i] = 0;

   for(int i =0; i < n; i++)
   {
      for(int j =0; j < 3; j++)
      {
         dp[i+1][j] = max(dp[i][(j+1)%3]+table[j][i],dp[i][(j+2)%3]+table[j][i]);
      }
   }
   int ans =0;
   rep(i,3) ans = max(ans, dp[n][i]);
   cout << ans << endl;
}
