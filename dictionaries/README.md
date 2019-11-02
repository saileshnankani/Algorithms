## Dictionary
A dictionary must support these operations:
 - search(k)
 - insert(k,v)
 - delete(k)

 There can be many implementations of the dictionary ADT:

 1. BST:
    Search, insert, and delete are Theta(h),
    so:
    - Best case: Theta(log n)
    - Worst case: Theta(n)
    - Average case: Theta(log n)
 2. AVL
 3. Skip Lists
 
For special keys:

1. Tries
2. Points:
    - Quadtrees
    - kd-Trees
    - Range Trees