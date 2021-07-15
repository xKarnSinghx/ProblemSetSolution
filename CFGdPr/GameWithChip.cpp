/*
C. Game with Chips
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya has a rectangular Board of size n×m. Initially, k chips are placed on the board, i-th chip is located in the cell at the intersection of sxi-th row and syi-th column.

In one action, Petya can move all the chips to the left, right, down or up by 1 cell.

If the chip was in the (x,y) cell, then after the operation:

left, its coordinates will be (x,y−1);
right, its coordinates will be (x,y+1);
down, its coordinates will be (x+1,y);
up, its coordinates will be (x−1,y).
If the chip is located by the wall of the board, and the action chosen by Petya moves it towards the wall, then the chip remains in its current position.

Note that several chips can be located in the same cell.

For each chip, Petya chose the position which it should visit. Note that it's not necessary for a chip to end up in this position.

Since Petya does not have a lot of free time, he is ready to do no more than 2nm actions.

You have to find out what actions Petya should do so that each chip visits the position that Petya selected for it at least once. Or determine that it is not possible to do this in 2nm actions.

Input
The first line contains three integers n,m,k (1≤n,m,k≤200) — the number of rows and columns of the board and the number of chips, respectively.

The next k lines contains two integers each sxi,syi (1≤sxi≤n,1≤syi≤m) — the starting position of the i-th chip.

The next k lines contains two integers each fxi,fyi (1≤fxi≤n,1≤fyi≤m) — the position that the i-chip should visit at least once.

Output
In the first line print the number of operations so that each chip visits the position that Petya selected for it at least once.

In the second line output the sequence of operations. To indicate operations left, right, down, and up, use the characters L,R,D,U respectively.

If the required sequence does not exist, print -1 in the single line.

Examples
inputCopy
3 3 2
1 2
2 1
3 3
3 2
outputCopy
3
DRD
inputCopy
5 4 3
3 4
3 1
3 3
5 3
1 3
1 4
outputCopy
9
DDLUUUURR*/
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
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
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
//	ll t ; cin >> t;
//	while (t--)
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
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
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
	ll n, m, k;
	cin >> n >> m >> k;
	vpll a(k), b(k);
	foi(k) {
		ll x, y;
		cin >> x >> y;
		a[i].ff = x;
		a[i].ss = y;
	}
	foi(k) {
		ll x, y;
		cin >> x >> y;
		b[i].ff = x;
		b[i].ss = y;
	}
	cout << 2 * n + m - 3 + n*m - n << endl;
	foi(n + m - 2) {
		if (i < n - 1)
			cout << "U";
		else
			cout << "L";
	}
	foi(n) {
		foj(m) {
			if (j == m - 1 and i != n - 1)
				cout << "D";
			else if (i == n - 1 and j == m - 1)
				cout << "";
			else if (i % 2)
				cout << "L";
			else
				cout << "R";
		}
	}
}
 
