/*
A. Omkar and Bad Story
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Omkar has received a message from Anton saying "Your story for problem A is confusing. Just make a formal statement." Because of this, Omkar gives you an array a=[a1,a2,…,an] of n distinct integers. An array b=[b1,b2,…,bk] is called nice if for any two distinct elements bi,bj of b, |bi−bj| appears in b at least once. In addition, all elements in b must be distinct. Can you add several (maybe, 0) integers to a to create a nice array b of size at most 300? If a is already nice, you don't have to add any elements.

For example, array [3,6,9] is nice, as |6−3|=|9−6|=3, which appears in the array, and |9−3|=6, which appears in the array, while array [4,2,0,6,9] is not nice, as |9−4|=5 is not present in the array.

For integers x and y, |x−y|=x−y if x>y and |x−y|=y−x otherwise.

Input
Each test contains multiple test cases. The first line contains t (1≤t≤50), the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤100) — the length of the array a.

The second line of each test case contains n distinct integers a1,a2,⋯,an (−100≤ai≤100) — the elements of the array a.

Output
For each test case, output one line containing YES if Omkar can create a nice array b by adding elements to a and NO otherwise. The case of each letter does not matter, so yEs and nO will also be accepted.

If the first line is YES, output a second line containing a single integer k (n≤k≤300).

Then output one line containing k distinct integers b1,b2,⋯,bk (−109≤bi≤109), the elements of the nice array b. b1,b2,⋯,bk can be in any order. For each ai in a, ai must appear at least once in b.

It can be proved that if Omkar can create such an array b, then he can also do so in a way that satisfies the above constraints.

If multiple solutions exist, you can print any.

Example
inputCopy
4
3
3 0 9
2
3 4
5
-7 3 13 -2 8
4
4 8 12 6
outputCopy
yes
4
6 0 3 9
yEs
5
5 3 1 2 4
NO
Yes
6
8 12 6 2 4 10
Note
For the first case, you can add integers to a to receive the array b=[6,0,3,9]. Note that |6−3|=|9−6|=|3−0|=3 and 3 is in b, |6−0|=|9−3|=6 and 6 is in b, and |9−0|=9 is in b, so b is nice.

For the second case, you can add integers to a to receive the array b=[5,3,1,2,4]. We have that |2−1|=|3−2|=|4−3|=|5−4|=1 is in b, |3−1|=|4−2|=|5−3|=2 is in b, |4−1|=|5−2|=3 is in b, and |5−1|=4 is in b, so b is nice.

For the fourth case, you can add integers to a to receive the array b=[8,12,6,2,4,10]. We have that |4−2|=|6−4|=|8−6|=|10−8|=|12−10|=2 is in b, |6−2|=|8−4|=|10−6|=|12−8|=4 is in b, |8−2|=|10−4|=|12−6|=6 is in b, |10−2|=|12−4|=8 is in b, and |12−2|=10 is in b, so b is nice.

It can be proven that for all other test cases it is impossible to create a nice array b.
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
	ll x, f = 0;
	foi(n) {
		cin >> x;
		if (x < 0) {
			f = 1;
		}
	}
	if (f) {
		cout << "No";
		return;
	}
	cout << "Yes" << endl;
	cout << 101 << endl;
	foi(101) {
		cout << i << " ";
	}
}
