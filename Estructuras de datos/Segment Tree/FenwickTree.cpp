#include<bits/stdc++.h>

using namespace std;
const int MAXN=8;
int ft[MAXN+1]; 
void upd(int i0, int v){ // añadir v al indice i0 (index 0-based)
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){ // get sum of range [0,i0) el ultimo indice no lo contempla
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
	return get(i1)-get(i0);
}

int main(){
	//Fenwick 0 based index
	vector<int> v = {1,1,1};
	for (int i = 0; i < v.size(); i++) {
		upd(i,v[i]);
	}
	
	cout<<get_sum(2,3)<<endl;

	return 0;
}