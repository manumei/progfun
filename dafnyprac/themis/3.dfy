// problem 3:
// name:      ....... (fill in your name)
// s-number: s....... (fill in your student number)
// table:     ....... (fill in your table number)

method problem3(n: int) returns (a: int, b: int, c: int)
  ensures a + b + c == n
  ensures a < b + 1 < c + 2 < a + 4
{
  match n%3 {
    case 0 =>
      a := n/3 + 0;
      b := n/3 + 0;
      c := n/3 + 0;
    case 1 =>
      a := n/3 + 0;
      b := n/3 + 0;
      c := n/3 + 1;
    case 2 =>
      a := n/3 + 0;
      b := n/3 + 1;
      c := n/3 + 1;
  }
}
