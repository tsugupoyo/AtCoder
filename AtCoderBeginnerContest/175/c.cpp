#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   ll x, k, d;
   cin >> x >> k >> d;

    ll test = d/1000000000000000;
    while(test < k)
    {
         k--;
    }

   if(x < 0){
       ll b = k*d;
       ll r = x + b;
       if(r <= 0) 
       {
           cout << abs(r) << endl;
           return 0;
       } else {
           ll m = abs(x/d);
           ll num = k - m;
           if(abs (x + m*d) > abs(x+m*d +d)) 
           {
               num++;
               m++;
           }
           if((num)%2 == 0){
               cout << abs(x + m*d)<< endl;
               return 0;
           } else {
                ll tmp = x + m*d;
               cout << min( abs(tmp +d), abs(tmp-d)) << endl;
               return 0;
           }
       }

   } else {
       ll b = k*d;
       ll l = x - b;

       if(l >= 0){
           cout << l << endl;
           return 0;
       } else {
           ll m = x/d;
           ll num = k - m;
           if(abs (x - m*d) > abs(x-m*d -d))
           {
                num++;
                m++;
           }
            if((num)%2 == 0){
               cout << abs(x - m*d)<< endl;
               return 0;
           } else {
               ll tmp = x - m*d;
               cout << min( abs(tmp+d), abs(tmp-d)) << endl;
               return 0;
           }
       }
   }
}