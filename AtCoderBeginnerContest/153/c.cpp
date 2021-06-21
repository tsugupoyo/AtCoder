#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
    ll n, k;
    cin >> n >> k;

    if(n <= k) 
    {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    
    sort(h.rbegin(), h.rend());

    rep(i,k) h[i] = 0;

    ll ans = 0;
    rep(i,n) ans += h[i];

    cout << ans << endl;
}