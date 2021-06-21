#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main()
{
   int n;
   cin >> n;
   vector<P> a(n);
   vector<P> b(n);
   vector<bool> used(n);
   rep(i,n)
   {
      int x, y;
      cin >> x >> y;
      a[i] = P(x,y);
      used[i] = false;
   }

   rep(i,n)
   {
      int x, y;
      cin >> x >> y;
      b[i] = P(x,y);
   }

  // sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   int ans = 0;
   rep(i,n)
   {
      int x = b[i].first;
      int y = b[i].second;
      int m = -1;
      int index = -1;
      rep(j,n)
      {
         if(used[j]) continue;
         if(x > a[j].first && y > a[j].second)
         {
            if(m < a[j].second)
            {
               index = j;
               m = a[j].second;
            }
         }
      }
      //cout << index << " :";
      if(index != -1)
      {
          ans++;
          used[index] = true;
      }
   }
   cout << ans << endl;
}