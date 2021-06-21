#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int  d;
   cin >> d;
   vector<int> c(26);
   vector<vector<int>> s(d,vector<int>(26));
   vector<int> t(d);
   vector<int> last(26,0);
   rep(i,26) cin >> c[i];
   rep(i,d) rep(j,26) cin >> s[i][j];
   rep(i,d) cin >> t[i];

   int ans = 0;
   rep(i,d)
   {
      int type = t[i] -1;
      ans += s[i][type];
      last[type] = i+1;
      rep(j,26) ans -= c[j] * (i+1 - last[j]);

      cout << ans << endl;
   }
   return 0;
}
