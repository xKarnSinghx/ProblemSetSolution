/*
E. Breaking the Wall
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Monocarp plays "Rage of Empires II: Definitive Edition" — a strategic computer game. Right now he's planning to attack his opponent in the game, but Monocarp's forces cannot enter the opponent's territory since the opponent has built a wall.

The wall consists of n sections, aligned in a row. The i-th section initially has durability ai. If durability of some section becomes 0 or less, this section is considered broken.

To attack the opponent, Monocarp needs to break at least two sections of the wall (any two sections: possibly adjacent, possibly not). To do this, he plans to use an onager — a special siege weapon. The onager can be used to shoot any section of the wall; the shot deals 2 damage to the target section and 1 damage to adjacent sections. In other words, if the onager shoots at the section x, then the durability of the section x decreases by 2, and the durability of the sections x−1 and x+1 (if they exist) decreases by 1 each.

Monocarp can shoot at any sections any number of times, he can even shoot at broken sections.

Monocarp wants to calculate the minimum number of onager shots needed to break at least two sections. Help him!

Input
The first line contains one integer n (2≤n≤2⋅105) — the number of sections.

The second line contains the sequence of integers a1,a2,…,an (1≤ai≤106), where ai is the initial durability of the i-th section.

Output
Print one integer — the minimum number of onager shots needed to break at least two sections of the wall.

Examples
inputCopy
5
20 10 30 10 20
outputCopy
10
inputCopy
3
1 8 1
outputCopy
1
inputCopy
6
7 6 6 8 5 8
outputCopy
4
inputCopy
6
14 3 8 10 15 4
outputCopy
4
inputCopy
4
1 100 100 1
outputCopy
2
inputCopy
3
40 10 10
outputCopy
7
Note
In the first example, it is possible to break the 2-nd and the 4-th section in 10 shots, for example, by shooting the third section 10 times. After that, the durabilities become [20,0,10,0,20]. Another way of doing it is firing 5 shots at the 2-nd section, and another 5 shots at the 4-th section. After that, the durabilities become [15,0,20,0,15].

In the second example, it is enough to shoot the 2-nd section once. Then the 1-st and the 3-rd section will be broken.

In the third example, it is enough to shoot the 2-nd section twice (then the durabilities become [5,2,4,8,5,8]), and then shoot the 3-rd section twice (then the durabilities become [5,0,0,6,5,8]). So, four shots are enough to break the 2-nd and the 3-rd section.
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
typedef vector<ld>          vld;
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
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000001;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
// 	ll t; cin >> t;
// 	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve() {
	ll n;
	cin >> n;
	vll a(n), b(n);
	foi(n) {
		cin >> a[i];
	}
	ll mn = MOD, mn1 = mn;
	for (ll x : a) {
		x = (x + 1) / 2;
		if (x < mn) {
			mn1 = mn;
			mn = x;
		}
		else if (x < mn1) {
			mn1 = x;
		}
	}
	ll ans = mn1 + mn;
	foi(n) {
		if (i)
			ans = min(ans, max({(a[i - 1] + 1) / 2, (a[i] + 1) / 2, (a[i - 1] + a[i] + 2) / 3}));
		if (i > 1)
			ans = min(ans, min(a[i - 2], a[i]) + (max(a[i - 2], a[i]) - min(a[i - 2], a[i]) + 1) / 2);
	}
	cout << ans;

}
