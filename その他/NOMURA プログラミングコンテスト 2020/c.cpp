#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n+1) cin >> a[i];
    ll par = 0;
    ll ans = 0;

    rep(i,n+1)
    {
        if(i == n) 
        {
            //最後
            if(par * 2 != a[i])
            {
                cout << -1 <<endl;
                return 0;
            }
        }
        else if(i == 0)
        {
            if(a[i] != 0)
            {
                cout << -1 << endl;
                return 0;
            }
            par = 1;
            ans++;
            continue;
        }
        else if(par * 2 <= a[i])
        {
            cout << -1 << endl;
            return 0;
        }
        ll mx = 2 * par -a[i];
        ans += a[i];
        ans += par;
        cout << ans << " " << par << endl;
    }
    cout << ans << endl;
}
