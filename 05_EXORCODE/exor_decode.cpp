//g++ exor_decode.cpp -o exor_decode
//./exor_decode <kodolt.szoveg
#include <iostream>
#include <vector>
#include <ctype.h>
#include <unistd.h>

using namespace std;

string kulcs_noveles(string kulcs, vector<char> abc);
void exor(string &titkos, string kulcs);
int ertelmes(string uzenet, vector<string> szavak);
string my_tolower(string str);

int main(){
    
    vector<char> abc;				//a kulcs abc-je
    string titkos;

    for(int i = '0'; i <= '9'; i++){		//az abc vektor feltöltése
	abc.push_back(i);
    }

    for(int i = 'a'; i <= 'z'; i++){
	abc.push_back(i);
    }

    string kulcs = "0";			//a kulcs először egy karakter, és a 0. eleme a vektornak

    vector<string> szavak;		//gyakori szavak vectora

    szavak.push_back(" az ");
    szavak.push_back(" a ");
    szavak.push_back("nem ");
    szavak.push_back(" is ");

    char c;				//karakterenkénti beolvasás

    while(cin.get(c)){
        titkos += c;
    }

    while(true){
	exor(titkos, kulcs);		//exor dekódolás
					//ha sok értelmes szó van benne akkor megáll
	if(ertelmes(titkos, szavak) >= szavak.size()-1){  

	    cout << "A valoszinu kulcs: " << kulcs << endl << titkos << endl;
	    break;
	}
	exor(titkos, kulcs);		//ha nem jó akkor visszakódolja
	kulcs = kulcs_noveles(kulcs, abc);
    }

    return 0;
}

string kulcs_noveles(string kulcs, vector<char> abc){

//megkeresi a kulcs utolsó betűjét az abc vektorban, és azt az abc vektor következő elemével
//teszi egyenlővé ha épp az utolsó elemről van szó és a hossz 1 akkor a kulcs elejéhez adja az
//abc első betűjét, ha nem egy hosszú akkor a kulcs a növelést a kulcs utolsó eleme nélkül végzi el

//Ezek után az utolsó elemet megnöveli, de maradékosan osztva, hogy ne tudjon kimenni a tartományból
    for(int i = 0; i < abc.size(); i++){
	if(kulcs[kulcs.length()-1] == abc[i]){
	    if(i == abc.size()-1){
		if(kulcs.length() == 1){
		    kulcs = abc[0]+kulcs;
		} else{
		    kulcs = kulcs_noveles(kulcs.substr(0, kulcs.length()-1), abc) + (char)abc[i];
		}
	    }
	    kulcs[kulcs.length()-1] = abc[(i+1)%abc.size()];
	    break;
	}
    }
    return kulcs;
}

void exor(string &titkos, string kulcs){
//exor kódolás
    for(int i = 0; i < titkos.length(); i++){
	titkos[i] ^= kulcs[i%kulcs.length()];
	
    }
}

int ertelmes(string uzenet, vector<string> szavak){
//megszámolja mennyi gyakori szó van benne a vektorból az üzenetben
    int count = 0;
    uzenet = my_tolower(uzenet);
    for(int j = 0; j < szavak.size(); j++){
    	for(int i = 0; i < uzenet.length()-4; i++){
	    if(uzenet.substr(i, szavak[j].length()).compare(szavak[j]) == 0){
	        count++;
		break;
	    }
	}
    }
    return count;
}

string my_tolower(string str){
//kisbetűssé teszi a stringet
    for(int i = 0; i < str.length(); i++){
    	if(isupper(str[i])){
	    str[i] -= ('A'-'a');
    	}
    }
    return str;
}
