#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{

int tolasszam=1,bitpozicio=1;

while(bitpozicio<<=1)
	++tolasszam;
cout << "A gépen a szóhossz: "<< tolasszam << " bites"<< endl;

}
