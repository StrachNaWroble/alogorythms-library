#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+5;

long long fastp(int a, int b)
{
    if (b == 0) return 1;
    if (b % 2 == 0) return fastp((a*a)%MOD, b/2);
    if (b % 2 == 1) return (fastp(a, b-1)%MOD * a)%MOD;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << fastp(a, b);


    return 0;
}
