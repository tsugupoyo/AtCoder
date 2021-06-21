#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int n;
   cin >>n;
   vector<ll>a(n);
   rep(i,n) cin >> a[i];
   sort(a.rbegin(), a.rend());
    ll ans = a[0];
   rep(i,n-2)
   {
       int target = i/2;
       ans += a[target+1];
       //cout <<a[target+1] << endl;
   }
   cout << ans << endl;
}