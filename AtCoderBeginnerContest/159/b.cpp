#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
        string s;
    cin >> s;
    int n = s.size();

    int sep = (n -1)/2;
    string first = s.substr(0, sep);
    string end = s.substr(sep + 1, sep);
   
    if(first == end)
    {
        cout << "Yes" << endl;
        return 0;
    }
   
    cout << "No" << endl;
    return 0;
}