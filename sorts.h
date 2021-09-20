#ifndef sorts_h
#define sorts_h

#include <vector>
#include <iostream>
#include <list>

using namespace std;

template < class T >
class Sorts {

  private:
    void swap(vector<T>&vec, int, int);
    void copyArray(vector<T>& , vector<T>& , int , int );
    void mergeArray(vector<T>& A, vector<T>& B, int i, int j, int k);
    void mergeSplit(vector<T>& , vector<T>& , int , int );

  public:
    void ordenaMerge(vector<T>&);
};

template <class T>
void Sorts<T>::swap(vector<T> &vec, int i, int j) {
	int aux = vec[i];
	vec[i] = vec[j];
	vec[j] = aux;
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T> &vec) {
	vector<T> aux(vec.size());

	mergeSplit(vec, aux, 0, vec.size() - 1);
}

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int inf, int sup) {
	int med;

	if ( (sup - inf) < 1 ) {
		return;
	}
	med = (sup + inf) / 2;
	mergeSplit(A, B, inf, med);
	mergeSplit(A, B, med + 1, sup);
	mergeArray(A, B, inf, med, sup);
	copyArray(A, B, inf, sup);
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int inf, int med, int sup) {
	int i, j, k;

	i = inf;
	j = med + 1;
	k = inf;

	while (i <= med &&j <= sup) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > med) {
		for (; j <= sup; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= med; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int inf, int sup) {
	for (int i = inf; i <= sup; i++) {
		A[i] = B[i];
	}
}



#endif
