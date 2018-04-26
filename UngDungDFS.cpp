#include<iostream>
#include<map>
#include<set>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
map<int, int> d;// d[v] visiting time point
map<int, int> f;
map<int, int> p;
map<int, char> color;
int t;
map<int ,int> indeCC;
int nbCC;
//-----------------------------
set<int> code;
map< int , string > code2name;
map<int , string > code2ID;
map<string,int> ID2code;
map<string,string > name2ID;
map<int,set<int> > code2Code;

void readData(char *fn){
	FILE* f =fopen(fn,"r");
	int n;
	fscanf(f,"%d",&n);
	int m=n;
	char name[200];
	char id[20];
	for(int i =0;i< m;i++){
		fscanf(f,"%s", &name);
		cout<<name<<"  ";
		fscanf(f,"%s", &id);
		cout<<id<<endl;
	}
}
void readData2(char*fn){
	ifstream f(fn);
	int n;
	int index=0;
	f>>n;
	//cout<<n<<endl;
	char name[200];
	char id[20];
	while(!f.eof()){
		f>>name;
		if(name[0]=='-') break;
		//cout<<name<<"  ";
		f>>id;
		index++,
		//cout<<id<<endl;
		code.insert(index);
		code2ID[index]= id;
		ID2code[id] =index;
		code2name[index] = name;
		name2ID[name] = id;
	}
	while(!f.eof()){
		char i[10];
		char j[10];
		f >> i;
		if(i[0]=='-') break;
		f>>j;
		code2Code[ID2code[i]].insert(ID2code[j]);
	}
}


void init(){
    for(set<int>::iterator q = code.begin(); q != code.end(); q++){
        int v = *q;
        color[v] = 'W';
       // p[v] = -1;
    }

}

void DFSVisit(int u){
    t++;
    d[u] = t;
    indeCC[u] =nbCC;
    color[u] = 'G';
    for(set<int>::iterator q = code2Code[u].begin(); q != code2Code[u].end(); q++){
        int v = *q;
        if(color[v] == 'W'){
            p[v] = u;
            DFSVisit(v);
        }
    }
    t++;
    f[u] = t;
    color[u] = 'B';
}
void DFS(){
   // t = 0;
    init();
    nbCC=0;
    for(set<int>::iterator q = code.begin(); q != code.end(); q++){
        int  v = *q;
        if(color[v] == 'W'){
            nbCC++;
            DFSVisit(v);
        }
    }

    for(int i =1;i<=nbCC;i++){
        cout<<" dieu kien hoc mon " << i<<":  ";
        for(set<int>::iterator q = code.begin(); q != code.end(); q++){
        int  v = *q;
        if(indeCC[v] == i)
                cout<<v<<"  ";

        }
        cout<<endl;
    }
}
int main(){
	readData2("ttt.txt");
	DFS();
/*	cout<<"-------------------------------------------"<<endl;
	for(set<int> ::iterator p =code.begin();p != code.end(); p++){
		int s =*p;
		cout<<setw(5)<<s<<endl;
	}
	cout<<"-------------------------------------------"<<endl;
/*	for(set< string> ::iterator p =code2ID.begin();p != code2ID.end(); p++){
		string s =*p;
		cout<<s<<"    ";
		for(set<string> ::iterator q =ID2name[s].begin();q !=ID2name[s].end();q++){
			string r =*q;
			cout<<r <<endl;
		}
	}
= for(set<int>::iterator p = code.begin(); p != code.end(); p++){
        int v = *p;
        cout << "A[" << v << "] = ";
        for(set<int>::iterator q = code2Code[v].begin(); q != code2Code[v].end(); q++){
            int u = *q;
            cout << u << " ";
        }
        cout << endl;
    }
*/
}