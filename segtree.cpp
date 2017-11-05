ll getMid(ll s, ll e) {  return s + (e -s)/2;  }

ll getSumUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll si)
{
    if (qs <= ss && qe >= se)
        return st[si];
 
    if (se < qs || ss > qe)
        return 0;
 
    ll mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
 
void updateValueUtil(ll *st, ll ss, ll se, ll i, ll diff, ll si)
{
    if (i < ss || i > se)
        return;
 
    st[si] = st[si] + diff;
    if (se != ss)
    {
        ll mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}
 
void updateValue(ll arr[], ll *st, ll n, ll i, ll new_val)
{
    if (i < 0 || i > n-1)
    {
        prllf("Invalid Input");
        return;
    } 
    ll diff = new_val - arr[i]; 
    arr[i] = new_val; 
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
ll getSum(ll *st, ll n, ll qs, ll qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        prllf("Invalid Input");
        return -1;
    } 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }    
    ll mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
ll *constructST(ll arr[], ll n)
{
    ll x = (ll)(ceil(log2(n)));  
    ll max_size = 2*(ll)pow(2, x) - 1;  
    ll *st = new ll[max_size]; 
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
int main()
{
    ll arr[] = {1, 3, 5, 7, 9, 11};
    ll n = sizeof(arr)/sizeof(arr[0]); 
    ll *st = constructST(arr, n); 
    printf("Sum of values in given range = %d\n", 
            getSum(st, n, 1, 3)); 
    updateValue(arr, st, n, 1, 10); 
    printf("Updated sum of values in given range = %d\n",
             getSum(st, n, 1, 3));
    return 0;
}
