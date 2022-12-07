#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>//Ele é o responsável por criar uma variavel arquivo na memoria que uso para separar os dados dos atributos em uma linha lida do csv
using namespace std;
class dadoAtleta{//Classe do objeto referente aos dados dos Atletas
    private:
        unsigned id;
        char name[50];
        char city[15];
        char sport[50];
        char event[50];
        char noc[4];
    public:
    /*Metodo que recebe um vetor de string de tamanho 6, cada um contendo os dados a serem passados para os atributos, da seguinte forma:
    INDICES DO VETOR DE STRINGS
    0 -> string que tem a id;
    1 -> string que tem o name;
    2 -> string que tem a city;
    3 -> string que tem o sport;
    4 -> string que tem a event;
    5 -> string que tem noc.

    Ai sabendo que cada vetor desses é também um vetor de char ai uso uma variavel 'lim' que recebe justamente o tamanho de cada vetor de char deles
    e uso ele em um for para passar caractere a caractere para o atributo correspondente.

    Como a string do indice 0 contem um numero então eu faço logo a conversão dele para int e assim o atributo unsigned id aceita sem problemas
    */
        void dados(string dados_STR[]){
            unsigned id_mod=stoi(dados_STR[0]);
            this->id=id_mod;
            int lim=dados_STR[1].size();//
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
        void list(){//Método  que uso para listar o que tem dentro do objeto
            cout<<this->id<<endl;
            cout<<this->name<<endl;
            cout<<this->city<<endl;
            cout<<this->sport<<endl;
            cout<<this->event<<endl;
            cout<<this->noc<<endl;
        }
};
dadoAtleta* F_GET_CSV();//Assinatura, para garantir que a partir daqui todo o codigo encherge a função;

//Função que faz a criação e preenchimento dos objetos por meio da leitura do csv, retornando o ponteiro para uso na main do vetor de objetos;
dadoAtleta* F_GET_CSV(){
    ifstream arq("data_athlete_event.csv");
    if(!arq){//Se o arquivo não for encontrado a função se encerra com mensagem de erro;
        cout<<"Error in csv"<<endl;
        return 0;
    }
    string name; //Variavel que uso para ler linha a linha o arquivo
    int cont=0; //contador que vai servir para calcular o tamanho de objetos por meio do '\n' em cada fim de cadastro e também para não entourar a momory
    getline(arq, name);//le a primeira linha que não deve ser usada
    while(!arq.eof()){//percorre o arquivo linha a linha para descobrir seu tamanho
        getline(arq, name);
        cont++;
    }
    cont--; //subtraio 1 pq no fim do arq tem um campo extra que deve ser omitido (ele é invisivel, deve conveter apena um espaço)
    const int pass=cont;//defino pass como quem vai definir a quantidade de objetos a serem criados
    dadoAtleta *atleta=new dadoAtleta[pass];
    //Reinicio o arquivo para voltar o ponto de leitura no inicio
    arq.clear();
    arq.close();
    arq.open("data_athlete_event.csv");
    getline(arq, name);//leio linha
    string campos[6];//crio o vetor de strings que vão armazenar as informações de cada campo de atributo
    int cont_campos=0;//contador que percorre este indices do vetor de strings
    int percorrer=0;//contador que soma a cada ojeto criado, garantindo que não vai ter busca de acesso a objeto indevido na memoria
    while(!arq.eof() and cont>0){//percorre até o fim do arquivo exceto o valor nulo no fim do arquivo
        getline(arq, name);//leio a linha do arquivo
        cont--;
        stringstream tmp(name);//crio a variavel de memoria interna que tem comportamento de string e uso de operandos >> e << de arquivos e cin/cout;
        getline(tmp,campos[cont_campos], ','); //obter id;
        cont_campos++;//proximo campo do vetor
        while(cont_campos<6){//percorre cada campo para depois parrar eles para os atributos
            char n=tmp.peek();//n vai só espiar qual é o proximo caractere a ser lido na string que leu 
            if(n=='"'){//se o próximo for "
                getline(tmp,campos[cont_campos], '"');//pulo ela
                getline(tmp,campos[cont_campos], '"');//capturo até o proximo ser o próximo 
                int save=cont_campos; //salva o campo
                cont_campos+=2;//pulo 2 campos a frente; 1-" e 1-, assim eu posso ver se o proximo vai ser a letra do proximo campo
                n=tmp.peek();// espio para saber
                if(n=='"'){// Caso ele seja " então entra no caso de ser aqueles com "" 
                    string aux;
                    getline(tmp,aux, '"');//pulo o primeiro "
                    getline(tmp,aux, '"');//capturo o texto até o "
                    campos[save]+='"'+aux;//me refiro ao campo correto usando o save dizendo para ele acrescenatr " e o texto
                    getline(tmp,aux, '"');//pulo o "
                    getline(tmp,aux, '"');//pulo o outro "
                    campos[save]+='"'+aux;//me refiro ao campo correto usando o save dizendo para ele acrescenatr " e o texto final
                    save++; // save para para o que deve ser o proximo campo
                    cont_campos=save;//para ele para a variavel responsável
                    getline(tmp,campos[cont_campos], ',');//obter proximo campo até a virgula
                }
                else{
                }
            }
            else{ //se não tiver " então o pornto de parada é o ,
                getline(tmp,campos[cont_campos], ',');
                cont_campos++;//proximo campo
            }
        }
        cont_campos=0;// ao preencher todos os campos o indice é zerado para ser usado no próximo objeto
        //Se a quantidade de objetos criados for menor que o limite maximo ele passa os dados para os atributos
        //Como percorrrer começa 0 zero e o passa tem o tamanho real , então ser  pass-1 é justamente equivalente no que tange a leitura;
        if(percorrer<pass){
            atleta[percorrer].dados(campos);
            percorrer++;
        }
        else{
            cont=-1;// se ele estourar então paro o while com o -1 visto que cont tem que ser maior que 0 para que o while continue
        }
        
    }
    arq.close();
    arq.clear();
    return atleta;//retorno o ponteiro de objetos resultante
}
int main(){
    dadoAtleta *atleta=F_GET_CSV();// crio um ponteiro que vai aguardar este endereço contendo os vetores de objetos
    if(atleta==0){//Caso ele não receba um endereço valido ele fecha
		return 0;
	}
	//-----AMBIENTE APENAS PARA TESTE APAGUE-ME----->IN
	cout<<"Olá tester, insira a id de algum atleta para acessar as info dele. "<<endl;
	int teste;
	cin>>teste;
	atleta[teste].list();
    //----------------------------------------------OUT

    return 0;//FIM
}
