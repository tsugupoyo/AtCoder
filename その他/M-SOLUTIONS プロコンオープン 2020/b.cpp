#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    //a b c
    rep(i, k){
        if(a >= c) {
            c *= 2;
        }
        else if(b >= c){
            c *= 2;
        } 
        else if(a >= b) {
            b *= 2;
        }
        else break;
    }
  // cout << a << " " << b << " " << c << endl;
    if(c > b && b > a && c > a) cout << "Yes" << endl;
    else cout << "No" << endl;

}
