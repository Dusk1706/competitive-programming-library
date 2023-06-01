#include <bits/stdc++.h>

using namespace std;

void intToRoman(int A){
    map<int,string> cvt;
    cvt[1000]="M";  cvt[900]="CM";  cvt[500]="D";   cvt[400]="CD";
    cvt[100]="C";   cvt[90]="XC";   cvt[50]="L";    cvt[40]="XL";
    cvt[10]="X";    cvt[9]="IX";    cvt[5]="V";     cvt[4]="IV";
    cvt[1]="I";

    //Procesar los valores de mayor a menor
    for(auto it=cvt.rbegin(); it!=cvt.rend(); it++){
        while(A >= it->first){
            cout<<it->second;
            A-=it->first;
        }
    }
    cout<<'\n';
}

int romanToInt(string R){
    map<char,int> RtoA;
    RtoA['I']=1;    RtoA['V']=5;    RtoA['X']=10;   RtoA['L']=50;
    RtoA['C']=100;  RtoA['D']=500;  RtoA['M']=1000;
    int value=0;
    for(int i=0; R[i]; i++){
        if(R[i+1] && RtoA[R[i]] < RtoA[R[i+1]]){
            value+=RtoA[R[i+1]] - RtoA[R[i]];
            i++;
        }else{
            value+=RtoA[R[i]];
        }
    }
    return value;
}
        
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string R;
    cin>>R;
    cout<<romanToInt(R)<<'\n';
    intToRoman(500);
    return 0;
}