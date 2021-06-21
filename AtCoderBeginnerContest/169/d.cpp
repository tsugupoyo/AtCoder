#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

//最大公倍数、最小公約数
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(void) 
{
    ll n;
    cin >> n;
    ll ans = 0;
    vector<pair<ll,int>> fs;
    for (ll i = 2; i*i <= n; ++i) 
    {
        int x = 0;
        while (n%i == 0) {
        n /= i;
        ++x;
        }
        fs.emplace_back(i,x);
    }
    
    if (n != 1) fs.emplace_back(n,1);
    
    for (auto p : fs) 
    {
        int x = p.second;
        int b = 1;
        while (b <= x) 
        {
            x -= b;
            b++;
            ++ans;
        }
    }
    cout << ans << endl;
}