class SegmentTree {//Indice base 0 
  private:
    int n;
    vi arr, st;

    int l(int p) { return p << 1; }       // ir al hijo izquierdo
    int r(int p) { return (p << 1) + 1; } // ir al hijo derecho

    void build(int index, int start, int end) {
        if (start == end) {
            st[index] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(l(index), start, mid);
            build(r(index), mid + 1, end);
            st[index] = st[l(index)] + st[r(index)]; //Cambiar de ser necesario
        }
    }

    int query(int index, int start, int end, int i, int j) {
        if (j < start || end < i)
            return 0; // Si ese rango no nos sirve, retornar un valor que no cambie nada

        if (i <= start && end <= j) //Se ocupa todo el rango
            return st[index];
		//Se ocupa parte del rango
        int mid = (start + end) / 2;
        int q1 = query(l(index), start, mid, i, j);
        int q2 = query(r(index), mid + 1, end, i, j);

        return q1 + q2;
    }

    void update(int index, int start, int end, int idx, int val) {
        if (start == end) {
            st[index] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
                update(l(index), start, mid, idx, val);
            else
                update(r(index), mid + 1, end, idx, val);

            st[index] = st[l(index)] + st[r(index)]; //Cambiar de ser necesario
        }
    }

  public:
    SegmentTree(int sz) : n(sz), st(4 * n) {} // Constructor de st sin valores
	// Constructor de st con arreglo inicial
    SegmentTree(const vi &initialArr) : SegmentTree((int)initialArr.size()) { 
        arr = initialArr;
        build(1, 0, n - 1);
    }

    void update(int i, int val) { update(1, 0, n - 1, i, val); }
    int query(int i, int j) { return query(1, 0, n - 1, i, j); }
};