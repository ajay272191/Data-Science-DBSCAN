#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define max 100
#define size 10

int dataSetCount;
struct{
	int data[size];
	int corePoint;
	int visited;
	int clusterId;
}dataSet[max];
#include"scanDataSet.c"
int distance[max];
int distances(int E,int pointIndex,int feature);
int main()
{
	int e,MinPts,count,feature=2;
	int clusterNumber=1,j;
	scan();
	printf("give the eps(E) and MinPts\n");
	scanf("%d %d",&e,&MinPts);	
	printf("dataSEtcount %d\n",dataSetCount);
	for(int i=0;i<dataSetCount;i++){
		
			
			count=distances(e,i,feature);
			// printf("count::%d %d\n",i,count);
			if(count>=MinPts){
				dataSet[i].corePoint=1;
				for(j=0;j<dataSetCount;j++){
					 
					// printf("distance[%d]<=e %d && dataSet[j].clusterId %d\n",j,distance[j],dataSet[j].clusterId);
					if(distance[j]<=e && dataSet[j].clusterId!=0){
						//printf("hey\n");
						
						dataSet[i].clusterId=dataSet[j].clusterId ;
						dataSet[j].visited=1;	
					}
									
				}
				if(dataSet[i].clusterId==0)
					{dataSet[i].clusterId=clusterNumber;clusterNumber++;}
			}
			else dataSet[i].corePoint=0;
			
		
	}
	printf("\nresult!!!!!!!!\nfeatureData 0 : Noise\nfeatureData 1 : corePoint\n");
	for(int i=0;i<dataSetCount;i++){
		printf("data: (%d,%d)\tfeatureData: %d\tclusterid: %d\n ",dataSet[i].data[0],dataSet[i].data[1],dataSet[i].corePoint,dataSet[i].clusterId);	
	}
	
return 0;
}
int distances(int E,int pointIndex,int feature){

	int count=0,interSpace=0;
	for(int i=0;i<dataSetCount;i++){
		interSpace=0;	
		for(int j=0;j<feature;j++){
		
			interSpace+=pow(dataSet[i].data[j]-dataSet[pointIndex].data[j],2);
		}
		distance[i]=sqrt(interSpace);
		 //printf("\tdistances ::  %d\t",distance[i]);
		if(distance[i]<=E)
			count++;
	}
	//printf("\n");
//printf("count::%d E %d\n",count,E);
return count;
}




















