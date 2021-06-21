#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    ll a, b, v, w, t;
    cin >> a >>v >> b >> w >> t;
    if(a > b) 
    {
        a = -a;
        b = -b;
    } 
    while (t > 0)
    {
        a += v;
        b += w;
        if(a >= b)
        {
            cout << "YES" << endl;
            return 0;
        }
        --t;
    }

    cout << "NO" << endl;
}
