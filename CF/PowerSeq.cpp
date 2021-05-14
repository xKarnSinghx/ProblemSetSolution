/*
B. Power Sequence
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's call a list of positive integers a0,a1,...,an−1 a power sequence if there is a positive integer c, so that for every 0≤i≤n−1 then ai=ci.

Given a list of n positive integers a0,a1,...,an−1, you are allowed to:

Reorder the list (i.e. pick a permutation p of {0,1,...,n−1} and change ai to api), then
Do the following operation any number of times: pick an index i and change ai to ai−1 or ai+1 (i.e. increment or decrement ai by 1) with a cost of 1.
Find the minimum cost to transform a0,a1,...,an−1 into a power sequence.

Input
The first line contains an integer n (3≤n≤105).

The second line contains n integers a0,a1,...,an−1 (1≤ai≤109).

Output
Print the minimum cost to transform a0,a1,...,an−1 into a power sequence.

Examples
inputCopy
3
1 3 2
outputCopy
1
inputCopy
3
1000000000 1000000000 1000000000
outputCopy
1999982505
Note
In the first example, we first reorder {1,3,2} into {1,2,3}, then increment a2 to 4 with cost 1 to get a power sequence {1,2,4}.


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
void solve() {
	ll n;
	cin >> n;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	ll ans = 111111111111111;
	sort(a, a + n);
	ll x = pow(1e12, 1 / (ld)(n - 1));
	for (ll j = 1; j <= x; j++)
	{
		ll s = 0;
		foi(n)
		{
			s += abs(pow(j, i) - a[i]);
		}
		ans = min(s, ans);
	}
	cout << ans;
}

