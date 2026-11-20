method problem2(a: int, b: int) returns (r: int, s: int)
  requires a%2 == b%2
  ensures r + s == a && r - s == b
{
  r := (a+b)/2;
  s := a-r;
}

