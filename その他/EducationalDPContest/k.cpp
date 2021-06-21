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
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   rep(i,n) cin >> a[i];

   //d[i] 石の残り枚数がiの時に勝てるか否か
   bool dp[k+1];
   rep(i,k+1) dp[i] = false;

   for(int i =1; i <= k; i++)
   {
      for(int j = 0; j < n; j++)
      {
         if(i - a[j] >= 0) dp[i] |= !dp[i - a[j]];
      }
   }
   // rep(i,k) cout << dp[i+1] << " ";
   // cout << endl;
   if (dp[k]) cout << "First" << endl;
   else cout << "Second" << endl;
}
