#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using P = pair<int,int>;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<P> sc(m);
    rep(i,m)  {
        int s,c;
        cin >> s >> c;
        sc[i] = (P(s,c));
    }

    vector<int>ans(n);

    rep(i,m){
        int index = sc[i].first -1;
        if((ans[index] != 0 && ans[index] != sc[i].second)
        ||(n >= 2 && index == 0 && sc[i].second == 0)){
            //すでに値が入っているまたは先頭が0
            cout << -1 << endl;
            return 0;
        }
        ans[index] = sc[i].second;
    } 
    if(n == 1) {
        if( m == 0)  
            cout << 0 << endl;
        else
            cout << ans[0] << endl;
        return 0;
    }

    if(ans[0] == 0) {
        ans[0] = 1;
    }

    rep(i,n) cout << ans[i];
    cout  << endl;
} 