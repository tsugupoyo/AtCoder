#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
const int mod = 1000000007;
using P = pair<int,int>;

int main(void) 
{
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];

    ll a = 0;
    ll b = 0;
    int c = 0;
    rep(i,n) 
    {
        a += abs(x[i]);
        b += pow(abs(x[i]),2);
        c = max(c, abs(x[i]));
    }

    cout << a << endl;
    printf("%.15f\n", sqrt(b));
    cout << c << endl;
    return 0;
}
