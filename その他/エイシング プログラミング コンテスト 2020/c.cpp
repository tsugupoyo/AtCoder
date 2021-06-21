#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int  num [10005];

void f(int n)
{
    int m = sqrt(n);
    rep(i,m) rep(j,m) rep(k,m)  
    {
        int x = i+1;
        int y = j+1;
        int z = k+1;
        int index = x*x + y*y + z*z + x*y + y*z + z*x;
        if(index < 10005) num[index]++;
    }
}

int main()
{
    int n;
    cin >> n;
    f(n);
    rep(i,n) cout << num[i+1] << endl;
    return 0;
}
