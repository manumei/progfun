ghost function Pow(a: nat, e: nat) : nat {
  if e==0 then 1 else a*Pow(a, e-1)
}
method GeometricSeries(r: nat, n: nat) returns (s: nat)
  requires r > 1
  ensures s*(r-1) == Pow(r, n) - 1
{
  var i := 0;
  var pow := 1;
  s := 0;
  while i < n
    invariant i <= n && (pow == Pow(r,i))
    invariant s*(r - 1) == pow - 1
  {
    s := s + pow;
    pow := pow * r;
    i := i + 1;
  }
}