#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   string s;
   cin >> s;

   int size = s.size();
   ll ans = 0;

   rep(i, 1<< size-1){
      string rem = s;
      int cnt = 1;
      rep(j, size -1){
         if(i >> j & 1)
         {
            //+入れる
            ll target = stoll(rem.substr(0,cnt));
            ans += target;
            rem = rem.substr(cnt);
           // cout << target << " (" << rem << ")" <<endl;
            cnt = 1;
         }
         else 
         {
            //+入れない
            cnt++;
         }
      }
     // cout << "--" << rem << "--" << endl;
      if(rem.size())
         ans += stoll(rem);
   }

   cout << ans << endl;
}