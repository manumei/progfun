method PeasantMul(a: nat, b: nat) returns (p: nat)
  ensures p == a*b
{
  var x := a;
  var y := b;
  p := 0;
  while y > 0
    invariant a*b == p + x*y
    decreases y
  {
    p := p + (y%2) * x;
    x := x*2;
    y := y/2;
  }
}