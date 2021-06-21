#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main()
{
   int n, m;
   cin >> n >> m;
   P p[m];
   rep(i,m)
   {
      int a, b;
      cin >> a >> b;
      p[i] =P(b,a);
   }
   sort(p,p+m);
   reverse(p, p+m);
   vector<int> cut;
   int prev = -1;
   rep(i,m)
   {
      int start = p[i].second;
      int end = p[i].first;
     // cout << start << " " << end << " " << prev << endl;
      if(prev!= -1)
      {
         if(end > prev)
         {
            if(prev < start) prev = start;
         } 
         else {
            prev = start;
            cut.push_back(start);
         }
      }
      else
      {
         prev = start;
         cut.push_back(start);
      }

   }
   cout << cut.size() << endl;
}