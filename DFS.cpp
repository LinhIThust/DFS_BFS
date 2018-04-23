#include<iostream>
#include<fstream>
#include<map>
#include<set>
using namespace std;
//-------------DFS variable----------
set<int> V;
map<int ,set<int>  > A;
map<int,int> p;
map<int ,int> d;
map<int,char> color;
//---------------*****---------------
//------------Connected graph--------
map <int,int> indexCC;
int nbCC;
//---------------*****---------------

void readData(char* filename){
    ifstream f(filename);
	int n;
	f >>n;
	for(int i =1;i<=n;i++)
		V.insert(i);
	//----------------
	int u=0,v=0;
    while(u != -1){
        f >> u;
        if(u == -1) break;
        f >> v;
        A[u].insert(v);
    }
}
//Creates W(white) vertices
void init(){
	for(set<int>::iterator p = V.begin(); p != V.end(); p++){
		int v = *p;
		color[v] = 'W';
	}
}

void DFS_Visit(int u){
	indexCC[u] = nbCC;
	color[u] ='G';
	for(set<int>::iterator p = A[u].begin(); p != A[u].end(); p++){
		int v=*p;
		if(color[v]='W'){
			DFS_Visit(v);
		}
	}
	color[u] = 'B';
}

void DFS(){
	init();
	nbCC=0;
	for(set<int>::iterator p = V.begin(); p != V.end(); p++){
		int v=*p;
		if(color[v] == 'W'){
			nbCC++;
			//cout<<"test"<<nbCC<<"  <> ";
			DFS_Visit(v);
		}
	}

}

void printGraph(){
	for(set<int> :: iterator  p = V.begin(); p != V.end();p++){
		int u = *p;
		cout<< "A[ "<< u <<"] : ";
		for(set<int>::iterator q = A[u].begin(); q != A[u].end(); q++){
            int v = *q;
            cout << v << " ";
        }
	cout<<endl;
	}

}

void printConnectedGraph(){
	for(int i = 1;i<=nbCC;i++){
		cout<<"Connected graph"<<i<<" : ";
		for(set<int> :: iterator  p = V.begin(); p != V.end();p++){
			int u = *p;
			if(indexCC[u] == i)
				cout<<u <<"  ";
		}
	cout<<endl;
	}
}


int main(){
	readData("graph-dfsV2.txt");
    printGraph();
    DFS();
	printConnectedGraph();



}