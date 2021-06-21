#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    int n, h;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    //dp[i][j] i番目までの魔法、モンスターのHPjまでの最小魔法消費量
    vector<vector<int>> dp(n+1, vector<int>(h+1));
    rep(i,n+1)rep(j,h+1) dp[i][j] = INF;
    rep(i,n)dp[i][0] = 0;
    rep(i,n)
    {
        rep(j,h+1)
        {
            if(j - a[i] >= 0)
            {
                dp[i+1][j] = min(dp[i][j], dp[i+1][j-a[i]]+b[i]);
            }
            else dp[i+1][j] = min(dp[i][j], dp[i+1][0] + b[i]);
            //cout << dp[i+1][j] << " ";
        }
       // cout << endl;
    }
    cout << dp[n][h] << endl;
    
}