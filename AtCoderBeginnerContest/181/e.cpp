#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n),w(m);
    rep(i,n) cin >> h[i];
    rep(i,m) cin >> w[i];
    ll ans = INF;
    rep(i,m)
    {
        ll tmp =0;
        vector<ll> hh = h;
        hh.push_back(w[i]);
        sort(hh.begin(), hh.end());
        for(int j = 0; j < n; j+=2)
        {
            tmp += hh[j+1] - hh[j];
        }

        ans = min(ans, tmp);
    }
    cout << ans << endl;
}