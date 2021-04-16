#include <iostream>
#include <queue>
#include <cmath>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
//obicni bfs
using namespace std;
bool debug=0;
struct Tacka {
    double x, y;
};
struct Lokvanj {
    Tacka c;
    double r;
};
double daljina(Tacka a, Tacka b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

map<int,vector<int>> formirajGraf(int na_lokvanju, int kuca_lokvanj, vector<Lokvanj> lokvanji) {
    map<int,vector<int>> graf;
    vector<int> komsije;
    for(int i=0; i<lokvanji.size(); i++) {
        if(debug) {
            cout<<"Node br"<<i+1<<" Komsije: "<<endl;
        }
        for(int j=0; j<lokvanji.size(); j++) {
            if(i!=j) {
                if(daljina(lokvanji[i].c,lokvanji[j].c)<lokvanji[i].r+lokvanji[j].r+0.1) {
                    komsije.push_back(j);
                    if(debug) {
                        cout<<j+1<<" "<<endl;
                    }
                }
            }
        }
        graf.emplace(i,komsije);
        komsije.clear();
    }
    return graf;
}


vector<int> bfs(map<int,vector<int>> graf, int na_lokvanju, int kuca_lokvanj){
    queue<int> q;
    vector<bool> obradjeni(graf.size(),false);

    //upisujemo prvi element u queue, stavljamo ga u put, i markiramo kao obradjen
    q.push(na_lokvanju);
    obradjeni[na_lokvanju]=true;
    int node=na_lokvanju;
    while(q.size()!=0){
        node=q.front();
        q.pop();
        cout<<node+1<<" ";
        for(int i=0;i<graf[node].size();i++){
            if(!obradjeni[graf[node][i]]){
                q.push(graf[node][i]);
                obradjeni[graf[node][i]]=true;

            }
        }

    }
}


int main() {
    int br_lokvanja;
    vector<Lokvanj> lokvanji;
    fstream file;
    file.open("input3.txt",ios::in);
    if(!file.is_open()) {
        cout<<"Error pri otvaranju fajla";
    }
    Tacka frogi, kuca;
    Lokvanj temp;
    file>> frogi.x >> frogi.y;
    file>> kuca.x >> kuca.y;
    file>> br_lokvanja;
    for(int i=0; i<br_lokvanja; i++) {
        file >> temp.c.x >> temp.c.y >> temp.r;
        if(debug) {
            cout<<"Lokvanj"<<" "<<i+1<<" c=("<<temp.c.x<<","<<temp.c.y<<") i r="<<temp.r<<endl;
        }
        lokvanji.push_back(temp);
    }
    file.close();

// Da li je frogi na lokvanju?
    int na_lokvanju = -1;
    for (int i=0; i<br_lokvanja; i++) {
        if (daljina(frogi, lokvanji[i].c) < lokvanji[i].r) {
            na_lokvanju = i;
            break;
        }
    }
    if (na_lokvanju == -1) {
        cout << "Frogi ce ostati gladan" << endl;
        return 0;
    }
// Da li je kuca manje od 0.1 od lokvanja
    int kuca_lokvanj = -1;
    for (int i=0; i<br_lokvanja; i++) {

        if (daljina(kuca, lokvanji[i].c) < lokvanji[i].r+0.1) {
            kuca_lokvanj = i;
            break;
        }
    }
    if (kuca_lokvanj == -1) {
        cout << "Frogi ce ostati gladan" << endl;
        return 0;
    }
    map<int,vector<int>> graf=formirajGraf(na_lokvanju, kuca_lokvanj, lokvanji);
    vector<int> put;
    put = bfs(graf, na_lokvanju, kuca_lokvanj);
    if (put.size() == 0)
        cout << "Frogi ce ostati gladan";
    else
        for (int i=0; i<put.size(); i++)
            cout << (put[i]+1) << " ";
    cout << endl;
    return 0;
}
