#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const ll INF =1001001001001001001;

int main()
{
   ll n, x;
   cin >> n >> x;
   vector<ll>a(n);
   rep(i,n) cin >> a[i];
   ll ans = 0;

   rep(i,n-1)
   {
      if(x >= a[i] + a[i+1]) continue;
      if(x < a[i])
      {
         ans += a[i] - x + a[i+1];
         a[i] = x;
         a[i+1] = 0;
      }
      else if(x == a[i])
      {
         ans += a[i+1];
         a[i+1] = 0;
      }
      else
      {
         ll tmp = x -a[i];
         ans +=  a[i+1] - tmp;
         a[i+1] = tmp;
      }
   }
  // rep(i,n) cout << a[i] << " ";
   cout << endl;
  cout << ans << endl;
}