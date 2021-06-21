#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;


const string zero_2 =".#.#";

const string one_0 ="..#.";
const string twe_3 = ".#..";

const string three_1 = "...#";
const string three_2 = ".###";
const string three_3 = "...#";
const string four_0 =".#.#";
const string five_1 =".#..";
const string five_3 ="...#";
const string six_1 =".#..";
const string six_3 =".#.#";
const string seven_1 ="...#";
const string seven_2 ="...#";
const string eight_1 =".#.#";
const string eight_2 =".###";
const string eight_3 =".#.#";


int main()
{
   int n;
   cin >> n;

   vector<string> s(5);
   rep(i,5) cin >> s[i];
   int start = 0;
   string ans = "";
   rep(i, n)
   {
      string zero = s[0].substr(start, 4);
      string one = s[1].substr(start, 4);
      string twe = s[2].substr(start, 4);
      string three = s[3].substr(start, 4);
      if(zero == one_0)
      {
         ans += "1";
      }
      else if(zero == four_0){
         ans += "4";
      } else if( twe == zero_2) {
         ans += "0";
      } else if( three == twe_3) {
         ans += "2";
      } else if(one == three_1 && twe == three_2&& three == three_3) {
         ans += "3";
      } else if(one == five_1 && three == five_3) {
         ans += "5";
      } else if(one == six_1 && three == six_3) {
         ans += "6";
      } else if(one == seven_1 && twe == seven_2) {
         ans += "7";
      } else if(one == eight_1 && twe == eight_2 && three == eight_3) {
         ans += "8";
      }
      else {
         ans += "9";
      }
      //位置更新
      start += 4;
   }
   cout << ans << endl;
}
