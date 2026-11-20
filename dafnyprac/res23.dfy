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