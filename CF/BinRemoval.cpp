/*
B. Binary Removals
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string s, consisting only of characters '0' or '1'. Let |s| be the length of s.

You are asked to choose some integer k (k>0) and find a sequence a of length k such that:

1≤a1<a2<⋯<ak≤|s|;
ai−1+1<ai for all i from 2 to k.
The characters at positions a1,a2,…,ak are removed, the remaining characters are concatenated without changing the order. So, in other words, the positions in the sequence a should not be adjacent.

Let the resulting string be s′. s′ is called sorted if for all i from 2 to |s′| s′i−1≤s′i.

Does there exist such a sequence a that the resulting string s′ is sorted?

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

Then the descriptions of t testcases follow.

The only line of each testcase contains a string s (2≤|s|≤100). Each character is either '0' or '1'.

Output
For each testcase print "YES" if there exists a sequence a such that removing the characters at positions a1,a2,…,ak and concatenating the parts without changing the order produces a sorted string.

Otherwise, print "NO".

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
inputCopy
5
10101011011
0000
11111
110
1100
outputCopy
YES
YES
YES
YES
NO
Note
In the first testcase you can choose a sequence a=[1,3,6,9]. Removing the underlined letters from "10101011011" will produce a string "0011111", which is sorted.

In the second and the third testcases the sequences are already sorted.

In the fourth testcase you can choose a sequence a=[3]. s′= "11", which is sorted.

In the fifth testcase there is no way to choose a sequence a such that s′ is sorted.


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

	string s;
	cin >> s;
	string s1 = s;
	ll n = s.size();
	sort(s1.begin(), s1.end());

	ll f = 0, f1 = 0;
	for (ll i = 0; i < s.size() - 1; i++) {
		if (f1 == 0 and s[i] == '0')
			continue;
		else if (f1 == 0 and s[i] == '1' and s[i + 1] == '1')
			f1++;
		else if (f1 and s[i] == '0' and s[i + 1] == '0') {
			f = 1; break;
		}



	}

	if (f == 1)
		cout << "NO";
	else if (s[s.size() - 1] == '0' and s[s.size() - 2] == '0' and f1 >= 1)
		cout << "NO";
	else
		cout << "YES";
}
