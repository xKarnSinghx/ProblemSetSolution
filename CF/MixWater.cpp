/*
C. Mixing Water
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are two infinite sources of water:

hot water of temperature h;
cold water of temperature c (c<h).
You perform the following procedure of alternating moves:

take one cup of the hot water and pour it into an infinitely deep barrel;
take one cup of the cold water and pour it into an infinitely deep barrel;
take one cup of the hot water …
and so on …
Note that you always start with the cup of hot water.

The barrel is initially empty. You have to pour at least one cup into the barrel. The water temperature in the barrel is an average of the temperatures of the poured cups.

You want to achieve a temperature as close as possible to t. So if the temperature in the barrel is tb, then the absolute difference of tb and t (|tb−t|) should be as small as possible.

How many cups should you pour into the barrel, so that the temperature in it is as close as possible to t? If there are multiple answers with the minimum absolute difference, then print the smallest of them.

Input
The first line contains a single integer T (1≤T≤3⋅104) — the number of testcases.

Each of the next T lines contains three integers h, c and t (1≤c<h≤106; c≤t≤h) — the temperature of the hot water, the temperature of the cold water and the desired temperature in the barrel.

Output
For each testcase print a single positive integer — the minimum number of cups required to be poured into the barrel to achieve the closest temperature to t.

Example
inputCopy
3
30 10 20
41 15 30
18 13 18
outputCopy
2
7
1
Note
In the first testcase the temperature after 2 poured cups: 1 hot and 1 cold is exactly 20. So that is the closest we can achieve.

In the second testcase the temperature after 7 poured cups: 4 hot and 3 cold is about 29.857. Pouring more water won't get us closer to t than that.

In the third testcase the temperature after 1 poured cup: 1 hot is 18. That's exactly equal to t.

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
void solve() {
	ld h, c, t;
	cin >> h >> c >> t;
	if (h == t)
		cout << 1;
	else if (t <= (h + c) / 2)
		cout << 2;
	else {
		ll ans = (c - t) / ( h + c - 2 * t);
		if ((abs((ans * (h + c) - c) / (2 * ans - 1) - t) > abs((ans * (h + c) + h) / (2 * ans + 1) - t)))
			cout << 2 * ans + 1;
		else
			cout << 2 * ans - 1;
	}
}
