#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main()
{
   int n;
   cin >> n;
   vector<ll> a(3*n);
   rep(i,3*n) cin >> a[i];

   priority_queue<ll, vector<ll>,greater<ll>> left;
   priority_queue<ll> right;

   ll sum =0;
   rep(i,n) 
   {
      left.push(a[i]);
      sum += a[i];
   }
   vector<ll> x(n+1,0);
   for(int i = n;  i< 2*n ; i++)
   {
      x[i-n] = sum; 
      sum += a[i];
      left.push(a[i]);
      sum = sum - left.top(); left.pop();
   }
   x[n] = sum;
   sum = 0;
   for(int i = 3*n-1; i >= 2*n; i--)
   {
      right.push(a[i]);
      sum += a[i];
   }
   vector<ll> y(n+1,0);
   for(int i = 2*n-1; i >= n ; i--)
   {
      y[i+1-n] = sum; 
      sum += a[i];
      right.push(a[i]);
      sum = sum - right.top(); right.pop();
   }
   y[0] = sum;
   ll ans = -LINF;
   // rep(i,x.size()) cout << x[i] << " ";
   // cout << endl;
   // rep(i,y.size()) cout << y[i] << " ";
   // cout << endl;
    rep(i,n+1) ans = max(ans,x[i]-y[i]);
   cout << ans << endl;
}