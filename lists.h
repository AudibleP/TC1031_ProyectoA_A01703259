#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>

using namespace std;

template <class T> class List;

template <class T>
class Link {
private:

	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

template <class T>

class List {

public:

    List();
    List(const List<T>&);
	~List();

	string toString() const;

	void insertion(T);
	void show();
	void deleteAt(T);

private:

    Link<T> *head;
    int size;

};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
void List<T>::insertion(T val){

    Link<T> *newL, *p;

    newL = new Link<T>(val);


    if (head == 0) {
        newL->next = head;
        head = newL;
        size++;
        return;
	}

    p = head;
    while (p->next != 0) {
		p = p->next;
	}

	newL->next = 0;
	p->next = newL;
    size++;
}


template <class T>
void List<T>::deleteAt(T val) {
    Link<T> *p, *temp;
    p = head;

    while(p->value != val){
        temp = p;
        p = p->next;
    }
    if(p==NULL){
        cout<<"adsda\n";
    }
    else if(temp == NULL){
        head = head ->next;
        delete p;
    }
    else{
        temp->next = p->next;
        delete p;
    }

}

template <class T>
void List<T>::show(){
    Link<T> *p;
    p = head;
    while(p != NULL){
        cout<<p->value<<"\n";
        p = p->next;
    }
}

template <class T>
string List<T>::toString() const {
	stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}
#endif
