/*
E. Restorer Distance
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have to restore the wall. The wall consists of N pillars of bricks, the height of the i-th pillar is initially equal to hi, the height is measured in number of bricks. After the restoration all the N pillars should have equal heights.

You are allowed the following operations:

put a brick on top of one pillar, the cost of this operation is A;
remove a brick from the top of one non-empty pillar, the cost of this operation is R;
move a brick from the top of one non-empty pillar to the top of another pillar, the cost of this operation is M.
You cannot create additional pillars or ignore some of pre-existing pillars even if their height becomes 0.

What is the minimal total cost of restoration, in other words, what is the minimal total cost to make all the pillars of equal height?

Input
The first line of input contains four integers N, A, R, M (1≤N≤105, 0≤A,R,M≤104) — the number of pillars and the costs of operations.

The second line contains N integers hi (0≤hi≤109) — initial heights of pillars.

Output
Print one integer — the minimal cost of restoration.

Examples
inputCopy
3 1 100 100
1 3 8
outputCopy
12
inputCopy
3 100 1 100
1 3 8
outputCopy
9
inputCopy
3 100 100 1
1 3 8
outputCopy
4
inputCopy
5 1 2 4
5 5 3 6 5
outputCopy
4
inputCopy
5 1 2 2
5 5 3 6 5
outputCopy
3

*/
