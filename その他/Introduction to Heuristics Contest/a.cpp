#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int  d;
vector<int> c(26);
vector<int> t(365);
vector<int> last(26,0);
vector<vector<int>> s(365,vector<int>(26));

int f()
{
   int ans =0;
   rep(i,26) last[i] = 0;
   rep(i,d)
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
   cin >> d;
   rep(i,26) cin >> c[i];
   rep(i,d) rep(j,26) cin >> s[i][j];
   t.resize(d);
   int sum = 0;
   vector<int> type(d);
   rep(i,d)
   {
       t[i] = i+1;
       type[i] = i+1;
   }

   rep(i,1)
   {
      int ret = f();

      if(ret > sum)
      {
         sum = ret;
         rep(j,d)
         {
            type[j] = t[j];
         }
      }
   }

   rep(i,d) cout << type[i] << endl;
   return 0;
}
