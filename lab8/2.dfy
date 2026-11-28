function max(x: int, y: int): int
{
  if x >= y then x else y
}

method PairProduct(a: array<int>, w: int) returns (b: bool)
  requires a.Length >= 1
  requires forall i :: 0 <= i < a.Length ==> a[i] >= 0
  ensures b <==> (exists i,j :: 0 <=i<j< a.Length && a[i]*a[j] >= w)
{
  if a.Length == 1 {
    return false;
  }
  // keep track of 2 variables: the max element so far, and the max product so far
  // so when a new element shows up, check if multiplying it by the max element is bigger than max prod
  // to always keep the max product possible (since all non negative)
  var mx := max(a[0], a[1]);
  var best := a[0]*a[1];
  var k := 2;
  while k < a.Length
    invariant 2 <= k <= a.Length
    invariant forall i :: 0 <= i < k ==> a[i] <= mx
    invariant exists i :: 0 <= i < k && a[i] == mx
    invariant forall i, j :: 0 <= i < j < k ==> a[i]*a[j] <= best
    invariant exists i, j :: 0 <= i < j < k && a[i]*a[j] == best
  {
    // needed to add this or dafny would take forever to realize that if c>=0, then (a <= b) ==> (a*c <= b*c)
    assert forall i :: 0 <= i < k ==> a[i]*a[k] <= mx*a[k];

    best := max(best, mx*a[k]);
    mx := max(mx, a[k]);
    k := k + 1;
  }
  b := best >= w;
}
