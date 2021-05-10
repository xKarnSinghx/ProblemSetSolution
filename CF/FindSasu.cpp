/*

A. Finding Sasuke
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Naruto has sneaked into the Orochimaru's lair and is now looking for Sasuke. There are T rooms there. Every room has a door into it, each door can be described by the number n of seals on it and their integer energies a1, a2, ..., an. All energies ai are nonzero and do not exceed 100 by absolute value. Also, n is even.

In order to open a door, Naruto must find such n seals with integer energies b1, b2, ..., bn that the following equality holds: a1⋅b1+a2⋅b2+...+an⋅bn=0. All bi must be nonzero as well as ai are, and also must not exceed 100 by absolute value. Please find required seals for every room there.

Input
The first line contains the only integer T (1≤T≤1000) standing for the number of rooms in the Orochimaru's lair. The other lines contain descriptions of the doors.

Each description starts with the line containing the only even integer n (2≤n≤100) denoting the number of seals.

The following line contains the space separated sequence of nonzero integers a1, a2, ..., an (|ai|≤100, ai≠0) denoting the energies of seals.

Output
For each door print a space separated sequence of nonzero integers b1, b2, ..., bn (|bi|≤100, bi≠0) denoting the seals that can open the door. If there are multiple valid answers, print any. It can be proven that at least one answer always exists.

Example
inputCopy
2
2
1 100
4
1 2 3 6
outputCopy
-100 1
1 1 1 -1
Note
For the first door Naruto can use energies [−100,1]. The required equality does indeed hold: 1⋅(−100)+100⋅1=0.

For the second door Naruto can use, for example, energies [1,1,1,−1]. The required equality also holds: 1⋅1+2⋅1+3⋅1+6⋅(−1)=0.

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
void solve() {

	ll n;
	cin >> n;
	ll a[n];
	foi(n)
	cin >> a[i];
	ll b[n];
	for (ll i = 0; i < n; i += 2) {
		b[i] = -1 * a[i + 1];
		b[i + 1] = a[i];
	}
	foi(n)
	cout << b[i] << " ";
}
