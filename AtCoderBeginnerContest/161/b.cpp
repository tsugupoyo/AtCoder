#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main(void) 
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    //大きい順
    sort(a.rbegin(),a.rend());

    ll sum = 0;
    rep(i,n) sum += a[i];

    rep(i,m) 
    {
        if( 4*m*a[i] < sum)
        { 
            cout << "No" << endl;
            return 0;
        }
        //選択可
    }
    cout << "Yes" << endl;

}
