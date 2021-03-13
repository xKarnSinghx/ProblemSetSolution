/*
A. Alexey and Train
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alexey is travelling on a train. Unfortunately, due to the bad weather, the train moves slower that it should!

Alexey took the train at the railroad terminal. Let's say that the train starts from the terminal at the moment 0. Also, let's say that the train will visit n stations numbered from 1 to n along its way, and that Alexey destination is the station n.

Alexey learned from the train schedule n integer pairs (ai,bi) where ai is the expected time of train's arrival at the i-th station and bi is the expected time of departure.

Also, using all information he has, Alexey was able to calculate n integers tm1,tm2,…,tmn where tmi is the extra time the train need to travel from the station i−1 to the station i. Formally, the train needs exactly ai−bi−1+tmi time to travel from station i−1 to station i (if i=1 then b0 is the moment the train leave the terminal, and it's equal to 0).

The train leaves the station i, if both conditions are met:

it's on the station for at least ⌈bi−ai2⌉ units of time (division with ceiling);
current time ≥bi.
Since Alexey spent all his energy on prediction of time delays, help him to calculate the time of arrival at the station n.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains the single integer n (1≤n≤100) — the number of stations.

Next n lines contain two integers each: ai and bi (1≤ai<bi≤106). It's guaranteed that bi<ai+1.

Next line contains n integers tm1,tm2,…,tmn (0≤tmi≤106).

Output
For each test case, print one integer — the time of Alexey's arrival at the last station.

Example
inputCopy
2
2
2 4
10 12
0 2
5
1 4
7 8
9 10
13 15
19 20
1 2 3 4 5
outputCopy
12
32
Note
In the first test case, Alexey arrives at station 1 without any delay at the moment a1=2 (since tm1=0). After that, he departs at moment b1=4. Finally, he arrives at station 2 with tm2=2 extra time, or at the moment 12.

In the second test case, Alexey arrives at the first station with tm1=1 extra time, or at moment 2. The train, from one side, should stay at the station at least ⌈b1−a12⌉=2 units of time and from the other side should depart not earlier than at moment b1=4. As a result, the trains departs right at the moment 4.

Using the same logic, we can figure out that the train arrives at the second station at the moment 9 and departs at the moment 10; at the third station: arrives at 14 and departs at 15; at the fourth: arrives at 22 and departs at 23. And, finally, arrives at the fifth station at 32.


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
typedef pair<ll, pll>      plll;
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
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif

	int t ; cin >> t;
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
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}

void solve()
{
	
	ll n;
	cin >> n;

	ll a[n], b[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	ll tm[n];
	b[0] = 0;
	for (ll i = 1; i <= n; i++)
		cin >> tm[i];
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ans += a[i] + tm[i] - b[i - 1];
		if (i == n)
			ans = ans;
		else
			ans += ceils(b[i] - a[i], 2);
		if (i == n)
			ans = ans;
		else if (ans < b[i])
			ans = b[i];
	}
	cout << ans;
}
 
