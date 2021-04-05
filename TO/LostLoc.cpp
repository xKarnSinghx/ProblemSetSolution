/*
1785. Lost in Localization
Time limit: 1.0 second
Memory limit: 64 MB
The Lavin Interactive Company, which has developed the turn-based strategy Losers-V, is constantly extending its target market by localizing the game to as many languages as it can. In particular, they are interested in creating a version of the game in Anindilyakwa, which is one of the languages spoken by indigenous Australians.
However, the localization is complicated by the fact that Anindilyakwa has no numerals. How can a phrase such as “You have seven black dragons and your enemy has forty black dragons” be translated into this language? The localizers have decided to translate it as follows: “You have few black dragons and your enemy has lots of black dragons.” They have compiled a table showing the rule of replacing numbers of monsters by Anindilyakwa words.
Number	Designation in Anindilyakwa
from 1 to 4	few
from 5 to 9	several
from 10 to 19	pack
from 20 to 49	lots
from 50 to 99	horde
from 100 to 249	throng
from 250 to 499	swarm
from 500 to 999	zounds
from 1000	legion
Help the localizers automatize the process. Write a program that would output the appropriate word given the number of monsters.
Input
The only line contains the number of monsters n (1 ≤ n ≤ 2000).
Output
Output the word corresponding to the given number of monsters in the Anindilyakwa language.
Samples
input	output
7
several
40
lots
Problem Author: folklore
Problem Source: Ural Regional School Programming Contest 2010
*/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
        ll n;
        cin>>n;

        if(n<=4)
cout<<"few";
else if(n<=9 and n>=5)
cout<<"several";
else if(n<=19 and n>=10)
cout<<"pack";
else if(n<=49 and n>=20)
cout<<"lots";
else if(n<=99 and n>=50)
cout<<"horde";
else if(n<=249 and n>=100)
cout<<"throng";
else if(n<=499 and n>=250)
cout<<"swarm";
else if(n<=999 and n>=500)
cout<<"zounds";
else 
cout<<"legion";

    

    return 0;
}
