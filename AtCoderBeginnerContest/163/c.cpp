#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main(void) 
{
    int n;
    cin >> n;

    vector<int> a(n-1);
    rep(i,n-1) cin >> a[i];
    vector<int> ans(n +1);

    rep(i, n-1) 
    {
       ans[a[i]]++;
    }

    for(int i = 1; i < n + 1; i++) cout << ans[i] << endl;

    return 0;
}