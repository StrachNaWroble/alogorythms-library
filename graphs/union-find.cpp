#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e6+5;
int boss[MAXX];

int Find(int a)
{
	if (boss[a] == a) return a;
	return boss[a] = Find(boss[a]);
}

void Union(int a, int b)
{
	int bossA = Find(a);
	int bossB = Find(b);
	boss[bossA] = boss[bossB];
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) boss[i] = i;
	
	for (int i=0; i<m; i++)
	{
		string s;
		cin >> s;
		int a, b;
		cin >> a >> b;
		if (s == "?")
		{
			if (Find(a) == Find(b)) 
				cout << "TAK" << '\n';
			else 
				cout << "NIE" << '\n';
		}
		else
		{
			Union(min(a, b), max(a, b));
		}
	}
	return 0;
}
