#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<stack>

using namespace std;
//-------------DFS variable----------
set<int> V;
map<int ,set<int>  > A;

map<int,int> p;//cha của đỉnh d[v] là u
map<int,int> d;//d[v] đỉnh đang đc thăm
map<int,int> f;//thời điểm kết thúc thăm
map<int,char> color;
int t;//thời diderm thăm v
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
	t++;
	d[u] = t;
	indexCC[u] = nbCC;
	color[u] ='G';
	for(set<int>::iterator q = A[u].begin(); q != A[u].end(); q++){
		int v = *q;
		if(color[v]=='W'){
			p[v] = u;
			DFS_Visit(v);
		}
	}
	t++;
	f[u] =t;
	color[u] = 'B';
}

void DFS(){
	t=0;

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
// find Path from s to t
void findPath(int s,int t){
	init();
	stack <int> S;
	DFS_Visit(s);
	if(color[t]=='W'){
		cout<<"Not Find Path from "<< s << " to "<< t;
		return;
	}
	while( t != s){
		S.push(t);
		t = p[t];
	}
	cout<< s;
	while(!S.empty()){
		cout<< "->" <<S.top();
		S.pop();
	}
	//cout<<t;
//	if()



}

int main(){
	readData("graph-dfsV2.txt");
    printGraph();
    DFS();
	printConnectedGraph();
	findPath(1,7);



}