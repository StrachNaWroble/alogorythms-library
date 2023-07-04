#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e6+5;
const int MOD = 1e9+7;
const int B = 31;

string s;
int pot[MAXX];
int sil[MAXX];
int tab[MAXX];

void fillhasz()
{
	pot[0] = 1, sil[0] = 1;
	for (int i=1; i<MAXX-1; i++)
		pot[i] = (pot[i-1] * B) % MOD,
		sil[i] = (sil[i-1] * i) % MOD;
	
	for (int i=1; i<=s.size(); i++)
		tab[i] = ((B * tab[i-1] + (s[i-1] - 'a' + 1))%MOD + MOD) % MOD;
}

int hasz(int i, int j)
{
	return ((tab[j] - tab[i-1]*pot[j-i+1])%MOD + MOD) % MOD ;
}

int main()
{
	cin >> s;
	s = s + '#';
	fillhasz();
	for (int i=0; i<=s.size(); i++)
		cout << tab[i] << " ";
	int q;
	cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << hasz(a, b) << '\n';
	}
	return 0;
}
