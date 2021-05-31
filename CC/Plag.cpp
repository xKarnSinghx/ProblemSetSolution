/*
You are an administrator of a popular quiz website. Every day, you hold a quiz on the website.

There are N users (numbered 1 through N) and M admins (numbered N+1 through N+M). For each quiz, each user is allowed to attempt it at most once. Sometimes, admins attempt the quizzes for testing purposes too; an admin may attempt a quiz any number of times.

On a certain day, the quiz was attempted K times. For each i (1≤i≤K), the i-th of these attempts was made by the person with number Li. Find all the users who attempted the quiz more than once, in order to disqualify them.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, M and K.
The second line contains K space-separated integers L1,L2,…,LK.
Output
For each test case, print a single line containing an integer D denoting the number of users who should be disqualified, followed by a space and D space-separated integers denoting their numbers in ascending order.

Constraints
1≤T≤10
0≤N,M≤105
1≤N+M,K≤105
1≤Li≤N+M for each valid i
Example Input
3
1 1 1
1
1 1 2
1 1
5 5 10
2 5 2 5 2 4 10 10 10 10
Example Output
0
1 1
2 2 5
Explanation
Example case 1: Since there is only a single attempt during the whole day, there cannot be any user who made more than one attempt.

Example case 2: User 1 attempted the quiz twice.

Example case 3: Users 2 and 5 attempted the quiz multiple times. The admin with number 10 also attempted the quiz multiple times, but admins are allowed to do that.
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

	mll mx;
	ll n, m, k;
	cin >> n >> m >> k;
	set<ll> s;
	ll rem = 0;
	vll a(k);
	foi(k) {
		cin >> a[i];
		mx[a[i]]++;
		if (a[i] <= n and mx[a[i]] > 1) {
			s.insert(a[i]);
		}
	}
	cout << s.size() << " ";
	for (auto it : s)
		cout << it << " ";

}



