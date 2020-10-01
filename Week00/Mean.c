/*
The following program is to calculate the mean of the triangle.
*/

int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",a[i]);
    }
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    sum = (float)sum/(float)n;
    printf("Mean = %f\n",sum);
    return 0;
}
