/*
D. Long Jumps
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Valery is a PE teacher at a school in Berland. Soon the students are going to take a test in long jumps, and Valery has lost his favorite ruler!

However, there is no reason for disappointment, as Valery has found another ruler, its length is l centimeters. The ruler already has n marks, with which he can make measurements. We assume that the marks are numbered from 1 to n in the order they appear from the beginning of the ruler to its end. The first point coincides with the beginning of the ruler and represents the origin. The last mark coincides with the end of the ruler, at distance l from the origin. This ruler can be repesented by an increasing sequence a1, a2, ..., an, where ai denotes the distance of the i-th mark from the origin (a1 = 0, an = l).

Valery believes that with a ruler he can measure the distance of d centimeters, if there is a pair of integers i and j (1 ≤ i ≤ j ≤ n), such that the distance between the i-th and the j-th mark is exactly equal to d (in other words, aj - ai = d).

Under the rules, the girls should be able to jump at least x centimeters, and the boys should be able to jump at least y (x < y) centimeters. To test the children's abilities, Valery needs a ruler to measure each of the distances x and y.

Your task is to determine what is the minimum number of additional marks you need to add on the ruler so that they can be used to measure the distances x and y. Valery can add the marks at any integer non-negative distance from the origin not exceeding the length of the ruler.

Input
The first line contains four positive space-separated integers n, l, x, y (2 ≤ n ≤ 105, 2 ≤ l ≤ 109, 1 ≤ x < y ≤ l) — the number of marks, the length of the ruler and the jump norms for girls and boys, correspondingly.

The second line contains a sequence of n integers a1, a2, ..., an (0 = a1 < a2 < ... < an = l), where ai shows the distance from the i-th mark to the origin.

Output
In the first line print a single non-negative integer v — the minimum number of marks that you need to add on the ruler.

In the second line print v space-separated integers p1, p2, ..., pv (0 ≤ pi ≤ l). Number pi means that the i-th mark should be at the distance of pi centimeters from the origin. Print the marks in any order. If there are multiple solutions, print any of them.

Examples
inputCopy
3 250 185 230
0 185 250
outputCopy
1
230
inputCopy
4 250 185 230
0 20 185 250
outputCopy
0
inputCopy
2 300 185 230
0 300
outputCopy
2
185 230
Note
In the first sample it is impossible to initially measure the distance of 230 centimeters. For that it is enough to add a 20 centimeter mark or a 230 centimeter mark.

In the second sample you already can use the ruler to measure the distances of 185 and 230 centimeters, so you don't have to add new marks.

In the third sample the ruler only contains the initial and the final marks. We will need to add two marks to be able to test the children's skills.

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
	ll n, l, x, y;
	cin >> n >> l >> x >> y;
	set<ll> s;
	std::set<long> marks;
	ll f = 0, f1 = 0, f2 = 0, d = 0;
	foi(n) {
		ll z;
		cin >> z;
		s.insert(z);
		if (x <= z and s.count(z - x))
			f = 1;
		if (y <= z and s.count(z - y))
			f1 = 1;
		if (x + y <= z and s.count(z - x - y)) {
			f2 = 1;
			d = z - y;
		}
		if (y <= z and s.count(z + x - y)) {
			f2 = 1;
			d = z - y;
		}
		if (z + x <= l and s.count(z + x - y)) {
			f2 = 1;
			d = z + x;
		}
	}

	if (f and f1)
		cout << 0;
	else if (f)
		cout << 1 << endl << y;
	else if (f1)
		cout << 1 << endl << x;
	else if (f2)
		cout << 1 << endl << d;
	else
		cout << 2 << endl << x << " " << y;
}
 
