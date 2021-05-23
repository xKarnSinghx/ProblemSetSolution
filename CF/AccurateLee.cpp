/*
B. AccurateLee
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Lee was cleaning his house for the party when he found a messy string under the carpets. Now he'd like to make it clean accurately and in a stylish way...

The string s he found is a binary string of length n (i. e. string consists only of 0-s and 1-s).

In one move he can choose two consecutive characters si and si+1, and if si is 1 and si+1 is 0, he can erase exactly one of them (he can choose which one to erase but he can't erase both characters simultaneously). The string shrinks after erasing.

Lee can make an arbitrary number of moves (possibly zero) and he'd like to make the string s as clean as possible. He thinks for two different strings x and y, the shorter string is cleaner, and if they are the same length, then the lexicographically smaller string is cleaner.

Now you should answer t test cases: for the i-th test case, print the cleanest possible string that Lee can get by doing some number of moves.

Small reminder: if we have two strings x and y of the same length then x is lexicographically smaller than y if there is a position i such that x1=y1, x2=y2,..., xi−1=yi−1 and xi<yi.

Input
The first line contains the integer t (1≤t≤104) — the number of test cases.

Next 2t lines contain test cases — one per two lines.

The first line of each test case contains the integer n (1≤n≤105) — the length of the string s.

The second line contains the binary string s. The string s is a string of length n which consists only of zeroes and ones.

It's guaranteed that sum of n over test cases doesn't exceed 105.

Output
Print t answers — one per test case.

The answer to the i-th test case is the cleanest string Lee can get after doing some number of moves (possibly zero).

Example
inputCopy
5
10
0001111111
4
0101
8
11001101
10
1110000000
1
1
outputCopy
0001111111
001
01
0
1
Note
In the first test case, Lee can't perform any moves.

In the second test case, Lee should erase s2.

In the third test case, Lee can make moves, for example, in the following order: 11001101 → 1100101 → 110101 → 10101 → 1101 → 101 → 01.

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
typedef pair< ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
void solve();

ll N = 1001;
ll a[1111][1111] = {};
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
void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll f = 0;
	if (s.size() == 1) {
		cout << s;
		return;
	}
	ll s1 = 0, s2 = n - 1;
	while (s[s1] == '0')
		s1++;
	while (s[s2] == '1')
		s2--;
	if (s1 == s2 + 1)
		cout << s;
	else {
		foi(s1 + 1)
		cout << 0;
		foi(n - s2 - 1)
		cout << 1;
	}
}


