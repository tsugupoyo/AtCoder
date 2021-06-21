#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    int ans = x;
    int base = 1;
    while(1)
    {
        bool exist = false;
        rep(i,n)
        {
            if(ans == p[i])
            {
                exist = true;
                break;
            }
        }
        if(!exist) break;
        if(base%2 != 0) ans -= base;
        else ans += base;
        base++;
    }

    cout << ans << endl;
}