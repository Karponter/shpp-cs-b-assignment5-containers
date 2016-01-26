#include <iostream>

#include "vector/kt_vector.cpp"
#include "dequeue/kt_dequeue.cpp"

using namespace KT;
using namespace std;

struct Points {
    int column;
    int row;

};

Points makePoints(int a, int b){
    Points p;
    return p={a, b};
}


int main(int argc, char const *argv[]) {

	Points a = makePoints(10,10);
	cout << a.row;

	// kt_vector<int> a;
	// a.push_back(0);
	// a.push_back(1);
	// a.push_back(2);
	// a.push_back(3);
	// a.push_back(4);
	// a.push_back(5);
	// cout << "VECTOR A:" << endl;
	// a.dump();

	// kt_vector<int>::iterator fr(a.begin()+2); 
	// kt_vector<int>::iterator to = a.end(); 
	// kt_vector<int> b(fr, to);
	// cout << "VECTOR B:" << endl;
	// b.dump();

	// fr = a.begin()+2;
	// kt_dequeue<int> c(fr, to);
	// cout << "QUEUE C: " << c << endl;

	return 0;
}