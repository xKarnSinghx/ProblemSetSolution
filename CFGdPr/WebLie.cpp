/*
C. Web of Lies
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
When you play the game of thrones, you win, or you die. There is no middle ground.
Cersei Lannister, A Game of Thrones by George R. R. Martin
There are n nobles, numbered from 1 to n. Noble i has a power of i. There are also m "friendships". A friendship between nobles a and b is always mutual.

A noble is defined to be vulnerable if both of the following conditions are satisfied:

the noble has at least one friend, and
all of that noble's friends have a higher power.
You will have to process the following three types of queries.

Add a friendship between nobles u and v.
Remove a friendship between nobles u and v.
Calculate the answer to the following process.
The process: all vulnerable nobles are simultaneously killed, and all their friendships end. Then, it is possible that new nobles become vulnerable. The process repeats itself until no nobles are vulnerable. It can be proven that the process will end in finite time. After the process is complete, you need to calculate the number of remaining nobles.

Note that the results of the process are not carried over between queries, that is, every process starts with all nobles being alive!

Input
The first line contains the integers n and m (1≤n≤2⋅105, 0≤m≤2⋅105) — the number of nobles and number of original friendships respectively.

The next m lines each contain the integers u and v (1≤u,v≤n, u≠v), describing a friendship. No friendship is listed twice.

The next line contains the integer q (1≤q≤2⋅105) — the number of queries.

The next q lines contain the queries themselves, each query has one of the following three formats.

1 u v (1≤u,v≤n, u≠v) — add a friendship between u and v. It is guaranteed that u and v are not friends at this moment.
2 u v (1≤u,v≤n, u≠v) — remove a friendship between u and v. It is guaranteed that u and v are friends at this moment.
3 — print the answer to the process described in the statement.
Output
For each type 3 query print one integer to a new line. It is guaranteed that there will be at least one type 3 query.

Examples
inputCopy
4 3
2 1
1 3
3 4
4
3
1 2 3
2 3 1
3
outputCopy
2
1
inputCopy
4 3
2 3
3 4
4 1
1
3
outputCopy
1
Note
Consider the first example. In the first type 3 query, we have the diagram below.

In the first round of the process, noble 1 is weaker than all of his friends (2 and 3), and is thus killed. No other noble is vulnerable in round 1. In round 2, noble 3 is weaker than his only friend, noble 4, and is therefore killed. At this point, the process ends, and the answer is 2.


In the second type 3 query, the only surviving noble is 4.

    

The second example consists of only one type 3 query. In the first round, two nobles are killed, and in the second round, one noble is killed. The final answer is 1, since only one noble survives.



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
void solve() {
	ll n, m;
	cin >> n >> m;
	vll a(n, 0);
	ll ans = 0;
	foi(m) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		a[min(x, y)]++;
		if (a[min(x, y)] == 1)
			ans++;
	}
	ll q;
	cin >> q;
	while (q--) {
		ll x;
		cin >> x;
		if (x == 1) {
			ll y, z;
			cin >> y >> z;
			y--, z--;
			a[min(y, z)]++;
			if (a[min(y, z)] == 1)
				ans++;
		}
		else if (x == 2) {
			ll y, z;
			cin >> y >> z;
			y--, z--;
			if (a[min(y, z)] == 1)
				ans--;
			a[min(y, z)]--;
		}
		else {
			cout << n - ans << endl;
		}
	}

}

 
