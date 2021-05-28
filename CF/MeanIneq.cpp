/*
A. Mean Inequality
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of 2n distinct integers. You want to arrange the elements of the array in a circle such that no element is equal to the the arithmetic mean of its 2 neighbours.

More formally, find an array b, such that:

b is a permutation of a.

For every i from 1 to 2n, bi≠bi−1+bi+12, where b0=b2n and b2n+1=b1.

It can be proved that under the constraints of this problem, such array b always exists.

Input
The first line of input contains a single integer t (1≤t≤1000) — the number of testcases. The description of testcases follows.

The first line of each testcase contains a single integer n (1≤n≤25).

The second line of each testcase contains 2n integers a1,a2,…,a2n (1≤ai≤109) — elements of the array.

Note that there is no limit to the sum of n over all testcases.

Output
For each testcase, you should output 2n integers, b1,b2,…b2n, for which the conditions from the statement are satisfied.

Example
inputCopy
3
3
1 2 3 4 5 6
2
123 456 789 10
1
6 9
outputCopy
3 1 4 2 5 6
123 10 456 789
9 6
Note
In the first testcase, array [3,1,4,2,5,6] works, as it's a permutation of [1,2,3,4,5,6], and 3+42≠1, 1+22≠4, 4+52≠2, 2+62≠5, 5+32≠6, 6+12≠3.

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
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
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
	ll n;
	cin >> n;
	ll a[2 * n + 1] = {};
	foi(2 * n) {
		cin >> a[i];
	}
	sort(a, a + 2 * n);
	ll b[2 * n] = {};
	foi(n) {
		b[i] = a[i];
		b[2 * n - i - 1] = a[2 * n - i - 1];
	}
	foi(n) {
		cout << b[i] << " " << b[2 * n - i - 1] << " ";
	}

}


 
