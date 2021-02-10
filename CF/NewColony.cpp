/*
B. New Colony
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
After reaching your destination, you want to build a new colony on the new planet. Since this planet has many mountains and the colony must be built on a flat surface you decided to flatten the mountains using boulders (you are still dreaming so this makes sense to you).


You are given an array h1,h2,…,hn, where hi is the height of the i-th mountain, and k — the number of boulders you have.

You will start throwing boulders from the top of the first mountain one by one and they will roll as follows (let's assume that the height of the current mountain is hi):

if hi≥hi+1, the boulder will roll to the next mountain;
if hi<hi+1, the boulder will stop rolling and increase the mountain height by 1 (hi=hi+1);
if the boulder reaches the last mountain it will fall to the waste collection system and disappear.
You want to find the position of the k-th boulder or determine that it will fall into the waste collection system.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

Each test case consists of two lines. The first line in each test case contains two integers n and k (1≤n≤100; 1≤k≤109) — the number of mountains and the number of boulders.

The second line contains n integers h1,h2,…,hn (1≤hi≤100) — the height of the mountains.

It is guaranteed that the sum of n over all test cases does not exceed 100.

Output
For each test case, print −1 if the k-th boulder will fall into the collection system. Otherwise, print the position of the k-th boulder.

Example
inputCopy
4
4 3
4 1 2 3
2 7
1 8
4 5
4 1 2 3
3 1
5 3 1
outputCopy
2
1
-1
-1
Note
Let's simulate the first case:

The first boulder starts at i=1; since h1≥h2 it rolls to i=2 and stops there because h2<h3.
The new heights are [4,2,2,3].
The second boulder starts at i=1; since h1≥h2 the boulder rolls to i=2; since h2≥h3 the boulder rolls to i=3 and stops there because h3<h4.
The new heights are [4,2,3,3].
The third boulder starts at i=1; since h1≥h2 it rolls to i=2 and stops there because h2<h3.
The new heights are [4,3,3,3].
The positions where each boulder stopped are the following: [2,3,2].

In the second case, all 7 boulders will stop right at the first mountain rising its height from 1 to 8.

The third case is similar to the first one but now you'll throw 5 boulders. The first three will roll in the same way as in the first test case. After that, mountain heights will be equal to [4,3,3,3], that's why the other two boulders will fall into the collection system.

In the fourth case, the first and only boulders will fall straight into the collection system.

TAG: brute force    greedy    implementation    *1100
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
void solve()

{
	ll ans, ans1, n, k;
	cin >> n >> k;
	ll a[n], i, j;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (j = 0; j < k; j++) {
		for (i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) {
				a[i - 1] += 1; ans = i; break;
			}
			else ans1 = 5;
		}
		if (ans1 == 5 && i == n) {cout << "-1" ; return;}

	}
	cout << ans ;

}

 
