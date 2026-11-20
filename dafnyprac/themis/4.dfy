// problem 4:
// name:      ....... (fill in your name)
// s-number: s....... (fill in your student number)
// table:     ....... (fill in your table number)

method problem4(a: nat, b: nat, c: nat) returns (x: nat, y: nat, z: nat)
  ensures x <= y <= z
  ensures x + y + z == a + b + c
{
  x,y,z := a,b,c;
  while (y < x) || (z < y)
    invariant x+y+z == a + b + c
    // x-z always decreases because either x gets smaller or z gets larger (or both)
    // but it might not start as 0, so add a fixed value that is definitely bigger than x-z
    decreases x-z+a+b+c
  {
    if x > y {
      x := x - 1;
      y := y + 1;
    }
    if y > z {
      y := y - 1;
      z := z + 1;
    }
  }
}
