int BIT[1000], a[1000], n;

void update(int x, int delta)
{
    for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for( ; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
     cin>>n;
     int i;
     for(i = 1; i <= n; i++)
     {
           cin>>a[i];
           update(i, a[i]);
     }
     cout<< “sum of first 10 elements is ” + query(10);
     cout<< “sum of all elements in range [2, 7] is ” + (query(7) – query(2-1));
  
}
