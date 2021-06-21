#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
const ll LLINF = 1000000000000000000;

//ACになるが、多分間違っている
//１つしか辺がない場合しか探索できない
int main()
{
   int n, m;
   cin >> n >> m;
   vector<int> data[n];
   rep(i,m){
      int a, b;
      cin >> a >> b;
      --a; --b;
      data[a].push_back(b);
      data[b].push_back(a);
   }
   bool update =true;
   int ans =0;
   while(update){
      update = false;
      rep(i,n){
         if(data[i].size() == 0) continue;
         else if(data[i].size() == 1)
         {
            int index = data[i].back(); 
            data[i].pop_back();
            auto e = remove(data[index].begin(), data[index].end(), i);
            data[index].erase(e, data[index].end());
          //  cout << "---" << i << " " << index << "---" << endl;
           // data[index].erase(data[index].begin());
            ++ans;
            update = true;
         }
      }
   }
   cout << ans << endl;
}