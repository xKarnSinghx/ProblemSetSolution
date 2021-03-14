/*
B. Substring Removal Game
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alice and Bob play a game. They have a binary string s (a string such that each character in it is either 0 or 1). Alice moves first, then Bob, then Alice again, and so on.

During their move, the player can choose any number (not less than one) of consecutive equal characters in s and delete them.

For example, if the string is 10110, there are 6 possible moves (deleted characters are bold):

10110→0110;
10110→1110;
10110→1010;
10110→1010;
10110→100;
10110→1011.
After the characters are removed, the characters to the left and to the right of the removed block become adjacent. I. e. the following sequence of moves is valid: 10110→100→1.

The game ends when the string becomes empty, and the score of each player is the number of 1-characters deleted by them.

Each player wants to maximize their score. Calculate the resulting score of Alice.

Input
The first line contains one integer T (1≤T≤500) — the number of test cases.

Each test case contains exactly one line containing a binary string s (1≤|s|≤100).

Output
For each test case, print one integer — the resulting score of Alice (the number of 1-characters deleted by her).

Example
inputCopy
5
01111001
0000
111111
101010101
011011110111
outputCopy
4
0
6
3
6
Note
Questions about the optimal strategy will be ignored.

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

	int t ; cin >> t;
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
void solve()
{
	string s;
	cin >> s;
	ll f = 0;
	vll x;
	if (s[0] == '1')
		f++;
	if ( s.length() == 1)
		x.pb(f);
	for (ll i = 1; i < s.length(); i++) {
		if (s[i] == '1')
			f++;
		if (s[i] == '0') {
			x.pb(f);
			f = 0;
		}
		if (i == s.length() - 1 and s[i] == '1')
			x.pb(f);

	}
	ll ans = 0;
	sort(x.rbegin(), x.rend());
	for (ll i = 0; i < x.size(); i = i + 2) {
		ans += x[i];
	}
	cout << ans;
}
