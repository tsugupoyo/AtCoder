#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

P GetPair(int i)
{
    int a = i %10;
    int b = 0;

    while(i){
        b = i;
        i /= 10;
    }
    return P(a,b);
}

int main()
{    
    int n;
    cin >> n;

    map<P,int> freq;
    for(int i = 1; i <= n ; ++i){
        P p = GetPair(i);
        freq[p]++;
    }
    ll ans =0;
    for(int i = 1; i <= n ; ++i){
        P p = GetPair(i);
        //ペアを探すために入れ替える
        P q(p.second, p.first);
        ans += freq[q];
    }

    cout << ans << endl;
}