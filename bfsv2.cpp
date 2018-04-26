#include <set>
#include <stack>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
#include<iomanip>

using namespace std;
set<int> V;// tập đỉnh
map<int,set<int> > A;//cặp "cạnh" : 2 đỉnh đc nối với nhau
map<int ,char > color;
map<int ,int > p;
map<int ,int> d;

void readData(char* fn){
	ifstream f(fn);
	while(!f.eof()){
		int v;
		f>>v;
		if(v ==-1) break;
		V.insert(v);
		}
	while(!f.eof()){
		int v;int u;
		f>> v;
		if(v==-1) break;
		f>>u;
		A[v].insert(u);
	}
}
void printGraph(){
	set<int> ::iterator p;
	for( p = V.begin();p != V.end();p++){
		int v=*p;
		cout<<"A["<<v<<"] = :";
		set<int> ::iterator q;
		for(q =A[v].begin();q != A[v].end();q++){
			int u =*q;
			cout<< u <<"  ";
		}
		cout<<endl;

	}
}
void init(){
	for(set<int>::iterator q = V.begin() ; q != V.end();q++){
		int u = *q;
		color[u] ='W';
		p[u] =-1;
	}
}
//duyet do thi BFS
/*
** Ý TƯỞNG CHUNG**
- Ban dau tất cả các đỉnh có màu White ( chua duyệt qua)
-khi duyệt qua đỉnh v mà chưa xong -> màu Gray
-khi tất cả các đỉnh kề của đỉnh v duyệt xong -> v chuyển sang màu Black
- dùng mảng d[v] : la  thoi diem tham diem v
- p[v] luu gia tri "cha" cua dinh v
*/

void BFS_Visit(int u){
	color[u] ='G';
	d[u] =0;
	queue <int> Q;
	Q.push(u);
	while(!Q.empty()){
		int v =Q.front();
		Q.pop();
		for(set <int> ::iterator q = A[v].begin();q != A[v].end();q++){
			int  temp = * q;
			//cout<< v << "->";
			//cout<< temp<<endl;
			if(color[temp]=='W'){
				color[temp] ='G';
				d[temp] = d[v]+1;
				p[temp] = v;
				Q.push(temp);
			}
		}
	}
	color[u] ='B';
}
void BFS(){
	init();
	for(set<int>::iterator q = V.begin() ; q != V.end();q++){
		int u = *q;
		if(color[u]=='W')
			BFS_Visit(u);
	}
}
void findPath(int vStart,int vFinish){
	BFS_Visit(vStart);
	if(color[vFinish]=='W'){
		cout<<"NO FIND PATH!!";
		return;
	}
	stack <int> S;
	while( vFinish != vStart){
		S.push(vFinish);
		vFinish = p[vFinish];
	}
	cout<< vStart;
	while(!S.empty()){
		int  v =S.top();
		cout <<"->"<<v;
		S.pop();
	}
	cout<<endl;
}

int main(){
	readData("graph-dfs.txt");
	init();
	printGraph();
	//BFS();
	//BFS_Visit();
	findPath(1,2);

}