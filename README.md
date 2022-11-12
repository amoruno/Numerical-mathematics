# Numerical-mathematics

Here you will find some numerical mathematics and algorithms problems I solved in C. The mathematical setup of the problem is posed and the reasoning of the solution proposed. Tools on: dynamic memory allocation, structs, dynamic structs, are widely used in the solutions.

## Index

1. [Geometric median](#Geometric-median): programming of a numerical iterative algorithm to compute the geometric median of any given set of points in $\mathbb{R}^n$.
2. [Cycles of a permutation](#Cycles-of-a-permutation)
3. [Third Example](#third-example)
4. [Fourth Example](#fourth-examplehttpwwwfourthexamplecom)

### Geometric median

Let $n, m \ge 1$ two fixed natural numbers. Given $m$ points in $\mathbb{R}^n$, $q^{(j)}$ $\forall j = 0,...,m-1$, define the **geometric median** as the point $x \in \mathbb{R}^n$ for which it verifies $f(x) \leq f(z)$ $\forall z \in \mathbb{R}^n$, where the function $f: \mathbb{R}^n \to \mathbb{R}$ is defined by $f(x) = \sum_{0 \leq j \leq m-1} d(x, q^{(j)})$

<img width="789" alt="image" src="https://user-images.githubusercontent.com/109459201/179391883-828cf6d9-a9d0-4123-b8d1-a41b38b4864f.png">


### Cycles of a permutation

Given a set $\mathbb{X} =$ {0, 1, ..., n-1}, where $n \in \mathbb{N}$, if $P$ is a permutation from the set $\mathbb{X}$, we will check that:

- The permutation $P$ is correct.
- Find and print all the cycles of the permutation $P$. A cycle is a subset of elements of $P$ that map to each other in a cyclic fashion, i.e a permutation $P =$ {0, 2, 1 }, of a set $\mathbb{X}$ = {0, 1, 2}, would have two cycles: $c_1 =$ {0}, $c_2 =$ {2, 1}

For the first point, I based the solution on the following observation: if $P$ is a permutation of $\mathbb{X}$ = {0, 1, ..., n-1} it must hold that both $card(P) = card(\mathbb{X})$ and $\sum_{0 \leq i \leq n-1} x_i = \sum_{0 \leq i \leq n-1} p_i$, otherwise $P$ cannot be a permutation of such set $\mathbb{X}$.

For the second point, I based the solution on the following observation: given two different cycles $c_1$ and $c_2$ of a permutation P then $c_1 \cap c_2 = \phi$, otherwise $c_1 = c_2$. 
