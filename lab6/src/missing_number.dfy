/* file : missing_number.dfy */
/* author : Manuel Meiriño (m.meirino.ferro@student.rug.nl) */
/* date : 07-11-2026 */

include "io.dfy"

method Main()
{
  var total: int := 0;

  for i := 0 to 9
  {
    var number := IO.ReadNat();
    total := total + number;
  }

  var missing: int := 45 - total;
  print missing, "\n";
}