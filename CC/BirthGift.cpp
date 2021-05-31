/*
It’s Chef's birthday. He and his twin have received N gifts in total. The i-th gift has a price of Ai. Each twin wants to keep the most expensive gifts for himself.

The twins take K turns alternately (each has K turns, for 2⋅K turns in total). It is given that 2⋅K+1≤N. In a turn, a person may choose one gift. The only exception is the last turn of the twin who moves second, where he gets to choose two gifts instead of one. Assuming they both choose gifts optimally and you can choose who takes the first turn, find the maximum total cost of the gifts that Chef keeps.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains two space-separated integers N, K.
The second line contains N space-separated integers A1,A2,…,AN, the price of the gifts.
Output
For each test case, output in a single line the answer to the problem.

Constraints
1≤T≤100
3≤N≤103
1≤K≤N−12
1≤Ai≤109
Subtasks
Subtask #1 (100 points): original constraints

Sample Input
3
3 1
1 3 2
3 1
3 1 3
5 2
5 1 3 2 4
Sample Output
3
4
8
Explanation
Test Case 1: Chef moves first and he chooses the gift with cost 3. His twin then chooses the gifts of costs 1 and 2.

Test Case 2: Chef allows his brother to choose first and his brother chooses a gift with cost 3. Then Chef chooses the remaining gift with cost 3. Since Chef moves second, he is allowed to choose one more gift, so he chooses gift with cost 1. The total cost of Chef's gifts is 3+1=4.

Test Case 3: Chef moves first and at the end he will have the gifts with costs 5 and 3. Hence, the total cost of gifts with Chef = 5+3=8.
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
	ll n, k;
	cin >> n >> k;
	ll a[n];
	foi(n)
	cin >> a[i];
	sort(a, a + n);
	ll ans = 0, ans1 = 0, z = 0, z1 = 0;
	for (ll i = n - 1; i > -1; i -= 2) {
		ans += a[i];
		z++;
		if (z == k)
			break;
	}
	for (ll i = n - 2; i > -1; i -= 2) {
		ans1 += a[i];
		z1++;
		if (z1 == k)
			break;
	}
	ans1 += a[n - 2 * z1 - 1];
	cout << max(ans, ans1);

}



