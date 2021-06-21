#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
    ll h,n;
    cin >> h >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    rep(i,n){
        h = h - a[i];
        if(h <= 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}