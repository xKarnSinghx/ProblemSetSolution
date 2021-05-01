/*
B. Cow and Friend
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Bessie has way too many friends because she is everyone's favorite cow! Her new friend Rabbit is trying to hop over so they can play!

More specifically, he wants to get from (0,0) to (x,0) by making multiple hops. He is only willing to hop from one point to another point on the 2D plane if the Euclidean distance between the endpoints of a hop is one of its n favorite numbers: a1,a2,…,an. What is the minimum number of hops Rabbit needs to get from (0,0) to (x,0)? Rabbit may land on points with non-integer coordinates. It can be proved that Rabbit can always reach his destination.

Recall that the Euclidean distance between points (xi,yi) and (xj,yj) is (xi−xj)2+(yi−yj)2−−−−−−−−−−−−−−−−−−√.

For example, if Rabbit has favorite numbers 1 and 3 he could hop from (0,0) to (4,0) in two hops as shown below. Note that there also exists other valid ways to hop to (4,0) in 2 hops (e.g. (0,0) → (2,−5–√) → (4,0)).

Here is a graphic for the first example. Both hops have distance 3, one of Rabbit's favorite numbers.
In other words, each time Rabbit chooses some number ai and hops with distance equal to ai in any direction he wants. The same number can be used multiple times.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤1000)  — the number of test cases. Next 2t lines contain test cases — two lines per test case.

The first line of each test case contains two integers n and x (1≤n≤105, 1≤x≤109)  — the number of favorite numbers and the distance Rabbit wants to travel, respectively.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109)  — Rabbit's favorite numbers. It is guaranteed that the favorite numbers are distinct.

It is guaranteed that the sum of n over all the test cases will not exceed 105.

Output
For each test case, print a single integer — the minimum number of hops needed.

Example
inputCopy
4
2 4
1 3
3 12
3 4 5
1 5
5
2 10
15 4
outputCopy
2
3
1
2
Note
The first test case of the sample is shown in the picture above. Rabbit can hop to (2,5–√), then to (4,0) for a total of two hops. Each hop has a distance of 3, which is one of his favorite numbers.

In the second test case of the sample, one way for Rabbit to hop 3 times is: (0,0) → (4,0) → (8,0) → (12,0).

In the third test case of the sample, Rabbit can hop from (0,0) to (5,0).

In the fourth test case of the sample, Rabbit can hop: (0,0) → (5,102–√) → (10,0).
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
typedef pair< ll, pll>      plll;
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
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
ll TT = 1;
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
void solve()
{
	ll n, x;
	cin >> n >> x;
	ll ans = 1111111111111;
	for (ll a; n--;) {
		cin >> a;
		ans = min(ans, max(2LL, (x + a - 1) / a));
		if (a == x)
			ans = 1;
	}
	cout << ans;
}


