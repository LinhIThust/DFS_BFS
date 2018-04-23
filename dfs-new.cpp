#include <set>
#include <stack>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

set<int> V;// set of vertices of the graph
map<int, set<int> > A;// A[v] is the set of adjacent vertices of v

// data structure for DFS
map<int, int> d;// d[v] visiting time point
map<int, int> f;
map<int, int> p;
map<int, char> color;
int t;
map<int ,int> indeCC;
int nbCC;

void DFSVisit(int u){
    //t++;
    //d[u] = t;
    indeCC[u] =nbCC;
    color[u] = 'G';
    for(set<int>::iterator q = A[u].begin(); q != A[u].end(); q++){
        int v = *q;
        if(color[v] == 'W'){
      //      p[v] = u;
            DFSVisit(v);
        }
    }
  //  t++;
   // f[u] = t;
    //color[u] = 'B';
}
void init(){
    for(set<int>::iterator q = V.begin(); q != V.end(); q++){
        int v = *q;
        color[v] = 'W';
       // p[v] = -1;
    }

}
void DFS(){
   // t = 0;
    init();
    nbCC=0;
    for(set<int>::iterator q = V.begin(); q != V.end(); q++){
        int  v = *q;
        if(color[v] == 'W'){
            nbCC++;
            DFSVisit(v);
        }
    }

    for(int i =1;i<=nbCC;i++){
        cout<<" thanh phan lien thong " << i<<":  ";
        for(set<int>::iterator q = V.begin(); q != V.end(); q++){
        int  v = *q;
        if(indeCC[v] == i)
                cout<<v<<"  ";

        }
        cout<<endl;
    }
      //  cout << v << ", d = " << d[v] << ", f = " << f[v] << ", p = " << p[v] << endl;
}
void findPath(int s, int t){
    init();
    DFSVisit(s);
    stack<int> S;
    while(t != s){
        S.push(t);
        t = p[t];
    }
    cout << s;
    while(!S.empty()){
        int v = S.top(); S.pop();
        cout << " -> " << v;
    }
}

void readData(char* filename){
    ifstream f(filename);
    while(!f.eof()){
        int v;
        f >> v;
        if(v == -1) break;
        V.insert(v);
    }
    while(!f.eof()){
        int u,v;
        f >> u;
        if(u == -1) break;
        f >> v;
        A[u].insert(v);
    }
}
void printGraph(){
    for(set<int>::iterator p = V.begin(); p != V.end(); p++){
        int v = *p;
        cout << "A[" << v << "] = ";
        for(set<int>::iterator q = A[v].begin(); q != A[v].end(); q++){
            int u = *q;
            cout << u << " ";
        }
        cout << endl;
    }
}
int main(){
    readData("graph-dfs.txt");
    printGraph();
    DFS();
    //findPath(1,7);
}
