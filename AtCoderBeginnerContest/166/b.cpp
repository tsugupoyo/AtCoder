#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    int n, k ;
    cin >>n >> k;
    vector<int> snuke(n);
    rep(i,k){
        int d;
        cin >> d;
        vector<int>a(d);
        rep(j,d){
            cin >> a[j];
            snuke[a[j]-1]++;
        }
    }
    int ans =0;
    rep(i,n) if(snuke[i] == 0) ans++;
    cout << ans <<endl;
}