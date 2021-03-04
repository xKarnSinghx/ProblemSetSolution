/*
A. Favorite Sequence
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp has a favorite sequence a[1…n] consisting of n integers. He wrote it out on the whiteboard as follows:

he wrote the number a1 to the left side (at the beginning of the whiteboard);
he wrote the number a2 to the right side (at the end of the whiteboard);
then as far to the left as possible (but to the right from a1), he wrote the number a3;
then as far to the right as possible (but to the left from a2), he wrote the number a4;
Polycarp continued to act as well, until he wrote out the entire sequence on the whiteboard.
The beginning of the result looks like this (of course, if n≥4).
For example, if n=7 and a=[3,1,4,1,5,9,2], then Polycarp will write a sequence on the whiteboard [3,4,5,2,9,1,1].

You saw the sequence written on the whiteboard and now you want to restore Polycarp's favorite sequence.

Input
The first line contains a single positive integer t (1≤t≤300) — the number of test cases in the test. Then t test cases follow.

The first line of each test case contains an integer n (1≤n≤300) — the length of the sequence written on the whiteboard.

The next line contains n integers b1,b2,…,bn (1≤bi≤109) — the sequence written on the whiteboard.

Output
Output t answers to the test cases. Each answer — is a sequence a that Polycarp wrote out on the whiteboard.

Example
inputCopy
6
7
3 4 5 2 9 1 1
4
9 2 7 1
11
8 4 3 1 2 7 8 7 9 4 2
1
42
2
11 7
8
1 1 1 1 1 1 1 1
outputCopy
3 1 4 1 5 9 2 
9 1 2 7 
8 2 4 4 3 9 1 7 2 8 7 
42 
11 7 
1 1 1 1 1 1 1 1 
Note
In the first test case, the sequence a matches the sequence from the statement. The whiteboard states after each step look like this:

[3]⇒[3,1]⇒[3,4,1]⇒[3,4,1,1]⇒[3,4,5,1,1]⇒[3,4,5,9,1,1]⇒[3,4,5,2,9,1,1].
*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	ll b[n];
	for (ll i = 0, j = 0; i < n, j < ceils(n, 2); i += 2, j++)
	{
		b[i] = a[j];
	}
	for (ll i = 1, j = n - 1 ; i < n, j >= ceils(n, 2); i += 2, j--)
	{
		b[i] = a[j];
	}
	foi(n) {
		cout << b[i] << " ";
	}
}



