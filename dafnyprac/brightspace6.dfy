ghost function f(n: nat): int {
  if n <= 2 then 1 else 3*f(n-1) + 2*f(n-2) - f(n-3)
}
ghost function fProd(n: nat): int {
  if n==0 then 1 else f(n-1)*fProd(n-1)
}

method problem6(n:nat) returns (r: int)
  ensures r == fProd(n)
{
  /*
  k is the iterator, it starts as 0 and builds up to n
  r is the cumulative, it holds r==P(k) at any given k, so since k starts as 0, r==P(0) which is 1, r starts as 1
  x will hold the f(k+0), which can be thought as 3*f(k-1)+2*f(k-2)-f(k-3)
  y will hold the f(k+1), which can be thought as 3*f(k)+2*f(k-1)-f(k-2)
  z will hold the f(k+2), which can be thought as 3*f(k+1)+2*f(k)-f(k-1)
  */
  var k, x, y, z;
  r, k, x, y, z := 1, 0, 1, 1, 1; // initialize yourself
  while k < n
    invariant 0<=k<=n && x==f(k) && y==f(k+1) && z==f(k+2) && r == fProd(k)
  {
    k := k + 1;
    // same values, but k has grown by 1, so in terms of the new k:
    // x == f(k-1), y == f(k), z == f(k+1)
    r := r * x; // multiply by f(k-1) each iteration
    // make x=f(k), y=f(k+1), z=f(k+2)
    x, y, z := y, z, 3*z+2*y-x;
  }
}