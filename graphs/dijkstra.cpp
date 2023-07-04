void dijkstra()
{
	q.push({0, 1});
	while(!q.empty())
	{
		int a = q.top().second;
		int d = q.top().first * -1;
		q.pop();
		if(S[a] <= d) continue;
		S[a] = d;
		for(auto v : graf[a])
		{
			if(S[v.first] > d + v.second)
				q.push({(d+v.second)*-1, v.first});
		}
	}
}
