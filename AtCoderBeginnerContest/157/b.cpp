#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    int bingo[3][3];
    rep(i,3) rep(j,3) cin >> bingo[i][j];

    int n;
    cin >> n;
    vector<int> targets(n);
    rep(i,n) cin >> targets[i];

    bool ans[3][3];
    rep(i,3) rep(j,3) ans[i][j] = false;

    for(int target: targets){
        rep(i,3) {
            bool isTrue = false;
            rep(j,3){
                if(bingo[i][j] == target){
                    isTrue = ans[i][j] = true;
                    break;
                }  
            }
            if(isTrue) break;
        }
    }

    if( (ans[0][0] && ans[0][1] && ans[0][2])
      ||(ans[1][0] && ans[1][1] && ans[1][2])
      ||(ans[2][0] && ans[2][1] && ans[2][2])
      ||(ans[0][0] && ans[1][0] && ans[2][0])
      ||(ans[1][0] && ans[1][1] && ans[1][2])
      ||(ans[0][2] && ans[1][2] && ans[2][2])
      ||(ans[0][0] && ans[1][1] && ans[2][2])
      ||(ans[0][2] && ans[1][1] && ans[0][2]))
      {
          cout << "Yes" << endl;
      }else{
          cout << "No" << endl;
      }
} 