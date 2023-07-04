#include <bits/stdc++.h>
using namespace std;

//punkt przedział ustaw, suma

const int SIZE = (1<<17);

int D[SIZE*2];

void upd(int x, int wart)
{
	x += SIZE;
	D[x] = wart;
	x /= 2;
	while (x != 0)
		D[x] = D[x*2] + D[x*2+1], x /= 2;
}

int que(int a, int b)
{
	a = a + SIZE - 1;
	b = b + SIZE + 1;
	int res = 0;
	while (a/2 != b/2)
	{
		if (a % 2 == 0) res += D[a+1];
		if (b % 2 == 1) res += D[b-1]; 
		a/=2, b/=2; 
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> D[SIZE+i];
		upd(i, D[SIZE+i]);
	}
	int q;
	cin >> q;
	while (q--)
	{
		string s;
		cin >> s;
		int a, b;
		cin >> a >> b;
		if (s == "u") 
			upd(a-1, b);
		else 
			cout << que(a-1, b-1);
	}
	
	
	return 0;
}
