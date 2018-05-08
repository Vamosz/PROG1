#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    int betu = 0;
    int sor = 0;
    int szo = 0;
    int szokoz = 0;
    int szam = 0;
    int irasjel = 0;
    char c;

    ifstream is("ki.txt");
	
    while (is.get(c)) {
        if (c == ' ' || c == '\t') {
		szokoz++;
		}
		if (isalpha(c)){
                        betu++;
                }
		if (isdigit(c)) {
			szam++;
		}
		if (c == '\n') {
			sor++;
		}
		if (ispunct(c)) {
			irasjel++;
		}
		if (c == ' ' || c == '\t' || c == '\n') {
			szo++;
		}
    }

    if (c != '\n') {
        sor++;
    }

	is.close();
	
    cout << "Sor, Szó, Betű, Szóköz, Szám, Egyéb írásjel\n";
    cout << setw(2) << sor << setw(6) << szo << setw(6) << betu << setw(6) << szokoz << setw(7) << szam << setw(9) << irasjel << endl;
}
