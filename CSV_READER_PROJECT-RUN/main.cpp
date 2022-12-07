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
            int lim=dados_STR[1].size();
            for(int i=0;i<lim;i++){
                this->name[i]=dados_STR[1][i];
            }
            lim=dados_STR[2].size();
            for(int i=0;i<lim;i++){
                this->city[i]=dados_STR[2][i];
            }
            lim=dados_STR[3].size();
            for(int i=0;i<lim;i++){
                this->sport[i]=dados_STR[3][i];
            }
            lim=dados_STR[4].size();
            for(int i=0;i<lim;i++){
                this->event[i]=dados_STR[4][i];
            }
            lim=dados_STR[5].size();
            for(int i=0;i<lim;i++){
                this->noc[i]=dados_STR[5][i];
            }
            lim=0;
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
dadoAtleta* F_GET_CSV();
dadoAtleta* F_GET_CSV(){
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
    const int pass=cont;
    dadoAtleta *atleta=new dadoAtleta[pass];
    arq.clear();
    arq.close();
    arq.open("data_athlete_event.csv");
    getline(arq, name);
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
        if(percorrer<pass){
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
    dadoAtleta *atleta=F_GET_CSV();
    if(atleta==0){
		return 0;
	}
	//-----AMBIENTE APENAS PARA TESTE APAGUE-ME----->IN
	cout<<"Olá tester, insira a id de algum atleta para acessar as info dele. "<<endl;
	int teste;
	cin>>teste;
	atleta[teste].list();
    //----------------------------------------------OUT

    return 0;
}
