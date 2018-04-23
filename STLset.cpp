#include<stdio.h>
#include<iostream>
#include<set>
#include<map>
//về cơ bản set và map có các phương thức chả khác mẹ gì nhuau cả :))
using namespace std;
int main(){

	set < int> setOfIntegers;
	map<int,set<int> > test;
	set<int>::iterator it;
	setOfIntegers.insert(1);
	setOfIntegers.insert(297);
	setOfIntegers.insert(11);
	setOfIntegers.insert(12);
	setOfIntegers.insert(132);
	setOfIntegers.insert(122);
	setOfIntegers.erase(setOfIntegers.find(11),setOfIntegers.find(297));
	for( it=setOfIntegers.begin();it !=setOfIntegers.end();it++)
		printf("%5d",*it);



}