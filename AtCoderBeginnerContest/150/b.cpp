#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
   int n;
   string s;
   cin >> n >> s;
   int ans = 0;

   rep(i,n -2){
      if(s[i] =='A' && s[i + 1] =='B' && s[i + 2] =='C')
         ++ans;
   }

   cout << ans << endl;
}