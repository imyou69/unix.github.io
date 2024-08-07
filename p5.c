//DFS
#include<stdio.h>

int n,a[10][10],i,j,v[10],count=0;

void dfs(int x)
{
	count++;
	v[x]=count;
	if(v[x]!=0)
		printf("%d\t",x);

	int k;
	for(k=1;k<=n;k++)
		if(a[x][k]==1 && v[k]==0)
			dfs(k);

}
		

void main()
{
	printf("\nEnter no. of Nodes: ");
	scanf("%d",&n);
	printf("\nEnter the Adjacency Matrix:-\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);

	for(i=1;i<=n;i++)
		v[i]=0;
	printf("\nDFS:\t");
	for(i=1;i<=n;i++)
		if(v[i]==0)
			dfs(i);
	printf("\n");

}