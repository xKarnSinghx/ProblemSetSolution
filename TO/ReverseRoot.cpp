/*
1001. Reverse Root
Time limit: 2.0 second
Memory limit: 64 MB
The problem is so easy, that the authors were lazy to write a statement for it!
Input
The input stream contains a set of integer numbers Ai (0 ≤ Ai ≤ 1018). The numbers are separated by any number of spaces and line breaks. A size of the input stream does not exceed 256 KB.
Output
For each number Ai from the last one till the first one you should output its square root. Each square root should be printed in a separate line with at least four digits after decimal point.
Sample
input	output
 1427  0   

   876652098643267843 
5276538
  
   
2297.0716
936297014.1164
0.0000
37.7757
Problem Author: Prepared by Dmitry Kovalioff
*/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
        ld n;
	ld a[256 * 1024];
	ll i = 0;
	while (cin >> n) {
		ld x = sqrt(n);
		a[i] = x;
		i++;
	}
	ll z = i;
	cout << fixed;
	cout << setprecision(4);
	for (ll z1 = z - 1; z1 > -1; z1--) {
		cout << a[z1] << endl;

	}

    return 0;
}
