/*
A. Where do I Turn?
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Trouble came from the overseas lands: a three-headed dragon Gorynych arrived. The dragon settled at point C and began to terrorize the residents of the surrounding villages.

A brave hero decided to put an end to the dragon. He moved from point A to fight with Gorynych. The hero rode from point A along a straight road and met point B on his way. The hero knows that in this land for every pair of roads it is true that they are either parallel to each other, or lie on a straight line, or are perpendicular to each other. He also knows well that points B and C are connected by a road. So the hero must either turn 90 degrees to the left or continue riding straight ahead or turn 90 degrees to the right. But he forgot where the point C is located.

Fortunately, a Brave Falcon flew right by. It can see all three points from the sky. The hero asked him what way to go to get to the dragon's lair.

If you have not got it, you are the falcon. Help the hero and tell him how to get him to point C: turn left, go straight or turn right.

At this moment the hero is believed to stand at point B, turning his back to point A.

Input
The first input line contains two space-separated integers xa, ya (|xa|, |ya| ≤ 109) — the coordinates of point A. The second line contains the coordinates of point B in the same form, the third line contains the coordinates of point C.

It is guaranteed that all points are pairwise different. It is also guaranteed that either point B lies on segment AC, or angle ABC is right.

Output
Print a single line. If a hero must turn left, print "LEFT" (without the quotes); If he must go straight ahead, print "TOWARDS" (without the quotes); if he should turn right, print "RIGHT" (without the quotes).

Examples
inputCopy
0 0
0 1
1 1
outputCopy
RIGHT
inputCopy
-1 -1
-3 -3
-4 -4
outputCopy
TOWARDS
inputCopy
-4 -6
-3 -7
-2 -6
outputCopy
LEFT
Note
The picture to the first sample:


The red color shows points A, B and C. The blue arrow shows the hero's direction. The green color shows the hero's trajectory.

The picture to the second sample:


*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <chrono>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<int>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair<ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


		solve();


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}
bool isPrime(ll n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
void solve()
{
	vpll a;
	foi(3) {
		ll x, y;
		cin >> x >> y;
		a.pb(mp(x, y));
	}
	if ((a[1].ff - a[0].ff) * (a[2].ss - a[1].ss) - (a[1].ss - a[0].ss) * (a[2].ff - a[1].ff) == 0)
		cout << "TOWARDS";
	else if ((a[1].ff - a[0].ff) * (a[2].ss - a[1].ss) - (a[1].ss - a[0].ss) * (a[2].ff - a[1].ff) > 0)
		cout << "LEFT";
	else
		cout << "RIGHT";

}
