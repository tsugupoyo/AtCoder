#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), sum(n-k+1);
    rep(i,n) cin >> a[i];
    ll tmp = 1;
    rep(i,k) tmp *= a[i];
    sum[0] = tmp;

    // for(int i = k; i < n; i++)
    // {
    //     ll t = sum[i-k];
    //     t = t * a[i] / a[i-k];
    //     sum[i-k+1] = t;
    // }

    rep(i,n-k)
    {
        if(a[i] < a[i+k]) cout << "Yes" << endl;
        else cout << "No" << endl;
       // cout << sum[i+1] << ">" <<  sum[i] << " ";
        // if(sum[i+1] > sum[i]) cout << "Yes" << endl;
        // else cout << "No" << endl;
    }
}
