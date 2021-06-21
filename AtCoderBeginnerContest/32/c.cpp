#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main()
{
   int n;
   ll k;
   cin >> n >> k;
   vector<ll> s(n);
   rep(i,n) cin >> s[i];
   ll ans = 0;
   ll sum = 1;
   ll cnt = 0;
   int r = 0;
   rep(i,n)
   {
      if(s[i] == 0)
      {
         cout << n << endl;
         return 0;
      }
      for(; r<n; r++)
      {
         if(sum * s[r] > k) break;
         sum *= s[r];
         cnt++;
        // cout << sum << " " << s[r] << " " << cnt<< endl;
      }

      ans = max(ans, cnt);

      if(i == r) r++;
      else
      {
         sum /= s[i];
         cnt--;
      }
   }
   cout << ans << endl;
}