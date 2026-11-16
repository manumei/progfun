/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
ghost function f(n: nat): int
{
  if n <= 1 then n
  else 4*(f(n-1) - f(n-2))
}
ghost function Pow(x: nat, y: nat): nat
{
  if y == 0 then 1
  else x*Pow(x, y-1)
}
ghost predicate toProve(n: nat)
{
  (n >= 1) ==> (f(n) == n * Pow(2, n - 1))
}
method InductionProof(n: nat)
  requires n >= 1
  ensures toProve(n)
{
  var i := 1;
  while i < n
    invariant 1<=i<=n && toProve(i) && (i == 1 || toProve(i - 1))
  {
    i := i + 1;
  }
}