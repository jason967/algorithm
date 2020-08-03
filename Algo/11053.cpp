#include<cstdio>
#define f(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int N,A[1001],d[1001],ans=1;
int main()
{
	scanf("%d", &N);
	f(i,0,N) scanf("%d", &A[i]);
	d[0] = 1;
	f(i,1,N)
	{
		d[i] = 1;
		f(j,0,i)
		{
			if(A[j]<A[i] && d[j]>=d[i])
			{
				d[i]=d[j]+1;
				if(ans<d[i]) ans=d[i];
			}
		}
	}
	printf("%d",ans);
}