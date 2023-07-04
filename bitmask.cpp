#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e6+5;
int A[MAXX];

void maska(int n)
{
	for (int bm=0; bm<(1<<n); bm++)
	{
		for (int i=0; i<n; i++)
		{
			if (bm & (1<<i))
				cout << 1 << " ";
			else
				cout << 0 << " ";		
		}
		cout << '\n';
	}
}

int main()
{
	int n;
	cin >> n;	
	maska(n);
	return 0;
}
