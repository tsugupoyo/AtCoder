#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    string t;
    cin >> t;

    rep(i,t.size())
    {
        if(t[i] != '?') continue;
        if(i == t.size()-1) t[i] = 'D';
        else if(i != 0 && t[i-1] == 'P') t[i] = 'D';
        else if(t[i+1] == 'D') t[i] = 'P';
        else t[i] = 'D';
    }
    cout << t << endl;
}
