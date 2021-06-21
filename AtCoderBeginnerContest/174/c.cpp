#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int k;
   cin >> k;

   if(k%2 == 0){
       cout << -1 << endl;
       return 0;
   }

   for(int i = 1; i < 1000000; i++){
        string str = to_string(ll(k*i));
        int seven = count(str.cbegin(), str.cend(), '7');
        if(str.size() == seven)
        {
            cout << seven << endl;
            return 0;
        }
   }
   cout << k-1 << endl;
}