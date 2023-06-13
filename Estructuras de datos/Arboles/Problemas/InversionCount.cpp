#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h>
using namespace __gnu_pbds;
template <class T> using Tree=
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int test_case;
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		Tree<int> tree;
		int N;  cin >> N;
		long long inv_num = 0;
		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;
			//Calculo del # de elementos en el tree
			// que son mayor que x
			inv_num += i-tree.order_of_key(x);
			tree.insert(x);
		}
		cout << inv_num << '\n';
	}
}