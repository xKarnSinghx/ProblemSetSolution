/*
E. Kuroni and the Score Distribution
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Kuroni is the coordinator of the next Mathforces round written by the "Proof by AC" team. All the preparation has been done, and he is discussing with the team about the score distribution for the round.

The round consists of n problems, numbered from 1 to n. The problems are ordered in increasing order of difficulty, no two problems have the same difficulty. A score distribution for the round can be denoted by an array a1,a2,…,an, where ai is the score of i-th problem.

Kuroni thinks that the score distribution should satisfy the following requirements:

The score of each problem should be a positive integer not exceeding 109.
A harder problem should grant a strictly higher score than an easier problem. In other words, 1≤a1<a2<⋯<an≤109.
The balance of the score distribution, defined as the number of triples (i,j,k) such that 1≤i<j<k≤n and ai+aj=ak, should be exactly m.
Help the team find a score distribution that satisfies Kuroni's requirement. In case such a score distribution does not exist, output −1.

Input
The first and single line contains two integers n and m (1≤n≤5000, 0≤m≤109) — the number of problems and the required balance.

Output
If there is no solution, print a single integer −1.

Otherwise, print a line containing n integers a1,a2,…,an, representing a score distribution that satisfies all the requirements. If there are multiple answers, print any of them.

Examples
inputCopy
5 3
outputCopy
4 5 9 13 18
inputCopy
8 0
outputCopy
10 11 12 13 14 15 16 17
inputCopy
4 10
outputCopy
-1
Note
In the first example, there are 3 triples (i,j,k) that contribute to the balance of the score distribution.

(1,2,3)
(1,3,4)
(2,4,5)
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
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
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
typedef  unordered_map< ll, ld>           umld;
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
//	ll t ; cin >> t;
//	while (t--)
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
bool COMP(pll l, pll r) {
	return l.ss < r.ss;
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
ll ask(ll x, ll y) {
	cout << "? " << x << " " << y << endl;
	ll z;
	cin >> z;
	return z;
}
void solve() {
	ll n, m;
	cin >> n >> m;
	if (n == 1) {
		if (m == 0)
			cout << 1;
		else
			cout << -1;
		return ;
	}
	if (n == 2) {
		if (m == 0)
			cout << 1 << " " << 2;
		else
			cout << -1;
		return;
	}
	ll s = 3;
	vll ans;
	while (m > 0) {
		if (m >= ((s - 1) / 2)) {
			m -= (s - 1) / 2;
			ans.pb(s++);
			continue;
		}
		s--;
		ans.pb(2 * s - 2 * m + 1);
		break;
	}
	if (ans.size() > n - 2) {
		cout << -1;
		return;
	}
	ll ex = 10000001;
	while (ans.size() < n - 2) {
		ans.pb(ex);
		ex += 100001;
	}
	cout << 1 << " " << 2 << " ";
	foi(ans.size()) {
		cout << ans[i] << " ";
	}

}
 
