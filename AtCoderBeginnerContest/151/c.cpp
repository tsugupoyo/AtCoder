#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
   int n,m;
   cin >> n >> m;
   vector<int> p(m);
   vector<string> s(m);
   rep(i,m) cin >> p[i] >> s[i];

   int ac = 0;
   int wa = 0;
   vector<bool> check(n+1);
   vector<int> tmpWa(n+1);

   rep(i,m){
      
      if(check[p[i]]) continue;

      if(s[i] == "WA") ++tmpWa[p[i]];
      else {
         check[p[i]] = true;
         ++ac;
         wa += tmpWa[p[i]];
      }
   }
   printf("%d %d\n",ac,wa);
}