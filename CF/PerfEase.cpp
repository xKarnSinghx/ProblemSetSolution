/*
C. Perform Easily
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
After battling Shikamaru, Tayuya decided that her flute is too predictable, and replaced it with a guitar. The guitar has 6 strings and an infinite number of frets numbered from 1. Fretting the fret number j on the i-th string produces the note ai+j.

Tayuya wants to play a melody of n notes. Each note can be played on different string-fret combination. The easiness of performance depends on the difference between the maximal and the minimal indices of used frets. The less this difference is, the easier it is to perform the technique. Please determine the minimal possible difference.

For example, if a=[1,1,2,2,3,3], and the sequence of notes is 4,11,11,12,12,13,13 (corresponding to the second example), we can play the first note on the first string, and all the other notes on the sixth string. Then the maximal fret will be 10, the minimal one will be 3, and the answer is 10−3=7, as shown on the picture.


Input
The first line contains 6 space-separated numbers a1, a2, ..., a6 (1≤ai≤109) which describe the Tayuya's strings.

The second line contains the only integer n (1≤n≤100000) standing for the number of notes in the melody.

The third line consists of n integers b1, b2, ..., bn (1≤bi≤109), separated by space. They describe the notes to be played. It's guaranteed that bi>aj for all 1≤i≤n and 1≤j≤6, in other words, you can play each note on any string.

Output
Print the minimal possible difference of the maximal and the minimal indices of used frets.

Examples
inputCopy
1 4 100 10 30 5
6
101 104 105 110 130 200
outputCopy
0
inputCopy
1 1 2 2 3 3
7
13 4 11 12 11 13 12
outputCopy
7
Note
In the first sample test it is optimal to play the first note on the first string, the second note on the second string, the third note on the sixth string, the fourth note on the fourth string, the fifth note on the fifth string, and the sixth note on the third string. In this case the 100-th fret is used each time, so the difference is 100−100=0.


In the second test it's optimal, for example, to play the second note on the first string, and all the other notes on the sixth string. Then the maximal fret will be 10, the minimal one will be 3, and the answer is 10−3=7.


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
void solve() {
	ll a[6];
	foi(6)
	cin >> a[i];
	sort(a, a + 6);
	ll n;
	cin >> n;
	ll b[n];
	foi(n)
	cin >> b[i];
	sort(b, b + n);
	ll id[n];
	set<pll> s;
	foi(n) {
		id[i] = 6;
		s.insert({b[i] - a[id[i] - 1], i});
	}
	ll ans = (*s.rbegin()).ff - (*s.begin()).ff;
	set<pll>::iterator p;
	while (true) {
		p = s.begin();
		ll i = p->ss;
		s.erase(p);
		if (id[i] == 1)
			break;
		id[i]--;
		s.insert({b[i] - a[id[i] - 1], i});
		ans = min(ans, (*s.rbegin()).ff - (*s.begin()).ff);
	}
	cout << ans;
}
