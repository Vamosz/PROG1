#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

using namespace std;

#define SZELESSEG 80
#define MAGASSAG 25
 void felsofal(void)
 	{
 		for(int i = 0; i < SZELESSEG; i++){
            cout << "_";
        }
        cout << endl;
 	}
 void labdafeletti(int y)
 	{
 		for(int i = 0; i < y-1; i++){
            cout << "|";
            for(int j = 0; j < SZELESSEG-2; j++){
                cout << " ";
            }
            cout << "|" << endl;
        }
 	}
 void labdasor(int x)
{ cout << "|";
        for(int i = 0; i < x-1; i++){
            cout << " ";
        }
        cout << "o";
        for(int i = x+1; i < SZELESSEG-1; i++){
            cout << " ";
        }
        cout << "|" << endl;
}
void labdaalatti(int y)
{for(int i = y; i < MAGASSAG-2; i++){
            cout << "|";
            for(int j = 0; j < SZELESSEG-2; j++){
                cout << " ";
            }
            cout << "|" << endl;
        }
        for(int i = 0; i < SZELESSEG; i++){
            cout << "-";
        }
              cout << endl;}
int main()
{
    int x =0 , y = 0;
    int x1 = x, y1 = y;
 

    while(true){
        usleep(40000);
        system("clear");
 
        
     x += pow(-1, (x1)/(SZELESSEG-3));
     y += pow(-1, (y1)/(MAGASSAG-3));
        x1++;
        y1++;


        felsofal();

        labdafeletti(y);
	
	   labdasor(x);

	   labdaalatti(y);

    }
    return 0;
}