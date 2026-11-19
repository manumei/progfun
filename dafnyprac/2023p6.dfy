ghost function f(n: nat): int
{
  if n <= 1 then n else 2 * f(n - 1) + 3 * f(n - 2)
}

ghost function fSum(n: nat): int
{
  if n == 0 then 0 else f(n-1) + fSum(n-1)
}

method problem6(n: nat) returns (a: int)
  ensures a == fSum(n)
{
  var k, x, y;
  a, k, x, y := 0, 0, 0, 1;   // initialize these variables

  while k < n
    invariant 0 <= k <= n && x == f(k)
              && y == f(k + 1) && a == fSum(k)
  {
    k := k + 1;
    // complete the rest of this method
    a := a + x;
    y, x := 2*y + 3*x, y;
  }
}