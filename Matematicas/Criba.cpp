const int N=100000;

bool esPrimo[N];
void criba(int n){
    memset(esPrimo, true, sizeof(esPrimo));
    for(int k = 2; (k * k) <= n; k++){
        if(esPrimo[k]){
            for(int j = k * k; j <= n; j += k){
                esPrimo[j] = false;
            }
        }
    }
}
