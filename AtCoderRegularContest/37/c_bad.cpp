#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

//5点分しか通らなかった
//時間とメモリが足らないので、他の方法を考えないといけない
int main()
{
   int n, k;
   cin >> n >> k;
   vector<ll> a(n),b(n);
   rep(i,n) cin >> a[i];
   rep(i,n) cin >> b[i];
   vector<ll> table(n*n);
   rep(i,n)
   {
      rep(j,n)
      {
         table[i*n+j] = a[i]*b[j];
      }
   }
   sort(table.begin(),table.end());

   cout << table[k-1] << endl;
}