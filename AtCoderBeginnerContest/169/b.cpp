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
   vector<ll> a(n);
   rep(i,n) cin >> a[i];
   sort(a.begin(), a.end());

   if(a[0] == 0)
   {
       cout << 0 << endl;
       return 0;
   }
   ll ans = 1;
   rep(i,n) 
   {
       ans *= a[i];
       if(ans > 1000000000000000000 || ans <= 0)
       {
           cout << -1 << endl;
           return 0;
       }
   }
    cout << ans << endl;
}