#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n;
   cin >> n;
   vector<string> s(n);
   rep(i,n) cin >> s[i];
   string ans ="";
   rep(i,n/2)
   {
      bool ok = false;
      rep(j,n)
      {
         rep(k,n)
         {
            if(s[i][j] == s[n-1-i][k]) 
            {
               ans += s[i][j];
               ok = true;
               break;
            }
         }
         if(ok) break;
      }
      if(!ok)
      {
         cout << -1 << endl;
         return 0;
      }
   }
   string mid ="";
   if(n%2 != 0) mid = s[n/2][0];
   string r = ans;
   reverse(r.begin(),r.end());
   ans += mid + r;
   cout << ans << endl;
}
