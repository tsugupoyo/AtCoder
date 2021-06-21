#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    string s;
    cin >> s;
    vector<int> table(10,0);
    vector<int> bottom;
    int s_size = s.size();
    rep(i,s_size)
    {
        int a = (int)(s[i] - '0');
        table[a]++;
        if((a%2 == 0) && std::find(bottom.begin(),bottom.end(), a) == bottom.end()) bottom.push_back(a);
    }
    int b_size = bottom.size();

    if(s_size == 1)
    {
        int a = (int)(s[0] - '0');
        if(a %8 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    else if(s_size == 2)
    {
        rep(i, b_size)
        {
            int b = bottom[i];
            table[b]--;
            rep(j,9)
            {
                if(table[j+1] == 0) continue;
                int bb = j+1;
                table[j+1]--;
                int target = bb*10+b;
                target /=2;
                if(target%4 == 0)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            table[b]++;
        }
        cout <<"No" << endl;
        return 0;
    }

    if(b_size == 0)
    {
        cout << "No" << endl;
        return 0;
    }
    rep(i, b_size)
    {
        int b = bottom[i];
        table[b]--;
        rep(j,9)
        {
            if(table[j+1] == 0) continue;
            int bb = j+1;
            table[j+1]--;
            rep(k,9)
            {
                if(table[k+1] == 0) continue;
                int bbb = k+1;
                int target = bbb*100 + bb*10+b;
                target /=2;
                if(target%4 == 0)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            table[j+1]++;
        }
         table[b]++;
    }
    cout << "No" << endl;
    return 0;
}