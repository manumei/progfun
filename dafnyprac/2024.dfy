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