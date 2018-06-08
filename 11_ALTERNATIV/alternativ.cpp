#include <iostream>
#include <math.h>

using namespace std;

int main(){

	int kereszt[16][16] = {
		{0, 3, 2, 1, 2, 3, 2, 3, 3, 2, 3, 2, 2, 2, 2, 3},		//siófok
		{3, 0, 2, 1, 3, 2, 1, 3, 3, 3, 1, 2, 1, 3, 2, 1},		//honvéd
		{1, 1, 0, 3, 3, 1, 3, 2, 2, 2, 3, 1, 1, 1, 2, 1},		//vasas
		{3, 2, 1, 0, 1, 2, 1, 1, 1, 1, 1, 1, 3, 2, 1, 1},		//dvsc
		{3, 3, 3, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2},		//ftc
		{1, 1, 3, 1, 1, 0, 1, 1, 3, 2, 2, 1, 2, 1, 2, 3},		//győr
		{1, 2, 3, 2, 1, 1, 0, 1, 1, 1, 3, 3, 1, 3, 3, 1},		//kaposvár
		{3, 1, 1, 1, 3, 2, 1, 0, 3, 1, 3, 1, 1, 1, 3, 1}, 	//kte
		{3, 3, 1, 2, 3, 1, 2, 1, 0, 3, 3, 2, 1, 1, 3, 1}, 	//pápa
		{3, 1, 1, 2, 3, 2, 3, 1, 1, 0, 3, 1, 3, 1, 3, 3},		//mtk
		{2, 3, 1, 2, 1, 1, 3, 1, 1, 2, 0, 1, 1, 1, 1, 2},		//paks
		{3, 3, 3, 3, 3, 3, 3, 1, 2, 1, 1, 0, 2, 1, 2, 3}, 	//szolnok
		{1, 2, 1, 1, 2, 2, 1, 1, 1, 1, 3, 1, 0, 3, 1, 2},		//haladás
		{2, 1, 2, 2, 1, 2, 1, 1, 1, 1, 3, 1, 1, 0, 1, 1},		//újpest
		{1, 3, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 0, 1},		//videoton
		{1, 1, 1, 2, 1, 2, 3, 1, 1, 1, 1, 1, 2, 1, 3, 0}		//zte
	};

	int pontot_szerez[16][16];
	int pontok[16];
	int oszlop[16];
	double link[16][16];

	string csapatok[16] = {
		"Siófok", "Honvéd", "Vasas", "DVSC", "FTC", "Győr", "Kaposvár", "KTE", "Pápa", "MTK", "Paks",
		"Szolnok", "Haladás", "Újpest", "Videoton", "ZTE"
	};

	for(int i = 0; i < 16; i++){
		pontok[i] = 0;
		for(int j = 0; j < 16; j++){
			pontot_szerez[i][j] = (kereszt[i][j] == 1 || kereszt[i][j] == 2) + (kereszt[j][i] == 3 || kereszt[j][i] == 2);

			pontok[i] += (kereszt[i][j] == 2) + 3*(kereszt[i][j] == 1);
			pontok[i] += (kereszt[j][i] == 2) + 3*(kereszt[j][i] == 3);

			cout << pontot_szerez[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 0; i < 16; i++){
		int sum = 0;
		for(int j = 0; j < 16; j++){
			sum += pontot_szerez[j][i];
		}
		oszlop[i] = sum;
		cout << oszlop[i] << ", ";		
	}
	cout << endl;
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			if(oszlop[j] != 0){
				link[i][j] = pontot_szerez[i][j] * (1.0 / oszlop[j]);
			} else{
				link[i][j] = pontot_szerez[i][j];
			}
		}
	}

	double hv[16];
	double h[16];

	for(int i = 0; i < 16; i++){
		hv[i] = 1.0 / 16;
		h[i] = 0.0;
	}

	double reginorma = 0.0, regiosszeg = 0.0;

	bool amig = true;
  while(amig){

  	for(int i = 0; i < 16; i++) {
			for(int j = 0; j < 16; j++) {
				h[i] += link[i][j] * hv[j];
			}
		}

		double osszeg = 0.0;
		for (int i = 0; i < 16; i++) {
			osszeg += (hv[i] - h[i]) * (hv[i] - h[i]);
		}

    double norma = sqrt(osszeg);
    cout << norma << "= Norma" << endl;

		if(norma < 0.000000000001){
			amig = false;

			cout << "+++++" << endl;
			double osszegEll = 0.0;
			for(int i = 0; i < 16; i++){
				osszegEll += h[i];
      	cout << h[i];
			}
        cout << "Ell. " << osszegEll << endl;
        cout << "+++++" << endl;
      }

      //double d = 0.98;
      double d = 0.87;
      //double d = 0.7;

      osszeg = 0.0;
      for(int i = 0; i < 16; ++i){
        //hv[i] = h[i];
        hv[i] = d * h[i] + (1.0 - d) / 16;

        osszeg += hv[i];
        h[i] = 0.0;
      }

    	cout << "osszeg = " << osszeg << endl;

      if (osszeg == regiosszeg && norma == reginorma) {
        amig = false;

      }
      reginorma = norma;
      regiosszeg = osszeg;
    } // while

		for(int i = 0; i < 16; i++){
			int max = i;
			for(int j = i; j < 16; j++){
				if(hv[max] < hv[j]){
					max = j;
				}
			} 
			double temp = hv[max];
			hv[max] = hv[i];
			hv[i] = temp;

			string temp_str;
			temp_str = csapatok[max];
			csapatok[max] = csapatok[i];
			csapatok[i] = temp_str;


			cout  << hv[i] << '\t' << csapatok[i] << endl;
		}






	return 0;
}
