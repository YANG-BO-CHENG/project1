#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct std
{
	int month;
	int day;
	int year;
	int time;
	char thing[100];
	int month2;
	int day2;
	int year2;
	int time2;
	char allday;
	char description[50];
	char location[50];
	char pri[50];
};

void bubble(struct std p[],int count);
void bubble2( struct std p[],int count );
void bubble3( struct std p[], struct std p2[], int count,int count2,FILE *fptr );
void bubble4( struct std p[], struct std p2[], int count,int count2 );
int main(void){
	FILE *fptr;
	
	fptr = fopen("event.csv","w");
	
	//���D 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
	printf("////////////////////////////////////////\n");
	printf("///\t\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("��ƾ�");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("\t\t     ///\n");
	printf("///\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("����Ū���ɮ׶i���ƾ�");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("\t     ///\n");
	printf("///\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	printf("1.�s�W�ƥ�");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("\t\t     ///\n");
	printf("///\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("2.�R���ƥ�");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("\t\t     ///\n");
    printf("///\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    printf("3.�ץX��GOOGLE���CSV");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("\t     ///\n");
    printf("///\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    printf("4.���");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("\t\t\t     ///\n");
    printf("///\t\t\t\t     ///\n");
    printf("///\t\t\t\t     ///\n");
    printf("////////////////////////////////////////\n");
    //���DEND 

	struct std s[100];
	struct std del[100];
    int i = 1;
    int count1 = 0, count2 = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    while( i != 0 ){   
        printf("Choose:");
        scanf("%d",&i);
        switch(i)
	   {
            case 1:
                bubble(s,count1);
                count1++;
           	    break;
            case 2:
		  	   bubble2(del,count2);
			   count2++;
    		   break;
            case 3:
        	   bubble3(s,del,count1,count2,fptr);
        	   i = 0;
    		  break;
 		    case 4:
               bubble4(s,del,count1,count2);
               break;
    	}
        printf("\n�H�K�[�ƥ�:%d\n\n",count1 - count2);
    }
    fclose(fptr);
	system("pause");
    return 0;
}

void bubble( struct std p[],int count )//Enter the event
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	printf("�п�J�_�l���(05,07,12):");
	scanf("%d",&p[count].month);
	printf("�п�J�_�l���(01,12,30):");
	scanf("%d",&p[count].day);
	printf("�п�J�_�l�~��(2016,1987):");
	scanf("%d",&p[count].year);
	printf("�п�J�_�l�ɶ�(ex:1210,0530):");
	scanf("%d",&p[count].time);
	printf("�п�J�ƥ�:");
	scanf("%s",p[count].thing);
	printf("�п�J�������(05,07,12):");
	scanf("%d",&p[count].month2);
	printf("�п�J�������(01,12,30):");
	scanf("%d",&p[count].day2);
	printf("�п�J�����~��(2016,1987):");
	scanf("%d",&p[count].year2);
	printf("�п�J�����ɶ�(1210,0530):");
	scanf("%d",&p[count].time2);
	printf("�O�_�����Ѭ���(T/F):");
	scanf("%c",&p[count].allday);
	if(getchar()!= 'F')
	{             
    	printf("�п�J���ʻ����Ϊ���:");
    	scanf("%s",p[count].description);
    	printf("�п�J���ʦa�I:");
    	scanf("%s",p[count].location);
		printf("�O�_���p�H����(T/F):");
		scanf("%s",p[count].pri);
    }
	return;
}

void bubble2( struct std p[],int count )//delete the event
{   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("�Ю����w�s�b���ƥ�\n");
	printf("�п�J�_�l���(05,07,12):");
	scanf("%d",&p[count].month);
	printf("�п�J�_�l���(01,12,30):");
	scanf("%d",&p[count].day);
	printf("�п�J�_�l�~��(2016,1987):");
	scanf("%d",&p[count].year);
	printf("�п�J�_�l�ɶ�(ex:1210,0530):");
	scanf("%d",&p[count].time);
	printf("�п�J�ƥ�:");
	scanf("%s",p[count].thing);
	printf("�п�J�������(05,07,12):");
	scanf("%d",&p[count].month2);
	printf("�п�J�������(01,12,30):");
	scanf("%d",&p[count].day2);
	printf("�п�J�����~��(2016,1987):");
	scanf("%d",&p[count].year2);
	printf("�п�J�����ɶ�(1210,0530):");
	scanf("%d",&p[count].time2);
	printf("�O�_�����Ѭ���(T/F):");
	scanf("%c",&p[count].allday); 
	if( getchar()!='F' )
	{
    	printf("�п�J���ʻ����Ϊ���:");
    	scanf("%s",p[count].description);
    	printf("�п�J���ʦa�I:");
    	scanf("%s",p[count].location);
		printf("�O�_���p�H����(T/F):");
    	scanf("%s",p[count].pri);
    }
	
	return;
}
void bubble3( struct std p[], struct std p2[], int count,int count2,FILE *fptr)//write the event into file
{
	int i,j,decide = 1;
	int v1,v2;//v1 = start hour , v2 =start minute
	int v3,v4;//v3 = end hour , v3 = end minute
	
	fprintf(fptr,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n","Start Date","Start Time","Subject","End Date","End Time",
												"All Day Event","Description","Location","Private");
	for( i = 0 ; i < count ; i++ )
	{
		for( j = 0 ; j < count2 ; j++ )
		{
			//check is same day or not
			if( p[i].month == p2[j].month && p[i].day == p2[j].day && p[i].year == p2[i].year && p[i].time == p2[j].time && 
				p[i].month2 == p2[i].month2 && p[i].day2 == p2[i].day2 && p[i].year2 == p2[i].year2 )
			{
				//check is same thing or not
				if( strcmp(p[i].thing,p2[j].thing) == 0 )
				{
					decide = 0;
					break;
				}
			}
			else
			{
				decide = 1;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
		if( decide == 1 )
		{
			v1 = p[i].time / 100;
			v2 = p[i].time % 100;
			v3 = p[i].time2 / 100;
			v4 = p[i].time2 % 100;
			fprintf(fptr,"%d/%02d/%04d,%d:%02d,%s,%d/%02d/%04d,%d:%02d,%d,%s,%s,%s\n",
			p[i].month,p[i].day,p[i].year,v1,v2,p[i].thing,p[i].month2,p[i].day2,p[i].year2,v3,v4,
			p[i].allday,p[i].description,p[i].location,p[i].pri);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12 );
	        printf("%d/%02d/%04d\n",p[i].month,p[i].day,p[i].year);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13 );
	        printf("%d:%02d\n",v1,v2);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10 );
	        printf("%s\n",p[i].thing);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12 );
	        printf("%d/%02d/%04d\n",p[i].month2,p[i].day2,p[i].year2);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	        printf("%d:%02d\n",v3,v4);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10 );
	        printf("%c\n",p[i].allday);
	        if( getchar()!= 'F'  )
	        {
	    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12 );
	    		printf("%s\n",p[i].description);
	    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13 );
        		printf("%s\n",p[i].location);
        		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10 );
        		printf("%s\n\n",p[i].pri);
			}
		}
	}
	return;
}
void bubble4( struct std p[], struct std p2[], int count,int count2 )
{
    int i,j,decide = 1;
	int v1,v2;//v1 = start hour , v2 =start minute
	int v3,v4;//v3 = end hour , v3 = end minute
	
	for( i = 0 ; i < count ; i++ )
	{
		for( j = 0 ; j < count2 ; j++ )
		{
			//check is same day or not
			if( p[i].month == p2[j].month && p[i].day == p2[j].day && p[i].year == p2[i].year && p[i].time == p2[j].time && 
				p[i].month2 == p2[i].month2 && p[i].day2 == p2[i].day2 && p[i].year2 == p2[i].year2 )
			{
				//check is same thing or not
				if( strcmp(p[i].thing,p2[j].thing) == 0 )
				{
					decide = 0;
					break;
				}
			}
			else
			{
				decide = 1;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
		if( decide == 1 )
		{
			v1 = p[i].time / 100;
			v2 = p[i].time % 100;
			v3 = p[i].time2 / 100;
			v4 = p[i].time2 % 100;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12 );
	        printf("%d/%02d/%04d\n",p[i].month,p[i].day,p[i].year);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13 );
	        printf("%d:%02d\n",v1,v2);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10 );
	        printf("%s\n",p[i].thing);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12 );
	        printf("%d/%02d/%04d\n",p[i].month2,p[i].day2,p[i].year2);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13 );
	        printf("%d:%02d\n",v3,v4);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10 );
	        printf("%c\n",p[i].allday);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12 );
	    	printf("%s\n",p[i].description);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13 );
        	printf("%s\n",p[i].location);
        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        	printf("%s\n\n",p[i].pri);
    	     
		}
	}
	return;
}
