#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   ll x, y;
   cin >> x >> y;
   ll ans = 0;
   while(x<= y)
   {
      x = 2*x;
      ans++;
   }
   cout << ans << endl;
   //x 2x 4x 8x 16x 32x ...
   //25 200  8
   //25 50 100 200
   //0 1 2 4
   //2^k * x = y
   //2^k = y/x;
   //log2 y/x = k
   //＊　少数点を切り捨てられてWAになる...
   //ll k = log2(y) -log2(x);
   //cout << k+1 << endl;
}