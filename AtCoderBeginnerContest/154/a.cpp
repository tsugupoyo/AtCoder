#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{    
    string s,t,u;
    int a,b;   
    cin >> s >> t >> a >> b >> u;

    if( s == u)
        --a;
    else
        b--;
    printf("%d %d\n",a,b);

}