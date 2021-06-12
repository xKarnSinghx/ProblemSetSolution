/*
C. Valhalla Siege
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ivar the Boneless is a great leader. He is trying to capture Kattegat from Lagertha. The war has begun and wave after wave Ivar's warriors are falling in battle.

Ivar has n warriors, he places them on a straight line in front of the main gate, in a way that the i-th warrior stands right after (i−1)-th warrior. The first warrior leads the attack.

Each attacker can take up to ai arrows before he falls to the ground, where ai is the i-th warrior's strength.

Lagertha orders her warriors to shoot ki arrows during the i-th minute, the arrows one by one hit the first still standing warrior. After all Ivar's warriors fall and all the currently flying arrows fly by, Thor smashes his hammer and all Ivar's warriors get their previous strengths back and stand up to fight again. In other words, if all warriors die in minute t, they will all be standing to fight at the end of minute t.

The battle will last for q minutes, after each minute you should tell Ivar what is the number of his standing warriors.

Input
The first line contains two integers n and q (1≤n,q≤200000) — the number of warriors and the number of minutes in the battle.

The second line contains n integers a1,a2,…,an (1≤ai≤109) that represent the warriors' strengths.

The third line contains q integers k1,k2,…,kq (1≤ki≤1014), the i-th of them represents Lagertha's order at the i-th minute: ki arrows will attack the warriors.

Output
Output q lines, the i-th of them is the number of standing warriors after the i-th minute.

Examples
inputCopy
5 5
1 2 1 2 1
3 10 1 1 1
outputCopy
3
5
4
4
3
inputCopy
4 4
1 2 3 4
9 1 10 6
outputCopy
1
4
4
1
Note
In the first example:

after the 1-st minute, the 1-st and 2-nd warriors die.
after the 2-nd minute all warriors die (and all arrows left over are wasted), then they will be revived thus answer is 5 — all warriors are alive.
after the 3-rd minute, the 1-st warrior dies.
after the 4-th minute, the 2-nd warrior takes a hit and his strength decreases by 1.
after the 5-th minute, the 2-nd warrior dies.

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
	ll n, q;
	cin >> n >> q;
	vll a(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
		if (i != 0)
			a[i] += a[i - 1];
	}
	ll s = 0;
	foi(q) {
		ll x;
		cin >> x;
		s += x;
		auto it = ub(all(a), s) - a.begin();
		if (n - it == 0)
			cout << n << endl;
		else
			cout << n - it << endl;
		if (s >= a[n - 1])
			s = 0;
	}

}
