/*
C. String Equality
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ashish has two strings a and b, each of length n, and an integer k. The strings only contain lowercase English letters.

He wants to convert string a into string b by performing some (possibly zero) operations on a.

In one move, he can either

choose an index i (1≤i≤n−1) and swap ai and ai+1, or
choose an index i (1≤i≤n−k+1) and if ai,ai+1,…,ai+k−1 are all equal to some character c (c≠ 'z'), replace each one with the next character (c+1), that is, 'a' is replaced by 'b', 'b' is replaced by 'c' and so on.
Note that he can perform any number of operations, and the operations can only be performed on string a.

Help Ashish determine if it is possible to convert string a into b after performing some (possibly zero) operations on it.

Input
The first line contains a single integer t (1≤t≤105) — the number of test cases. The description of each test case is as follows.

The first line of each test case contains two integers n (2≤n≤106) and k (1≤k≤n).

The second line of each test case contains the string a of length n consisting of lowercase English letters.

The third line of each test case contains the string b of length n consisting of lowercase English letters.

It is guaranteed that the sum of values n among all test cases does not exceed 106.

Output
For each test case, print "Yes" if Ashish can convert a into b after some moves, else print "No".

You may print the letters of the answer in any case (upper or lower).

Example
inputCopy
4
3 3
abc
bcd
4 2
abba
azza
2 1
zz
aa
6 2
aaabba
ddddcc
outputCopy
No
Yes
No
Yes
Note
In the first test case it can be shown that it is impossible to convert a into b.

In the second test case,

"abba" −→inc "acca" −→inc … −→inc "azza".

Here "swap" denotes an operation of the first type, and "inc" denotes an operation of the second type.

In the fourth test case,

"aaabba" −→−−swap "aaabab" −→−−swap "aaaabb" −→inc … −→inc "ddaabb" −→inc … −→inc "ddddbb" −→inc … −→inc "ddddcc".

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
	ll n, k;
	cin >> n >> k;
	string a, b;
	cin >> a >> b;
	ll ca[26] = {0}, cb[26] = {0};
	foi(n) {
		ca[a[i] - 'a']++;
	}
	foi(n) {
		cb[b[i] - 'a']++;
	}
	ll f = 0;
	foi(26) {
		if (ca[i] < cb[i] || (ca[i] -= cb[i]) % k)
			f = 1;
		ca[i + 1] += ca[i];
	}
	if (f == 1)
		cout << "NO";
	else
		cout << "YES";
}


