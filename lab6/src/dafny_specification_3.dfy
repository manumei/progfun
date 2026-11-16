/* file : dafny_specification_3.dfy */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 10-11-2026 */

method exercise4(x: int) returns (y: int)
  ensures y>0 && (y==2*x + 1 || y == -2*x)
{
  if x >= 0 {
    y := 2*x + 1;
  } else {
    y := -2*x;
  }
}