#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    int n,k;
    cin >> n >> k;

    int ans =0;

    while(n >= 1)
    {
        n = n/k;
        ++ans;
    }
    cout << ans << endl;
}