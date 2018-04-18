#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include<time.h>
#include<iostream>
FILE *pt;
struct struct_type
{
	int id;
	float balance;
	char name[30];
};
struct dob
{
	int d;
	int m;
	int y;
};
struct student
{
	char fName[30];
	char lName[30];
	char mName[30];
	dob dateofBirthday;
	int gender;
	int rate[10];
};

void Name(student *pt)
{
	for (int i = 0; i < 10; i++)
	{
		pt->fName[i] = (char)(97 + rand() % 24);
	}
	pt->fName[10] = '\0';
	for (int i = 0; i < 10; i++)
	{
		pt->lName[i] = (char)(97 + rand() % 24);
	}
	pt->lName[10] = '\0';
	for (int i = 0; i < 10; i++)
	{
		pt->mName[i] = (char)(97 + rand() % 24);
	}
	pt->mName[10] = '\0';
}

void PrintInfo(student *pt)
{
	printf("%s %c. %c.\n", pt->fName, pt->lName, pt->mName);
	printf("(%d.%d.%d)\n", pt->dateofBirthday.d, pt->dateofBirthday.m, pt->dateofBirthday.y);
}
void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	char nameGrpup[100];
	char command[100];
	char command2[150];
	puts("---------");
	printf("Введите название группы:");
	scanf("%s", nameGrpup);
	int A;
	printf("мини прога ахах\n");
	scanf("%d", &A);
	sprintf(command, "md %s\\%s", "\\\\dc\\Студенты\\ПКО\\SEB-172.2\\Общее\\ALLStudents", nameGrpup);
	int result = system(command);
	sprintf(command2, "%s\\%s\\%s.txt", "\\\\dc\\Студенты\\ПКО\\SEB-172.2\\Общее\\ALLStudents", nameGrpup, nameGrpup);
	if (A == 1)
	{
		if ((pt = fopen(command2, "a+")) != NULL)
		{
			for (int i = 0;i < 100;i++)
			{
				student st;
				/*printf("введите имя\n");
				*st.fName = (char)(1 + rand() % 100);
				printf("введите Фамилие\n");
				*st.lName = (char)(1 + rand() % 100);
				printf("введите отчество\n");
				*st.mName = (char)(1 + rand() % 100);*/
				Name(&st);
				//printf("введите дату рождения в формате day.month.year\n");
				st.dateofBirthday.d = 1 + rand() % 20;
				st.dateofBirthday.m = 1 + rand() % 12;
				st.dateofBirthday.y = 1990 + rand() % 10;
				//printf("Введите генер\n");
				st.gender = 0 + rand() % 1;
				for (int i = 0;i < 10;i++)
				{
					//printf("Введите %d оценку", i);
					st.rate[0] = 1 + rand() % 5;
				}
				fwrite(&st, sizeof(student), 1, pt);
			}
		}
		fclose(pt);
	}
	else if (A == 2)
	{
		student *st = NULL;
		int count = 0;
		if ((pt = fopen(command2, "r")) != NULL)
		{
			st = (student*)calloc(1, sizeof(student));
			while (fread(st + count, sizeof(student), 1, pt))
			{
				PrintInfo(st + count);
				count++;
				st = (student*)realloc(st,sizeof(student)* (count + 1));
			}

			student dd = *st;
		}
		int Z;
		scanf("%d", &Z);
		switch (Z)
		{
		case 1:
		{
			int max=5000;
			int h;
			//2.	Вывести информацию о самом старшем студенте
			for (int i = 0;i < count;i++)
			{
				if (max > (st[i].dateofBirthday.y + st[i].dateofBirthday.m))
				{
					max = (st[i].dateofBirthday.y + st[i].dateofBirthday.m);
					h = i;
				}
			}
			printf("sss:");
			PrintInfo(st + h);
		}
		break;
		}
	}
}