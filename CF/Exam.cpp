/*
C. Exams
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Student Valera is an undergraduate student at the University. His end of term exams are approaching and he is to pass exactly n exams. Valera is a smart guy, so he will be able to pass any exam he takes on his first try. Besides, he can take several exams on one day, and in any order.

According to the schedule, a student can take the exam for the i-th subject on the day number ai. However, Valera has made an arrangement with each teacher and the teacher of the i-th subject allowed him to take an exam before the schedule time on day bi (bi < ai). Thus, Valera can take an exam for the i-th subject either on day ai, or on day bi. All the teachers put the record of the exam in the student's record book on the day of the actual exam and write down the date of the mark as number ai.

Valera believes that it would be rather strange if the entries in the record book did not go in the order of non-decreasing date. Therefore Valera asks you to help him. Find the minimum possible value of the day when Valera can take the final exam if he takes exams so that all the records in his record book go in the order of non-decreasing date.

Input
The first line contains a single positive integer n (1 ≤ n ≤ 5000) — the number of exams Valera will take.

Each of the next n lines contains two positive space-separated integers ai and bi (1 ≤ bi < ai ≤ 109) — the date of the exam in the schedule and the early date of passing the i-th exam, correspondingly.

Output
Print a single integer — the minimum possible number of the day when Valera can take the last exam if he takes all the exams so that all the records in his record book go in the order of non-decreasing date.

Examples
inputCopy
3
5 2
3 1
4 2
outputCopy
2
inputCopy
3
6 1
5 2
4 3
outputCopy
6
Note
In the first sample Valera first takes an exam in the second subject on the first day (the teacher writes down the schedule date that is 3). On the next day he takes an exam in the third subject (the teacher writes down the schedule date, 4), then he takes an exam in the first subject (the teacher writes down the mark with date 5). Thus, Valera takes the last exam on the second day and the dates will go in the non-decreasing order: 3, 4, 5.

In the second sample Valera first takes an exam in the third subject on the fourth day. Then he takes an exam in the second subject on the fifth day. After that on the sixth day Valera takes an exam in the first subject.

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
typedef map<pair<ll, ll>, ll>  mplll;
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
	ll n;
	cin >> n;
	vpll a(n);
	foi(n) {
		ll x, y;
		cin >> x >> y;
		a[i].ff = x, a[i].ss = y;
	}
	sort(all(a));
	ll ans = 0;
	foi(n) {
		if (a[i].ss >= ans)
			ans = a[i].ss;
		else
			ans = a[i].ff;
	}
	cout << ans;
}
 
