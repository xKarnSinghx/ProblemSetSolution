/*
C. Number Game
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ashishgup and FastestFinger play a game.

They start with a number n and play in turns. In each turn, a player can make any one of the following moves:

Divide n by any of its odd divisors greater than 1.
Subtract 1 from n if n is greater than 1.
Divisors of a number include the number itself.

The player who is unable to make a move loses the game.

Ashishgup moves first. Determine the winner of the game if both of them play optimally.

Input
The first line contains a single integer t (1≤t≤100)  — the number of test cases. The description of the test cases follows.

The only line of each test case contains a single integer  — n (1≤n≤109).

Output
For each test case, print "Ashishgup" if he wins, and "FastestFinger" otherwise (without quotes).

Example
inputCopy
7
1
2
3
4
5
6
12
outputCopy
FastestFinger
Ashishgup
Ashishgup
FastestFinger
Ashishgup
FastestFinger
Ashishgup
Note
In the first test case, n=1, Ashishgup cannot make a move. He loses.

In the second test case, n=2, Ashishgup subtracts 1 on the first move. Now n=1, FastestFinger cannot make a move, so he loses.

In the third test case, n=3, Ashishgup divides by 3 on the first move. Now n=1, FastestFinger cannot make a move, so he loses.

In the last test case, n=12, Ashishgup divides it by 3. Now n=4, FastestFinger is forced to subtract 1, and Ashishgup gets 3, so he wins by dividing it by 3.

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
void solve() {
	ll n;
	cin >> n;
	if (n == 1)
		cout << "FastestFinger";
	else if (n == 2)
		cout << "Ashishgup";
	else if (n % 2 == 0) {
		n /= 2;
		ll t = n;
		while (t % 2 == 0)
			t /= 2;
		if (t == 1)
			cout << "FastestFinger";
		else if (isPrime(n))
			cout << "FastestFinger";
		else
			cout << "Ashishgup";

	}
	else
		cout << "Ashishgup";

}

 
