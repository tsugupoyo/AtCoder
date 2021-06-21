#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n;
   cin >> n;
   vector<int> h(n);
   rep(i,n) cin >> h[i];
   vector<int> dp(n,INF);
   dp[0] = 0;
   for(int i = 0; i < n-1;i++)
   {
      int c1 = abs(h[i+1] - h[i]);
      dp[i+1] = min(dp[i+1], dp[i] + c1);
      if(i == n-2) continue;
      int c2 = abs(h[i+2] - h[i]);
      dp[i+2] = min(dp[i+2], dp[i] + c2);
   }
   cout << dp[n-1] << endl;
}
