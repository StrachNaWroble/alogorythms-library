#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e6;
bool S[MAXX+5];

void sito() //0 --> pierwsza
{
	for (int i=2; i<=MAXX; i++)
		if (S[i] == 0)
			for (int j=2*i; j<=MAXX; j+=i)
				S[j] = 1;	
}

int main()
{
	sito();
	for (int i=1; i<20; i++)
		cout << i << " : " << S[i] << '\n';
	
	return 0;
}
