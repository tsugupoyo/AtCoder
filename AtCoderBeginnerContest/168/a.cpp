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
   int r = n%10;
   if(r == 3) cout << "bon" << endl;
   else if((r == 0 || r == 1 || r== 6 ||r == 8)) cout << "pon" <<endl;
   else cout << "hon" << endl;
   return 0;
}