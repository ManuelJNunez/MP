#include <iostream>

using namespace std;

void encadenar_cadenas(char s1[], char *s2){
	int i;

	i = 0;

	while( s1[i] != '\0' )
		i++;

	while( *s2 != '\0' ){
		s1[i] = *s2;
		i++;
		*(s2++);
	}

	s1[i++] = '\0';

}

int main(){
	const int TAM = 500;
	char caracter, cad1[TAM] = "hola", *cad2 = " mundo";

	cout << "Sin encadenar: ";

	for( int i = 0; cad1[i] != '\0'; i++  )
		cout << cad1[i];

	cout << endl;

	encadenar_cadenas(cad1, cad2);

	cout << "Encadenada: ";

	for(int i = 0; cad1[i] != '\0'; i++ )
		cout << cad1[i];

	cout << endl;

	return 0;
}
