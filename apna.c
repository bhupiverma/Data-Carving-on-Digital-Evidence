#include<stdio.h>
#include<stdlib.h>
void apna()
{
	int choice;
	char y;
	char ch[10];
	int cmd_flag;
	int key;
	system("clear");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t*******************************\n");
	printf("\t\t\t\t\t\t***\t\t\t    ***\n");
	printf("\t\t\t\t\t\t***\t\t\t    ***\n");
	printf("\t\t\t\t\t\t            WELCOME            \n");
	printf("\t\t\t\t\t\t***\t\t\t    ***\n");
	printf("\t\t\t\t\t\t***\t\t\t    ***\n");
	printf("\t\t\t\t\t\t*******************************\n\n\n\n");
	printf("\t\t\t\t\t    **************************************\n");
	printf("\t\t\t\t\t    **\t\t\t\t\t**\n");
	printf("\t\t\t\t\t    **\t\t\t\t\t**\n");
	printf("\t\t\t\t\t          DATA CARVING IN LINUX    \n");
	printf("\t\t\t\t\t    **\t\t\t\t\t**\n");
	printf("\t\t\t\t\t    **\t\t\t\t\t**\n");
	printf("\t\t\t\t\t    **************************************\n\n\n\n\n\n");
	printf("\n\n\n\nDo you want to CONTINUE:- Press y for Yes and n for No :- ");

	if(1){
		cmd_flag = 0;
		scanf("%s",ch);
		if(strcmp(ch,"y")==0){
			cmd_flag = 1; 
			welcome();

			scanf("%d",&choice);
			system("clear");
		}
		else if(strcmp(ch,"Y")==0){
			cmd_flag=1;
			welcome();
			scanf("%d",&choice);
			system("clear");
		}
		else if(strcmp(ch,"n")==0)
		{
			cmd_flag=1;
			printf("\n\nBYE\n\n");
			sleep(1);
			exit(1);
		}
		else if(strcmp(ch,"N")==0)
		{
			cmd_flag=1;
			printf("\n\nBYE\n\n");
			sleep(1);
			exit(1);
		}

		else if(cmd_flag==0)
		{	
			printf("Only Enter Valid Output\n");
			printf("Starting again.....\n");
			sleep(1);
			apna();
		}}

switch(choice)
{
	case 1:
		jpeg();
//		go_back_main_menu();
		break;
	case 2:
		pdf();
		go_back_main_menu();
		break;
	case 3:
		gif();
		go_back_main_menu();
		break;
	case 4:
		exit(1);
		//go_back_main_menu();
		break;
	default:
		printf("Invalid input?");
		go_back_main_menu();

}
}

