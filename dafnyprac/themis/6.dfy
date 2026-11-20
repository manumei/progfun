// problem 6:
// name:      ....... (fill in your name)
// s-number: s....... (fill in your student number)
// table:     ....... (fill in your table number)

ghost function f(n: nat): int {
  if n <= 1
  then n
  else if n%2 == 0
    then 1 + f(n-2)
    else f(n-1) + f(n-3)
}

ghost function fSum(n: nat): int {
  if n == 0 then 0 else f(n - 1) + fSum(n-1)
}

method problem6(n:nat) returns (a: int)
  ensures a == fSum(n)
{
  var k, x, y, z;
  /*
  k is the iterator, starts at 0, finishes at n
  a is the accumulator, initialization is ofc a=fSum(0)=0
  x holds the f(k),   for k=0, f(0) is 0
  y holds the f(k+1), for k=0, f(1) is 1
  z holds the f(k+2), for k=0, f(2) is 1 (1+0)
  */
  a,k,x,y,z := 0, 0, 0, 1, 1;
  while k < n
    invariant 0<=k<=n && x==f(k) && y==f(k+1) && z==f(k+2) && a == fSum(k)
  {
    k := k + 1;
    var even := k%2==0;
    // k became k+1, so x,y,z now hold the old k-1 values
    // CURRNT: x=f(k-1), y=f(k), z=f(k+1)
    // acumulator grows with f(k-1) in each turn, so add x
    a := a+x;
    // TARGET: x=y, y=z, z = f(k+2)
    // If k is even, then z is 1+f(k) = 1+y
    // If k is odd, then z is f(k+1)+f(k-1) = z+x
    x, y, z := y, z, if even then 1+y else z+x;
  }
}
