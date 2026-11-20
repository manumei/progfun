method problem2(m:int, n:int, X:int, Y:int) returns (x:int, y:int)
  requires 3*m + 2*n == 2*X + Y && 2*m == X + Y
  ensures x==X && y == Y
{
  x := m + 2*n;
  y := 2*m - x;
}

method problem3(n:int, m:int, X:int, Y: int) returns (p:int, q:int)
  requires X >= 0 && (n == X + 3 || n == -X) && n*n + m == Y
  ensures p == X && p*p + q == Y
{
  if n<=0 {
    p := -1*n;
    q := m;
  } else {
    p := n-3;
    q := n*n + m - (n-3)*(n-3);
  }
}

ghost function f(a: nat, b: nat): nat
{
  if a == 0
  then 1
  else if a % 2 == 0
    then f(a / 2, b * b)
    else b * f(a - 1, b)
}

method problem5(a: nat, b:nat) returns (r: nat)
  ensures r == f(a, b)
{
  r := 1;
  if a == 0 {
    return;
  }

  // function gives b^a
  // we keep track of r the accumulated product
  // such that r*f(i,z) = f(a,b)
  // where i is the exponent left to process, and z is the base being exponentiated
  // eventually i=0, so r*f(0,z) = r = f(a,b)
  var i, z := a, b;

  while i>0
    invariant r*f(i,z) == f(a,b)
    decreases i
  {
    if i%2==0 {
      // even case, half the exponent and square the base
      i := i/2;
      z := z*z;
      // since f(i/2,z*z)==f(i,z) for all i%2==0, we dont need to change r
    } else {
      // odd case, mult by base and decrease exponent
      i := i-1;
      // base stays, but we still need r*f(i,z)=f(n)
      // so now we gotta change r such that r*f(i-1,z)=f(i,z)
      // so multiply r by z
      r := r*z;
    }
  }
}