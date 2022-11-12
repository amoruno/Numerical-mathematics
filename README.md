# Numerical-mathematics

Here you will find some numerical mathematics and algorithms problems I solved in C. The mathematical setup of the problem is posed and the reasoning of the solution proposed. Tools on: dynamic memory allocation, structs, dynamic structs, are widely used in the solutions.

## Index

1. [Geometric median](#Geometric-median): programming of a numerical iterative algorithm to compute the geometric median of any given set of points in $\mathbb{R}^n$.
2. [Cycles of a permutation](#Cycles-of-a-permutation): check that a permutation of a given set is correct and print all its associated cycles.


### Geometric median

Let $n, m \ge 1$ two fixed natural numbers. Given $m$ points in $\mathbb{R}^n$, $q^{(j)}$ $\forall j = 0,...,m-1$, define the **geometric median** as the point $x \in \mathbb{R}^n$ for which it verifies $f(x) \leq f(z)$ $\forall z \in \mathbb{R}^n$, where the function $f: \mathbb{R}^n \to \mathbb{R}$ is defined by $f(x) = \sum_{0 \leq j \leq m-1} d(x, q^{(j)})$. The distance $d: \mathbb{R}^n \times \mathbb{R}^n \to \mathbb{R}^{+}$ indicates the euclidean distance between two points i.e $x, y \in \mathbb{R}^n$ then $d(x,y) = \left(\sum_{0 \leq i \leq n-1} (x_i -y_i)^2 \right) ^{1/2}$.

We assume the existence and unicity of the geometric median and apply an iterative algorithm to find the solution with a precision *prec* (for instance $10^{-6}$). 

- (i) *Initial approximation*. Compute the *barycenter* $x$ of the $m$ points $q^{(j)}$. 

$$
q^{(j)} = (q_0^{(j)}, ..., q_{n-1}^{(j)}) \space \forall j = 0,...,m-1, \text{then the barycenter } x=(x_0,...,x_{n-1})
$$

$$
\text{defined component-wise as } x_i = \frac{1}{m} \sum_{0 \leq j \leq m-1} q_i^{(j)} \space \forall i = 0,...,n-1.
$$

$f(x)$ is computed, and an initial step $h$ is chosen (for instance $10^{-1}$).

- (ii) *Successive updates* *of* $x$ *or* $h$. We name neighbours within distance $h$ of $x$ to the $2n$ points of $\mathbb{R}^n$ such that differ from $x$ only on a single component, and such difference is $\pm h$. Consider all neighbours $z$ of $x$, one by one, in a determined order.

- If, in any neighbour $z$, $f(z) < f(x)$, then the new approximation $x$ is updated to be $z$ and go back again to compute a new approximation (ii). Otherwise, we stop looking for other neighbours. 

- Otherwise, if the value of $f(z)$ does not decrease with respect to the value $f(x)$, in any of the $2n$ neighbours, then no update is made to the approximation of $x$, instead we update the step $h$ dividing it by $10$. In this case, two possibilities arise:
  - If $h \geq prec$ holds true, a new update of (ii) of x, with the number step value $h$.
  - Otherwise if $h < prec$, the update process is finished: the approximate solution with the required precision is attained.

The program must define a precision and the maximum number of iterations allowed, for instance *itermax* = 1000. During the updates (ii) one must count the number of updates of $x$, in case the maximum number of iterations is reached, the iterative procedure stops without obtaining the solution with the required precision. 

### Cycles of a permutation

Given a set $\mathbb{X} =$ {0, 1, ..., n-1}, where $n \in \mathbb{N}$, if $P$ is a permutation from the set $\mathbb{X}$, we will check that:

- The permutation $P$ is correct.
- Find and print all the cycles of the permutation $P$. A cycle is a subset of elements of $P$ that map to each other in a cyclic fashion, i.e a permutation $P =$ {0, 2, 1 }, of a set $\mathbb{X}$ = {0, 1, 2}, would have two cycles: $c_1 =$ {0}, $c_2 =$ {2, 1}

For the first point, I based the solution on the following observation: if $P$ is a permutation of $\mathbb{X}$ = {0, 1, ..., n-1} it must hold that both $card(P) = card(\mathbb{X})$ and $\sum_{0 \leq i \leq n-1} x_i = \sum_{0 \leq i \leq n-1} p_i$, otherwise $P$ cannot be a permutation of such set $\mathbb{X}$.

For the second point, I based the solution on the following observation: given two different cycles $c_1$ and $c_2$ of a permutation P then $c_1 \cap c_2 = \phi$, otherwise $c_1 = c_2$. 
