function sumCubes(n: nat) : nat {
  if n == 0 then 0 else n*n*n + sumCubes(n-1)
}
lemma {:induction false} sumLemma(n: nat)
  ensures sumCubes(n) == n*n*(n+1)*(n+1)/4
{
  if n == 0 {
    calc {
      sumCubes(n);
    == // define sumCubes for n==0
      0;
    == // n == 0
      n*n*(n+1)*(n+1)/4;
    }
  } else {
    calc {
      sumCubes(n);
    == // define sumCubes for n>0
      n*n*n + sumCubes(n-1);
    == { sumLemma(n-1); } // induction
      n*n*n + (n-1)*(n-1)*n*n/4;
    == // write n*n*n as fraction over 4
      4*n*n*n/4 + (n-1)*(n-1)*n*n/4;
    == // combine into one big fraction
      (4*n*n*n + (n-1)*(n-1)*n*n)/4;
    == // factor out n*n
      n*n*(4*n + (n-1)*(n-1))/4;
    == // expand (n-1)*(n-1)
      n*n*(4*n + n*n - 2*n + 1)/4;
    == // simplify 4n - 2n = 2n
      n*n*(n*n + 2*n + 1)/4;
    == // factor form, n*n + 2n + 1 = (n+1)*(n+1)
      n*n*(n+1)*(n+1)/4;
    }
  }
}