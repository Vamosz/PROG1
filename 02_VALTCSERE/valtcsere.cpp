#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int a=5, b=2;
	cout << a << ' ' << b << endl;
	
	a=b-a;
	b-=a;
	a+=b;
	
	cout << a << ' ' << b << endl;

	a *= b ;
	b = a / b;
	a /= b;

	cout << a << ' ' << b << endl;
	if (a>=b)
			for (int i = 0; i < a-b; ++i)	
			a--;
	else
		for (int i = 0; i < b-a; ++i)
			a++;


	return 0;
}
