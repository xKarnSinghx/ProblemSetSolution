/*
C. Everyone is a Winner!
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
On the well-known testing system MathForces, a draw of n rating units is arranged. The rating will be distributed according to the following algorithm: if k participants take part in this event, then the n rating is evenly distributed between them and rounded to the nearest lower integer, At the end of the drawing, an unused rating may remain — it is not given to any of the participants.

For example, if n=5 and k=3, then each participant will recieve an 1 rating unit, and also 2 rating units will remain unused. If n=5, and k=6, then none of the participants will increase their rating.

Vasya participates in this rating draw but does not have information on the total number of participants in this event. Therefore, he wants to know what different values of the rating increment are possible to get as a result of this draw and asks you for help.

For example, if n=5, then the answer is equal to the sequence 0,1,2,5. Each of the sequence values (and only them) can be obtained as ⌊n/k⌋ for some positive integer k (where ⌊x⌋ is the value of x rounded down): 0=⌊5/7⌋, 1=⌊5/5⌋, 2=⌊5/2⌋, 5=⌊5/1⌋.

Write a program that, for a given n, finds a sequence of all possible rating increments.

Input
The first line contains integer number t (1≤t≤10) — the number of test cases in the input. Then t test cases follow.

Each line contains an integer n (1≤n≤109) — the total number of the rating units being drawn.

Output
Output the answers for each of t test cases. Each answer should be contained in two lines.

In the first line print a single integer m — the number of different rating increment values that Vasya can get.

In the following line print m integers in ascending order — the values of possible rating increments.

Example
inputCopy
4
5
11
1
3
outputCopy
4
0 1 2 5 
6
0 1 2 3 5 11 
2
0 1 
3
0 1 3 

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
ll TT = 1;
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
void solve()
{
	ll n;
	cin >> n;
	vll x;
	ll z = (ll)sqrt(n);
	foi(z + 1) {
		x.pb(i);
	}
	for (ll i = 1; i <= z; i++) {
		x.pb(n / i);
	}
	sort(all(x));
	x.resize(unique(all(x)) - x.begin());
	cout << x.size() << "\n";
	foi(x.size())
	cout << x[i] << " ";


}


