#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   string s;
   cin >> s;
   string ans = "";
   int sum = 0;
   int target = 0;
   bool plus = true;

   rep(i, 1 << s.size()-1){
      ans = "";
      sum = 0;
      plus = true;
      target = s[0] - '0';
      rep(j, s.size()-1)
      {
         ans += s[j];
         //cout << target << " "<< plus << endl;
         if(plus) sum += target;
         else sum -= target;
         if(i >> j&1)
         {
            //+
            ans += '+';
            plus = true;
         }
         else
         {
            //-
            ans +='-';
            plus = false;
         }
         target = s[j+1] - '0';
      }
      ans += s[s.size()-1];
      if(plus) sum += target;
      else sum -= target;
     // cout << sum << " " << ans<< endl;
      if(sum == 7) break;     
   }
   ans += "=7";
   cout << ans << endl;
}