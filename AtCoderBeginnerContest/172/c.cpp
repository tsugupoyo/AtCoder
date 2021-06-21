#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    vector<ll> b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    int cnt1 = 0;
    ll sum = 0;
    rep(i,n)
    {
        if(sum + a[i] <= k)
        {
            cnt1++;
            sum += a[i];
        }
        else break;
    }
    int size = cnt1;
    int ans = cnt1;
    int b_index = 0;

    while(1)
    {
        if(b_index >= m) break;
        if(sum + b[b_index] <= k)
        {
            sum += b[b_index];
            b_index++;
            ans++;
        }
        else break;
    }
    int prev = ans;
    rep(i, size)
    {
        sum -= a[size -i-1];
        int cnt = 0;
        ll tmp = m - 1;
        for(ll index = b_index; index < m ; index++)
        {
            tmp = index;
            if(sum + b[index] <= k)
            {
                sum += b[index];
                cnt++;
            }
            else 
            {
                break;
            }
        }
        b_index = tmp;
        ans = max(ans, prev -1 + cnt);
        prev = prev - 1 + cnt;
    }

    cout << ans << endl;
}