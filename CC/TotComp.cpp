/*
You are given all N−1 integers in the range [2,N]. In each step, you choose 2 distinct integers and if they share a common factor greater than 1, you combine them into the same group. You keep doing it until no further merging is possible.

Belonging to a group is an equivalence relation. So if integers a and b are in the same group and integers b and c are in the same group, then integers a and c are also said to be in the same group.

Find the total number of groups formed in the end.

Input
First line will contain T, number of test cases. Then the test cases follow.
Each test case contains a single line of input, a single integer N.
Output
For each test case, output in a single line the answer to the problem.

Constraints
1≤T≤2⋅105
2≤N≤107
Subtasks
Subtask #1 (30 points):

1≤T≤200
2≤N≤1000
Subtask #2 (70 points): original constraints

Sample Input
3
2
4
8
Sample Output
1
2
3
Explanation
Test Case 1: The final group is {2}.

Test Case 2: The final groups are {2,4}, and {3}.

Test Case 3: The final groups are {2,3,4,6,8}, {5}, and {7}.
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
/*ll is_prime[10000001];
void seive()
{
	is_prime[0] = 0; is_prime[1] = 1;
	for (ll i = 2; i * i <= 1e7 + 1; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= 1e7 + 1; j += i)
				is_prime[j] = 1;
		}
	}
}*/
const ll N = 1e7 + 7;
ll a[N];
bool prime[N];
void sieve() {
	for (ll i = 0; i < N; i++) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for (ll p = 2; p * p < N; p++) {
		if (prime[p]) {
			for (ll i = p * p; i < N; i += p) {
				prime[i] = false;
			}
		}
	}

	a[0] = 0;
	a[1] = 0;
	a[2] = 1;
	for (ll i = 3; i <= N; i++) {
		if (prime[i]) {
			a[i] = a[i - 1] + 1;
		}
		else
			a[i] = a[i - 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	sieve();
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
	ll ans = 1;
	if (n == 2)
		cout << 1 ;
	else if (n == 3)
		cout << 2 ;
	else
		cout << 1 + abs(a[n] - a[n / 2]);
}

