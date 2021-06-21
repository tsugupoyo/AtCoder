#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
    int n;
    cin >> n;
    vector<int> p(n);

    rep(i,n) cin >> p[i];
    int ans = n;
    int low = p[0];
    for(int i = 1; i < n ; i++)
    {
        if(p[i] > low)
        {
            --ans;
        }
        else low = p[i];
    }

    cout << ans << endl;
}