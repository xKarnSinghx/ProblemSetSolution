/*
D. Omkar and the Meaning of Life
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
It turns out that the meaning of life is a permutation p1,p2,…,pn of the integers 1,2,…,n (2≤n≤100). Omkar, having created all life, knows this permutation, and will allow you to figure it out using some queries.

A query consists of an array a1,a2,…,an of integers between 1 and n. a is not required to be a permutation. Omkar will first compute the pairwise sum of a and p, meaning that he will compute an array s where sj=pj+aj for all j=1,2,…,n. Then, he will find the smallest index k such that sk occurs more than once in s, and answer with k. If there is no such index k, then he will answer with 0.

You can perform at most 2n queries. Figure out the meaning of life p.

Interaction
Start the interaction by reading single integer n (2≤n≤100)  — the length of the permutation p.

You can then make queries. A query consists of a single line "?a1a2…an" (1≤aj≤n).

The answer to each query will be a single integer k as described above (0≤k≤n).

After making a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see documentation for other languages.
To output your answer, print a single line "!p1p2…pn" then terminate.

You can make at most 2n queries. Outputting the answer does not count as a query.

Hack Format

To hack, first output a line containing n (2≤n≤100), then output another line containing the hidden permutation p1,p2,…,pn of numbers from 1 to n.

Example
inputCopy
5

2

0

1
outputCopy

? 4 4 2 3 2

? 3 5 1 5 5

? 5 2 4 3 1

! 3 2 1 5 4
Note
In the sample, the hidden permutation p is [3,2,1,5,4]. Three queries were made.

The first query is a=[4,4,2,3,2]. This yields s=[3+4,2+4,1+2,5+3,4+2]=[7,6,3,8,6]. 6 is the only number that appears more than once, and it appears first at index 2, making the answer to the query 2.

The second query is a=[3,5,1,5,5]. This yields s=[3+3,2+5,1+1,5+5,4+5]=[6,7,2,10,9]. There are no numbers that appear more than once here, so the answer to the query is 0.

The third query is a=[5,2,4,3,1]. This yields s=[3+5,2+2,1+4,5+3,4+1]=[8,4,5,8,5]. 5 and 8 both occur more than once here. 5 first appears at index 3, while 8 first appears at index 1, and 1<3, making the answer to the query 1.

Note that the sample is only meant to provide an example of how the interaction works; it is not guaranteed that the above queries represent a correct strategy with which to determine the answer.


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
typedef  map<vll, ll>             mvlll;
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
ld PI = 3.1415926535897;
const ll N = 200010;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	//ll t ; cin >> t;
	//while (t--)
	{
		solve();
		cout << endl;
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
ll ask(ll x, ll y, ll n) {
	cout << "?" << " ";
	foi(n - 1) {
		cout << x << " ";
	}
	cout << y << endl;
	ll s;
	cin >> s;
	return s;
}
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
bool isSubSequence(string a, string b, ll m, ll n) {
	ll j = 0;
	for (ll i = 0; i < n and j < m; i++)
		if (a[j] == b[i])
			j++;
	return (j == m);
}
void solve() {
	ll n;
	cin >> n;
	vll a(n + 1, 0);
	a[n] = 1;
	for (ll i = 2; i <= n; ++i) {
		a[n] += (ask(i, 1, n) > 0);
	}
	ll x = a[n];
	foi(n + 1) {
		if (x == i or i == 0)
			continue;
		if (i < x) {
			a[ask(n, n + i - x, n)] = i;
		}
		else {
			a[ask(n + x - i, n, n)] = i;
		}
	}
	cout << "!" << " ";
	foi(n + 1) {
		if (i)
			cout << a[i] << " ";
	}
}



