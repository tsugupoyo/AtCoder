#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n;
   cin >> n;
   vector<ll> a(n), b(n), c(n);
   rep(i,n) cin >> a[i]; 
   rep(i,n) cin >> b[i];
   rep(i,n) cin >> c[i];
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   sort(c.begin(),c.end());
   ll ans = 0;
   rep(i,n)
   {
      auto ite_c = upper_bound(c.begin(),c.end(), b[i]);
      auto ite_a = lower_bound(a.begin(),a.end(), b[i]);
      ll asum = (ite_a - a.begin()); 
      ll csum = -(ite_c - c.end()); 
     // cout << asum << " * " << csum << endl;
      ans += asum * csum;
   }
   cout << ans << endl;
}