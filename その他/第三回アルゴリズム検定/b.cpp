#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n, m, q;
   cin >> n >> m >> q;
   vector<int> table(m,n);
   vector<int> ans[n];
   vector<int> outs;
   rep(i,q)
   {
      int option, nn, mm;
      cin >> option >> nn;

      if(option == 2) 
      {
         cin >> mm;
         --nn; --mm;
         table[mm]--;
         ans[nn].push_back(mm);

      }
      else
      {
         //現在の点数を出力
         --nn;
         int out =0;
         for(auto tmp: ans[nn])
         {
            out += table[tmp];
         }
         outs.push_back(out);
      }
   }
   rep(i,outs.size()) cout << outs[i] << endl;
}
