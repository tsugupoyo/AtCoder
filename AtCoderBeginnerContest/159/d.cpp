#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

//nC2
ll choose2(ll n)
{
    return n *(n-1)/2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> data(n);
    rep(i,n) cin >> vec[i];
    rep(i,n) vec[i]--;

    rep(i,n) data[vec[i]]++;

    ll total =0;
    rep(i,n) total += choose2(data[i]);

    rep(i,n)
    {
        ll ans = total;
        ans -= choose2(data[vec[i]]);
        ans += choose2(data[vec[i]] - 1);
        cout << ans << endl;
    }
}