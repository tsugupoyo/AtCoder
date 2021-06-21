#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    ll n;
    cin >> n;
    ll ans =0;
    rep(i,n)
    {
        ll a,b;
        cin >> a >> b;
        ans += (b+a) * std::floor((b-a+1)/2);
        if((b-a+1)%2 != 0) ans += (b+a)/2; 
    }
    cout << ans << endl;
    return 0;
}