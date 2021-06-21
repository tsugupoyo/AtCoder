#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    int l, r, d, ans =0;
    cin >> l >> r >> d;

    for(int i = l; i <= r; i++)
    {
        if(i%d == 0) ans++;
    }
    cout << ans << endl;
}
