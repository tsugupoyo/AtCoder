#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
   int  n;
   cin >> n;
   vector<int>a(n);
   rep(i,n) cin >> a[i];
   int dp[n];
   dp[0] = 0;
   dp[1] = abs(a[1] - a[0]);
   for(int i = 2; i < n; i++){
      int n = abs(a[i] - a[i -1]);
      int nn = abs(a[i] - a[i -2]);
     
      dp[i] = min(dp[i -1] +n, dp[i - 2] + nn);
      //printf("n:%d nn: %d dp: %d\n", n,nn, dp[i]);
   }
   cout << dp[n - 1] << endl;
}