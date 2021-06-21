#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int a,b,c,d;
   cin >> a >> b >> c >> d;

   while(a > 0)
   {
       c = c - b;
       if(c <= 0)
       {
           cout << "Yes" << endl;
           return 0;
       }
       a = a - d;
   }

   cout << "No" << endl;
}