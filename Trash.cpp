#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstdlib>
#include<time.h>
#include<string>

using namespace std;

class TrashCan {
public:
	int size = 500; //can hold 500
	//trash can
	TrashCan() {

	}
	//trash can of custom size
	TrashCan(int s) {
		size = s;
	}

	friend TrashCan operator+(TrashCan a, TrashCan b) {
		a.size = a.size+b.size;
		return a;
	}

};

int main() {

	srand(time(NULL));

	vector<int> hello;

	for(int i = 0; i<10; i++)
		hello.push_back(rand()%100);

	sort(hello.begin(), hello.end(), greater<int>()); //sorts form largest to smallest

	cout<<count(hello.begin(), hello.end(), 24)<<endl; //prints the number of occur. of the number

	cout<<endl;

	for(int i = 0; i<hello.size(); i++)
		cout<<hello[i]<<endl;

	cout<<endl<<"Entering sets"<<endl<<endl;


	set<int> c;
	set<int> d;

	for(int i = 0; i<5; i++)
		c.insert(rand()%100);

	set<int>::iterator itItor;
	for(itItor=c.begin(); itItor!=c.end(); itItor++) {
		cout<<*itItor<<endl;
	}

	//can use both function for set and algorithm
	cout<<endl<<c.count(0)<<endl;

	cout<<endl<<count(c.begin(), c.end(), 0)<<endl;


	//uppper_bound and lower_bound
	for(int i = 0; i<5; i++) {
		d.insert(i+1);
	}

	cout<<endl;

	for(itItor=d.begin(); itItor!=d.end(); itItor++) {
		cout<<*itItor<<endl;
	}

	set<int>::iterator itLow;
	set<int>::iterator itHigh;

	itLow = d.lower_bound(2);
	itHigh = d.upper_bound(4);
	d.erase(itLow, itHigh);

	for(itItor=d.begin(); itItor!=d.end(); itItor++) {
		cout<<*itItor<<endl;
	}


	//friends and operator overloading
	cout<<endl;
	TrashCan t1(1000);
	cout<<"t1: "<<t1.size<<endl;
	TrashCan t2;
	cout<<"t2: "<<t2.size<<endl;
	t1=t1+t2;
	cout<<"t1: "<<t1.size<<endl;


	//strings
	string str = "Hello World";
	cout<<endl<<str.substr(0, 5)<<endl;

	cout<<str.find('H', 0)<<endl; //returns 0
	cout<<str.find("llo", 0)<<endl; //returns 2
	cout<<str.find('G', 0)<<endl; //returns npos (= 18446744073709551615)



	str.erase(0, 5);
	cout<<str<<endl;
	str.insert(3, "Moo");
	cout<<str<<endl;
	str.replace(3, 1, "F");
	cout<<str<<endl;

	int lists[5];
	cout<<endl<<sizeof(lists)/sizeof(int)<<endl;

	return 0;

}
