//g++ exor_code.cpp -o exor_code
//./exor_code "kulcs" <tiszta.szoveg >titkos.szoveg

#include <iostream>
#include <unistd.h>

using namespace std;


int main(int args, char *argv[]){
    string kulcs = argv[1];			//2. argumentum a kulcs (első: ./exor_code)	

    char c;
    int index = 0;

    while(cin.get(c)){				//egy karakter beolvasása a bemenetről
        c ^= kulcs[index];			//kódolás
	index = (index + 1) % kulcs.length();	//index léptetése
	
	cout << c;				//kódolt üzenet kiírása a kimenetre
    }

    return 0;
}
