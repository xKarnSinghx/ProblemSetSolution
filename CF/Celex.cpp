/*
C. Celex Update
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
During the quarantine, Sicromoft has more free time to create the new functions in "Celex-2021". The developers made a new function GAZ-GIZ, which infinitely fills an infinite table to the right and down from the upper left corner as follows:

The cell with coordinates (x,y) is at the intersection of x-th row and y-th column. Upper left cell (1,1) contains an integer 1.
The developers of the SUM function don't sleep either. Because of the boredom, they teamed up with the developers of the RAND function, so they added the ability to calculate the sum on an arbitrary path from one cell to another, moving down or right. Formally, from the cell (x,y) in one step you can move to the cell (x+1,y) or (x,y+1).

After another Dinwows update, Levian started to study "Celex-2021" (because he wants to be an accountant!). After filling in the table with the GAZ-GIZ function, he asked you to calculate the quantity of possible different amounts on the path from a given cell (x1,y1) to another given cell (x2,y2), if you can only move one cell down or right.

Formally, consider all the paths from the cell (x1,y1) to cell (x2,y2) such that each next cell in the path is located either to the down or to the right of the previous one. Calculate the number of different sums of elements for all such paths.

Input
The first line contains one integer t (1≤t≤57179) — the number of test cases.

Each of the following t lines contains four natural numbers x1, y1, x2, y2 (1≤x1≤x2≤109, 1≤y1≤y2≤109) — coordinates of the start and the end cells.

Output
For each test case, in a separate line, print the number of possible different sums on the way from the start cell to the end cell.

Example
inputCopy
4
1 1 2 2
1 2 2 4
179 1 179 100000
5 7 5 7
outputCopy
2
3
1
1
Note
In the first test case there are two possible sums: 1+2+5=8 and 1+3+5=9.

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
#define graph          vector<vector<ll>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
void solve();

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t ; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;

}
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}
void solve() {
	ll x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;
	cout << abs(x1 - x)*abs(y1 - y) + 1LL;

}
