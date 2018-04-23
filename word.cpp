#include <string>
#include <iostream>
#define MAX 100
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <fstream>

using namespace std;

struct Node{
    int id;
    string label;
};

map<string, int> m;

void solve(char* filename){
    ifstream f(filename);
    string s;
    set<string> W;
    while(!f.eof()){
        f >> s;
        //if(s.compare("-1") == 0) break;
        W.insert(s);
        m[s] = m[s] + 1;
        cout << s << endl;
    }
    cout << "KET QUA" << endl;
    for(set<string>::iterator p = W.begin(); p != W.end(); p++){
        string s = *p;
        cout << s << " xuat hien " << m[s] << endl;
    }
}

void testStack(){
    stack<int> S;
    for(int i = 1; i <= 10; i++)
        S.push(i);

    while(!S.empty()){
        int i = S.top(); S.pop();
        cout << i << endl;
    }

    queue<int> Q;
    for(int i = 1; i <= 10; i++){
        Q.push(i);
    }
    cout << "QUEUE" << endl;
    while(!Q.empty()){
        int i = Q.front(); Q.pop();
        cout << i << endl;
    }
}

int main(){
    testStack();
    //solve("words.txt");
    /*
    list<int> L;
    for(int i = 1; i <= 10; i++)
        L.push_back(i);
    for(int i = 1; i <= 10; i++)
        L.push_back(i);

    list<int>::iterator p;
    for(p = L.begin(); p != L.end(); p++){
        int x = *p;
        cout << x << " ";
    }
    cout << ", size of L = " << L.size() << endl;


    set<int> S;
    for(int i = 1; i <= 1000; i++)
        S.insert(i);

    for(int i = 1; i <= 990; i++)
        S.erase(i);

    cout << "S = ";
    set<int>::iterator ps;
    for(ps = S.begin(); ps != S.end(); ps++){
        cout << *ps << " ";
    }
    cout << ", size of S = " << S.size() << endl;
    */
}
