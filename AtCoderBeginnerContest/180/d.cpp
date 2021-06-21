#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll p = x;
    ll e = 0;
    while(p < b){
        ll tmp = p * a;
        if(tmp < y)
        {
            e++;
            p = tmp;
        } else {
            break;
        }

    }
    e += (y - p -1)/b;

    cout << e << endl;
    return 0;
}