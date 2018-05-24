int scan()
{
	FILE *fp;
	char ch,str[15],file_name[15];//="featuredData";
	printf("give the file name with extension::\t");
	scanf("%s",file_name);
	fp=fopen(file_name,"r");
	int count1=0,feature=0;
	
	if(fp==NULL){
		printf("openig error\n\n");	
		exit(0);
	}

	ch=fgetc(fp);
	dataSetCount=0;
	while(1)
	{
		if(ch==' '||ch=='\n'||ch==','){
			str[count1]='\0';
			dataSet[dataSetCount].data[feature]=atoi(str);
			//printf("\t%d",dataSet[dataSetCount].data[feature]);
			dataSetCount++;
			strcpy(str," ");
			count1=0;			
			if(ch==','){
				feature=1;
				dataSetCount--;
				ch=fgetc(fp);
	 		}
			else
				feature=0;
			
		}		
		else if(ch==EOF)
			break;
			str[count1]=ch;
			count1++;
			ch=fgetc(fp);
			
	}

	printf("\nData are\n\n");
	for(int i=0;i<dataSetCount;i++)
	{
		//printf("%d::",i);
		for(int j=0;j<2;j++)
		{
			printf("%d ",dataSet[i].data[j]);
		}
		printf("\n");
	}
fclose(fp);
return 0;
}












