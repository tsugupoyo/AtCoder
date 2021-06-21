#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

ll mod = 1000000007;

int main(void) 
{
   int n, k;
   cin >> n >> k;
   priority_queue<ll> a;
   priority_queue<ll, vector<ll>, std::greater<ll>> b;
   vector<ll> b2;
   rep(i,n)
   {
      int tmp = 0;
      cin >> tmp;
      if(tmp < 0)
      {
         b.push(tmp);
         b2.push_back(tmp);
      }
      else a.push(tmp);
   }

   ll ans = 1;
   if(a.size() == 0 && k%2 != 0){
      sort(b2.rbegin(), b2.rend());
      rep(i,k){
         ans *= b2[i];
         ans %= mod; 
      }
      ans = (ans%mod+mod)%mod;
      cout << ans << endl;
      return 0;
   }
   if(a.size() == 0){
      rep(i,k){
         ll tmp = b.top();
         ans *= tmp;
         ans %= mod; 
         b.pop();
      }

      cout << ans << endl;
      return 0;
   }

   if(b.size() == 0){
      rep(i,k){
         ll tmp = a.top();
         ans *= tmp;
         ans %= mod;
         a.pop();
      }
      cout << ans << endl;
      return 0;
   }

   ll preva = 1;
   ll prevb = 1;
   rep(i,k){
      ll ta = a.top();
      ll tb = b.top();

      if(ta >= abs(tb)){
         ans *= ta;
         a.pop();
         preva = ta;
      } else {
         ans *= tb;
         b.pop();
         prevb = tb;
      }
      ans %= mod;
   }

   if(ans < 0){
      ll ta = a.top();
      ll tb = b.top();
      if(ta > tb){
         ans /= prevb;
         ans *= ta;
      } else {
         ans /= preva;
         ans *= tb;
        // ans = (ans%mod+mod)%mod;
      }
         ans %= mod;
   }

   cout << ans << endl;

}