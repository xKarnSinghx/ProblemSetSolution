/*
E. Rock, Paper, Scissors
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alice and Bob have decided to play the game "Rock, Paper, Scissors".

The game consists of several rounds, each round is independent of each other. In each round, both players show one of the following things at the same time: rock, paper or scissors. If both players showed the same things then the round outcome is a draw. Otherwise, the following rules applied:

if one player showed rock and the other one showed scissors, then the player who showed rock is considered the winner and the other one is considered the loser;
if one player showed scissors and the other one showed paper, then the player who showed scissors is considered the winner and the other one is considered the loser;
if one player showed paper and the other one showed rock, then the player who showed paper is considered the winner and the other one is considered the loser.
Alice and Bob decided to play exactly n rounds of the game described above. Alice decided to show rock a1 times, show scissors a2 times and show paper a3 times. Bob decided to show rock b1 times, show scissors b2 times and show paper b3 times. Though, both Alice and Bob did not choose the sequence in which they show things. It is guaranteed that a1+a2+a3=n and b1+b2+b3=n.

Your task is to find two numbers:

the minimum number of round Alice can win;
the maximum number of rounds Alice can win.
Input
The first line of the input contains one integer n (1≤n≤109) — the number of rounds.

The second line of the input contains three integers a1,a2,a3 (0≤ai≤n) — the number of times Alice will show rock, scissors and paper, respectively. It is guaranteed that a1+a2+a3=n.

The third line of the input contains three integers b1,b2,b3 (0≤bj≤n) — the number of times Bob will show rock, scissors and paper, respectively. It is guaranteed that b1+b2+b3=n.

Output
Print two integers: the minimum and the maximum number of rounds Alice can win.

Examples
inputCopy
2
0 1 1
1 1 0
outputCopy
0 1
inputCopy
15
5 5 5
5 5 5
outputCopy
0 15
inputCopy
3
0 0 3
3 0 0
outputCopy
3 3
inputCopy
686
479 178 29
11 145 530
outputCopy
22 334
inputCopy
319
10 53 256
182 103 34
outputCopy
119 226
Note
In the first example, Alice will not win any rounds if she shows scissors and then paper and Bob shows rock and then scissors. In the best outcome, Alice will win one round if she shows paper and then scissors, and Bob shows rock and then scissors.

In the second example, Alice will not win any rounds if Bob shows the same things as Alice each round.

In the third example, Alice always shows paper and Bob always shows rock so Alice will win all three rounds anyway.

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
	ll a1, a2, a3, b1, b2, b3;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	cout << max(0LL, max(b1 - a1 - a2, max(b2 - a2 - a3, b3 - a3 - a1))) << " " << min(a1, b2) + min(a2, b3) + min(a3, b1);
}
