// Codigo para saber si dado un arreglo de strings se puede construir un string objetivo
#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int>memo;

bool canConstruct(string target, vector<string> array){
    if(memo.count(target)>0) return memo[target];
    if(target=="")return true;

    for(int i=0;i<array.size();i++){
        if(target.rfind(array[i], 0) == 0){
            string restante=target.substr(array[i].length());
            if(canConstruct(restante,array)){
                memo[target]=true;
                return true;
            }
        }
    }
    memo[target]=false;
    return false;
}


int main(){

    vector<string> array={"Huevo","Mama","Hola","Mundo","adiosmund"};
    cout<<canConstruct("MundoMamaHuevo",array)<<endl;
    cout<<canConstruct("Mundo",array)<<endl;
    cout<<canConstruct("Sopas",array)<<endl;
    return 0;
}