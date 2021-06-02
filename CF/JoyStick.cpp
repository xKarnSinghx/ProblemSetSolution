/*
A. Joysticks
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Friends are going to play console. They have two joysticks and only one charger for them. Initially first joystick is charged at a1 percent and second one is charged at a2 percent. You can connect charger to a joystick only at the beginning of each minute. In one minute joystick either discharges by 2 percent (if not connected to a charger) or charges by 1 percent (if connected to a charger).

Game continues while both joysticks have a positive charge. Hence, if at the beginning of minute some joystick is charged by 1 percent, it has to be connected to a charger, otherwise the game stops. If some joystick completely discharges (its charge turns to 0), the game also stops.

Determine the maximum number of minutes that game can last. It is prohibited to pause the game, i. e. at each moment both joysticks should be enabled. It is allowed for joystick to be charged by more than 100 percent.

Input
The first line of the input contains two positive integers a1 and a2 (1 ≤ a1, a2 ≤ 100), the initial charge level of first and second joystick respectively.

Output
Output the only integer, the maximum number of minutes that the game can last. Game continues until some joystick is discharged.

Examples
inputCopy
3 5
outputCopy
6
inputCopy
4 4
outputCopy
5
Note
In the first sample game lasts for 6 minute by using the following algorithm:

at the beginning of the first minute connect first joystick to the charger, by the end of this minute first joystick is at 4%, second is at 3%;
continue the game without changing charger, by the end of the second minute the first joystick is at 5%, second is at 1%;
at the beginning of the third minute connect second joystick to the charger, after this minute the first joystick is at 3%, the second one is at 2%;
continue the game without changing charger, by the end of the fourth minute first joystick is at 1%, second one is at 3%;
at the beginning of the fifth minute connect first joystick to the charger, after this minute the first joystick is at 2%, the second one is at 1%;
at the beginning of the sixth minute connect second joystick to the charger, after this minute the first joystick is at 0%, the second one is at 2%.
After that the first joystick is completely discharged and the game is stopped.


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
	ll a, b;
	cin >> a >> b;
	ll ans = 0;
	while (a > 0 and b > 0) {
		if (a == 1 and b == 1)
			break;
		if (a < b)
			a++, b -= 2;
		else
			b++, a -= 2;
		ans++;
	}
	cout << ans;
}
