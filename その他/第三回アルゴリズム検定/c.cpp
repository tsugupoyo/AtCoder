#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   ll a, r, n;
   cin >> a >> r >> n;
   // = a * r *(n-1); 
   ll ans = a * pow(r,(n-1));
   if(ans > 1000000000 || ans < 0) cout << "large";
   else cout << ans;
   cout << endl;
}
