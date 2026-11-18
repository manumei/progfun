include "io.dfy"
ghost function f(n: nat): int
{
  if n == 0 then 1
  else if n == 1 then 1
  else if n % 2 == 0 then f(n/2) - f(n/2 - 1)
  else f(n/2) + n/2
}

method computeF(m: nat) returns (x: int)
  ensures x == f(m)
{
  if m == 0 {
    x := 1;
    return;
  }
  // a for f(n), b for f(n-1), c for constants
  var n, a, b, c := m, 1, 0, 0;

  while n > 1
    invariant n >= 1
    invariant f(m) == a * f(n) + b * f(n - 1) + c
  {
    var k := n / 2;

    if n % 2 == 0 {
      a, b, c := a, b - a, c + b * (k - 1);
    }
    else {
      a, b, c := a + b, -b, c + a * k;
    }

    n := k;
  }
  x := a + b + c;
}

method Main()
{
  var n: int := 0;
  while n < 20
  {
    var fn := computeF(n);
    print "fusc(", n, ")=", fn, ".\n";
    n := n + 1;
  }
}