/*
E. Maximum Subsequence Value
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ridhiman challenged Ashish to find the maximum valued subsequence of an array a of size n consisting of positive integers.

The value of a non-empty subsequence of k elements of a is defined as ∑2i over all integers i≥0 such that at least max(1,k−2) elements of the subsequence have the i-th bit set in their binary representation (value x has the i-th bit set in its binary representation if ⌊x2i⌋mod2 is equal to 1).

Recall that b is a subsequence of a, if b can be obtained by deleting some(possibly zero) elements from a.

Help Ashish find the maximum value he can get by choosing some subsequence of a.

Input
The first line of the input consists of a single integer n (1≤n≤500) — the size of a.

The next line consists of n space-separated integers — the elements of the array (1≤ai≤1018).

Output
Print a single integer — the maximum value Ashish can get by choosing some subsequence of a.

Examples
inputCopy
3
2 1 3
outputCopy
3
inputCopy
3
3 1 4
outputCopy
7
inputCopy
1
1
outputCopy
1
inputCopy
4
7 7 1 1
outputCopy
7
Note
For the first test case, Ashish can pick the subsequence {2,3} of size 2. The binary representation of 2 is 10 and that of 3 is 11. Since max(k−2,1) is equal to 1, the value of the subsequence is 20+21 (both 2 and 3 have 1-st bit set in their binary representation and 3 has 0-th bit set in its binary representation). Note that he could also pick the subsequence {3} or {2,1,3}.

For the second test case, Ashish can pick the subsequence {3,4} with value 7.

For the third test case, Ashish can pick the subsequence {1} with value 1.

For the fourth test case, Ashish can pick the subsequence {7,7} with value 7.*/
