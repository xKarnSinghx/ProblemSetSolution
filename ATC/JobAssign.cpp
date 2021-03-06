/*
B - Job Assignment  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
Your company has 
N
 employees, called Employee 
1
 through 
N
.
You have received two work orders, called Work A and B, which must be completed.
Employee 
i
 can complete Work A in 
A
i
 minutes and Work B in 
B
i
 minutes.

You will assign each work to one employee.
You can assign both works to the same employee, in which case the time it takes for him/her to complete them is the sum of the times it takes for him/her to do them individually.
If you assign the works to different employees, the time it takes for them to complete them is the longer of the times it takes for them to do their respective works.
Find the shortest possible time needed to complete the works.

Constraints
2
≤
N
≤
1000
1
≤
A
i
≤
10
5
1
≤
B
i
≤
10
5
All values in input are integers.
Input
Input is given from Standard Input in the following format:

N

A
1
 
B
1

A
2
 
B
2

A
3
 
B
3

⋮

A
N
 
B
N

Output
Print the shortest possible time needed to complete the works, in minutes.

Sample Input 1 
Copy
3
8 5
4 4
7 9
Sample Output 1 
Copy
5
If you assign Work A to Employee 
2
 and Work B to Employee 
1
, they will complete them in 
4
 and 
5
 minutes, respectively.
Since you assigned the works to different employees, it will take 
max
(
4
,
5
)
=
5
 minutes for the two works to be finished.
It is impossible to finish them earlier.

Sample Input 2 
Copy
3
11 7
3 2
6 7
Sample Output 2 
Copy
5
It is optimal to assign both works to Employee 
2
.
Note that if you assign both works to the same employee, the time it takes for him/her to complete them is the sum of the times it takes for him/her to do them individually.


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


		solve();
	

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
	ll a[n], b[n], s[n];
	foi(n) {
		cin >> a[i] >> b[i];
		s[i] = a[i] + b[i];
	}
	ll ans = 111111, x = 0, mn = 111111;
	foi(n) {
		if (mn < a[i])
			continue;
		else
		{	mn = a[i];
			x = i;
		}
	}
	foi(n) {
		if (mn + b[x] >  b[i] and i != x)
			ans = min(ans, max(mn, b[i]));
		else
			ans = min( ans, mn + b[i]);
	}

	cout << ans;
}



