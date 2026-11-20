method problem2(a: int, b: int) returns (r: int, s: int)
  requires a%2 == b%2
  ensures r + s == a && r - s == b
{
  r := (a+b)/2;
  s := a-r;
}

method problem4(a: nat, b: nat, c: nat) returns (x: nat, y: nat, z: nat)
  ensures x <= y <= z
  ensures x + y + z == a + b + c
{
  x,y,z := a,b,c;
  while (x>y) || (y>z)
    invariant x+y+z == a + b + c
    decreases a+b+c - (z-x)
  {
    if x > y
    {
      x := x - 1;
      y := y + 1;
    }

    if y > z
    {
      y := y - 1;
      z := z + 1;
    }
  }
}

ghost function f(n: int): int
{
  if n < 2 then n
  else if n%2 == 0
  then 3*f(n/2) + n
  else 2*f(n/2) + 1
}

method problem5(n: nat) returns (x: int)
  ensures x == f(n)
{
  if n == 0 {
    x := n;
    return;
  }
  // a for f(n), b for constants
  var k,a,b := n, 1, 0;
  while k > 0
    // invariant k >= 0
    invariant f(n) == a*f(k) + b
  {
    var m := k/2;
    match k%2
    {
      case 0 => assert k==2*m;
      // f(k) = 3*f(k/2) + k
      // f(k) = 3*f(m) + 2*m
      // invariant --> f(n) = a*f(k)+b
      // f(n) = a*(3*f(m) + 2*m) + b
      // f(n) = 3*a*f(m) + 2*m*a + b
      b := b + 2*m*a;
      a := 3*a;
      k := m;

      case 1 => assert k==2*m+1;
      // // f(k) = 2*f(k/2) + 1
      // f(k) = 2*f(m) + 1
      // invariant --> f(n) = a*f(k)+
      // f(n) = a*(2*f(m) + 1) + b
      // f(n) = 2*a*f(m) + a + b
      b := b+a;
      a := 2*a;
      k := m;
    }
  }
  // when k=0, then f(n)=a*f(0)+b, and f(0)=0 so f(n)=b
  x := b;
}