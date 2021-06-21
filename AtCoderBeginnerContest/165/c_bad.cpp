#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int n, m, q;
   cin >> n >> m >> q;
   int a[q][4];
   rep(i,q){
       cin >> a[i][0] >> a[i][1]  >> a[i][2] >> a[i][3];
   }
    ll ans = 0;
    int A[n];


    rep(i,n){

        rep(x,q){
            for(int j = a[x][2]; j < n;j++){
                ll tmp =0;
                A[a[x][1]-1] = j;
                A[a[x][0]-1] = j - a[x][2]; 
                
                if(A[a[x][1]-1] - A[a[x][0]-1] == a[x][2])
                {
                    tmp += a[x][3];
                }
                    ans = max(ans, tmp);
            }
        }
   }

   cout << ans <<endl;
}