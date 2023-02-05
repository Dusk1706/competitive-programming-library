#include <iostream>
#include <string>

using namespace std;

string intToRoman(int num) {
    string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string ths[]={"","M","MM","MMM"};
    return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
}
        
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin>>n;
    if(n>3999){
        cout<<"LIMITE EXCEDIDO\n";
    }else{
        cout<<intToRoman(n)<<endl;
    }
    return 0;
}