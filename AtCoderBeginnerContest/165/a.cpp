#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int k, a, b;
   cin >> k >> a>> b;
   for(int i = a; i <= b; i++){
      if(i%k == 0){
         cout << "OK" << endl;
         return 0;
      }
   }
   cout << "NG" << endl;
}