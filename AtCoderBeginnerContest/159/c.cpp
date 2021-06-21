#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    double input;
    cin >> input;
    double len = input / 3;
    double result = len * len * len;

    printf("%.10f\n", result);
    return 0;
}