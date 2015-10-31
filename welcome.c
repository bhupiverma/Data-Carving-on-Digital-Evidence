void welcome()
{
	int choice;
	char ch[10];
	int cmd_flag;
	printf ("\n1. For JPEG FILE\n");
	printf("2. For PDF FILE\n");
	printf("3. FOR GIF FILE\n");
	printf("4. For Exit\n\n");
	printf("ENTER YOUR CHOICE:------------------------------------------------------------------------");
	if(1){
		cmd_flag = 0;
		scanf("%s",ch);
		if(strcmp(ch,"1")==0){
			cmd_flag = 1; 
			jpeg();

			scanf("%d",&choice);
			system("clear");
		}
		else if(strcmp(ch,"2")==0){
			cmd_flag=1;
			pdf();
			scanf("%d",&choice);
			system("clear");
		}
		else if(strcmp(ch,"3")==0)
		{
			cmd_flag=1;
			gif();
		}
		else if(strcmp(ch,"4")==0)
		{
			cmd_flag=1;
			exit(1);
		}

		else if(cmd_flag==0)
		{	
			printf("Only Enter Valid Output\n");
			printf("Starting again.....\n");
			sleep(1);
			system("clear");
			welcome();
		}}

	system("clear");
}
