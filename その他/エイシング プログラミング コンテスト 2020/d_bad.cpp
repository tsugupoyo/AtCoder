#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int bitnum(long bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int bitnum(string s)
{
    int ans = 0;
    rep(i,s.size())
    {
        if(s[i] == '1') ans++;
    }
    return ans;
}

ll strbin2i (const string &s) {

    ll out = 0;

    for (int i = 0, size = s.size() ; i < size ; ++i ) {

        out *= 2;

        out += ((int)s[i] == 49) ? 1 : 0;

    }

    return out;

}

int f(string s)
{
    int ans = 0;
    int n = bitnum(s);

    while(n > 0)
    {
        int b = bitnum(n);
        n = n%b;
        ans ++;
    }

      
    return ans;
}

int main()
{
    int n;
    string x;
    cin >> n >> x;

    rep(i,n)
    {
        string tmp = x;
        if(tmp[i] == '0') tmp[i] = '1';
        else tmp[i] = '0';
        cout << f(tmp) << endl;

    }
    return 0;

}
