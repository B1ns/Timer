/* ���� */

#define _CRT_SECURE_NO_WARNINGS 
#define YELLOW SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);

#define NextLine printf("\n");
#define TAB2 printf("\t\t");
#define TAB4 printf("\t\t\t\t");
#define TAB6 printf("\t\t\t\t\t\t");

#define DO    262
#define MI    330
#define PA    349    
#define SOL    392
#define RA    440


/*���� �������*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

/*�Լ�����*/

int timer();
int menu1();
int menu2();
int menu3();
int alarm();

char line();
char timerBuffer[8 + 1];
void stopwatch(int onOff);
void secToHHMMSS(int secs, char* s, size_t size);

/* �����Լ� */

int main()
{
	YELLOW
		int num;
	TAB6 printf(" Timer\n");
	TAB4 printf("\t    �ð��� �Ʋ�����.\n");
	line();
	timer();
	line();
	TAB4 printf(" �ð�,�˶�,�����ġ - (c) H1222 ���� \n");
	line();
	TAB4 printf("��1��: �ѱ��ð� ��2�� �˶� ��3�� �����ġ \n");
	printf("\n");
	TAB4 printf("�������ϰ� �ʹٸ� �ƹ�Ű�� �Է����ּ���. \n");
	TAB4 printf("\t  ��ȣ�� �Է����ּ���: ");
	scanf_s("%d", &num);

	switch (num) // ���ϴ� ����� �����ϱ����� switch �� 
	{
	case 1:
		menu1();
		break;
	case 2:
		menu2();
		break;
	case 3:
		menu3();
		break;
	default:
		printf("�����ϱ� \n");
	}
	system("PAUSE");
	return 0;
}

/* ���⼭ ���� ����� ���� �Լ� �Դϴ�. */

int timer() {

	TAB4 printf("                  ZZZ                \n");
	TAB4 printf("              8ZZZZZZZZZ9            \n");
	TAB4 printf("          EZZZB    y    8ZZZZ        \n");
	TAB4 printf("        ZZZ yj     Z      w ZZZ      \n");
	TAB4 printf("      ,ZZ   yD     Z      z   ZZD    \n");
	TAB4 printf("     8Z            Z    W       ZZ   \n");
	TAB4 printf("    BZ 8ZW         Z   Z9     Z  ZZ  \n");
	TAB4 printf("    Z8  D          Z  Z       8  wZ  \n");
	TAB4 printf("   jZ              Z Z            Z9 \n");
	TAB4 printf("   ZZ              ZZ             yZ \n");
	TAB4 printf("   ZZ Z            Z            Z DZ \n");
	TAB4 printf("   ZE             j5              WZ \n");
	TAB4 printf("   5Z                             ZE \n");
	TAB4 printf("    Z5  j                      ,  Z  \n");
	TAB4 printf("    EZ WZ                     Z9 ZZ  \n");
	TAB4 printf("     ZZ                         ZZ   \n");
	TAB4 printf("      5ZZ   y8           WD   ZZE    \n");
	TAB4 printf("        ZZZ        Z      y ZZZ      \n");
	TAB4 printf("          ZZZZj    Z    WZZZZ        \n");
	TAB4 printf("             wZZZZZZZZZZZw           \n");

	return 0;
}

/* �ڵ带 ���̱����� line �� �׷��� �Լ�. */

char line() {
	char line[102] = { "---------------------------------------------------------------------------------------------------\n" };
	printf(line);
	return 0;
}

/*�˶��� �︮������ �̽������� �ڵ带 ����� .feat �����*/

int alarm() {
	int sound[] = { MI, DO, SOL, DO, SOL, RA, SOL, DO, RA ,SOL, MI, SOL };
	/*�� -> �� -> �� -> �� -> �� -> �� -> �� -> �� -> �� -> �� -> �� ->��*/
	for (int t = 0; t < 2; t++)
	{
		for (int i = 0; i < 8; i++)	//2�� ���
		{
			Beep(sound[i], 200);
			Sleep(1000);		//1�� ��ǥ
		}
	}

	return 0;
}
/* �ѱ��ð��� 24�� ���·� ǥ���ϴ� �Լ� */
int menu1()
{
	struct tm korea_time;

	time_t ti;

	while (1)
	{

		system("cls");
		time(&ti);
		korea_time = *localtime(&ti);

		TAB6 printf("  �ѱ� �ð�    \n");
		line();
		TAB6 printf("(C)������:����\n");
		line();
		TAB4 printf("\t�� %d �� ", korea_time.tm_hour);
		printf("�� %d �� ", korea_time.tm_min);
		printf("�� %d �� \n", korea_time.tm_sec);
		printf("\n");
		TAB4 printf("    �������ϽǶ��� Ctrl_C �� �����ּ���.\n");
		Sleep(1000);

	}
	system("PAUSE");
	system("cls");
	main();
	return 0;
}
/* Ÿ�̸� �Լ� */
int menu2()
{
	system("cls");

	int minutes = 0;
	int seconds = 0;

	line();
	TAB4 printf("\t�ð��� �Է����ּ��� ?�� ?��");
	NextLine
		line();
	printf("�Է� : ");
	scanf_s("%d %d", &minutes, &seconds);


	while (minutes || seconds)
	{
		system("cls");
		NextLine
			line();
		TAB6 printf("%d�� %d��\t", minutes, seconds--);
		NextLine
			line();
		Sleep(1000);

		if (seconds == -1 && minutes)
		{
			seconds = 59;
			minutes--;
		}
	}
	system("cls");
	NextLine
		line();
	TAB6 printf("%d�� %d��\n", minutes, seconds--);
	line();
	alarm();
	TAB4 printf("\t     �˶��ð� ����!\n");
	alarm();
	system("PAUSE");
	system("cls");
	main();
	return 0;
}
/* ��ž��ġ �Լ� */
int menu3() {


	stopwatch(1); // 1�� �μ��� ������ Ÿ�̸Ӱ� ����
	TAB4 puts("    Ÿ�̸� ON! �ƹ�Ű�� ������ ����");

	// ������ �ƹ� Ű�� ���� ������ ������ ���
	_getch(); // _getch() �� getch() �� ���� ��ȭ ����


	stopwatch(0); // 0�� ������ Ÿ�̸Ӱ� ������ �ð� ���ڿ��� ���ۿ� ����
	TAB4 printf("    Ÿ�̸� OFF! ��� �ð���: [%s]\n", timerBuffer);

	system("PAUSE");
	system("cls");
	main();
	return 0;
}

void stopwatch(int onOff) {
	static int oldTime; // stopwatch �Լ��� ����Ǿ ���� ����ϴ� "���� ���� ����"

	if (onOff == 1) { // Ÿ�̸� �ѱ�
		oldTime = (int)time(NULL);
	}

	if (onOff == 0) { // Ÿ�̸� ����, �ú��ʸ� timerBuffer �� ����
		secToHHMMSS((int)time(NULL) - oldTime, timerBuffer, sizeof(timerBuffer));
	}

}


void secToHHMMSS(int secs, char* s, size_t size) { // ������ �� ��(sec)�� �Է� �޾�, "06:17:20" ���� ������ ���ڿ��� �ú��ʸ� �迭�� ����
	int hour, min, sec;

	sec = secs % 60;
	min = secs / 60 % 60;
	hour = secs / 3600;

	sprintf_s(s, size, "%02d:%02d:%02d", hour, min, sec);
}

/*���α׷� �ҽ� ��*/