// C++ Program to demonstrate the working of
// capacity(), resize() and shrink_to_fit()
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    // String inicial
	string str = "Hola como estas";
	cout << "String inicial : "<<str<<endl;

	// Muestra la capacidad del string
	cout << "Capacidad del string: "<<str.capacity() << endl;

	// Cambio de tamaño del string
	str.resize(5);

	cout<<"Cambio de capacidad "<<str.capacity()<<endl;

	// String despues de cambiarle el tamaño
	cout << "String despues del cambio de tamano: "<<str << endl;

	// Muestra la longitud del string
	cout << "Longitud del string: " << str.length()<< endl;

	// Decrementando la capacidad del string
	str.shrink_to_fit();

	// Muestra la capacidad del string despues de reducir su tamaño
	cout << "La nueva capacidad del string despues de reducirlo: "<<str.capacity() << endl;

	return 0;
}
