#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll>p(n+1,0);
    rep(i,n) cin >> p[i+1];
    vector<ll> t((n+1)*(n+1));

    //２本固定する
    rep(i,p.size())
    {
        rep(j,p.size())
        {
            t[i*n+j] =p[i] + p[j];
        }
    }
    sort(t.begin(), t.end());
    ll ans = 0;
    rep(i,p.size())
    {
        rep(j,p.size())
        {
            ll sum = p[i] + p[j];
            if(sum > m) continue;
            //二分探索で探す
            ll l = 0, r = (n+1)*(n+1)-1;
            while(l + 1 < r)
            {
                ll mid = (l + r)/2;
                ll all = sum + t[mid];
                if(all > m) r = mid;
                else if(all == m)
                {
                    cout << m << endl;
                    return 0;
                }
                else 
                {
                    l = mid;
                    ans = max(ans, all);
                }
            }
        }
    }
    cout << ans << endl;
}
