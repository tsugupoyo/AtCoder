#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

/*
string += string 
string + string + string
は文字列の長さ分push_back()するので遅い


https://marycore.jp/prog/cpp/concat-append-string/
https://blog.j5ik2o.me/entry/20110222/1298380551

*/

int main()
{
   string s;
   int q;
   cin >> s >> q;

   deque<char> que;
   for(char x : s) que.push_back(x);
   bool isReverse = false;

   rep(i,q){
      int t;
      cin >> t; 
      if(t != 1) 
      {
         int f; char str;
         cin >> f;
         cin >> str;

         if(isReverse) f = 3-f;
         if(f == 1) que.push_front(str);
         else que.push_back(str);
      }
      else
      {
         isReverse = !isReverse;
      }
      
   }

   string ret;
   if(isReverse) reverse(que.begin(), que.end());
   for(char c : que) ret+=c;
   cout << ret << endl;
}