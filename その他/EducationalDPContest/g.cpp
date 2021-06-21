#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int dp[100005];
vector<int> dist[100005];

int rec(int i)
{
   if(dp[i] != -1) return dp[i];
   int res = 0;
   for(auto a : dist[i])
   {
      res = max(rec(a)+1,res);
   }
   return dp[i] = res;
}

int main()
{
   int n, m;
   cin >> n >> m;

   rep(i,m)
   {
      int x, y;
      cin >> x >> y;
      --x; --y;
      dist[x].push_back(y);
   }

   rep(i, 100005) dp[i] = -1;

   int ans = 0;
   rep(i,n)
   {
      ans = max(rec(i), ans);
   }
   cout << ans << endl;

}
