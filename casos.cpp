#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include "sorts.h"
#include "bst.h"
#include "lists.h"

using namespace std;

template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}


int main(int argc, char* argv[]) {

	int array1[] = {43, 21, 3542, 213 ,321, 543, 645, 324, 1, 3, 3, 123};
	vector<int> original1 (array1, array1 + sizeof(array1) / sizeof(int) );

	int array2[] = {120, 110, 52, 97, 33, 68, 1};
	vector<int> original2 (array2, array2 + sizeof(array2) / sizeof(int) );

	vector<int> prueba;
	Sorts<int> sorts;
	string resp1 = "[1, 3, 3, 21, 43, 123, 213, 321, 324, 543, 645, 3542]";
	string resp2 = "[1, 33, 52, 68, 97, 110, 120]";

	prueba = original1;
	sorts.ordenaMerge(prueba);


	cout << "\n" <<"1.- esperada " << resp1 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaMerge(prueba);

	cout << "\n" <<"2.- esperada " << resp2 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");


	//////////////////////////////

	BST<int> bst;
	string  ans;

	bst.add(9);

	ans =	"[9]\n[9]\n[9]\n[9]";
	cout << "\n" <<"3.- esperada " << ans << "\n programa " << bst.visit() << "\n";
	cout <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

	cout << "\n" <<"4.- esperada " << 1  << "\n programa " << bst.height() << "\n";
	cout << 	(1 == bst.height() ? "success\n" : "fail\n");

	bst.add(15);
	bst.add(2);
	bst.add(116);
	bst.add(210);
	bst.add(50);

	ans = "[9 2 15 116 50 210]\n[2 9 15 50 116 210]\n[2 50 210 116 15 9]\n[9 2 15 116 50 210]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << bst.visit() << "\n";
	cout <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

	cout << "\n" <<"6.- esperada " << 4  << "\n programa " << bst.height() << "\n";
	cout <<	(4 == bst.height() ? "success\n" : "fail\n");

	cout << "\n" <<"7.- esperada " << 2  << "\n programa " << bst.whatlevelamI(18) << "\n";
	cout << (2 == bst.whatlevelamI(18) ? "success\n" : "fail\n");

	cout << "\n" <<"8.- esperada " << 0  << "\n programa " << bst.whatlevelamI(8) << "\n";
	cout <<	(0 == bst.whatlevelamI(8) ? "success\n" : "fail\n");

	/////////////////////////////////////

    List<string> b1;

	b1.insertion("2");
	ans = "[2]";
	cout << "\n" <<"9.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.insertion("3");
	b1.insertion("6");
	b1.insertion("10");
	ans = "[2, 3, 6, 10]";
	cout << "\n" <<"10.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.deleteAt("3");
	ans = "[2, 6, 10]";
	cout << "\n" <<"11.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");
}
