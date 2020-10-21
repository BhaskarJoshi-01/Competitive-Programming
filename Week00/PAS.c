//This is generalised matrix exponentation to compute F(n) = a*F(n-1) + b*F(n-2) + c*F(n-3) + ...... + x*F(n-k); 

#include<stdio.h>
long long int M2[105][105]={0},b,m;

void multiplication(long long int F1[105][105],long long int F2[105][105]);

/*void pm(long long int X[105][105])
  {
  int i,j,k;
  printf("\n");
  for (i=0;i<b;i++)
  {
  for (j=0;j<b;j++)
  {
  printf("%lld",X[i][j]);
  }
  printf("\n");
  }
  printf("\n\n");

  }*/
void power(long long int M1[105][105],long long int x)
{
	if (x==0 || x==1)
	{
		return;
	}

	power (M1,x/2);
	multiplication(M1,M1);

	//	 printf("during power when x =%lld",x);
	//      pm(M1);

	if (x%2==1)
	{
		multiplication(M1,M2);
	}

	//	printf("during power when x =%lld",x);
	//	pm(M1);
	///	printf("M2 : \n");
	//	pm(M2);
}

void multiplication(long long int F1[105][105],long long int F2[105][105])
{
	long long int Bk[105][105]={0};
	long long int i,j,k,c=0;
	for (i=0;i<b;i++)
	{
		for (j=0;j<b;j++)
		{
			c=0;
			for (k=0;k<b;k++)
			{
				c += ((F1[i][k])*(F2[k][j]))%m; 
			}
			Bk[i][j] = c%m;  
		}
	}
	//	printf("During mul");
	//	pm(Bk);
	for (i=0;i<b;i++)
	{
		for (j=0;j<b;j++)
		{
			F1[i][j] = Bk[i][j];
		}				
	}
}


int main()
{
	long long int j,n,k,m1,i,ans,a[105],c[105],M[105][105]={0};
	scanf("%lld %lld %lld",&n,&k,&m1);
	b=k;
	m=m1;
	n = n-1;



	for (i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
	}
	for (i=0;i<k;i++)
	{
		scanf("%lld",&a[i]);
	}
	if (n<=k)
	{
		printf("%lld\n",a[n]%m);
	}
	else 
	{
		for (i=0;i<k;i++)
		{
			for (j=0;j<k;j++)
			{
				if (j==k-1)
				{
					M[i][j] = c[k-i];
					M2[i][j] = c[k-i];

				}
				if (i-j==1)
				{
					M[i][j] = 1;
					M2[i][j] = 1;
				}

			}
		}
		//	printf("before = \n");
		//	pm(M);
		power(M,n-k+1);
		ans = 0;
		//	printf("Final");
		//	pm(M);

		for (i=0;i<k;i++)
		{
			ans = (ans + a[i]*M[i][k-1])%m;
		}

		printf("%lld\n",ans%m);
	}
	return 0;
}







