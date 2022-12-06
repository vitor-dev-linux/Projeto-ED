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
        void get_dados(unsigned idCOPY, char nameSTR[], char citySTR[], char sportSTR[], char eventSTR[], char nocSTR[]){
            this->id=idCOPY;//copia segura do id por cópia;

            for(int i=0;i<50;i++){//copia segura do name por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->name[i]=nameSTR[i];
            }

            for(int i=0;i<15;i++){//copia segura do city por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->city[i]=citySTR[i];
            }

            for(int i=0;i<50;i++){//copia segura do sport por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->sport[i]=sportSTR[i];
            }

            for(int i=0;i<50;i++){//copia segura do name por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->event[i]=eventSTR[i];
            }

            for(int i=0;i<4;i++){//copia segura do name por cópia, bloco a bloco em string secundaria NULA de privilégios ADM;
                this->noc[i]=nocSTR[i];
            }
        }
};
//ASSINATURAS
dadoAtleta* redimensionar( dadoAtleta[], int&);


dadoAtleta* redimensionar(dadoAtleta velho[], int &tam){
    dadoAtleta *novo=new dadoAtleta[tam+1];
    copy(velho, velho+tam, novo);
    tam++;
    delete[] velho;
    return novo;
}


int main(){
    unsigned idCOPY;
     char nameSTR[50]={}, citySTR[15]={}, sportSTR[50]={}, eventSTR[50]={}, nocSTR[4]={};
    int tam=1;//variavel que vai armazenar e percorrer o vetor de objetos
    dadoAtleta *atleta=new dadoAtleta[tam];
    //atleta[tam-1].get_dados(idCOPY, nameSTR, citySTR, sportSTR, eventSTR, nocSTR);//transcreve as informações das strings e o unsigned id para os atributos do obejto segur0


    //parte arquivo, para a conversao em .bin;
    ifstream arq_ini("convertido.bin", ios::binary);
    if(!arq_ini){
        arq_ini.close();
        arq_ini.clear();
        ifstream arq_entry("data_athlete_event.csv");
        char *point=new char;
        arq_entry.getline(point,'0');
        arq_entry>>*point;//aqui é enviado o id '0' ao point;
        while(!arq_entry.eof()){//garante que o processo vai até o fim do arquivo csv
            string percorrer;
            ////////////////////////////////////////////////////////////->BEGIN
            //                       Modulo ID
            //getline(arq_entry>>ws, percorrer, ',');//forma de preencher corretamente a string
            idCOPY=atoi(point);//captura a id
            percorrer="";
            arq_entry>>ws,*point;
            ////////////////////////////////////////////////////////////
            if(*point=='"'){ //módulo nameSTR;
                getline(arq_entry>>ws, percorrer, '"');
                arq_entry>>*point;
                arq_entry>>*point;
                if(*point=='"'){
                    string complemento="";
                    getline(arq_entry, complemento, '"');
                    percorrer+=complemento;
                    arq_entry>>*point;
                    arq_entry>>*point;
                }
                
                if(*point=='"'){
                    string complemento="";
                    getline(arq_entry>>ws, complemento, '"');
                    percorrer+=complemento;
                    arq_entry>>*point;
                }
                nameSTR=percorrer;
                percorrer="";
                arq_entry>>*point;
                arq_entry>>*point;
            }
            else{
                getline(arq_entry>>ws, percorrer, ',');
                nameSTR=percorrer;
                arq_entry>>*point;
                percorrer="";
            }
            ////////////////////////////////////////////////////////////
            if(*point=='"'){ //módulo citySTR;
                getline(arq_entry>>ws, percorrer, '"');
                arq_entry>>*point;
                arq_entry>>*point;
                if(*point=='"'){
                    string complemento="";
                    getline(arq_entry, complemento, '"');
                    percorrer+=complemento;
                    arq_entry>>*point;
                    arq_entry>>*point;
                }
                
                if(*point=='"'){
                    string complemento="";
                    getline(arq_entry>>ws, complemento, '"');
                    percorrer+=complemento;
                    arq_entry>>*point;
                }
                citySTR=percorrer;
                percorrer="";
                arq_entry>>*point;
                arq_entry>>*point;
            }
            else{
                getline(arq_entry>>ws, percorrer, ',');
                citySTR=*point+percorrer;
                arq_entry>>*point;
                percorrer="";
            }
            ////////////////////////////////////////////////////////////
            if(*point=='"'){ //módulo sportSTR;
                getline(arq_entry>>ws, percorrer, '"');
                arq_entry>>*point;
                arq_entry>>*point;
                if(*point=='"'){
                    string complemento="";
                    getline(arq_entry, complemento, '"');
                    percorrer+=complemento;
                    arq_entry>>*point;
                    arq_entry>>*point;
                }
                
                if(*point=='"'){
                    string complemento="";
                    getline(arq_entry>>ws, complemento, '"');
                    percorrer+=complemento;
                    arq_entry>>*point;
                }
                sportSTR=percorrer;
                percorrer="";
                arq_entry>>*point;
                arq_entry>>*point;
            }
            else{
                getline(arq_entry>>ws, percorrer, ',');
                sportSTR=*point+percorrer;
                arq_entry>>*point;
                percorrer="";
            }
            ////////////////////////////////////////////////////////////
            if(*point=='"'){ //módulo eventSTR;
                getline(arq_entry>>ws, percorrer, '"');
                arq_entry>>*point;
                arq_entry>>*point;
                if(*point=='"'){
                    string complemento="";
                    getline(arq_entry, complemento, '"');
                    percorrer+=complemento;
                    arq_entry>>*point;
                    arq_entry>>*point;
                }
                
                if(*point=='"'){
                    string complemento="";
                    getline(arq_entry>>ws, complemento, '"');
                    percorrer+=complemento;
                    arq_entry>>*point;
                }
                eventSTR=percorrer;
                percorrer="";
            }
            else{
                stringstream t;
                char teste[50];
                arq_entry.getline(teste, 50, ',');
                //getline(arq_entry>>ws, percorrer, ',');
                eventSTR=*point+percorrer;
                arq_entry>>*point;
                percorrer="";
            }
            ////////////////////////////////////////////////////////////

            ////////////////////////////////////////////////////////////
                       //módulo noc;

            //getline(arq_entry, percorrer, '\n');
            //arq_entry.ignore(256,'\n');
            //nocSTR=percorrer;
            //percorrer="";
            //arq_entry>>*point;
            ////////////////////////////////////////////////////////////->END

            //Agora passo os dados para os objetos e crio um novo armazanamento;
            atleta[tam-1].get_dados(idCOPY, nameSTR, citySTR, sportSTR, eventSTR, nocSTR);
            //atleta=redimensionar(atleta, tam);

        }
    }
    return 0;
}