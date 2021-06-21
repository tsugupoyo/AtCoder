#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n,k;
   cin >> n >> k;
   vector<int> h(n);
   rep(i,n) cin >> h[i];
   vector<int> dp(n,INF);
   dp[0] = 0;
   for(int i = 0; i < n-1;i++)
   {
      for(int j =1; j <=k; j++)
      {
         if(i+j >= n)continue;
         int c = abs(h[i+j] - h[i]);
         dp[i+j] = min(dp[i+j], dp[i] + c);
      }
   }
   cout << dp[n-1] << endl;
}
