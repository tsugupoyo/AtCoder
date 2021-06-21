#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
   
ll n, m;
vector<ll> x;

bool Check(ll d)
{
   ll left = 0;
   rep(i,m)
   {
      ll num = x[i] - left;
      if(num > d) return false;
      //左が超えてしまった時
      if (num <= 0) left = x[i]+d+1;
      else
      {
         //左まで行って右に行くパターン
         ll tmp = x[i]-2*num+d;
         //出来るだけ右に行って左に行くパターンと比較
         tmp = max(tmp, x[i] + (d-num)/2);
         //一番左を更新
         left = tmp +1;
         left = min(n,left);
      }
      
   }

   return left >= n;
}

int main()
{
   cin >> n >> m;
   x.resize(m);
   rep(i,m) 
   {
      cin >> x[i];
      x[i]--;
   }
   ll left = -1, right = 1001001001001001001;
   while(right - left > 1)
   {
      ll mid = (left + right) /2;
      if(Check(mid)) right = mid;
      else left = mid;
   }
   cout << right << endl;
}
