/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
function f(n: nat): nat {
  if n == 0 then 1
  else if n%2 == 0 then 1 + 2*f(n/2)
  else 2*f(n/2)
}
method computeF(m: nat) returns (a: nat)
  ensures a == f(m)
{
  a := 0;
  var n: nat := m;
  var p: nat := 1;

  while n > 0
    // f(m) = a + p*f(n)
    // a = already calculated.
    // p*f(n) = remaining recursive computation.
    invariant a + p*f(n) == f(m)
    invariant p >= 1
  {
    if n % 2 == 0 {
      a := a + p; // even case is 1+f(n/2) so add p to a
    } // odd case is 2*f(n/2) so no adding, just p*=2
    p := 2 * p;
    n := n / 2;
  }
  // f(m) = a + p*f(n) but n=0 and f(0)=1, so f(m) = a + p*1
  a := a + p;
}