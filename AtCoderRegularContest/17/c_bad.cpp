#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main()
{
   int n;
   ll x;
   cin >> n >> x;
   vector<ll>w(n);
   rep(i,n) cin >>w[i];

   int a = n/2;
   int b = n - a;

   map<ll,ll> num;
   vector<ll> a_sum;
   rep(k,1 << a)
   {
      ll sum = 0;
      rep(i,a) 
      {
         if(k >> i&1)
         {
            sum += w[i];
         }       
      }
      a_sum.push_back(sum);
      num[sum]++;
   }
   vector<ll> b_sum;
   rep(k,1 << b)
   {
      ll sum = 0;
      rep(i,b) 
      {
         if(k >> i&1)
         {
            sum += w[i+a-1];
         }       
      }
      b_sum.push_back(sum);
      num[sum]++;
   }
   num[0] = 0;
   sort(a_sum.begin(), a_sum.end());
   sort(b_sum.begin(), b_sum.end());

   ll ans = 0;
   rep(i,a_sum.size())
   {
      ll l = 0;
      ll r = b_sum.size() -1;
      while(l + 1 < r)
      {
         ll mid = (l + r)/2;
         ll sum = a_sum[i] + b_sum[mid];
         if(x == sum)
         {
            cout << num[a_sum[i]] * num[b_sum[mid]] << endl;
            ans += num[a_sum[i]] * num[b_sum[mid]];
            break;
         }
         else if(x > sum) l = mid;
         else r = mid;
      }
   }

   cout << ans << endl;
}