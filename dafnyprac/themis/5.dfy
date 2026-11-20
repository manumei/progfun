// problem 5:
// name:      ....... (fill in your name)
// s-number: s....... (fill in your student number)
// table:     ....... (fill in your table number)


ghost function f(n: int): int
{
  if n < 2 then n
  else if n%2 == 0
  then 3*f(n/2) + n
  else 2*f(n/2) + 1
}

method problem5(n: nat) returns (x: int)
  ensures x == f(n)
{
  // First the base case
  if n == 0 {
    x := n;
    return;
  }
  /*
    LOGIC
    Since f(n) calls f(n/2) as a recursive step, we can set k=n and halve it every iteration  until 0
    And since each call gives two outputs: a call to f(n) and a constant, we need to store tham in 2 factors
    So I can set (a,b) to store them, with the invariant that f(n)=a*f(k)+b for whatever k I'm in
    This means initialiazing is trivially k=n, thus f(n)=a*f(k)+b, thus (a,b)=(1,0)
  */
  var a, b, k := 1, 0, n;
  while k > 0
    invariant f(n) == a*f(k)+b
  {
    match k%2 {
      case 0 =>
        // [func] f(k) = 3*f(k/2) + k
        // [inva] f(n) = a*f(k)+b
        // f(n) = a*(3*f(k/2) + k)+b
        // f(n) = 3*a*f(k/2) + a*k + b
        b := a*k+b;
        a := 3*a;
        k := k/2;

      case 1 =>
        // [func] f(k) = 2*f(k/2) + 1
        // [inva] f(n) = a*f(k)+b
        // f(n) = a*(2*f(k/2) + 1)+b
        // f(n) = 2*a*f(k/2) + a*1 + b
        b := a+b;
        a := 2*a;
        k := k/2;
    }
  }
  x := b;
}
