#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
    ll h;
    cin >> h;

    ll ans = 0;
    int count = 0;
    while(h){
        ans += pow(2, count);
        h = h/2;
        count++;
    }

    cout << ans << endl;
}