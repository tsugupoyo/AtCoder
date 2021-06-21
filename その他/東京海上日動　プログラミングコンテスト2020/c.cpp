#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    rep(i, k)
    {
        vector<ll> memo(n+1);
        rep(j,n)
        {
            int l = j - a[j];
            int r = j + a[j]+1;
            if(l < 0) l = 0;
            if(r >= n) r = n;

            memo[l]++; memo[r]--;
        }
        rep(j,n) memo[j+1] += memo[j];
        memo.pop_back();
        if(a == memo) break;
        a = memo;
    }

    rep(i,n) cout << a[i] << " ";
    cout << endl;
}
