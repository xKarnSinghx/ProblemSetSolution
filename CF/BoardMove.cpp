/*
C. Board Moves
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a board of size n×n, where n is odd (not divisible by 2). Initially, each cell of the board contains one figure.

In one move, you can select exactly one figure presented in some cell and move it to one of the cells sharing a side or a corner with the current cell, i.e. from the cell (i,j) you can move the figure to cells:

(i−1,j−1);
(i−1,j);
(i−1,j+1);
(i,j−1);
(i,j+1);
(i+1,j−1);
(i+1,j);
(i+1,j+1);
Of course, you can not move figures to cells out of the board. It is allowed that after a move there will be several figures in one cell.

Your task is to find the minimum number of moves needed to get all the figures into one cell (i.e. n2−1 cells should contain 0 figures and one cell should contain n2 figures).

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤200) — the number of test cases. Then t test cases follow.

The only line of the test case contains one integer n (1≤n<5⋅105) — the size of the board. It is guaranteed that n is odd (not divisible by 2).

It is guaranteed that the sum of n over all test cases does not exceed 5⋅105 (∑n≤5⋅105).

Output
For each test case print the answer — the minimum number of moves needed to get all the figures into one cell.

Example
inputCopy
3
1
5
499993
outputCopy
0
40
41664916690999888
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
typedef map<pair<ll, ll>, ll>  mplll;
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
struct cmp {
	bool operator() (const pll &a, const pll &b) const {
		ll fir = a.ss - a.ff + 1;
		ll sec = b.ss - b.ff + 1;
		if (fir == sec)
			return a.ff < b.ff;
		return fir > sec;
	}
};
void solve() {
	ll n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return;
	}
	n--;
	n /= 2;
	ll ans = n * (n + 1) * (1 + 2 * n) / 6 * 8;
	cout << ans;

}
