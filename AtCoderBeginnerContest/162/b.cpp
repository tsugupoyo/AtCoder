#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main(void) 
{
    int n;
    cin >> n;
    ll ans =0;

    for(int i =1; i<=n ; ++i)
    {
        if(i%3 == 0 || i%5 ==0)
            continue;
        ans += i;
    }
    cout << ans << endl;
    return 0;
}