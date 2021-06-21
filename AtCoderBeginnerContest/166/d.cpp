#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

ll f(ll a, ll b)
{
   return pow(a,5) - pow(b,5);
}

ll ff(ll a, ll b){
    if(a > 0){
        return a - b;
    }
    else
    {
        if(b > 0) return b -a;
        else return abs(a) -abs(b);
    }
}

int main(void) 
{
    ll x;
    cin >> x;
    int inf = 200;
    
    int L = -inf, R =inf;
    for(int a = 0; a <= inf ; a++){
        int l = -inf, r = inf;
        while(l +1 < r)
        {
            int mid = (l + r)/2;
            ll ret = f(a,mid);
            if(ret == x)
            {
                cout << a << " " << mid << endl;
                return 0;
            }
            else if(ret < x){
                r = mid;
            }
            else{
                l = mid;
            }
        }      
    }
    return 0;
}