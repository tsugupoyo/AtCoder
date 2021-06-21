#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const ll INF =110000000000000;
using P = pair<int,int>;

int n;
vector<ll> h,s;

bool check(ll v)
{
   vector<double> t(n);
   rep(i,n) 
   {
      if(h[i] > v) return false;
      // v = h + s *t ⇨　t = v -h /s
      t[i] = (double)(v- h[i])/s[i];
   }
   sort(t.begin(),t.end());
   rep(i,n)
   {
      if(t[i] < i) return false;
   }
   return true;
}

int main()
{
   cin >> n;
   h.resize(n);
   s.resize(n);
   rep(i,n)
   {
      cin >> h[i] >> s[i];
   }

   ll left = 0, right = INF;

   while(right - left > 1)
   {
      ll mid = (right + left) /2;
      if(check(mid)) right = mid;
      else left = mid;
   }
   cout << right << endl;
}