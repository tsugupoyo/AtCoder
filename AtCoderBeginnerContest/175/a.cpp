#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   string s;
   cin >> s;
   int ans = 0;
   int tmp =0;
   rep(i,3)
   {
       if(s[i] == 'R') tmp++;
       else
       {
           ans = max(tmp, ans);
           tmp = 0;
       }
   }

   ans = max(tmp, ans);
   cout << ans << endl;
}