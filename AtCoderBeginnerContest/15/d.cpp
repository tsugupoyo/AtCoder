#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

//でかいのでグローバルで宣言
int dp[64][64][10010];

int main()
{
   int w, n, k;
   cin >> w >> n >> k;
   vector<int> a(n);
   vector<int> b(n);
   rep(i,n) cin >> a[i] >> b[i];

   //dp[i][j][w] := i番目まででj個選んだ時幅合計wでの最大の価値
   rep(i,n) rep(s,k+1) rep(j,w+1)
   {
      if(j + a[i] <= w){
         dp[i+1][s+1][j+a[i]] = max(dp[i][s][j]+ b[i],dp[i][s][j+a[i]]);
      }
      dp[i+1][s][j]=max(dp[i+1][s][j],dp[i][s][j]);
   }

   //i+1に順に入れていったため
   cout << dp[n][k][w]<< endl;
}