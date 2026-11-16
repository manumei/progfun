/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
ghost function exp(n: nat, e: nat): nat
{
  if e == 0 then 1 else n * exp(n, e - 1)
}
method intLog(n: nat, b: nat) returns (k: nat)
  requires n > 0 && b > 1
  ensures exp(b, k) <= n < exp(b, k+1)
{
  // implement yourself
  k := 0;
  var power := 1;
  while power * b <= n
    invariant exp(b, k) == power && exp(b, k) <= n
  {
    power := power * b;
    k := k + 1;
  }
}