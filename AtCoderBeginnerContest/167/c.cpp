#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,vector<int>>;

int a[12][12];

int main(void) 
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int>c (n);
    rep(i,n) {
        cin >> c[i];
        rep(j,m){
            cin >> a[i][j];
        }
    }
    int ans = INF;
    //全探索　ビットを使う
    //買う = 1 買わない = 0 
    rep(i,1 << n){
        int cost = 0;
        vector<int> d (m);
        rep(j,n){
            if(i >> j & 1){
                //買う
                cost += c[j];
                rep(k,m) d[k] += a[j][k];
            }
        }

        bool ok = true;
        rep(k,m) if(d[k] < x) ok =false;
        if(ok) ans = min(ans,cost);
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

