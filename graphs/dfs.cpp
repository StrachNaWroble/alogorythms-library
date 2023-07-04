#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e6+5;
vector <int> V[MAXX];
bool vis[MAXX];

void DFS(int v)
{
	vis[v] = true;
	cout << v << " ";
	for (auto u : V[v])
		if (!vis[u])
			DFS(u);
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i=0; i<n; i++)
		if (!vis[i])
			DFS(i);
	
}
