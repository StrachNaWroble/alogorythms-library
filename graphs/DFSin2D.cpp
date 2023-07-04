#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e3+4;

char plan[MAXX][MAXX];
bool vis[MAXX][MAXX];
int di[] = {-1,-1,0,1,1,1,0,-1},
	dj[] = {0,1,1,1,0,-1,-1, -1};
int n, m;

void DFS(int i, int j)
{
	vis[i][j] = true;
	for (int k=0; k<8; k++)
	{
		int nI = i+di[k], nJ = j+dj[k];
		if (vis[nI][nJ] == true) continue;
		if (nI < 1 || nI > n || nJ < 1 || nJ > m) continue; //granice planszy
		if (plan[nI][nJ] == '#') continue; //blokada
		cout << nI << " " << nJ << '\n';
		DFS(nI, nJ);
	}
}

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> plan[i][j];
	DFS(1, 1);
	
	
	
	return 0;
}
