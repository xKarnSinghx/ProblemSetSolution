/*
E. Riding in a Lift
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Imagine that you are in a building that has exactly n floors. You can move between the floors in a lift. Let's number the floors from bottom to top with integers from 1 to n. Now you're on the floor number a. You are very bored, so you want to take the lift. Floor number b has a secret lab, the entry is forbidden. However, you already are in the mood and decide to make k consecutive trips in the lift.

Let us suppose that at the moment you are on the floor number x (initially, you were on floor a). For another trip between floors you choose some floor with number y (y ≠ x) and the lift travels to this floor. As you cannot visit floor b with the secret lab, you decided that the distance from the current floor x to the chosen y must be strictly less than the distance from the current floor x to floor b with the secret lab. Formally, it means that the following inequation must fulfill: |x - y| < |x - b|. After the lift successfully transports you to floor y, you write down number y in your notepad.

Your task is to find the number of distinct number sequences that you could have written in the notebook as the result of k trips in the lift. As the sought number of trips can be rather large, find the remainder after dividing the number by 1000000007 (109 + 7).

Input
The first line of the input contains four space-separated integers n, a, b, k (2 ≤ n ≤ 5000, 1 ≤ k ≤ 5000, 1 ≤ a, b ≤ n, a ≠ b).

Output
Print a single integer — the remainder after dividing the sought number of sequences by 1000000007 (109 + 7).

Examples
inputCopy
5 2 4 1
outputCopy
2
inputCopy
5 2 4 2
outputCopy
2
inputCopy
5 3 4 1
outputCopy
0
Note
Two sequences p1, p2, ..., pk and q1, q2, ..., qk are distinct, if there is such integer j (1 ≤ j ≤ k), that pj ≠ qj.

Notes to the samples:

In the first sample after the first trip you are either on floor 1, or on floor 3, because |1 - 2| < |2 - 4| and |3 - 2| < |2 - 4|.
In the second sample there are two possible sequences: (1, 2); (1, 3). You cannot choose floor 3 for the first trip because in this case no floor can be the floor for the second trip.
In the third sample there are no sought sequences, because you cannot choose the floor for the first trip.

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
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	ll ans[k + 1][n + 1] = {}, v[n + 1] = {};
	ans[0][a] = 1;
	for (ll i = 1; i <= n; i++) {
		v[i] = v[i - 1] + ans[0][i];
	}
	for (ll i = 1; i <= k; i++)
	{
		for (ll j = 1; j <= n; j++)	{
			if (j == b)
				continue;
			if (j > b)
				ans[i][j] = ((v[n] - v[(b + j) / 2] + MOD) % MOD - ans[i - 1][j] + MOD) % MOD;
			else
				ans[i][j] = (v[(b - 1 + j) / 2] - ans[i - 1][j] + MOD) % MOD;
		}
		for (ll j = 1; j <= n; j++) {
			v[j] = (v[j - 1] + ans[i][j]) % MOD;
		}
	}
	cout << v[n];

}
 
