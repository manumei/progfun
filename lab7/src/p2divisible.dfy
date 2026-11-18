method DivisibleBy3(n: nat) returns (res: bool)
  ensures res == (n%3 == 0)
{
  var x, sum := n, 0;
  while x > 0
    invariant (n%3 == (sum+x)%3)
    decreases x
  {
    sum := sum + x%10;
    x := x/10;
  }
  res := (sum%3 == 0);
}