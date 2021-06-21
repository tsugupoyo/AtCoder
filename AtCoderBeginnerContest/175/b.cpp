#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int n;
   cin >> n;
   vector<ll> l(n);
   rep(i,n) cin >> l[i];
   int ans = 0;
   rep(i,n-2){
       for(int j = i+1; j < n-1; j++){
           if(l[i] == l[j]) continue;
           for(int k = j+1 ; k < n; k++){
               if(l[i] == l[k] || l[j] == l[k]) continue;
               if( (l[i] +l[j] > l[k]) && (l[i] +l[k] > l[j]) && (l[k] +l[j] > l[i])) 
               {
                   ans ++;
                  // cout << i << " " << j << " " << k << endl;
               }
           }
       }
   }

   cout << ans << endl;
}