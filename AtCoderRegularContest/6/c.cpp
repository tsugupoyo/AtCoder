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
   vector<int> ans;
   rep(i,n) 
   {
      int w;
      cin >> w;
      int index = -1;
      int m= INF;
      rep(j,ans.size())
      {
         if(ans[j] >= w) if(m > ans[j])
         {
            m = ans[j];
            index = j;
         }
      }
      if(index != -1) ans[index] = w;
      else ans.push_back(w);
   }
   cout << ans.size() << endl;
}