#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

ll dp[101][101][101];

int main()
{
   int n,m;
   cin >> n >> m;
   vector<ll> a(n), b(n), c(n), w(n), x(m), y(m), z(m);
   rep(i,n)
   {
      cin >> a[i] >> b[i] >> c[i] >> w[i];
      dp[a[i]][b[i]][c[i]] = max(dp[a[i]][b[i]][c[i]] ,w[i]);
   }
   rep(i,m) cin >> x[i] >> y[i] >> z[i];

   rep(i, 101) rep(j,101) rep(k, 101)
   {
      if(i != 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);   
      if(j != 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
      if(k != 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
   }

   rep(i,m) cout << dp[x[i]][y[i]][z[i]] << endl;
}
