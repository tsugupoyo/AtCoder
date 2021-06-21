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
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i,n) cin >> a[i];

   //dp[i][j][k] 残り個数が1個の皿がi枚、２個の皿がj枚、3この皿がk枚の時の寿司を全てなくす操作回数の期待値
   
}
