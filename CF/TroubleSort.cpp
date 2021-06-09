/*
B. Trouble Sort
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ashish has n elements arranged in a line.

These elements are represented by two integers ai — the value of the element and bi — the type of the element (there are only two possible types: 0 and 1). He wants to sort the elements in non-decreasing values of ai.

He can perform the following operation any number of times:

Select any two elements i and j such that bi≠bj and swap them. That is, he can only swap two elements of different types in one move.
Tell him if he can sort the elements in non-decreasing values of ai after performing any number of operations.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains one integer n (1≤n≤500) — the size of the arrays.

The second line contains n integers ai (1≤ai≤105)  — the value of the i-th element.

The third line containts n integers bi (bi∈{0,1})  — the type of the i-th element.

Output
For each test case, print "Yes" or "No" (without quotes) depending on whether it is possible to sort elements in non-decreasing order of their value.

You may print each letter in any case (upper or lower).

Example
inputCopy
5
4
10 20 20 30
0 1 0 1
3
3 1 2
0 1 1
4
2 2 4 8
1 1 1 1
3
5 15 4
0 0 0
4
20 10 100 50
1 0 0 1
outputCopy
Yes
Yes
Yes
No
Yes
Note
For the first case: The elements are already in sorted order.

For the second case: Ashish may first swap elements at positions 1 and 2, then swap elements at positions 2 and 3.

For the third case: The elements are already in sorted order.

For the fourth case: No swap operations may be performed as there is no pair of elements i and j such that bi≠bj. The elements cannot be sorted.

For the fifth case: Ashish may swap elements at positions 3 and 4, then elements at positions 1 and 2.

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
	ll n;
	cin >> n;
	vll a(n, 0), b(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	ll o = 0, z = 0;
	foi(n) {
		ll x;
		cin >> x;
		if (x == 0)
			z++;
		b[i] = x;
	}
	ll cnt = 0;
	foi(n - 1) {
		if (a[i] <= a[i + 1])
			cnt++;
	}
	o = n - z;
	if (o != n and o != 0 or cnt == n - 1) {
		cout << "Yes";
		return;
	}
	cout << "No";
}
