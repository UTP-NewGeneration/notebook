int g[MN][MN];
stack<int> s;

void dfs(int u) {
	fori(v, 0, n) if (g[u][v]) {
		if (used[u][v]) continue;
		used[u][v] = 1;
		dfs(v);
	}
	s.push(u);
}