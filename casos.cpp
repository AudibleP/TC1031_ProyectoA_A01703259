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

	int array1[] = {58, 92, 75, 5, 21, 92, 84, 91, 64, 54, 3, 28, 11, 61, 65, 4, 1, 8, 52, 78};
	vector<int> original1 (array1, array1 + sizeof(array1) / sizeof(int) );

	int array2[] = {120, 10, 5, 897, 333, 68};
	vector<int> original2 (array2, array2 + sizeof(array2) / sizeof(int) );

	vector<int> prueba;
	Sorts<int> sorts;
	string resp1 = "[1, 3, 4, 5, 8, 11, 21, 28, 52, 54, 58, 61, 64, 65, 75, 78, 84, 91, 92, 92]";
	string resp2 = "[5, 10, 68, 120, 333, 897]";

	prueba = original1;
	sorts.ordenaMerge(prueba);


	cout << "\n" <<"1.- esperada " << resp1 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaMerge(prueba);

	cout << "\n" <<"2.- esperada " << resp2 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original1;
	sorts.ordenaMerge(prueba);

	cout << "\n" <<"3.- esperada " << resp1 << "\n   programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	prueba = original2;
	sorts.ordenaMerge(prueba);

	cout << "\n" <<"4.- esperada "  << resp2 << "\n programa " << arrayToString(prueba) << "\n";
	cout <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

	//////////////////////////////

	BST<int> bst;
	string  ans;

	bst.add(10);

	ans =	"[10]\n[10]\n[10]\n[10]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << bst.visit() << "\n";
	cout <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

	cout << "\n" <<"6.- esperada " << 1  << "\n programa " << bst.height() << "\n";
	cout << 	(1 == bst.height() ? "success\n" : "fail\n");

	bst.add(12);
	bst.add(8);
	bst.add(110);
	bst.add(112);
	bst.add(18);

	ans = "[10 8 12 110 18 112]\n[8 10 12 18 110 112]\n[8 18 112 110 12 10]\n[10 8 12 110 18 112]";
	cout << "\n" <<"7.- esperada " << ans << "\n programa " << bst.visit() << "\n";
	cout <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

	cout << "\n" <<"8.- esperada " << 4  << "\n programa " << bst.height() << "\n";
	cout <<	(4 == bst.height() ? "success\n" : "fail\n");

	cout << "\n" <<"9.- esperada " << 4  << "\n programa " << bst.whatlevelamI(18) << "\n";
	cout << (4 == bst.whatlevelamI(18) ? "success\n" : "fail\n");

	cout << "\n" <<"10.- esperada " << 2  << "\n programa " << bst.whatlevelamI(8) << "\n";
	cout <<	(2 == bst.whatlevelamI(8) ? "success\n" : "fail\n");

	/////////////////////////////////////

    List<string> b1;

	b1.insertion("2");
	ans = "[2]";
	cout << "\n" <<"11.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.insertion("3");
	b1.insertion("6");
	b1.insertion("10");
	ans = "[2, 3, 6, 10]";
	cout << "\n" <<"12.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

	b1.deleteAt("3");
	ans = "[2, 6, 10]";
	cout << "\n" <<"13.- esperada " << ans << "\n programa " << b1.toString() << "\n";
	cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");
}
