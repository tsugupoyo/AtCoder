#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
    int a,b;
    cin >> a >> b;

    int count = 0;
    int data = 0;

    if(a > b) {
        count = a;
        data = b;
    }else{
        count = b;
        data = a;
    }

    rep(i,count) cout << data;
    cout << endl;
}