method SumSum(n: nat) returns (s: nat)
  ensures s == n*(n + 1)*(n + 2)/6
{
  var i := 0;
  var t := 0;
  s := 0;
  while i < n
    invariant 2*t==i*(i+1) && (6*s == i*(i + 1)*(i + 2)) && (i <= n)
  {
    i := i + 1;
    t := t + i;
    s := s + t;
  }
}