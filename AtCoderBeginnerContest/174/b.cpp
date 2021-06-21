#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    int n;
    ll d;
    cin >> n >> d;
    ll ans = 0;
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        long double sum = sqrtl(x*x + y*y);
        if(sum <= d) ans++;
    }

    cout << ans << endl;
}