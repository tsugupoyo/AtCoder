#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int d, g;
   cin >> d >> g;
   vector<int>p(d);
   vector<int>c(d);
   rep(i,d) {
      cin >> p[i] >> c[i];
   }

   vector<bool> used(d);
   int ans = INF;
   rep(i,1 << d)
   {
      int sum =0;
      int tmp = 0;
      rep(a,d) used[a] = false;
      rep(j, p.size())
      {
         if(i >> j&1)
         {
            //この配列を使う場合
            sum += p[j] * (j+1) * 100 + c[j];
            tmp += p[j];
            used[j] = true;
         }
      }
      int index = -1; 
      for(int k = p.size() -1; k >=0; k--)
      {
         if(!used[k])
         {
            index = k;
            break;
         }
      }
      if(index == -1) 
      {
         //全使用
         if(sum >= g) ans = min(ans, tmp);
      }
      else{
      rep(k,p[index]+1){
         if(sum >= g)
         {
            //全使用
            ans = min(ans, tmp);
            break;
         }
         sum += (index+1) * 100;
         tmp++;
      }
      }
   }
   cout << ans << endl;
}