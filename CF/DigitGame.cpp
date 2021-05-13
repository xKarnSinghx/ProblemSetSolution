/*
A. Digit Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Everyone knows that agents in Valorant decide, who will play as attackers, and who will play as defenders. To do that Raze and Breach decided to play t matches of a digit game...

In each of t matches of the digit game, a positive integer is generated. It consists of n digits. The digits of this integer are numerated from 1 to n from the highest-order digit to the lowest-order digit. After this integer is announced, the match starts.

Agents play in turns. Raze starts. In one turn an agent can choose any unmarked digit and mark it. Raze can choose digits on odd positions, but can not choose digits on even positions. Breach can choose digits on even positions, but can not choose digits on odd positions. The match ends, when there is only one unmarked digit left. If the single last digit is odd, then Raze wins, else Breach wins.

It can be proved, that before the end of the match (for every initial integer with n digits) each agent has an ability to make a turn, i.e. there is at least one unmarked digit, that stands on a position of required parity.

For each of t matches find out, which agent wins, if both of them want to win and play optimally.

Input
First line of input contains an integer t (1≤t≤100)  — the number of matches.

The first line of each match description contains an integer n (1≤n≤103)  — the number of digits of the generated number.

The second line of each match description contains an n-digit positive integer without leading zeros.

Output
For each match print 1, if Raze wins, and 2, if Breach wins.

Example
inputCopy
4
1
2
1
3
3
102
4
2069
outputCopy
2
1
1
2
Note
In the first match no one can make a turn, the only digit left is 2, it's even, so Breach wins.

In the second match the only digit left is 3, it's odd, so Raze wins.

In the third match Raze can mark the last digit, after that Breach can only mark 0. 1 will be the last digit left, it's odd, so Raze wins.

In the fourth match no matter how Raze plays, Breach can mark 9, and in the end there will be digit 0. It's even, so Breach wins.


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
	string s;
	ll e = 0, o = 0;
	cin >> s;
	foi(n) {
		if ((i + 1) % 2) {
			if ((s[i] - '0') % 2)
				o++;
		}
		else {
			if ((s[i] - '0') % 2 == 0)
				e++;
		}
	}
	if (n % 2) {
		if (o)
			cout << 1;
		else
			cout << 2;
	}
	else {
		if (e)
			cout << 2;
		else
			cout << 1;
	}
}
