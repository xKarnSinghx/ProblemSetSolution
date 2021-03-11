/*
B. Valerii Against Everyone
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You're given an array b of length n. Let's define another array a, also of length n, for which ai=2bi (1≤i≤n).

Valerii says that every two non-intersecting subarrays of a have different sums of elements. You want to determine if he is wrong. More formally, you need to determine if there exist four integers l1,r1,l2,r2 that satisfy the following conditions:

1≤l1≤r1<l2≤r2≤n;
al1+al1+1+…+ar1−1+ar1=al2+al2+1+…+ar2−1+ar2.
If such four integers exist, you will prove Valerii wrong. Do they exist?

An array c is a subarray of an array d if c can be obtained from d by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

The first line of every test case contains a single integer n (2≤n≤1000).

The second line of every test case contains n integers b1,b2,…,bn (0≤bi≤109).

Output
For every test case, if there exist two non-intersecting subarrays in a that have the same sum, output YES on a separate line. Otherwise, output NO on a separate line.

Also, note that each letter can be in any case.

Example
inputCopy
2
6
4 3 0 1 2 0
2
2 5
outputCopy
YES
NO
Note
In the first case, a=[16,8,1,2,4,1]. Choosing l1=1, r1=1, l2=2 and r2=6 works because 16=(8+1+2+4+1).

In the second case, you can verify that there is no way to select to such subarrays.


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

void solve()
{	ll n;
	cin >> n ;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll s = 0;
	for (ll i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
			{s=1;break;}
	}
	if (s)
		cout << "YES";
	else
		cout << "NO";
}
