/*
A. Fair Playoff
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Four players participate in the playoff tournament. The tournament is held according to the following scheme: the first player will play with the second, and the third player with the fourth, then the winners of the pairs will play in the finals of the tournament.

It is known that in a match between two players, the one whose skill is greater will win. The skill of the i-th player is equal to si and all skill levels are pairwise different (i. e. there are no two identical values in the array s).

The tournament is called fair if the two players with the highest skills meet in the finals.

Determine whether the given tournament is fair.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

A single line of test case contains four integers s1,s2,s3,s4 (1≤si≤100) — skill of the players. It is guaranteed that all the numbers in the array are different.

Output
For each testcase, output YES if the tournament is fair, or NO otherwise.

Example
inputCopy
4
3 7 9 5
4 5 6 9
5 3 8 1
6 5 3 2
outputCopy
YES
NO
YES
NO
Note
Consider the example:

in the first test case, players 2 and 3 with skills 7 and 9 advance to the finals;
in the second test case, players 2 and 4 with skills 5 and 9 advance to the finals. The player with skill 6 does not advance, but the player with skill 5 advances to the finals, so the tournament is not fair;
in the third test case, players 1 and 3 with skills 5 and 8 advance to the finals;
in the fourth test case, players 1 and 3 with skills 6 and 3 advance to the finals. The player with skill 5 does not advance, but the player with skill 3 advances to the finals, so the tournament is not fair.

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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (min(a, b) > max(c, d) or max(a, b) < min(c, d))
		cout << "NO";
	else
		cout << "YES";
}
