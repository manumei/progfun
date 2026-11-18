method terminationPuzzle(a: nat, b: nat, c: nat)
  returns (x: nat, y: nat, z: nat)
  ensures x == y == z == 0
{
  x, y, z := a, b, c;
  while x > 0 || y > 0 || z > 0
    invariant x >= 0 && y >= 0 && z >= 0
    decreases x*x + 2*y + z
  {
    if x > 0 {
      y := y + x - 1;
      x := x - 1;
    } else if y > 0 {
      y := y - 1;
      z := z + 1;
    } else {
      z := z - 1;
    }
  }
}