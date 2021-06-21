#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    string s,t;
    cin >> s >> t;
    ll ans =0;
    rep(i,s.size())
    {
        if(s[i] != t[i]) ++ans;
    }
    cout << ans << endl;
    return 0;
}