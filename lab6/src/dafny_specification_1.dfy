/* file : dafny_specification_1.dfy */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 07-11-2026 */

method exercise2(x: int, ghost X: int) returns (y: int)
  requires 7*X - 3 < x < 7*X + 5
  ensures y == X
{
  assert 7*X - 2 <= x < 7*X + 7 - 2;
  y := (x+2)/7;
}
