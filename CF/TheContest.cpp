/*
A. The Contest
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Pasha is participating in a contest on one well-known website. This time he wants to win the contest and will do anything to get to the first place!

This contest consists of n problems, and Pasha solves ith problem in ai time units (his solutions are always correct). At any moment of time he can be thinking about a solution to only one of the problems (that is, he cannot be solving two problems at the same time). The time Pasha spends to send his solutions is negligible. Pasha can send any number of solutions at the same moment.

Unfortunately, there are too many participants, and the website is not always working. Pasha received the information that the website will be working only during m time periods, jth period is represented by its starting moment lj and ending moment rj. Of course, Pasha can send his solution only when the website is working. In other words, Pasha can send his solution at some moment T iff there exists a period x such that lx ≤ T ≤ rx.

Pasha wants to know his best possible result. We need to tell him the minimal moment of time by which he is able to have solutions to all problems submitted, if he acts optimally, or say that it's impossible no matter how Pasha solves the problems.

Input
The first line contains one integer n (1 ≤ n ≤ 1000) — the number of problems. The second line contains n integers ai (1 ≤ ai ≤ 105) — the time Pasha needs to solve ith problem.

The third line contains one integer m (0 ≤ m ≤ 1000) — the number of periods of time when the website is working. Next m lines represent these periods. jth line contains two numbers lj and rj (1 ≤ lj < rj ≤ 105) — the starting and the ending moment of jth period.

It is guaranteed that the periods are not intersecting and are given in chronological order, so for every j > 1 the condition lj > rj - 1 is met.

Output
If Pasha can solve and submit all the problems before the end of the contest, print the minimal moment of time by which he can have all the solutions submitted.

Otherwise print "-1" (without brackets).

Examples
inputCopy
2
3 4
2
1 4
7 9
outputCopy
7
inputCopy
1
5
1
1 4
outputCopy
-1
inputCopy
1
5
1
1 5
outputCopy
5
Note
In the first example Pasha can act like this: he solves the second problem in 4 units of time and sends it immediately. Then he spends 3 time units to solve the first problem and sends it 7 time units after the contest starts, because at this moment the website starts working again.

In the second example Pasha invents the solution only after the website stops working for the last time.

In the third example Pasha sends the solution exactly at the end of the first period.
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


	//ll t ; cin >> t;
	//while (t--)
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
	ll n;
	cin >> n;
	ll m, a[n], s = 0;
	foi(n) {
		cin >> a[i];
		s += a[i];
	}
	cin >> m;
	vpll x;
	ll ans = -1;
	foi(m) {
		ll x1, y;
		cin >> x1 >> y;
		x.pb(mp(x1, y));
		if (s >= x1 and s <= y and ans == -1 ) {
			ans = s;
		}
		if (s <= x1 and s <= y and ans == -1 ) {
			ans = min(x1, y);
		}
	}
	cout << ans;



}


