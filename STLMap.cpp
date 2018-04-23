#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#define Insert(a,b) insert(pair<int,int>(a,b))
/*Lớp "map" quản lý "data" bằng "position", nếu trường hợp ta quên "position" thì làm sao có thể truy xuất để lấy dữ liệu "data" cần dùng. Để giải quyết vấn đề trên thì trong lớp "map" đã được định nghĩa thao tác "iterators" cho phép chúng ta truy xuất đến phần tử trong "map" để lấy dữ liệu "data" và "position" cần thiết. Có các "iterators" đã được cung cấp như: begin(), end(), rbegin(), rend(),… chúng hoạt động như nhau nhưng chỉ khác phần tử truy cập ở vị trí nào trong lớp "map".*/
using namespace std;

int main(){
	map<int,char*> student;
	map<int,int> testInt,testIntCopy;
	testInt[7] =7;
	testInt[1] =9;
	testInt[2] =10;
	testInt[3] =100;
	testInt[0] =-1;
	//-------------------
	student[0] ="linh dep trai  v l";
	student[1] ="ddkfdkjh dfhdkjhg";
	student[2] ="legrege";
	student[0] ="haha";
	//---------------------
	map<int,char*>::iterator temp;
	map<int,int>::iterator temp2;
	for(temp = student.begin();temp !=student.end();temp++)
		printf("  (%d, %s)  ",*temp);
	cout<<endl;


	//copy map testInt->testIntCopy
	testIntCopy=testInt;
	//--------------DELETE--------------
	//delete element "position" ???
	testIntCopy.erase(1);
	//delete element "position",which xx accessing!!
	map<int,int>::iterator x = testIntCopy.find(0);
	//testIntCopy.erase(x);
	//delete element form x -> ???
	testIntCopy.erase(x,testIntCopy.end());
	//printf map
	//--------------INSERT-----------
	//chèn 1 cặp đối tượng
	testInt.insert(pair<int,int>(10,7));
	//chen vao dau vi tri
	testInt.Insert(12,5);
	//chen map 1 vào map2
	testInt.insert(testIntCopy.begin(),testIntCopy.end());
	//
	testInt.insert(testIntCopy.begin(),testIntCopy.find(3));
	//-----------------------------------------------------
	testInt[4] =77;
	for(temp2 =testInt.begin();temp2 !=testInt.end();temp2++)
		printf("  (%d,%d)  ",*temp2);
	cout<<endl;
	for(temp2 =testIntCopy.begin();temp2 !=testIntCopy.end();temp2++)
		printf("  (%d,%d)  ",*temp2);
	//swap 2 map
	testInt.swap(testIntCopy);



}