#include <set>
#include <stack>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;

set<int> V;// set of vertices of the graph
map<int, set<int> > A;// A[v]=x: x is the set of adjacent vertices of v

// data structure for DFS
map<int, int> d;// d[v] visiting time point
map<int, int> f;
map<int, int> p;
map<int, char> color;
int t;

void init(){
    for(set<int>::iterator q = V.begin(); q != V.end(); q++){
        int v = *q;
        color[v] = 'W';
        p[v] = -1;
    }

}
void readData(char* filename){
    ifstream f(filename);
    while(!f.eof()){
        int v;
        f >> v;

        if(v == -1) break;
        cout<<v<<"  ";
        V.insert(v);
    }
    cout<<endl;
   while(!f.eof()){
        int u,v;
        f >> u;
        if(u == -1) break;
        f >> v;
        A[u].insert(v);
        cout<<u<<"  "<<v<<endl;
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
void findPath(int s, int t){
    init();
    // use BFS
    queue<int> Q;
    d[s] = 0;
    Q.push(s);
    color[s] = 'G';
    while(!Q.empty()){
        int v = Q.front();
        cout<<"lay ra:"<<v<<"->";
        Q.pop();
        /*duyệt tât các các định cạnh đỉnh xxx
        khi được duyệt qua thì đỉnh đổi màu
        đưa đỉnh đó vào hàng đợi
        p là map chứa cha của nó
        */
        for(set<int>::iterator q = A[v].begin(); q != A[v].end(); q++){
            int x = *q;
            if(color[x] == 'W'){
                d[x] = d[v] + 1;
                p[x] = v;
                color[x] = 'G';
                Q.push(x);
            }
        }
        cout<<endl;
    }
    if(color[t] == 'W'){
        cout << "PATH NOT FOUND" << endl;
    }else{
        stack<int> S;
        int x = t;
        while(x != s){
            S.push(x);
            x = p[x];
        }
        cout << "Path from " << s << " -> " << t << ": ";
        cout << s;
        while(!S.empty()){
            x = S.top(); S.pop();
            cout << " -> " << x;
        }
        cout << endl;
    }
}

int main(){
    readData("graph-dfs.txt");
   // printGraph();
//    DFS();
    findPath(1,7);
}
