#include <iostream> // cin, cout
#include <cstdio>   // scanf, printf
#include <cmath>    // ceil(x)
using namespace std;
bool DEBUG = false;

// Referenciar: &
// Desreferenciar: *

void pasaje_por_valor(int param) {
    cout << "Imprimo el parametro: " << param << endl;
    param++;
}

void pasaje_por_referencia(int& param) {
    cout << "Imprimo el parametro: " << param << endl;
    param++;
}

void pasarle_un_puntero(int* param) {
    cout << "Imprimo el parametro: " << param << endl;
    (*param)++; //Lo desreferencio y lo edito
}

void punteros_para_devolver_2_cosas(int* un_puntero, int* otro_puntero) {
    *un_puntero = 3;  // cambio el valor de lo que referencia el puntero
    *otro_puntero = 7;
}


int main()
{
    int valor = 5;

    int *p; // Define un puntero de int
    p = &valor; // & devuelve la "dirección" de esa variable. Se asigna a p.

    cout << "valor: " << valor << endl;
    cout << "dirección (&valor): " << &valor << endl;
    cout << "puntero (p): " << p << endl;

    int v1;
    v1 = *p; // Si p es un puntero, se desreferencia y devuelve el valor.
    cout << "Desreferenciar el puntero (v1 = *p): " << v1 << endl;

    cout << "===========================" << endl;
    cout << "Pasaje por valor..." << endl;
    cout << "valor pre: " << valor << endl;
    pasaje_por_valor(valor);
    cout << "valor post: " << valor << endl;


    cout << "Pasaje por referencia..." << endl;
    cout << "valor pre: " << valor << endl;
    pasaje_por_referencia(valor);
    cout << "valor post: " << valor << endl;
    
    cout << "Pasarle un puntero..." << endl;
    cout << "valor pre: " << valor << endl;
    pasarle_un_puntero(p);
    cout << "valor post: " << valor << endl;

    cout << "===========================" << endl;
    cout << "Void pointers..." << endl;
    void* void_ptr; // puede apuntar a cualquier tipo, pero hay que castearlo (Ojo porque te deja castearlo a cualquier cosa).
    int pepe = 5;
    void_ptr = &pepe;
    cout << "void pointer casteado a int y desreferenciado: " << *(int*)void_ptr << endl;

    string tito = "un_string";
    void_ptr = &tito;
    cout << "void pointer casteado a string y desreferenciado: " << *(string*)void_ptr << endl;

    void_ptr = &tito;
    cout << "void pointer casteado a double pero que tenía string y desreferenciado: " << *(double*)void_ptr << endl;

//Foo* f = new Foo(); // Initializes f pointer.
//int k = f->x; // Sets k equal to the value of f’s member variable.


    cout << "===========================" << endl;
    cout << "Arrays son direcciones..." << endl;

    int intArray[5] = {3, 5, 8, 18, 24};

    cout << "intArray es {3, 5, 8, 18, 24}" << endl;
    cout << "intArray[3]: " << intArray[3] <<  endl;
    cout << "*(intArray+3): " << *(intArray+3) <<  endl;
    cout << "*(intArray+247): " << *(intArray+247) <<  endl;

    cout << "===========================" << endl;
    cout << "Usar punteros para devolver cosas..." << endl;
    int alpha = 0;
    int beta = 0;
    punteros_para_devolver_2_cosas(&alpha, &beta);
    cout << "alpha que era 0: " << alpha << endl;
    cout << "beta que era 0: " << beta << endl;






}