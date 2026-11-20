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