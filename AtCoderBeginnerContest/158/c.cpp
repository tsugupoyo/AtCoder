#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
   int a, b;
   cin >> a >> b;
  
   for(int i = 0; i < 10000; i++)
   {
      int a_ = i *8/100;
      int b_ = i/10;
      if( a == a_ && b == b_) 
      {
         cout << i << endl;
         return 0;
      }
   }
   cout << -1 << endl;

}