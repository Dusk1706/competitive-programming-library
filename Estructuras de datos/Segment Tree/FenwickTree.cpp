#include<bits/stdc++.h>

using namespace std;

struct fenwick {
	vector<int> fn;
	int n;

	void init(int n) {
		this->n = n + 1;
		fn.resize(this->n, 0);
	}

	void add(int x, int y) {
		x++; // 1 based index
		while (x < n) {
			fn[x] += y;
			x += (x & (-x));// last set bit
		}
	}

	int sum(int x) {
		x++; // 1 based index
		int ans = 0;
		while (x) {
			ans += fn[x];
			x -= (x & (-x));// last set bit
		}
		return ans;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

};

struct fenwick2{
	vector<int> ft;
	int n;

	void init(int n) {
		this->n = n + 1;
		ft.resize(this->n, 0);
	}

	void build(vector<int> sumArray) {
    	for (int t=0;t<n;++t)
        	updateNode(t+1, n, sumArray[t]);
	}

	void updateNode(int in, int n, int val) {
    	while (in <= n) {
        	ft[in] += val;
        	in += in & (-in);
   	 	}
	}

	int getSum(int in) {
    	int sum = 0;
    	++in;

    	while (in > 0) {
        	sum += ft[in];
        	in -= in & (-in);

    	}
    	return sum;
	}

	int getRangeSum(int st, int ed) {
    	--st;
    	int left = getSum(st);
    	int right = getSum(ed);

    	return (right - left);
	}
};

int main(){
	//Fenwick Version 1 0 based index
	vector<int> v = {1, 2, 3, 4, 5, 6, 7};
	fenwick tree;
	tree.init(v.size());
	for (int i = 0; i < v.size(); i++) {
		tree.add(i, v[i]);
	}
	cout << tree.sum(3, 5) << '\n';
	tree.add(4, -3);
	cout << tree.sum(3, 5) << '\n';

	//Fenwick Version 2 0 based index
	fenwick2 tree2;
	tree2.init(v.size());
	tree2.build(v);
	cout<<tree2.getRangeSum(0,6)<<endl;
	cout<<tree2.getSum(1)<<endl;

	return 0;
}