#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   ll a, b, c, k;
   cin >> a >> b >> c >> k;

    ll ans = k;
   if(k <= a) {
       cout << ans << endl;
       return 0;
   }

   k = k - a;

   if(k <= b){
       cout << a << endl;
       return 0;
   }
   k = k - b;

   cout << a - k << endl;
}