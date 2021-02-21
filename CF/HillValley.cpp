/*
B. Hills And Valleys
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a sequence of n integers a1, a2, ..., an. Let us call an index j (2≤j≤n−1) a hill if aj>aj+1 and aj>aj−1; and let us call it a valley if aj<aj+1 and aj<aj−1.

Let us define the intimidation value of a sequence as the sum of the number of hills and the number of valleys in the sequence. You can change exactly one integer in the sequence to any number that you want, or let the sequence remain unchanged. What is the minimum intimidation value that you can achieve?

Input
The first line of the input contains a single integer t (1≤t≤10000) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤3⋅105).

The second line of each test case contains n space-separated integers a1, a2, ..., an (1≤ai≤109).

It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

Output
For each test case, print a single integer — the minimum intimidation value that you can achieve.

Example
inputCopy
4
3
1 5 3
5
2 2 2 2 2
6
1 6 2 5 2 10
5
1 6 2 5 1
outputCopy
0
0
1
0
Note
In the first test case, changing a2 to 2 results in no hills and no valleys.

In the second test case, the best answer is just to leave the array as it is.

In the third test case, changing a3 to 6 results in only one valley (at the index 5).

In the fourth test case, changing a3 to 6 results in no hills and no valleys.
*/
#include<bits/stdc++.h>
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
void solve();
ll n;
ll a[1111111];
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

ll v(ll i) {
	return (i > 0 && i < n - 1 && a[i] < a[i - 1] && a[i] < a[i + 1]);
}

ll h(ll i) {
	return (i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]);
}
void solve()

{

	cin >> n;

	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll is[n] = {} ;
	ll s = 0;
	for (ll i = 1; i < n - 1; i++) {
		if (h(i) || v(i))
			is[i] = 1, s++;
	}

	ll ans = s;
	for (ll i = 1; i < n - 1; i++) {
		ll temp = a[i];
		a[i] = a[i - 1];
		ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + h(i - 1) + v(i - 1) + h(i) + v(i) + h(i + 1) + v(i + 1));
		a[i] = a[i + 1];
		ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + h(i - 1) + v(i - 1) + h(i) + v(i) + h(i + 1) + v(i + 1));
		a[i] = temp;
	}

	cout << ans ;

}

 
