/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
method exercise6(ghost X: int, y: int) returns (z: int)
  requires 2*X - y == 3 || 4*X + y == 42
  ensures z == X
{
  if y%2 != 0
  {
    z := (y + 3)/2;
  } else
  {
    z := (42 - y)/4;
  }
}