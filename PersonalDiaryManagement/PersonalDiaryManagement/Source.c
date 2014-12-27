#include<stdio.h>

FILE *fp;

struct appointment
{
	char time[6];
	char name[30];
	char place[25];
	char note[500];
};

void mainMenu();
void writeAppo();
void viewAppo();
void eraseAppo();

int main()
{
	int choice = 2; // given a value because of error output

	while (1)
	{
		mainMenu();

		// Error output
		if (choice<1 || choice>4)
			printf("\t Error: Wrong Choice. Enter again\n");
		
		printf("\t Your choice: ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:		viewAppo();		break;
			case 2:		writeAppo();	break;
			case 3:		eraseAppo();	break;
			case 4:		return 0;		break;
			default:	system("cls");	break;
		}
	}
}


void mainMenu()
{
	printf("\n\n");
	printf("\t ---------------------------\n");
	printf("\t| PERSONAL DIARY MANAGEMENT |\n");
	printf("\t|---------------------------|\n");
	printf("\t| 1: View Appointments      |\n");
	printf("\t| 2: Add Appointment        |\n");
	printf("\t| 3: Erase All Data         |\n");
	printf("\t| 4: Exit                   |\n");
	printf("\t ---------------------------\n\n");
}
void writeAppo()
{
	// u txt fajlu novi red nakon slova, isti red nakon broja _problem

	system("cls");
	struct appointment appo;
	fp = fopen("C:/Users/Ferhat/Documents/Visual Studio 2013/Projects/Special/PersonalDiaryManagement/appointments/appointments.txt", "a");

	fflush(stdin);
	fprintf(fp, "Meeting with: ");
	printf("\n\n\tWho do you have a meeting with? ");
	fgets(appo.name, sizeof appo.name, stdin);
	fprintf(fp, "%s", appo.name);
	
	fflush(stdin);
	fprintf(fp, "At: ");
	printf("\tWhat time? ");
	fgets(appo.time, sizeof appo.time, stdin);
	fprintf(fp, "%s", appo.time);

	fflush(stdin);
	fprintf(fp, "\nIn: ");
	printf("\tWhere? ");
	fgets(appo.place, sizeof appo.place, stdin);
	fprintf(fp, "%s", appo.place);

	fflush(stdin);
	fprintf(fp, "Additional notes: ");
	printf("\tAny additional notes? ");
	fgets(appo.note, sizeof appo.note, stdin);
	fprintf(fp, "%s", appo.note);

	fprintf(fp, "\n");

	fclose(fp);

	printf("\n\t");
	system("Pause");
	system("cls");
}
void viewAppo()
{
	system("cls");
	char *contents;
	fp = fopen("C:/Users/Ferhat/Documents/Visual Studio 2013/Projects/Special/PersonalDiaryManagement/appointments/appointments.txt", "r");
	fseek(fp, 0L, SEEK_END);
	long fileSize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	contents = malloc(fileSize + 1);
	long size = fread(contents, 1, fileSize, fp);
	contents[size] = 0;
	printf("\n\n%s\n", contents);
	fclose(fp);

	system("Pause");
	system("cls");
}
void eraseAppo()
{
	system("cls");
	fp = fopen("C:/Users/Ferhat/Documents/Visual Studio 2013/Projects/Special/PersonalDiaryManagement/appointments/appointments.txt", "w");
	fclose(fp);
	printf("\n\n\tData successfully erased.\n\t");
	system("Pause");
	system("cls");
}

