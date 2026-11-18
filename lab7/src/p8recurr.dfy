ghost function f(n: nat): int
{
  if n <= 1 then 1-n else 2*f(n-1) + f(n-2)
}
method computeF(n: nat) returns (a: int)
  ensures a == f(n)
{
  if n <= 1 {
    a := 1-n;
    return;
  }

  var m := 2;
  var x, y := 0, 1;
  a := 0;
  while m <= n
    invariant (m <= n+1) && (a==x)
    invariant (x==f(m-1)) && (y==f(m-2))
  {
    x, y := 2*x + y, x;
    a := x;
    m := m + 1;
  }
}