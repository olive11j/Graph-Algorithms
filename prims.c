#include<stdio.h>
int min_key(int k[],int mst[],int no_ver)
{
	int i,min_pos,min=999;
	for(i=0;i<no_ver;i++)
	{
		if(mst[i]==0 && k[i]<min)
		{
			min=k[i];
			min_pos=i;
		}
	}
	return min_pos;
}
void prims(int gr[][100],int no_ver)
{
	int p[100],k[100],i,count,edge,v,mst[100],min_cost=0;
	for(i=0;i<no_ver;i++)
	{
		k[i]=99;
		mst[i]=0;
	}
	k[0]=0;
	p[0]=-1;
	for(count=0;count<no_ver-1;count++)
	{
		edge=min_key(k,mst,no_ver);
		mst[edge]=1;
		for(v=0;v<no_ver;v++)
		{
			if(gr[edge][v] && mst[v]==0 && gr[edge][v]<k[v])
			{
				p[v]=edge;
				k[v]=gr[edge][v];
			}
		}
	}
printf("\n edge \t weight \n");
for(i=1;i<no_ver;i++)
{
	printf("%d - %d    %d\n",p[i],i,gr[i][p[i]]);
	min_cost=min_cost+gr[i][p[i]];
}
printf("total cost is: %d\n",min_cost);
}
int main()
{
	int i,j,gr[100][100],no_ver;
	printf("how many vertices:\n");
	scanf("%d",&no_ver);
	printf("enter the weights:\n");
	for(i=0;i<no_ver;i++)
	{
		for(j=0;j<no_ver;j++)
		scanf("%d",&gr[i][j]);
	}
		prims(gr,no_ver);
		return 0;
}

