#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n, m, l, x;
   cin >> n >> m >> l >> x;
   vector<int> a(n);
   rep(i,n) cin >> a[i];
   vector<vector<int>> dp(n+1,vector<int>(m+1, INF));
   dp[0][0] = 0;
   //dp[i][j] i番目まででjにいるための最小周回数
   for(int i = 0; i < n; i++)
   {
      for(int j = 0; j <= m; j++)
      {
         if(j == 0) dp[i+1][j] = 0;
         else  {
            int b = 0;
            if(dp[i][(j +a[i])%m] != INF)  b = dp[i][(j +a[i])%m] ;
            dp[i+1][j] = min(dp[i][j], dp[i][j -a[i] +);
         }
      }
   }

   rep(i,n)
   {
      rep(j,m+1) cout <<dp[i][j] << " ";
      cout << endl;
   }
   if(dp[n][l] <= x) cout << "Yes" << endl;
   else cout << "No" << endl;
   cout << dp[n][l] << endl;
}
