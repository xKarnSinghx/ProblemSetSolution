/*
D. Stoned Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
T is playing a game with his friend, HL.

There are n piles of stones, the i-th pile initially has ai stones.

T and HL will take alternating turns, with T going first. In each turn, a player chooses a non-empty pile and then removes a single stone from it. However, one cannot choose a pile that has been chosen in the previous turn (the pile that was chosen by the other player, or if the current turn is the first turn then the player can choose any non-empty pile). The player who cannot choose a pile in his turn loses, and the game ends.

Assuming both players play optimally, given the starting configuration of t games, determine the winner of each game.

Input
The first line of the input contains a single integer t (1≤t≤100) — the number of games. The description of the games follows. Each description contains two lines:

The first line contains a single integer n (1≤n≤100) — the number of piles.

The second line contains n integers a1,a2,…,an (1≤ai≤100).

Output
For each game, print on a single line the name of the winner, "T" or "HL" (without quotes)

Example
inputCopy
2
1
2
2
1 1
outputCopy
T
HL
Note
In the first game, T removes a single stone from the only pile in his first turn. After that, although the pile still contains 1 stone, HL cannot choose from this pile because it has been chosen by T in the previous turn. Therefore, T is the winner.

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
string to_oct(ll n) {
	string s;
	while (n) {
		s = to_string(n % 8) + s;
		n /= 8;
	}
	return s;
}
void solve() {
	ll n;
	cin >> n;
	ll a[n], s = 0;
	foi(n) {
		cin >> a[i];
		s += a[i];
	}
	ll f = 0;
	foi(n) {
		if (a[i] > s / 2) {
			f = 1;
			break;
		}
	}
	if (f == 1 or s % 2 == 1)
		cout << "T";
	else
		cout << "HL";

}

