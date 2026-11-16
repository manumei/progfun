/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */

ghost function f(n: nat): int
{
  if n == 0 then 1
  else f(n-1) + 3*n*n + 3*n + 1
}
ghost predicate toProve(n: nat)
{
  f(n) == (n+1)*(n+1)*(n+1)
}
method InductionProof(n: nat)
  ensures toProve(n)
{
  var i := 0;
  while i < n
    invariant 0<=i<=n && toProve(i)
  {
    i := i + 1;
  }
}