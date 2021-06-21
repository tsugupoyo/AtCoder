#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

ll f (ll n)
{
    return n*(n+1)/2;
}

int main(void) 
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <=n; i++)
    {
        ll r = n/i;
        ans += i * f(r);
       // cout <<  i * f(r) << endl;
    }
    cout << ans << endl;
}