#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

//Zadatak Zabac iz biltena KTOS15 (ima u folderu sto sam postavio "korisni dokumenti")

bool debug=0;
using namespace std;
struct Tacka{
	//predstavlja tacku
    double x,y;
};
struct Lokvanj{
	//predstavlja lokvanj sa centralnom tackom i radiusom
    Tacka c;
    double r;
};

double daljina(Tacka a, Tacka b){
	//racunanje razdaljine dvije tacke u koord. sistemu
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
map<int, vector<int>> formirajGraf(vector<Lokvanj> lokvanji, int poc){
	//ova funkcija formira graf od lokvanja i pocetne tacke
    map<int, vector<int>> graf;
    vector<int> komsije;
    for(int i=0;i<lokvanji.size();i++){
        if(debug){
            cout<<"Node br "<<i+1<<" Komsije: ";
        }
        for(int j=0;j<lokvanji.size();j++){
            if(i!=j){
                if(daljina(lokvanji[i].c,lokvanji[j].c)<lokvanji[i].r+lokvanji[j].r+0.1){
                    komsije.push_back(j);
                    if(debug){
                    cout<<j+1<<" ";
                    }
                }
            }
        }
        graf.emplace(i,komsije);
        komsije.clear();
    }
    return graf;
}
vector<int> getShortestPath(map<int,int> parentNodes, int poc, int kraj){
	//ova funkcija, nakon sto BFS odradi svoj posao, ide unazad kroz parentNodes mapu i poveze
	//zadnji lokvanj sa prvim, i onda obrne vektor tako da dobijemo put od pocetka do kraja
	//koji je najkraci
    vector<int> put;
    int node=kraj;
    while(1){
        put.push_back(node);
        node=parentNodes[node];
        if(node==poc){
            break;
        }
    }
    put.push_back(poc);
    reverse(put.begin(),put.end());
    return put;
}
vector<int> bfs(map<int, vector<int>> graf, int poc, int kraj){
	//Standardni breadth first search, pratimo vec obradjene nodes
	//u vektoru obradjeni, svaki node povezujemo sa prethodnim koristeci
	//parent nodes mapu, kad se dodje do zadnjeg lokvanja, pozivom funkcije getShortestPath 
	//pronadje se put koji je najkraci
    queue<int> q;
    vector<bool> obradjeni(graf.size(),false);
    map<int,int> parentNodes;
    vector<int> put;
    q.push(poc);
    obradjeni[poc]=true;
    int node=poc;
    while(q.size()!=0){
        node=q.front();
        q.pop();
        if(node==kraj){
            put=getShortestPath(parentNodes,poc,kraj);
            return put;
        }
		//petlja koja obradjuje komsije od trenutnog node-a
        for(int i=0;i<graf[node].size();i++){
			//provjeri ako je node vec obradjen, ako nije, markiraj kao obradjen
			//te stavi ga u queue, i takodjer ubaci ga u mapu tako da se naprave
			//poveznice izmedju trenutnih i predhodnih elemenata sto se koristi
			//u getShortestPath funkciji
            if(!obradjeni[graf[node][i]]){
                obradjeni[graf[node][i]]=true;
                q.push(graf[node][i]);
                parentNodes.emplace(graf[node][i],node);
            }
        }

    }

}
int main()
{
    fstream file;
    file.open("input3.txt",ios::in);
    if(!file.is_open()){
        cout<<"Error pri otvaranju";
    }
    Tacka frogi, kuca;
    file>>frogi.x>>frogi.y;
    file>>kuca.x>>kuca.y;
    int br_lokvanja;
    file>>br_lokvanja;
    Lokvanj temp;
    vector<Lokvanj> lokvanji;
    for(int i=0;i<br_lokvanja;i++){
        file>>temp.c.x>>temp.c.y>>temp.r;
        lokvanji.push_back(temp);
    }

    file.close();
    //pronaci froggija
    int poc=-1;
    for(int i=0;i<lokvanji.size();i++){
        if(daljina(lokvanji[i].c,frogi)<lokvanji[i].r){
            poc=i;
            break;
        }
    }
	//ako frogi nije na nekom od lokvanja
    if(poc==-1){
        cout<<"Frogi ce ostati gladan";
        return 0;
    }

    int kraj=-1;
    for(int i=0;i<lokvanji.size();i++){
        if(daljina(lokvanji[i].c,kuca)<lokvanji[i].r){
            kraj=i;
            break;
        }
    }
	//ako kuca nije na jednom od lokvanja
    if(kraj==-1){
        cout<<"Frogi ce ostati gladan";
        return 0;
    }
	//formiraj graf, pa nadji najkraci put kroz njega
    map<int, vector<int>> graf=formirajGraf(lokvanji, poc);
    vector<int> put=bfs(graf,poc,kraj);
    if(put.size()==0){
        cout<<"Frogi ce ostati gladan";
    } else {
        for(int i=0;i<put.size();i++){
            cout<<put[i]+1<<" ";
        }
    }
    return 0;
}
