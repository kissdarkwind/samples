#include "col.h"

template <typename T>
T* Collection<T>::item(int index) {
	return v[index];
}

template <typename T>
int Collection<T>::getLength() {
	return v.size();
}

template <typename T>
void Collection<T>::add(T *t) {
	v.push_back(t);
}

template <typename T>
void Collection<T>::remove(int index) {
	v.erase(v.begin() + index);
}
