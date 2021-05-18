/*
B. Omkar and Last Class of Math
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
In Omkar's last class of math, he learned about the least common multiple, or LCM. LCM(a,b) is the smallest positive integer x which is divisible by both a and b.

Omkar, having a laudably curious mind, immediately thought of a problem involving the LCM operation: given an integer n, find positive integers a and b such that a+b=n and LCM(a,b) is the minimum value possible.

Can you help Omkar solve his ludicrously challenging math problem?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10). Description of the test cases follows.

Each test case consists of a single integer n (2≤n≤109).

Output
For each test case, output two positive integers a and b, such that a+b=n and LCM(a,b) is the minimum possible.

Example
inputCopy
3
4
6
9
outputCopy
2 2
3 3
3 6
Note
For the first test case, the numbers we can choose are 1,3 or 2,2. LCM(1,3)=3 and LCM(2,2)=2, so we output 2 2.

For the second test case, the numbers we can choose are 1,5, 2,4, or 3,3. LCM(1,5)=5, LCM(2,4)=4, and LCM(3,3)=3, so we output 3 3.

For the third test case, LCM(3,6)=6. It can be shown that there are no other pairs of numbers which sum to 9 that have a lower LCM.


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
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			cout << n / i << " " << n - n / i;
			return;
		}
	}
	cout << 1 << " " << n - 1;
}

