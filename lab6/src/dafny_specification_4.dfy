/* file : dafny_specification_4.dfy */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 07-11-2026 */

method exercise5(x: int, ghost X:int) returns (y: int)
  requires x>0 && (x==2*X + 7 || x == 2*X + 2)
  ensures y == X
{
  if x%2 == 0 {
    y := (x-2)/2;
  } else {
    y := (x-7)/2;
  }
}