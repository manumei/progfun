method problem2(n:int, t:int, X:int, Y:int) returns (r:int, s:int)
  requires n == Y + 1 && t == X + 2 * Y
  ensures r == X && s == Y
{
  s := n - 1;
  r := t - 2*s;
}

method problem3(n:int, X:int) returns (r:int)
  requires X >= 0 && (n == 2 * X + 5 || 2 * n == 9 - X)
  ensures r == X
{
  if n>=5 {
    r := (n-5)/2;
  } else {
    r := 9 - 2*n;
  }
}

method problem4(a: int, b: int, c: int) returns (i: int, j: int, k: int)
  requires a <= b <= c
  ensures i == j == k
{
  i, j, k := a, b, c;
  while i < j || j < k
    invariant (i<=j) && (j<=k)      // choose a suitable invariant
    decreases (2*k - i -j)     // choose a suitable variant function
  {
    if i < j
    {
      i := i + 1;
    }
    else
    {
      if j < k
      {
        j := j + 1;
      }
      else
      {
        k := k + 1;
      }
    }
  }
}

ghost function f(n: nat): int
{
  if n == 0 then 0 else 2 * f(n / 7) + n % 7
}

method problem5(n: nat) returns (x: int)
  ensures x == f(n)
{

  x := 0;
  var i := 1;
  var k := n;
  while k>0
    invariant f(n) == x + i*f(k)
    decreases k
  {
    x := x + i * (k % 7);
    i := 2*i;
    k := k/7;
  }
}
