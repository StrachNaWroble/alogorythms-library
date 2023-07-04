#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e6+5;
const int BAZA = 1e4+5;

int boss[MAXX];
pair <int, int> kraw[MAXX];
unordered_map <long long, int> M;
vector <pair <long double, pair <int, int> > > V; 

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i=0; i<=n; i++) boss[i] = i;
    
    for (int i=0; i<n; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	M[a*BAZA+b] = i;
    	kraw[i] = {a, b};
    }

	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			auto X = kraw[i], Y = kraw[j];
			int a = abs(X.first - X.second);
			int b = abs(Y.first - Y.second);
			long double c = sqrt(a*a + b*b);
			cout << a << " " << b << " " << c << '\n';
			V.push_back({c, {i, j}});
		}	
	}
	
	sort(V.begin(), V.end());
	long double wyn = 0;
	for (int i=0; i<n; i++)
	{
		auto p = V[i];
		if (Find(p.second.second) == Find(p.second.first))
			 continue;
		Union(p.second.first, p.second.second);
		wyn = max(wyn, p.first);
	}

	cout << wyn;
    return 0;
}
