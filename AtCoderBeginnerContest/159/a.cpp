#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

//nC2
ll choose2(ll n)
{
    return n *(n-1)/2;
}

int main()
{
    int n,m;
    cin >> n >>m;
    int ans = choose2(n) + choose2(m);
    cout << ans << endl;
    return 0;
}