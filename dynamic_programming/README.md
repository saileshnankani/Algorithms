# Dynamic programming

Method to solve problems that have _optimal substructure_ i.e. need to solve subproblems optimally to solve the original problem. Also need subproblems to overlap, but to not share resources i.e. they are independent. 

Typically, dynamic programming is applied to optimization problems. 

Two equivalent ways to solve a dynamic programming problem:

1. Top-down with memoization:
    Uses recursion, but saves results in a hashtable.
2. Bottom-up:
    Solve smallest subproblems first.  