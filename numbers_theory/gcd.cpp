#include <bits/stdc++.h>
using namespace std;

int NWD(int a, int b)
{
	while (b != 0)
	{
		a = a%b;
		swap(a, b);
	}
	return a;	
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << NWD(a, b);
	
	
	return 0;
}
