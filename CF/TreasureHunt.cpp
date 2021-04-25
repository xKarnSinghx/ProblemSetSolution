/*
A. Treasure Hunt
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Captain Bill the Hummingbird and his crew recieved an interesting challenge offer. Some stranger gave them a map, potion of teleportation and said that only this potion might help them to reach the treasure.

Bottle with potion has two values x and y written on it. These values define four moves which can be performed using the potion:





Map shows that the position of Captain Bill the Hummingbird is (x1, y1) and the position of the treasure is (x2, y2).

You task is to tell Captain Bill the Hummingbird whether he should accept this challenge or decline. If it is possible for Captain to reach the treasure using the potion then output "YES", otherwise "NO" (without quotes).

The potion can be used infinite amount of times.

Input
The first line contains four integer numbers x1, y1, x2, y2 ( - 105 ≤ x1, y1, x2, y2 ≤ 105) — positions of Captain Bill the Hummingbird and treasure respectively.

The second line contains two integer numbers x, y (1 ≤ x, y ≤ 105) — values on the potion bottle.

Output
Print "YES" if it is possible for Captain to reach the treasure using the potion, otherwise print "NO" (without quotes).

Examples
inputCopy
0 0 0 6
2 3
outputCopy
YES
inputCopy
1 1 3 6
1 5
outputCopy
NO
Note
In the first example there exists such sequence of moves:

 — the first type of move
 — the third type of move

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
void solve()
{
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll x, y;
	cin >> x >> y;
	ll diff1 = abs(x1 - x2), diff2 = abs(y1 - y2);
	if (diff1 % x  or diff2 % y or abs(diff1 / x - diff2 / y) % 2  )
		cout << "NO";
	else
		cout << "YES";

}


