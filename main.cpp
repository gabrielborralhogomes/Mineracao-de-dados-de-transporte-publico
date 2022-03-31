using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <list>
#include <fstream>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include "model.h"
#include "grafo.cpp"

// 321 stations
// 15 lines
// 842 connections

int main(){

    string CD,DOWno,DOW,SubSystem,StartStn,EndStn,EntTime,ExTime,Zones,JourneyType,DailyCapping,FullFare,DiscountFare,FinalProduct,JourneyLength;

    int tamL=759368;
    int tamC=15;
    vector<vector<string> > matriz(tamL);
    for ( int i = 0 ; i < tamL ; i++ ){
        matriz[i].resize(tamC);
    }
    int li=0,co=0;

    ifstream myFile("oc.csv");
    myFile.is_open();

    while (getline(myFile, CD, ',') and li < tamL) {
        matriz[li][co]=CD;
        co++;

        getline(myFile, DOW, ',') ;
        matriz[li][co]=DOW;
        co++;

        getline(myFile, SubSystem, ',') ;
        matriz[li][co]=SubSystem;
        co++;

        getline(myFile, DOWno, ',') ;
        matriz[li][co]=DOWno;
        co++;

        getline(myFile, StartStn, ',') ;
        matriz[li][co]=StartStn;
        co++;

        getline(myFile, EndStn, ',') ;
        matriz[li][co]=EndStn;
        co++;

        getline(myFile, EntTime, ',') ;
        matriz[li][co]=EntTime;
        co++;

        getline(myFile, ExTime, ',') ;
        matriz[li][co]=ExTime;
        co++;

        getline(myFile, Zones, ',') ;
        matriz[li][co]=Zones;
        co++;

        getline(myFile, JourneyType, ',') ;
        matriz[li][co]=JourneyType;
        co++;

        getline(myFile, DailyCapping, ',') ;
        matriz[li][co]=DailyCapping;
        co++;

        getline(myFile, FullFare, ',') ;
        matriz[li][co]=FullFare;
        co++;

        getline(myFile, DiscountFare, ',') ;
        matriz[li][co]=DiscountFare;
        co++;

        getline(myFile, FinalProduct, ',') ;
        matriz[li][co]=FinalProduct;
        co++;

        getline(myFile, JourneyLength) ;
        matriz[li][co]=JourneyLength;
        co=0;
        li++;

    }

    myFile.close();

    int v = 321;
    vector<int> adj[v];

    for(int i=0;i<NBR_CONNECTIONS;i++){
        add_edge(adj,connections[i].s,connections[i].t);
    }

    string name_arq;
    vector<int> horarios;
    string es;
    string ec;
    int hin;
    int hou;
    string duracao;
    int dados_salvos=0;
    int num_es, num_ec;
    FILE *saveFile;

    // string CD,DOWno,DOW,SubSystem,StartStn,EndStn,EntTime,ExTime,Zones,JourneyType,DailyCapping,FullFare,DiscountFare,FinalProduct,JourneyLength;
    //      45989,2,Mon,LUL,Goodge Street,Totteridge,1000,1041,Z0110,TKT,N,0,0,Freedom Pass (Elderly),41
    for(int k=1;k<tamL;k++){
        cout << "Passo " << k << endl;

        name_arq="dataset/"+matriz[k][1]+".txt";
        es=matriz[k][4];
        ec=matriz[k][5];
        duracao=""+matriz[k][14];
        stringstream geek(matriz[k][6]);
        geek >> hin;
        stringstream geekk(matriz[k][7]);
        geekk >> hou;

        num_es =-1;
        num_ec=-1;
        for(int i=0;i<320;i++){
            if(es == lookup_station[i]){
                num_es=i;
                break;
            }
        }
        for(int i=0;i<320;i++){
            if(ec == lookup_station[i]){
                num_ec=i;
                break;
            }
        }

        if(num_es != -1 && num_ec != -1 && printShortestDistance(adj, num_es, num_ec, v) == 1){
            horarios = horas(hin, hou, caminho.size()-1);
            saveFile = fopen(name_arq.c_str(), "a");
            char saveH [33];
            for (int i = caminho.size() - 1; i >= 0; i--){
                fprintf(saveFile, lookup_station[caminho[i]]);
                fprintf(saveFile, ";");
                itoa (horarios[i],saveH,10);
                fprintf(saveFile, saveH);
                fprintf(saveFile, ";");
            }
            fprintf(saveFile,duracao.c_str());
            fprintf(saveFile,"\n");
            fclose(saveFile);
            dados_salvos++;
        }

        caminho.clear();
        horarios.clear();
        name_arq.clear();
        duracao.clear();
    }

    cout << "\nDados salvos: " << dados_salvos << "\n";
    cout << "Dados nao salvos: " << tamL-dados_salvos << endl;

    return 0;
}


    /*cout << "\n\Horas:\n";
        for (int i = horarios.size() - 1; i >= 0; i--){
            cout << horarios[i] << " // ";
        }
        printf("\n");

        cout << "\nCaminho:\n";
        for (int i = caminho.size() - 1; i >= 0; i--){
            cout << lookup_station[caminho[i]] << " // ";
        }
        printf("\n");
        */

    /*
    int caminhos[100][15];
    for(int i=0;i<100;i++){
        for(int j=0;j<15;j++){
            caminho[i][j]=-1;
        }
    }
    int cont[100];
    cont[0]=num_es;
    int aux=0;
    int achou=0;
    int cam=0; // inicio do caminho
    int rota=0; // percurso do caminho
    list<int> lista[100];
	list<int>::iterator it;

    while(true){
        for(int i=0;i<NBR_CONNECTIONS;i++){
            if(lookup_station[cont[aux]] == lookup_station[connections[i].s]){
                lista[cam].push_back(connections[i].l);
                if(lookup_station[connections[i].t] == lookup_station[num_ec]){
                    achou = 1;
                    break;
                }
                cont[cam+1]=connections[i].t;
                cam++;
            }
        }
        aux++;
        if(achou == 1){
            break;
        }else{
            rota++;
        }
    }

*/
