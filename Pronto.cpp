#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class dadoAtleta{
    private:
        unsigned id;
        char name[50];
        char city[15];
        char sport[50];
        char event[50];
        char noc[4];
    public:
        void dados(string dados_STR[]){
            unsigned id_mod=stoi(dados_STR[0]);
            this->id=id_mod;//copia segura do id por cópia;
            for(int i=0;i<dados_STR[1].size();i++){
                this->name[i]=dados_STR[1][i];
            }
            for(int i=0;i<dados_STR[2].size();i++){
                this->city[i]=dados_STR[2][i];
            }
            for(int i=0;i<dados_STR[3].size();i++){
                this->sport[i]=dados_STR[3][i];
            }
            for(int i=0;i<dados_STR[4].size();i++){
                this->event[i]=dados_STR[4][i];
            }
            for(int i=0;i<dados_STR[5].size();i++){
                this->noc[i]=dados_STR[5][i];
            }
        }
        void list(){
            cout<<this->id<<endl;
            cout<<this->name<<endl;
            cout<<this->city<<endl;
            cout<<this->sport<<endl;
            cout<<this->event<<endl;
            cout<<this->noc<<endl;
        }
};

dadoAtleta* realoca(dadoAtleta *atleta, int &tam);
dadoAtleta* F_GET_CSV(dadoAtleta *atleta, int &tam);


dadoAtleta* realoca(dadoAtleta atleta[], int &tam){
    dadoAtleta *novo=new dadoAtleta[tam+1];
    copy(atleta, atleta+tam, novo);
    tam++;
    delete[]atleta;
    return novo;
}
dadoAtleta* F_GET_CSV(dadoAtleta *atleta, int &tam){
    ifstream arq("data_athlete_event.csv");
    if(!arq){
        cout<<"Error in csv"<<endl;
        return 0;
    }
    string name;
    int cont=0;
    getline(arq, name);
    while(!arq.eof()){
        getline(arq, name);
        cont++;
    }
    cont--;
    arq.clear();
    arq.close();
    arq.open("data_athlete_event.csv");
    getline(arq, name);
    unsigned idCOPY;
    string campos[6];
    int cont_campos=0;
    int percorrer=0;
    while(!arq.eof() and cont>0){
        getline(arq, name);
        cont--;
        stringstream tmp(name);
        getline(tmp,campos[cont_campos], ','); //obter id;
        cont_campos++;
        while(cont_campos<6){
            atleta=realoca(atleta, tam);
            char n=tmp.peek();
            if(n=='"'){
                getline(tmp,campos[cont_campos], '"');
                getline(tmp,campos[cont_campos], '"');
                int save=cont_campos;
                cont_campos+=2;
                n=tmp.peek();
                if(n=='"'){
                    string aux;
                    getline(tmp,aux, '"');
                    getline(tmp,aux, '"');
                    campos[save]+='"'+aux;
                    getline(tmp,aux, '"');
                    getline(tmp,aux, '"');
                    campos[save]+='"'+aux;
                    save++;
                    cont_campos=save;
                    getline(tmp,campos[cont_campos], ',');
                }
                else{
                }
            }
            else{
                getline(tmp,campos[cont_campos], ',');
                cont_campos++;
            }
        }
        cont_campos=0;
        if(percorrer<tam){
            atleta[percorrer].dados(campos);
            percorrer++;
        }
        else{
            cont=-1;
        }
        
    }
    percorrer--;
    arq.close();
    arq.clear();
    return atleta;
}
int main(){
    int tam=0;
    dadoAtleta *atleta=new dadoAtleta[tam];
    atleta=F_GET_CSV(atleta, tam);
    atleta[106].list();

    return 0;
}