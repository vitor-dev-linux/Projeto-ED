#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class dadoAtleta{
    private:
        unsigned id;
        char name[100];
        char city[50];
        char sport[100];
        char event[100];
        char noc[4];
    public:
        void get_dados(unsigned idCOPY, char nameSTR[], char citySTR[], char sportSTR[], char eventSTR[], char nocSTR[]){
            this->id=idCOPY;//copia segura do id por cópia;

            for(int i=0;i<100;i++){//copia segura do name por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->name[i]=nameSTR[i];
            }

            for(int i=0;i<50;i++){//copia segura do city por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->city[i]=citySTR[i];
            }

            for(int i=0;i<100;i++){//copia segura do sport por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->sport[i]=sportSTR[i];
            }

            for(int i=0;i<100;i++){//copia segura do name por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->event[i]=eventSTR[i];
            }

            for(int i=0;i<4;i++){//copia segura do name por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->noc[i]=nocSTR[i];
            }
        }
};
//ASSINATURAS
/*
dadoAtleta* redimensionar( dadoAtleta[], int&);


dadoAtleta* redimensionar(dadoAtleta velho[], int &tam){
    dadoAtleta *novo=new dadoAtleta[tam+1];
    copy(velho, velho+tam, novo);
    tam++;
    delete[] velho;
    return novo;
}
*/

int main(){
    unsigned idCOPY;
     char nameSTR[100]={}, citySTR[50]={}, sportSTR[100]={}, eventSTR[100]={}, nocSTR[4]={};
    int tam=1;//variavel que vai armazenar e percorrer o vetor de objetos
    dadoAtleta *atleta=new dadoAtleta[tam];
    //atleta[tam-1].get_dados(idCOPY, nameSTR, citySTR, sportSTR, eventSTR, nocSTR);//transcreve as informações das strings e o unsigned id para os atributos do obejto segur0


    //parte arquivo, para a conversao em .bin;
    ifstream arq_ini("convertido.bin", ios::binary);
    if(!arq_ini.is_open()){
        arq_ini.close();
        arq_ini.clear();
        ifstream arq_entry("data_athlete_event.csv");
        char *point=new char[1];
        arq_entry.getline(point,'0');
        //arq_entry>>*point;//aqui é enviado o id '0' ao point;
        bool loop=true;
        while(loop==true){//garante que o processo vai até o fim do arquivo csv
            //string percorrer;
            string id;
            getline(arq_entry, id, ',');
            idCOPY=stoi(id);//captura a id
            arq_entry>>*point;//virgula
            //arq_entry>>*point;//valor

            if(*point=='"'){ //módulo nameSTR;
                string percorrer="";
                int tt1=0, tt2=0, tt3=0;
                char teste2[100];
                for(char &n:teste2){
                    n='*';
                }
                arq_entry.getline( teste2,100, '"');
                for(char &n:teste2){
                    if ((n!='*')&& (n!='\000')){
                        tt1++;
                    }
                }
                for(int i=0;i<tt1;i++){
                    nameSTR[i]=teste2[i];
                }
                nameSTR[tt1]=' ';
                tt1++;
                arq_entry>>*point;
                if(*point=='"'){
                    char testing[100];
                    for(char &n:testing){
                        n='*';
                    }
                    arq_entry.getline( testing,100, '"');
                    for(char &n:testing){
                        if ((n!='*')&& (n!='\000')){
                            tt2++;
                        }
                    }
                    for(int i=0;i<tt2;i++){
                        nameSTR[tt1]=testing[i];
                        tt1++;
                    }
                    nameSTR[tt2]=' ';
                    tt2++;
                    arq_entry>>*point;
                }
                if(*point=='"'){
                    char testing[100];
                    for(char &n:testing){
                        n='*';
                    }
                    arq_entry.getline( testing,100, '"');
                    for(char &n:testing){
                        if ((n!='*')&& (n!='\000')){
                            tt3++;
                        }
                    }
                    for(int i=0;i<tt3;i++){
                        nameSTR[tt1]=testing[i];
                        tt1++;
                    }
                    arq_entry>>*point;
                }
                percorrer="";
                arq_entry>>*point;
            }
            else{
                int arm=arq_entry.tellg();
                arq_entry.seekg(arm-1);
                arq_entry.getline(nameSTR, 100, ',');
                arq_entry>>*point;
            }
            /////////////////////////////////////////////
            if(*point=='"'){ //módulo citySTR;
                string percorrer="";
                int tt1=0, tt2=0, tt3=0;
                char teste2[100];
                for(char &n:teste2){
                    n='*';
                }
                arq_entry.getline( teste2,100, '"');
                for(char &n:teste2){
                    if ((n!='*')&& (n!='\000')){
                        tt1++;
                    }
                }
                for(int i=0;i<tt1;i++){
                    citySTR[i]=teste2[i];
                }
                citySTR[tt1]=' ';
                tt1++;
                arq_entry>>*point;
                if(*point=='"'){
                    char testing[100];
                    for(char &n:testing){
                        n='*';
                    }
                    arq_entry.getline( testing,100, '"');
                    for(char &n:testing){
                        if ((n!='*')&& (n!='\000')){
                            tt2++;
                        }
                    }
                    for(int i=0;i<tt2;i++){
                        citySTR[tt1]=testing[i];
                        tt1++;
                    }
                    citySTR[tt2]=' ';
                    tt2++;
                    arq_entry>>*point;
                }
                if(*point=='"'){
                    char testing[100];
                    for(char &n:testing){
                        n='*';
                    }
                    arq_entry.getline( testing,100, '"');
                    for(char &n:testing){
                        if ((n!='*')&& (n!='\000')){
                            tt3++;
                        }
                    }
                    for(int i=0;i<tt3;i++){
                        citySTR[tt1]=testing[i];
                        tt1++;
                    }
                    arq_entry>>*point;
                }
                percorrer="";
                arq_entry>>*point;
            }
            else{
                int arm=arq_entry.tellg();
                arq_entry.seekg(arm-1);
                arq_entry.getline(citySTR, 100, ',');
                arq_entry>>*point;
            }
            //////////////////////////////////////////////
            if(*point=='"'){ //módulo sportSTR;
                string percorrer="";
                int tt1=0, tt2=0, tt3=0;
                char teste2[100];
                for(char &n:teste2){
                    n='*';
                }
                arq_entry.getline( teste2,100, '"');
                for(char &n:teste2){
                    if ((n!='*')&& (n!='\000')){
                        tt1++;
                    }
                }
                for(int i=0;i<tt1;i++){
                    sportSTR[i]=teste2[i];
                }
                sportSTR[tt1]=' ';
                tt1++;
                arq_entry>>*point;
                if(*point=='"'){
                    char testing[100];
                    for(char &n:testing){
                        n='*';
                    }
                    arq_entry.getline( testing,100, '"');
                    for(char &n:testing){
                        if ((n!='*')&& (n!='\000')){
                            tt2++;
                        }
                    }
                    for(int i=0;i<tt2;i++){
                        sportSTR[tt1]=testing[i];
                        tt1++;
                    }
                    sportSTR[tt2]=' ';
                    tt2++;
                    arq_entry>>*point;
                }
                if(*point=='"'){
                    char testing[100];
                    for(char &n:testing){
                        n='*';
                    }
                    arq_entry.getline( testing,100, '"');
                    for(char &n:testing){
                        if ((n!='*')&& (n!='\000')){
                            tt3++;
                        }
                    }
                    for(int i=0;i<tt3;i++){
                        sportSTR[tt1]=testing[i];
                        tt1++;
                    }
                    arq_entry>>*point;
                }
                percorrer="";
                arq_entry>>*point;
            }
            else{
                int arm=arq_entry.tellg();
                arq_entry.seekg(arm-1);
                arq_entry.getline(sportSTR, 100, ',');
                arq_entry>>*point;
            }
            ///////////////////////////////////////////
            if(*point=='"'){ //módulo eventSTR;
                string percorrer="";
                int tt1=0, tt2=0, tt3=0;
                char teste2[100];
                for(char &n:teste2){
                    n='*';
                }
                arq_entry.getline( teste2,100, '"');
                for(char &n:teste2){
                    if ((n!='*')&& (n!='\000')){
                        tt1++;
                    }
                }
                for(int i=0;i<tt1;i++){
                    eventSTR[i]=teste2[i];
                }
                eventSTR[tt1]=' ';
                tt1++;
                arq_entry>>*point;
                if(*point=='"'){
                    char testing[100];
                    for(char &n:testing){
                        n='*';
                    }
                    arq_entry.getline( testing,100, '"');
                    for(char &n:testing){
                        if ((n!='*')&& (n!='\000')){
                            tt2++;
                        }
                    }
                    for(int i=0;i<tt2;i++){
                        eventSTR[tt1]=testing[i];
                        tt1++;
                    }
                    eventSTR[tt2]=' ';
                    tt2++;
                    arq_entry>>*point;
                }
                if(*point=='"'){
                    char testing[100];
                    for(char &n:testing){
                        n='*';
                    }
                    arq_entry.getline( testing,100, '"');
                    for(char &n:testing){
                        if ((n!='*')&& (n!='\000')){
                            tt3++;
                        }
                    }
                    for(int i=0;i<tt3;i++){
                        eventSTR[tt1]=testing[i];
                        tt1++;
                    }
                    arq_entry>>*point;
                }
                percorrer="";
                arq_entry>>*point;
            }
            else{
                int arm=arq_entry.tellg();
                arq_entry.seekg(arm-1);
                arq_entry.getline(eventSTR, 100, ',');
                arq_entry>>*point;
            }
            /////////////////////////////////////////////////
            //
            int arm=arq_entry.tellg();                                  
            arq_entry.seekg(arm-1);
            arq_entry.getline(nocSTR, 4);
            atleta[tam-1].get_dados(idCOPY, nameSTR, citySTR, sportSTR, eventSTR, nocSTR);
            if(arq_entry.eof()){
                loop=false;
                delete[] point;
                arq_entry.ignore();
            }
            arm=arq_entry.tellg();
            ///////////////////////////////////////////////////////////////////////
            ////////////////DAQUI PRA FRENTE É ALOCAÇÃO DINAMICA;
            //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        }
        arq_entry.close();
    }
    else{

    }
    
    return 0;
}