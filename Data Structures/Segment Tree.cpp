struct SegmentTree {

	int n;
	vi A;
	vi tree;
	SegmentTree() {}

	SegmentTree(vi &_A) {
		A = _A;
		int n = SZ(_A);
		tree.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	build(int p, int i, int j) {
		if (i == j) {
			tree[p] = A[i];
		} else {
			int mid = (i + j) / 2;
			build(2 * p, i, mid);
			build(2 * p + 1, mid + 1, j);
			tree[p] = min(tree[2 * p], tree[2 * p + 1]);
		}
	}

	int query(int p, int i, int j, int L, int R) {
		if (j < L || i > R) return oo;
		if (L <= i && j <= R) return tree[p];
		int mid = (i + j) / 2;
		int q1 = query(2 * p, i, mid, L, R);
		int q2 = query(2 * p + 1, mid + 1, j, L, R);
		return min(q1, q2);
	}

	int query(int i, int j) { return query(1, 0, n - 1, i, j); }

	void update(int p, int i, int j, int at, int by) {
		if (j < at || i > at) return;
		if (i == j) {
			A[i] = by;
			tree[p] = by;
			return;
		}
		int mid = (i + j) / 2;
		update(2 * p, i, mid, at, by);
		update(2 * p + 1, mid + 1, j, at, by);
		tree[p] = min(tree[2 * p], tree[2 * p + 1]);
	}

	void update(int at, int by) { return update(1, 0, n - 1, at, by); }

};

// Segment Tree Lazy Propagation
struct SegmentTree {

	int n;
	vi A;
	vi tree;
	vi lazy;

	SegmentTree(vi &_A) {
		A = _A;
		n = _A.size();
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	void build(int p, int i, int j) {
		if (i == j) {
			tree[p] = A[i];
		} else {
			int mid = (i + j) / 2;
			build(2 * p, i, mid);
			build(2 * p + 1, mid + 1, j);
			tree[p] = tree[2 * p] + tree[2 * p + 1];
		}
	}

	int query(int p, int i, int j, int L, int R) {
		if (j < L || R < i) return 0;
		if (lazy[p] != 0) {
			tree[p] += (j - i + 1) * lazy[p];
			if (i < j) {
				lazy[2 * p] += lazy[p];
				lazy[2 * p + 1] += lazy[p];
			}
			lazy[p] = 0;
		}
		if (L <= i && j <= R) return tree[p];
		int mid = (i + j) / 2;
		int q1 = query(2 * p, i, mid, L, R);
		int q2 = query(2 * p + 1, mid + 1, j, L, R);
		return q1 + q2;
	}

	int query(int i, int j) { return query(1, 0, n - 1, i, j); }

	void update(int p, int i, int j, int L, int R, int new_value) {
		if (lazy[p] != 0) {
			tree[p] += (j - i + 1) * lazy[p];
			if (i < j) {
				lazy[2 * p] += lazy[p];
				lazy[2 * p] += lazy[p];
			}
			lazy[p] = 0;
		}
		if (j < L || R < i) return;
		if (L <= i && j <= R) {
			tree[p] += (j - i + 1) * new_value;
			if (i < j) {
				lazy[2 * p] += new_value;
				lazy[2 * p + 1] += new_value;
			}
			return;
		}
		int mid = (i + j) / 2;
		update(2 * p, i, mid, L, R, new_value);
		update(2 * p + 1, mid + 1, j, L, R, new_value);
		tree[p] = tree[2 * p] + tree[2 * p + 1];
	}

	void update(int i, int j, int new_value) { update(1, 0, n - 1, i, j, new_value); }

};