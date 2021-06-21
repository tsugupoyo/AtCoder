#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int  D;
vector<int> c(26);
vector<int> t(365);
vector<int> last(26,0);
vector<vector<int>> s(365,vector<int>(26));

int f()
{
   int ans =0;
   rep(i,26) last[i] = 0;
   rep(i,D)
   {
      int type = t[i] -1;
      ans += s[i][type];
      last[type] = i+1;
      rep(j,26) ans -= c[j] * (i+1 - last[j]);

   }
   return ans;
}

int main()
{
   ll m;
   cin >> D;

   rep(i,26) cin >> c[i];
   rep(i,D) rep(j,26) cin >> s[i][j];
   rep(i,D) cin >> t[i];
   cin >> m;
   vector<int> d(m), q(m);
   rep(i,m) cin >> d[i] >> q[i];

   rep(i,m)
   {
      int day = d[i] -1;
      t[day] = q[i];
      cout << f() << endl;
   }

   //rep(i,D) cout << anslist[i] <<endl;

   return 0;
}
