#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

ll f(ll a, ll b, ll x){
    return (a*x)/b - (x/b) * a;
}

int main(void) 
{
    ll a, b, n;
    cin >> a >> b >> n;
    ll ans =0;
    ans = f(a,b,min(b-1,n));
    cout << ans << endl;
}