#pragma once

template<class T>
class Nodo {
private:
	T* item;
	Nodo* siguiente;
public:
	Nodo(T*, Nodo*);
	virtual ~Nodo();

	Nodo* getSiguiente();
	T* getItem();

	void setSiguiente(Nodo*);
	void setItem(T*);
};

template<class T>
Nodo<T>::Nodo(T* itemIn, Nodo* nodoIn) {
	item = itemIn;
	siguiente = nodoIn;
}
template<class T>
Nodo<T>::~Nodo() {}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() {
	return siguiente;
}
template<class T>
T* Nodo<T>::getItem() {
	return item;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo* nodoIn) {
	siguiente = nodoIn;
}
template<class T>
void Nodo<T>::setItem(T* itemIn) {
	item = itemIn;
}