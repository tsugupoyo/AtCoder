#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

const int Max = 1000005;
int main(void) 
{
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i,n) cin >> a[i];

   vector<int> memo(Max);
   rep(i,n)
   {
       if(memo[a[i]] != 0){
           memo[a[i]] =2;
       }
       else
       {
           for(int x = a[i]; x < Max; x+=a[i]) memo[x]++;
       }
   }
   int ans =0;
   rep(i,n) if(memo[a[i]] == 1) ans++;
   cout << ans << endl;
}