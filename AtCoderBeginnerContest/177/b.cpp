#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    string s, t;
    cin >> s >> t;
    int num = 0;

    rep(i,s.size()-t.size()+1)
    {
        int snum = 0;
        rep(j,t.size())
        {
            if(s[i+j] == t[j]) snum++;
        }
        num = max(num, snum);
    }

    cout << t.size() - num << endl;
}