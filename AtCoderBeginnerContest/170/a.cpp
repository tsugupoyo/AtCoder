#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   vector<ll> x(5);
   rep(i,5) cin >> x[i];
   rep(i,5)
   {
      if(x[i] == 0)
      {
         cout << i+1 << endl;
         return 0;
      }
   }
}