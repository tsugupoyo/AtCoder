#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

const char a[26] ={'a','b','c', 'd','e', 'f', 'g', 'h', 'i', 'j', 'k','l','m','n','o', 'p', 'q', 'r', 's', 't','u', 'v', 'w', 'x', 'y', 'z'};

int main(void) 
{
    ll n;
    cin >> n;
    ll tmp = n;
    ll base = 26;
    ll cnt =0;  //桁数
    while(tmp > 0) 
    {
        tmp -= base;
        base *= 26;
        cnt++;
    }
    vector<char> ans(cnt);
    rep(i,cnt)
    {
        ll rem = (n%26) -1;
        n = n/ 26;
       // cout << n << " " << rem << endl;
        if( rem == -1) 
        {
            ans[cnt -i-1] = 'z';
            n--;
        }
        else ans[cnt-i-1] = a[rem];
    }

    rep(i,cnt) cout << ans[i];
    cout << endl;
    return 0;
}