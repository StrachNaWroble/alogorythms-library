#include <bits/stdc++.h>
using namespace std;

//mozliwe ze wszytsko na long longach

const int MAXX = 1e6+5;
const int MOD = 1e9+9;

long long silnia[MAXX];

long long fastpow(long long a, long long b) {
	if (b == 0) return 1;
	if (b % 2 == 0) return fastpow((a*a)%MOD, b/2);
	if (b % 2 == 1) return (a * fastpow(a, b-1)%MOD)%MOD;
}

int main() {
	long long n, k;
	cin >> n >> k;
	
	silnia[1] = 1;
	for (int i=2; i<=MAXX-3; i++)
		silnia[i] = (silnia[i-1]*i)%MOD;
	
	long long g = silnia[n];
	long long d = (silnia[k] * silnia[n-k])%MOD;
	cout << (g * fastpow(d, MOD-2)%MOD)%MOD;
	
	
	return 0;
}
