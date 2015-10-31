
void go_back_main_menu()
{
	int choice;
	printf("\t\n\nDo you want to CONTINUE:-\n");
	printf("Enter :-\n\t1 For Continue with Main Menu \n\tOther for Exit\n\n");
	printf("ENTER YOUR CHOICE:------------------------------------------------------------");
	scanf("%d",&choice);
	if (choice==1)
	{
		system("clear");
		apna();
	}
	else
		{
			printf("\nBYE\n");
			sleep(1);
			exit(1);
		}

}
