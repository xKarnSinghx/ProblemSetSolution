/*
B. Weakened Common Divisor
time limit per test1.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
During the research on properties of the greatest common divisor (GCD) of a set of numbers, Ildar, a famous mathematician, introduced a brand new concept of the weakened common divisor (WCD) of a list of pairs of integers.

For a given list of pairs of integers (a1,b1), (a2,b2), ..., (an,bn) their WCD is arbitrary integer greater than 1, such that it divides at least one element in each pair. WCD may not exist for some lists.

For example, if the list looks like [(12,15),(25,18),(10,24)], then their WCD can be equal to 2, 3, 5 or 6 (each of these numbers is strictly greater than 1 and divides at least one number in each pair).

You're currently pursuing your PhD degree under Ildar's mentorship, and that's why this problem was delegated to you. Your task is to calculate WCD efficiently.

Input
The first line contains a single integer n (1≤n≤150000) — the number of pairs.

Each of the next n lines contains two integer values ai, bi (2≤ai,bi≤2⋅109).

Output
Print a single integer — the WCD of the set of pairs.

If there are multiple possible answers, output any; if there is no answer, print −1.

Examples
inputCopy
3
17 18
15 24
12 15
outputCopy
6
inputCopy
2
10 16
7 17
outputCopy
-1
inputCopy
5
90 108
45 105
75 40
165 175
33 30
outputCopy
5
Note
In the first example the answer is 6 since it divides 18 from the first pair, 24 from the second and 12 from the third ones. Note that other valid answers will also be accepted.

In the second example there are no integers greater than 1 satisfying the conditions.

In the third example one of the possible answers is 5. Note that, for example, 15 is also allowed, but it's not necessary to maximize the output.

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
	ll n;
	cin >> n;
	ll g, x, y;
	foi(n)
	{
		cin >> x >> y;
		if (!i)
			g = lcm(x, y);
		else	{
			g = gcd(g, lcm(x, y));
		}
	}
	//cout << g;
	if (g == 1) {
		cout << -1;
		return;
	}
	g = max(gcd(g, x), gcd(g, y));
	//cout << g;
	for (ll i = 2; i * i <= g; i++)
		if (g % i == 0)
			g = i;
	cout << g;
}
