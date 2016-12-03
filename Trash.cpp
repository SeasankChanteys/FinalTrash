#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstdlib>
#include<time.h>

using namespace std;

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

	return 0;
}
