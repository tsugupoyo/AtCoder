#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
const ll LLINF = 1000000000000000000;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main()
{
   int n;
   cin >> n;
   vector<ll> t(n);
   rep(i,n) cin >> t[i];
   ll ans =1;
   rep(i,n){
      ans = lcm(ans,t[i]);
      if(ans == LLINF){
         cout << LLINF << endl;
         return 0;
      }
   }
   cout << ans << endl;
}