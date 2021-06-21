#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int GetCommon(int a, int b, int c)
{
    int m = min(a,b);
        m = min(m,c);

    for(int i = m; i >0; --i)
    {
        if(a%i ==0 && b%i ==0 && c%i ==0)
        {
            return i;
        }
    }
    return 1;
}

int main(void) 
{
    int k;
    cin >> k;
    ll ans =0;

    for(int a = 1; a <=k ; ++a)
    for(int b = 1; b <=k ; ++b)
    for(int c = 1; c <= k; ++c)
    ans += GetCommon(a,b,c);

    cout << ans << endl;
    return 0;
}