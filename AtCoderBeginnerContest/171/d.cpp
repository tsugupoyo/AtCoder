#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    ll n, q;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> table;
    ll ans = 0;
    rep(i,n) 
    {
        cin >> a[i];
        table[a[i]]++;
        ans += a[i];
    }
    cin >> q;
    rep(i,q)
    {
        ll b, c;
        cin >> b >> c;
        ll num = c - b;
        ans = ans + table[b] * num;
        table[c] += table[b];
        table[b] = 0;
       
        cout << ans << endl;
    }
    return 0;
}