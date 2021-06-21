#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];

    int max = *max_element(x.begin(), x.end());
    int min = *min_element(x.begin(), x.end());
    int ans =INF;
    for(int p = min; p <=max; ++p)
    {
        int sum = 0;
        rep(i,n) sum += (x[i] -p)*(x[i] -p);
        if( ans > sum) ans = sum;
    }
    cout << ans << endl;
}