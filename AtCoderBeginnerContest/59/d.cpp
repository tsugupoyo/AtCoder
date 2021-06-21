#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   ll x, y;
   cin >> x >> y;

   //   xy 1 2 3 4 5
   //    1 L L W W W
   //    2 L L L W W
   //    3 W L L L W
   //    4 W W L L L
   //    5 W W W L L
   // x-yの絶対値が 0か1の時は負ける。
   // それ以外は勝ちパターンに持っていける
   ll a = abs(x -y);
   if(a != 1 && a != 0) cout << "Alice" << endl;
   else cout << "Brown" << endl;
}