#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int main()
{
   ll n, l, t;
   cin >> n >> l >> t;
   vector<ll> x(n), w(n);
   rep(i,n) cin >> x[i] >> w[i];
   vector<ll> tmp(n);
   ll start = 0;
   rep(i,n)
   {
      if(w[i] == 1)
      { 
         tmp[i] = (x[i] + t)%l;
         start+=(x[i]+t)/l%n;
      }
      else 
      {
         tmp[i] = (l + (x[i] - t)%l)%l;
			if(x[i]-t<0) start-=(t-x[i]+l-1)/l%n;
      }
      cout << start << endl;
     // cout << tmp[i] << endl;
   }
   sort(tmp.begin(), tmp.end());
   start=(start%n+n)%n;
   rep(i,n) cout <<  tmp[(i+start)%n]  << endl;
}