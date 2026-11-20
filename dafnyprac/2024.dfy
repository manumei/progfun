method problem2(a:int, b:int, ghost X:int, ghost Y:int) returns (c:int, d : int)
  requires a == 2*X - 5*Y && b == X + 2*Y
  ensures c == X && d == Y
{
  d := (2*b-a)/9;
  c := b - 2*d;
}

method problem3(a: int, n:int, ghost X: int) returns (b:int)
  requires a == 2*X - n || a == 3*n - 2*X + 1
  ensures b == X
{
  var s := a+n;
  if (s%2)==0 {
    b := s/2;
  } else {
    b := (3*n - a + 1)/2;
  }
}

method problem4(a: nat, b:nat)
  requires a >= b
{
  var x := a;
  var y := b;
  while x != y
    invariant x >= y   // choose a suitable invariant
    decreases x-y   // choose a suitable variant function
  {
    y := y + 1;
    x := x - x % y;
  }
  assert x == y;
}

ghost function f(x: nat): nat
{
  // you are not allowed to remove 'ghost', so an assignment
  // like x := f(n) is not allowed.
  if x < 2 then 1
  else if x % 2 == 0 then 2*f(x/2) + 1
  else 3 * f(x/2) - 2
}

method problem5(n: nat) returns (x: nat)
  ensures x == f(n)
{
  if n == 0 {
    x := 1;
    return;
  }

  /*
  for even x -- 2*f(x/2)+1
  for odds x -- 3*f(x/2)-2
  we can assign a k=n and halve it every turn, then
  we need factors a,b to keep track of f() calls and constants
  such that for the current k, it holds that f(n) = a*f(k)+b
  initialization is trivial, since k=n, then a=1 and b=0 so f(n)=1*f(n)
  */
  var a,b,k := 1,0,n;
  while k>0
    invariant k>=0
    invariant a*f(k)+b == f(n)
  {
    if k%2==0 {
      // f(k) = 2*f(k/2)+1
      // f(n) = a*f(k)+b
      // f(n) = a*(2*f(k/2) + 1)+b
      // f(n) = 2*a*f(k/2) + a + b
      b := a+b;
      a := 2*a;
    } else {
      // f(k) = 3*f(k/2)-2
      // f(n) = a*f(k)+b
      // f(n) = a*(3*f(k/2) - 2)+b
      // f(n) = 3*a*f(k/2) - 2a + b
      b := b - 2*a;
      a := 3*a;
    }
    k := k/2;
  }
  // last case is k=0, so a*f(0)+b, so a+b
  x := a+b;
}