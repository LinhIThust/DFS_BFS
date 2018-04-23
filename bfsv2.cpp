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
/* tìm đường đi từ đỉnh vStart -> vFinish
** Ý TƯỞNG CHUNG**
- Ban dau tất cả các đỉnh có màu White ( chua duyệt qua)
-khi duyệt qua đỉnh v mà chưa xong -> màu Gray
-khi tất cả các đỉnh kề của đỉnh v duyệt xong -> v chuyển sang màu Black
*/
/* 	 VỚI DUYỆT THEP CHIỀU RỘNG (BFS)
- dùng mảng d[v]

*/
void findPath(int vStart,int vFinish){




}
int main(){
	readData("graph-dfs.txt");
	printGraph();


}