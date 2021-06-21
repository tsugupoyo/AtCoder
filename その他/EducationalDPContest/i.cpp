#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvd = vector<vector<double>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n;
   cin >> n;
   vector<double> p(n);
   rep(i,n) cin >> p[i];

   //dp[i][j] i番目までで　j枚表になる確率
   vvd dp(n+1,vector<double>(n+1,0.0));
   dp[0][0] = 1.0;

   for(int i = 0; i < n ; i++)
   {
      for(int j = 0; j <=i; j++)
      {
         //i番目が裏(jはそのまま)
         dp[i+1][j] += dp[i][j] * (1.0-p[i]);
         //i番目が表(jも増える)
         dp[i+1][j+1] += dp[i][j] *p[i];
      }
   }
   // rep(i,n+1)
   // {
   //    rep(j,n+1) cout << dp[i][j] << " ";
   //    cout << endl;
   // }

   double ans = 0.0;
   //半分以上の確率をタス
   for(int i = n/2+1; i <= n; i++) ans += dp[n][i];
   printf("%.10lf\n",ans);
}
