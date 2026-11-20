// problem 2:
// name:      ....... (fill in your name)
// s-number: s....... (fill in your student number)
// table:     ....... (fill in your table number)

method problem2(a: int, b: int) returns (r: int, s: int)
  requires a%2 == b%2
  ensures r + s == a && r - s == b
{
  r := (a+b)/2;
  s := (a-b)/2;
}
