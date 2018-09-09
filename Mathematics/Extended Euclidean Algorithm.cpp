void extendedEuclidean(ll a, ll b, ll &d, ll &x, ll &y) {
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
	} else {
		extendedEuclidean(b, a % b, d, x, y);
		ll x1 = x, y1 = y;
		x = y1;
		y = x1 - (a / b) * y1;
	}
}

ll invModular(ll c, ll m) {
	ll d, x, y;
	extendedEuclidean(c, m, d, x, y);
	return (x + m) % m;
}
