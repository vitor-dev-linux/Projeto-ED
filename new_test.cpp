#include <iostream>
using namespace std;
int main(){
    char teste1[5];
    char teste2[4];
    char teste[15];
    for(char &n:teste1){
        n='*';
    }
    cin>>teste1;
    cin>>teste2;
    int cont=0;
    for(char &n:teste2){
        if ((n!='*')&& (n!='\0')){
            cont++;
        }
    }
    cout<<"a saida em string é >> "<<cont<<endl;
}