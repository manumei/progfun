/* file : dafny_specification_2.dfy */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 10-11-2026 */

method exercise3(x: int) returns (y: int)
  ensures y>=1 && (y==x || y == 1 - x)
{
  if x > 0 {
    y := x;
  } else {
    y := 1 - x;
  }
}