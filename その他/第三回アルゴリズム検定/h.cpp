#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   ll n, l;
   cin >> n >> l;
   vector<ll> wall(n);
   rep(i,n) cin >> wall[i];
   ll t1, t2, t3;
   cin >> t1 >> t2 >> t3;
   //dp[i][j] 行動i個目までで、距離j進んだ時の最小時間
   vector<ll> dp(l+1, INF);
   dp[0] = 0;
   int index = 0;
   rep(i,l+1)
   {
      bool iswall = false;
      if(wall[index] == i) 
      {
         iswall =  true;
         if( wall.size() -1 > index) index++;
      }
      int t =0;
      if(iswall) t += t3;
      if(i-1 < 0) continue;
      else if(i - 2 < 0) 
      {
         t += t1;
         dp[i] = min(dp[i], dp[i-1] + t);
      }
      else if(i-4 < 0) 
      {
         t += t1;
         dp[i] = min(dp[i], dp[i-1] + t);
         t += t2;
         dp[i] = min(dp[i], dp[i-2] + t);
      }
      else {
         t += t1;
         dp[i] = min(dp[i], dp[i-1] + t);
         t += t2;
         dp[i] = min(dp[i], dp[i-2] + t);

         t += 2*t2;
         dp[i] = min(dp[i], dp[i-4] + t);
      }
   }
   //lまでは埋まった。　l-3の距離から計り直す
   dp[l] = min(dp[l], dp[l-3] + t1/2 + 2*t2 + t2/2);
   dp[l] = min(dp[l], dp[l-2] + t1/2 + t2 + t2/2);
   dp[l] = min(dp[l], dp[l-1] + t1/2 + t2/2);
   cout << dp[l] << endl;
}