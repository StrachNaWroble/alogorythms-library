#include <bits/stdc++.h>
using namespace std;

//lca dla kazdych podanych wierzcholkow

const int MAXX = 3e5+5;
const int INF = 1e9+5;

vector <int> V[MAXX];
queue <int> Q;
int odl[MAXX];
int up[23][MAXX];

int n, m;

void bfs(int s)
{
	for (int i=0; i<=n; i++) odl[i] = INF;
	odl[s] = 0;
	up[1][s]=s;
	Q.push(s);
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for (auto u : V[v])
			if (odl[u] == INF)
				up[1][u] = v, odl[u] = odl[v] + 1, Q.push(u);
	}	
}

void generate()
{
	for (int i=2; i<22; i++)
		for (int j=0; j<n; j++)
			up[i][j] = up[i-1][up[i-1][j]];
}

int nadgon(int x, int y)
{
	int r = odl[y] - odl[x], skok=1;	
	cout << x << " " << y << " " << odl[x] << " " << odl[y] << " " << r << '\n';
	while (r > 0)
	{
		if (r % 2 == 1) 
			y = up[skok][y];
		skok++;
		r /= 2;
	}
	return y;
}

int main()
{
	cin >> n;
	for (int i=0; i<n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	
	bfs(0);
	//for (int i=1; i<=n; i++) cout << i << " : " << odl[i] << '\n';
	generate();
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << odl[x] << " " << odl[y] << '\n'; 
		if (odl[x] > odl[y]) swap(x, y); //x jest wyzej  
		y = nadgon(x, y);
		int skok = 22;
		cout << x << " " << y << '\n'; 
		while (up[1][x] != up[1][y])
		{
			if (up[skok][x] != up[skok][y])
				x = up[skok][x], y = up[skok][y];
			skok--;
		}
		cout << up[1][x]+1 << '\n';
	}
	
	
	
	return 0;
}

