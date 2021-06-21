#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    int k,n;
    cin >> k >> n;
    vector<int> a(n);

    rep(i,n) cin >> a[i];

    //差を求めて一番大きいところを探す
    int longest = 0;
    rep(i,n -1) {
        int dis = abs(a[i + 1] - a[i]);
        if(longest < dis)
        {
            longest = dis;
        } 
    }

    int lastdis = abs(k - a[n -1] + a[0]);
    if(longest < lastdis)
    {
        longest = lastdis;
    } 

    cout << k - longest << endl;
}