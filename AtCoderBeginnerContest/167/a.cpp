#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   string s, t;
   cin >> s >> t;

   rep(i, s.size()){
      if(s[i] != t[i])
      {
         cout << "No" << endl;
         return 0;
      }
   }
   if(s.size() + 1 == t.size())  cout << "Yes" << endl;
   else  cout << "No" << endl;
   return 0;
}