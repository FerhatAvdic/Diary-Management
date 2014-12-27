#include<stdio.h>

FILE *fp;

struct appointment
{
	char name[30];
	char time[6];
	char place[25];
	char note[500];
};

void mainMenu();
void writeInstance(char *,char *,char *);
void writeAppo();
void viewAppo();
void eraseAppo();

int main()
{
	int choice = 2; // given a value between 1 and 4 so program doesn't show error on first run

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
			case 1:		viewAppo();	break;
			case 2:		writeAppo();	break;
			case 3:		eraseAppo();	break;
			case 4:		return 0;	break;
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
void writeInstance(char *autoInput, char *question, const char *userInput)
{
	fflush(stdin);
	fprintf(fp, "%s", autoInput);
	printf("%s", question);
	fgets(userInput, 500, stdin);
	fprintf(fp, "%s", userInput);
}
void writeAppo()
{
	// u txt fajlu novi red nakon slova, isti red nakon broja _problem

	system("cls");
	struct appointment appo;
	fp = fopen("C:/Users/Ferhat/Documents/Visual Studio 2013/Projects/Special/PersonalDiaryManagement/appointments/appointments.txt", "a");
	writeInstance("Meeting with: ", "\n\n\tWho do you have a meeting with ? ", appo.name);
	writeInstance("At: ", "\tWhat time? ", appo.time);
	writeInstance("In: ", "\tWhere? ", appo.place);
	writeInstance("Additional notes : ", "\tAny additional notes ? ", appo.note);
	fprintf(fp, "\n");
	fclose(fp);

	printf("\n\t");
	system("Pause");
	system("cls");
}
void viewAppo()
{
	system("cls");
	int c;
	fp = fopen("C:/Users/Ferhat/Documents/Visual Studio 2013/Projects/Special/PersonalDiaryManagement/appointments/appointments.txt", "r");
	// Algorithm to read a character from the txt file, and print it right after reading
	if (fp) {
		while ((c = getc(fp)) != EOF)
			putchar(c);
		fclose(fp);
	}
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

