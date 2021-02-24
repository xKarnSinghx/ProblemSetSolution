/*
Problem Statement
You have gotten a new job: your task is to put house numbers onto a range of houses. All these houses are on one side of a long road. The first of these houses (the one with the smallest number) has the number firstHouse. There are numberOfHouses houses in the range of houses you should number.

As is customary, the street uses odd house numbers for one side of the street and even house numbers for the other side. As the houses you should number are on the same side, their numbers all have the same parity.

Before you go to the street, you need to purchase the material you need. The hardware store only sells individual digits. Calculate how many copies of each digit you'll need. Return a with exactly 10 elements, element x being the number of times the digit x occurs in your collection of house numbers.
Definition
Class: HouseNumbering
Method: prepareDigits
Parameters: int, int
Returns: vector <int>
Method signature: vector <int> prepareDigits(int firstHouse, int numberOfHouses)
(be sure your method is public)
Limits
Time limit (s): 2.000
Memory limit (MB): 256
Constraints
- firstHouse will be between 1 and 1000, inclusive.
- numberOfHouses will be between 1 and 1000, inclusive.
Examples
0)
7
4
Returns: {0, 3, 0, 1, 0, 0, 0, 1, 0, 1 }
The four houses have numbers 7, 9, 11 and 13.

You need three digits 1 and one each of digits 3, 7, and 9.
1)
2
6
Returns: {1, 2, 2, 0, 1, 0, 1, 0, 1, 0 }
These houses have numbers 2, 4, 6, 8, 10, and 12. Make sure you don't forget the digit 0 you need for the number 10.
2)
997
1
Returns: {0, 0, 0, 0, 0, 0, 0, 1, 0, 2 }
3)
160
47
Returns: {15, 25, 42, 5, 14, 2, 14, 5, 14, 5 }
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include<bits/stdc++.h>
using namespace std;
class HouseNumbering{
public:
vector <int> prepareDigits(int firstHouse, int numberOfHouses){
vector<int> a(numberOfHouses);
    int x=firstHouse,s=0;
for(int i=0;i<numberOfHouses;i++)
    {a[i]=x;
     x+=2;
    s+=a[i];}
    std::vector<int> b(10);
    for(int i=0;i<10;i++)
       { b[i]=0;}
    for(int i=0;i<numberOfHouses;i++){
        while(a[i]>0){
            int y=a[i]%10;
            b[y]++;
            a[i]/=10;
    }
    }
	return b;
}
};
