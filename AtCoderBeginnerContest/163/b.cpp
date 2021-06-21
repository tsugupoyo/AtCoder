#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main(void) 
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m);

    rep(i,m) cin >> a[i];

    ll num =0;
    rep(i,m) num += a[i];

    if(n < num) cout << -1 << endl;
    else cout << n -num << endl;
    return 0;
}