ghost function pow2(e: nat) : nat
{
  if e == 0 then 1 else 2*pow2(e - 1)
}
method Mersenne(n: nat) returns (m: nat)
  ensures m == pow2(n) - 1
{
  m := 0;
  var i := 0;
  while i < n
    invariant (i <= n) && (m == pow2(i) - 1)
  {
    m := 2*m + 1;
    i := i + 1;
  }
}