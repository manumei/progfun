function exp(a:nat, e:nat): nat {
  if e==0 then 1 else a*exp(a,e-1)
}
function fastExp(a:nat, e:nat): nat
  decreases e // had to add this, dafny warned about needing a decreases clause
{
  if e==0 then 1
  else if e%2==0
  then fastExp(a*a, e/2)
  else a*fastExp(a, e-1)
}

lemma expSquare(a: nat, k: nat)
  ensures exp(a*a, k) == exp(a, 2*k)
  decreases k
{
  if k == 0 {
    calc {
      exp(a*a, 0);
    == // definition of exp for e==0
      1;
    == // definition of exp for e==0
      exp(a, 2*0);
    }
  } else {
    expSquare(a, k-1);
  }
}

lemma equalExp(a: nat, e: nat)
  ensures exp(a,e) == fastExp(a,e)
  decreases e
{
  if e == 0 {
    calc {
      exp(a, e);
    == // definition of exp for e==0
      1;
    == // definition of fastExp for e==0
      fastExp(a, e);
    }
  } else if e % 2 != 0 {
    // e is odd (so e > 0)
    calc {
      exp(a, e);
    == // definition of exp for e>0
      a*exp(a, e-1);
    == { equalExp(a, e-1); }  // induction
      a*fastExp(a, e-1);
    == // definition of fastExp for e odd
      fastExp(a, e);
    }
  } else {
    // e is even and e > 0
    calc {
      exp(a, e);
    == // definition of exp for e>0
      exp(a, 2*(e/2));
    == { expSquare(a, e/2); }
      exp(a*a, e/2);
    == // definition of fastExp for e even
      fastExp(a, e);
    }
  }
}