#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

const int mod = 1000000007;

int main()
{
   int h, w;
   cin >> h >> w;
   vector<string> a(h);
   rep(i,h) cin >> a[i];

   /* 1 2 3 4 5 6
    1 1 1 1 * 0 0
    2 1 * 1 * 0 0
    3 1 * 1 * 0 0
    4 1 * 1 1 1 1
    5 1 1 2 2 2 2
   */

   //dp[i][j] 繋がっていたら dp[i-1][j]とdp[i][j-1]を足す
   vvi dp(h,vector<int>(w,0));
   dp[0][0] = 1;

   for(int i = 0; i < h ; i++)
   {
      for(int j = 0; j < w; j++)
      {
         if(a[i][j] == '#') continue;
         if(i -1 >=0) 
         {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %=mod;
         }
         if(j -1 >=0) 
         {
            dp[i][j] += dp[i][j-1];
            dp[i][j] %=mod;
         }
      }
   }

   cout << dp[h-1][w-1] << endl;
}
