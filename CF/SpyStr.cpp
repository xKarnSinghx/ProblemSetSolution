/*
F. Spy-string
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given n strings a1,a2,…,an: all of them have the same length m. The strings consist of lowercase English letters.

Find any string s of length m such that each of the given n strings differs from s in at most one position. Formally, for each given string ai, there is no more than one position j such that ai[j]≠s[j].

Note that the desired string s may be equal to one of the given strings ai, or it may differ from all the given strings.

For example, if you have the strings abac and zbab, then the answer to the problem might be the string abab, which differs from the first only by the last character, and from the second only by the first.

Input
The first line contains an integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

Each test case starts with a line containing two positive integers n (1≤n≤10) and m (1≤m≤10) — the number of strings and their length.

Then follow n strings ai, one per line. Each of them has length m and consists of lowercase English letters.

Output
Print t answers to the test cases. Each answer (if it exists) is a string of length m consisting of lowercase English letters. If there are several answers, print any of them. If the answer does not exist, print "-1" ("minus one", without quotes).

Example
inputCopy
5
2 4
abac
zbab
2 4
aaaa
bbbb
3 3
baa
aaa
aab
2 2
ab
bb
3 1
a
b
c
outputCopy
abab
-1
aaa
ab
z
Note
The first test case was explained in the statement.

In the second test case, the answer does not exist.
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
void solve() {
	ll n, m;
	cin >> n >> m;
	string a[201];
	foi(n)
	cin >> a[i];
	foi(n) {
		foj(m) {
			string t = a[i];
			for (char c = 'a'; c <= 'z'; c++) {
				t[j] = c;
				ll f = 0;
				fok(n) {
					ll diff = 0;
					for (ll l = 0; l < m; l++)
						diff += (a[k][l] != t[l]);
					if (diff > 1) {
						f = 1;
						break;
					}
				}
				if (f == 0) {
					cout << t;
					return;
				}
			}
		}
	}
	cout << -1;
}
