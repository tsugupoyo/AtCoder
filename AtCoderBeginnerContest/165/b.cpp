#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   ll x;
   cin >> x;
   ll ans =0;
   ll m = 100;

   while(x > m){
       m = m * 1.01;
       ans++;
   }
   cout << ans << endl;
}