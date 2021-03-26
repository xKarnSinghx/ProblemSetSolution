/*
A. Strange Table
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp found a rectangular table consisting of n rows and m columns. He noticed that each cell of the table has its number, obtained by the following algorithm "by columns":

cells are numbered starting from one;
cells are numbered from left to right by columns, and inside each column from top to bottom;
number of each cell is an integer one greater than in the previous cell.
For example, if n=3 and m=5, the table will be numbered as follows:

123456789101112131415
However, Polycarp considers such numbering inconvenient. He likes the numbering "by rows":

cells are numbered starting from one;
cells are numbered from top to bottom by rows, and inside each row from left to right;
number of each cell is an integer one greater than the number of the previous cell.
For example, if n=3 and m=5, then Polycarp likes the following table numbering:
161127123813491451015
Polycarp doesn't have much time, so he asks you to find out what would be the cell number in the numbering "by rows", if in the numbering "by columns" the cell has the number x?

Input
The first line contains a single integer t (1≤t≤104). Then t test cases follow.

Each test case consists of a single line containing three integers n, m, x (1≤n,m≤106, 1≤x≤n⋅m), where n and m are the number of rows and columns in the table, and x is the cell number.

Note that the numbers in some test cases do not fit into the 32-bit integer type, so you must use at least the 64-bit integer type of your programming language.

Output
For each test case, output the cell number in the numbering "by rows".

Example
inputCopy
5
1 1 1
2 2 3
3 5 11
100 100 7312
1000000 1000000 1000000000000
outputCopy
1
2
9
1174
1000000000000

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
const ll MOD = 1000000007;
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
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll fac(ll n) {
	while (n % 4 == 0) {
		n /= 4;
	}
	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % (i * i) == 0) {
			n /= (i * i);
		}
	}
	return n;
}

void solve()
{
	ll n, m, x;
	cin >> n >> m >> x;
	ll f = ceils(x, n), g = x % n;
	if (g != 0)
		cout << (g - 1) * m + f ;
	else
		cout << (n - 1)*m + f;



}


