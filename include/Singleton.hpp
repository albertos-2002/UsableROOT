// included by "Singleton.h"
#include <iostream>

template <typename T> bool Singleton<T>::verbose = false;

template <typename T> Singleton<T>::Singleton() {
  if ( verbose ) std::cout << "create Singleton " << this << std::endl; 
}

template <typename T> Singleton<T>::~Singleton() {
  if ( verbose ) std::cout << "delete Singleton " << this << std::endl; 
}

template <typename T> T* Singleton<T>::instance() {
  if ( verbose ) std::cout << "Singleton::instance " << std::endl; 
  // the object is created only once (static for the function), the first time "instance()" is called
  static T* obj = new T;
  return obj;
}

