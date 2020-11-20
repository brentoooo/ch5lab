#include<stdio.h>
#include<stdlib.h>
#define students 3
#define exams 4
void minimum(int grades[][exams], int pupils, int tests);
void maximum(int grades[][exams], int pupils, int tests);
void average(int grades[][exams], int pupils, int tests);
void printarray(int grades[][exams], int pupils, int tests);
void printmenu();
int main()
{
int studentgrades[students][exams] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };
	void(*processgrades[4]) (int[students][exams], int, int) = { printarray,minimum ,maximum,average };
	int choice = 0;
	while (choice != 4)
	{
		do
		{
			printmenu();
			scanf_s("%d",&choice);
		} while (choice<0||choice>4);
		if (choice != 4)
		{
			(*processgrades[choice])(studentgrades, students, exams);
		}
		else
		{
			printf("\tprogram ended.\n");
		}
	}
	system("pause");
	return 0;
}
void minimum(int grades[][exams], int pupils, int tests)
{
	int i, j;
	int lowgrade = 100;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] < lowgrade)
				lowgrade = grades[i][j];
		}
	}
	printf("\n\tthe lowest grade is %d\n", lowgrade);
}
void maximum(int grades[][exams], int pupils, int tests)
{
	int i, j;
	int highgrade = 0;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] > highgrade)
				highgrade = grades[i][j];
		}
	}
	printf("\n\tthe highest grade is %d\n", highgrade);
}
void average(int grades[][exams], int pupils, int tests)
{
	int i, j,total;
	for (i = 0; i < pupils; i++)
	{
		total = 0;
		for (j = 0; j < tests; j++)
				total +=grades[i][j];
	}
	printf("\n\tthe average grade for students %d is %.1f\n",i+1,(double)total/tests);
}
void printarray(int grades[][exams], int pupils, int tests)
{
	{
		int i, j;
		printf("\n\t\t\t[0]     [1]     [2]     [3]");
		for (i = 0; i < pupils; i++)
		{
			printf("\n\tstudentgrades[%d]",i);
			for (j = 0; j < tests; j++)
			{
				printf("%-7d",grades[i][j]);
			}
		}
		printf("\n");
	}
}
void printmenu()
{
	printf("\n");
	printf("\tentser a choice:\n");
	printf("\t0 print the array of grades\n");
	printf("\t1 find the minimum grade\n");
	printf("\t2 find the maximum grade\n");
	printf("\t3 find the average on all tests for each students\n");
	printf("\t4 end program\n");
	printf("choice:");
}