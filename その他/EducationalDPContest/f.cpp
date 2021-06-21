#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   string s,t;
   cin >> s >> t;

   vvi dp(s.size()+1,vector<int>(t.size()+1, 0));

   /* s= abcde t = aabbc
      1 2 3 4 5
    1 1 1 1 1 1
    2 1 1 2 2 2
    3 1 1 2 2 3
    4 1 1 2 2 3
    5 1 1 2 2 3
   */
   /* s= axyb t = abyxb
      a x y b
    a 1 1 1 1 
    b 1 1 1 2 
    y 1 1 2 2 
    x 1 2 2 2 
    b 1 2 2 3 
   */
   string ans = "";
   vector<P> index(min(s.size()+1,t.size()) + 1, P(-1,-1));

   for(int i = 0; i < s.size();i++)
   {
      for(int j = 0; j < t.size(); j++)
      {
         if(s[i] == t[j]) 
         {
            dp[i+1][j+1] = dp[i][j]+ 1;
            if(index[dp[i+1][j+1]].first == -1) index[dp[i+1][j+1]] = P(i,j);
            else
            {
               int before = max(index[dp[i+1][j+1]].first, index[dp[i+1][j+1]].second);
               int now = max(i,j);
               if(now < before) index[dp[i+1][j+1]] = P(i,j);
            }
         }
         else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
      }
   }
   
   // rep(i,s.size()+1)
   // {
   //    rep(j,t.size()+1)
   //    {
   //       cout << dp[i][j] << " ";
   //    }
   //    cout << endl;
   // }

    // 復元
    string res = "";
    int i = (int)s.size(), j = (int)t.size();
    while (i > 0 && j > 0)
    {
        // (i-1, j) -> (i, j) と更新されていた場合
        if (dp[i][j] == dp[i-1][j]) {
            --i; // DP の遷移を遡る
        }

        // (i, j-1) -> (i, j) と更新されていた場合
        else if (dp[i][j] == dp[i][j-1]) {
            --j; // DP の遷移を遡る
        }

        // (i-1, j-1) -> (i, j) と更新されていた場合
        else {
            res = s[i-1] + res; // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
            --i, --j; // DP の遷移を遡る
        }
    }
    cout << res << endl;

   //以下自分のコードだがうまくいかなかったのでコメントアウト
   // rep(i, index.size())
   // {

   //    if(index[i+1].first == -1) break;
   //    ans += s[index[i+1].first];
   // }

   // cout << ans << endl;;
}
