method problem2(m:int, n:int, ghost X:int, ghost Y:int) returns (x:int, y:int)
  requires m + n == 3*X + 2*Y && 2*m + 3*n == 5*X + 7*Y
  ensures x==X && y == Y
{
  x := (3*m+n)/11;
  y := (2*m+3*n-5*x)/7;
}

method problem3(n:int, ghost X: int) returns (r:int)
  requires n == X
  ensures r >= 0 && (r + X == 0 || 3*r <= X + 1 < 3*(r + 1))
{
  if n<0 {
    r := -1*n;
  } else {
    r :=(n+1)/3;
  }
}

method problem4(a:nat, b:nat) returns (x:nat)
  requires a > 0 && b > 0
{
  var y:nat;
  x := a;
  y := b;

  while x != y
    // find a suitable invariant and decreases clause such
    // that Dafny is able to prove termination
    invariant x>0 && y>0
    decreases x+y
  {
    if x > y
    {
      x := x - y;
    }
    else
    {
      y := y - x;
    }
  }
}

ghost function f(x: nat): int
{
  // you are not allowed to remove 'ghost'.
  if x <= 2 then 1
  else if x % 3 == 0 then 3*f(x/3 + 1) + 1
  else if x % 3 == 1 then 2*f(x/3) - 1
  else 2*f(x/3 + 1) - 1
}
// Note that:
// f(1)==f(3*0+1)=2*f(0)-1=2-1=1
// f(2)==f(3*0+2)=2*f(0+1)-1=2*f(1)-1=2-1=1

method problem5(n: nat) returns (x: int)
  ensures x == f(n)
{
  var y:int, z: int, k: nat;
  x,y,k := 1,0,n;   // initialize yourself

  while k>0              // choose a suitable guard
    invariant 0 <= k && x*f(k) + y == f(n)
    decreases k        // choose a suitable variant function
  {
    var m := k/3;
    match k % 3
    {
      case 0 => assert 3*m == k;
      y := y + x;
      x := 3*x;
      k := m + 1;
      case 1 => assert 3*m + 1 == k;
      y := y-x;
      x := 2*x;
      k := m;
      case 2 => assert 3*m + 2 == k;
      y := y-x;
      x := 2*x;
      k := m+1;
    }
  }
  x := x+y;
}