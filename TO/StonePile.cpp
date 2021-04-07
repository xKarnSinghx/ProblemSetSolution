/*
1005. Stone Pile
Time limit: 1.0 second
Memory limit: 64 MB
You have a number of stones with known weights w1, …, wn. Write a program that will rearrange the stones into two piles such that weight difference between the piles is minimal.
Input
Input contains the number of stones n (1 ≤ n ≤ 20) and weights of the stones w1, …, wn (integers, 1 ≤ wi ≤ 100000) delimited by white spaces.
Output
Your program should output a number representing the minimal possible weight difference between stone piles.
Sample
input	output
5
5 8 13 27 14
3
Problem Source: USU Championship 1997
*/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
#define ll long long
#define ld long double
ll eqDiv(ll *a, ll s1, ll s, ll l) {
	if (l == 0)
		return abs((s - s1) - s1);

	return min(eqDiv(a, s1 + a[l], s, l - 1), eqDiv(a, s1, s, l - 1));

}
int main()
{
ll n;
cin>>n;
ll a[n],s=0;
for(ll i=0;i<n;i++){
cin>>a[i];
s+=a[i];}

cout << eqDiv(a, 0, s, n - 1);
    return 0;
}
