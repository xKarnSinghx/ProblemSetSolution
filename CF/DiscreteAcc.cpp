/*
C. Discrete Acceleration
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a road with length l meters. The start of the road has coordinate 0, the end of the road has coordinate l.

There are two cars, the first standing at the start of the road and the second standing at the end of the road. They will start driving simultaneously. The first car will drive from the start to the end and the second car will drive from the end to the start.

Initially, they will drive with a speed of 1 meter per second. There are n flags at different coordinates a1,a2,…,an. Each time when any of two cars drives through a flag, the speed of that car increases by 1 meter per second.

Find how long will it take for cars to meet (to reach the same coordinate).

Input
The first line contains one integer t (1≤t≤104): the number of test cases.

The first line of each test case contains two integers n, l (1≤n≤105, 1≤l≤109): the number of flags and the length of the road.

The second line contains n integers a1,a2,…,an in the increasing order (1≤a1<a2<…<an<l).

It is guaranteed that the sum of n among all test cases does not exceed 105.

Output
For each test case print a single real number: the time required for cars to meet.

Your answer will be considered correct, if its absolute or relative error does not exceed 10−6. More formally, if your answer is a and jury's answer is b, your answer will be considered correct if |a−b|max(1,b)≤10−6.

Example
inputCopy
5
2 10
1 9
1 10
1
5 7
1 2 3 4 6
2 1000000000
413470354 982876160
9 478
1 10 25 33 239 445 453 468 477
outputCopy
3.000000000000000
3.666666666666667
2.047619047619048
329737645.750000000000000
53.700000000000000
Note
In the first test case cars will meet in the coordinate 5.

The first car will be in the coordinate 1 in 1 second and after that its speed will increase by 1 and will be equal to 2 meters per second. After 2 more seconds it will be in the coordinate 5. So, it will be in the coordinate 5 in 3 seconds.

The second car will be in the coordinate 9 in 1 second and after that its speed will increase by 1 and will be equal to 2 meters per second. After 2 more seconds it will be in the coordinate 5. So, it will be in the coordinate 5 in 3 seconds.

In the second test case after 1 second the first car will be in the coordinate 1 and will have the speed equal to 2 meters per second, the second car will be in the coordinate 9 and will have the speed equal to 1 meter per second. So, they will meet after 9−12+1=83 seconds. So, the answer is equal to 1+83=113.


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
	ll n, k;
	cin >> n >> k;
	ll a[n];
	foi(n)
	cin >> a[i];
	ll l = 0, r = n - 1, ls = 1, lr = 1;
	ld t = 0, dl = 0, dr = (ld)k;
	while (l <= r) {
		ld x = ((ld)a[l] - dl) / (ld)ls;
		ld y = (dr - (ld)a[r]) / (ld)lr;
		if (x >= y) {
			t += y;
			dr -= y * lr;
			dl += y * ls;
			lr++;
			r--;
		}
		else {
			t += x;
			dl += x * ls;
			dr -= x * lr;
			ls++;
			l++;
		}
	}
	cout << fixed << setprecision(15) << t + ((dr - dl) / (ls + lr));

}
