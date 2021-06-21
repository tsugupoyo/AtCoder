#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

//半分全列挙の部分ができていない

int main()
{
   ll n, W;
   cin >> n >> W;
   vector<ll> v(n), w(n);
   ll maxv=0, maxw=0;
   rep(i,n)
   {
       cin >> v[i] >> w[i];
       maxv = max(maxv, v[i]);
       maxw = max(maxw, w[i]);
   }

   if(maxv <= 1000)
   {
      maxv *= n;
      vector<vector<ll>> dp(n+1, vector<ll>(maxv+1, INF));
      dp[0][0] = 0;
      //dp[i][j] i番目までで価値jまでの重さの最小値
      for(int i = 0; i < n ; i++)
      {
         for(int j = 0; j <= maxv; j++)
         {
            if(j-v[i] >= 0) dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
            else dp[i+1][j] = dp[i][j];
         }
      }
      int ans = 0;
      rep(i,maxv+1) if(dp[n][i] <= W) ans = (ll)i;
      cout << ans << endl;
      return 0;
   }
   else if(maxw <= 1000)
   {
      ll dp [n+1][W+1];
      rep(i,n+1)rep(j,W+1) dp[i][j] = 0;

      //dp[i][j] i番目までで重さjまでの価値の最大値 オーソドックス
      rep(i,n)
      {
         rep(j,W+1)
         {
            if(j-w[i]>=0) dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+ v[i]);
            else dp[i+1][j] = dp[i][j];
         }
      }
      cout << dp[n][W] << endl;
      return 0;
   }
   else
   {
      ll ans =0;
      //全ビット探索では間に合わない... 2^30 ≒ 10^9よりちょい上くらい
      //半分全列挙　2^15 ≒  32768と　二部探索 log 2 ^ n/2  o(2^ n/2 * n)
      vector<pair<ll,ll>> a,b;

      //aグループ
      rep(i, 1 << n/2)
      {
         ll vsum = 0;
         ll wsum = 0;
         rep(j, n/2)
         {
            if(1 >> j&1)
            {
               vsum += v[j];
               wsum += w[j];
            }
         }
         a.push_back(pair<ll,ll>(wsum,vsum));
      }

      //bグループ
      rep(i, 1 << n/2)
      {
         ll vsum = 0;
         ll wsum = 0;
         rep(j, n/2)
         {
            if(1 >> j&1)
            {
               vsum += v[n/2 + j];
               wsum += w[n/2 + j];
            }
         }
         b.push_back(pair<ll,ll>(wsum,vsum));
      }
      sort(b.begin(), b.end());
      vector<ll> vb;
      vector<ll> wb;
      for(auto t:b)
      {
         wb.push_back(t.first);
         vb.push_back(t.second);
      }

      //aを固定して二分探索
      for(auto A : a)
      {
         if(W - A.first >= 0)
         {
            auto iter = upper_bound(wb.begin(), wb.end(), W - A.first) - 1;
            int index = iter - wb.begin();
            ans = max(ans, A.second + vb[index]);
         }
      }
      cout << ans << endl;
   }
   return 0;
}