const ll k = 28759543;
const ll MD = 1e9 + 7;

ll pol[MN], pt[MN];

ll calc(int l, int r) {
	return ((pol[r] - (l > 0 ? pol[l - 1] : 0) + MD) * fastExp(pt[l], MD - 2)) % MD;
}

int main() {
	/* ... */
	pt[0] = 1;
	fori(i, 1, MN) pt[i] = (k * pt[i - 1]) % MD;
	string s; cin >> s;
	int n = s.size();
	fori(i, 0, n) pol[i] = (s[i] * pt[i]) % MD;
	fori(i, 1, n) pol[i] = (pol[i] + pol[i - 1]) % MD;
	/* ... */
}