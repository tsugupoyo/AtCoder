#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int n;
   cin >> n;
   vector<ll>a(n);
   rep(i,n) cin >> a[i];

   ll base = 0;
   ll ans = 0;
   int i = 0;
   while(i < n)
   {
      if(a[i] >= a[i+1]) 
      {
         ans = ans + 1 + i - base; 
         base = i+1;
      }
      else
      {
         ans = ans + 1 + i - base;
      }
      ++i;
     // cout << ans << " = " << i << " " << base << endl;
   }
   cout << ans << endl;
}