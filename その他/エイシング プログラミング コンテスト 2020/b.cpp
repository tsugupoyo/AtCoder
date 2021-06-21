#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    int n ;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n)
    {
        if(i %2 != 0) continue;
        if(a[i]%2 != 0) ans++;
    }

    cout << ans << endl;
}
