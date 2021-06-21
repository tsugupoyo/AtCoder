#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    ll n,m;
    cin >> n >> m;

    vector<ll> h(n);
    vector<int> tree[n];
    rep(i,n) cin >> h[i];
    rep(i,m) {
        int a, b;
        cin >> a >>b;
        --a; --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ll ans = 0;
    rep(i,n){
        bool ok = true;
        for(int target : tree[i])
        {
            if(h[i] <= h[target]) {
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans << endl;

}