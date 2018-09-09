int par[MN];
int to[MN], from[MN], weight[MN];

bool cmp(int i, int j) { return weight[i] < weight[j]; }

int findSet(int i) { return par[i] < 0 ? i : par[i] = findSet(par[i]); }
void unionSet(int i, int j) { par[findSet(i)] = findSet(j); }

int MST() {
	ll cost = 0;
	vi edges(m);
	fori(i, 0, m) edges[i] = i;
	sort(edges.begin(), edges.end(), cmp);
	memset(par, -1, sizeof par);
	fori(i, 0, m) {
		int e = edges[i];
		if (findSet(to[e]) != findSet(from[e])) {
			cost += weight[e];
			unionSet(to[e], from[e]);
		}
	}
	return cost;
}