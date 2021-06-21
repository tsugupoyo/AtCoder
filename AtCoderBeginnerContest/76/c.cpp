#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   string s,t;
   cin >> s >> t;
   bool ok = false;
   for(int i = s.size() -t.size(); i >= 0 ; i--)
   {
      if(s[i] == '?' || s[i] == t[0])
      {
         ok = true;
         rep(j,t.size())
         {
            if(s[i + j] == t[j] || s[i + j] == '?') continue;
            else ok = false;
         }
         if(ok) 
         {
            rep(j,t.size()) s[i + j] = t[j]; 
            break;
         }
      }
   }
   if(!ok) {
      cout << "UNRESTORABLE" << endl;
      return 0;
   }
   rep(i,s.size()){
      if(s[i] == '?') s[i] ='a';
   }
   cout << s << endl;
}