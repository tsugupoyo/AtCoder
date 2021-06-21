#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int t, n, m;
   cin >> t >> n;
   vector<int>a(n);
   vector<bool> used(n);
   rep(i,n) 
   { 
      cin >> a[i];
      used[i] = false;
   }
   cin >> m;
   vector<int>b(m);
   rep(i,m) cin >> b[i];

   rep(i,m)
   {
      bool ok = false;
      rep(j,n)
      {
         if(used[j]) continue;
         if(b[i] >= a[j] && b[i] <= a[j] + t) 
         {
            ok = true;
            used[j] = true;
            break;
         }
      }
      if(!ok)
      {
         cout << "no" << endl;
         return 0;
      }
   }

   cout << "yes" << endl;
}