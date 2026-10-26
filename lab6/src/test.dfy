
method Increment(x: int) returns (y: int)
  ensures y == x + 1
{
  y := x + 1;
}

method Main()
{
  var result := Increment(4);
  assert result == 5;
  print result, "\n";
}
