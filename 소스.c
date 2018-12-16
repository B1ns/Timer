/* 정의 */

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


/*사용된 헤더파일*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

/*함수선언*/

int timer();
int menu1();
int menu2();
int menu3();
int alarm();

char line();
char timerBuffer[8 + 1];
void stopwatch(int onOff);
void secToHHMMSS(int secs, char* s, size_t size);

/* 메인함수 */

int main()
{
	YELLOW
		int num;
	TAB6 printf(" Timer\n");
	TAB4 printf("\t    시간을 아껴쓰자.\n");
	line();
	timer();
	line();
	TAB4 printf(" 시계,알람,스톱워치 - (c) H1222 정빈 \n");
	line();
	TAB4 printf("※1번: 한국시간 ※2번 알람 ※3번 스톱워치 \n");
	printf("\n");
	TAB4 printf("※종료하고 싶다면 아무키나 입력해주세요. \n");
	TAB4 printf("\t  번호를 입력해주세요: ");
	scanf_s("%d", &num);

	switch (num) // 원하는 기능을 선택하기위한 switch 문 
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
		printf("종료하기 \n");
	}
	system("PAUSE");
	return 0;
}

/* 여기서 부터 사용자 정의 함수 입니다. */

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

/* 코드를 줄이기위한 line 을 그려줄 함수. */

char line() {
	char line[102] = { "---------------------------------------------------------------------------------------------------\n" };
	printf(line);
	return 0;
}

/*알람을 울리기위한 이스케이프 코드를 사용함 .feat 경고음*/

int alarm() {
	int sound[] = { MI, DO, SOL, DO, SOL, RA, SOL, DO, RA ,SOL, MI, SOL };
	/*미 -> 도 -> 솔 -> 도 -> 솔 -> 라 -> 솔 -> 도 -> 라 -> 솔 -> 미 ->솔*/
	for (int t = 0; t < 2; t++)
	{
		for (int i = 0; i < 8; i++)	//2번 출력
		{
			Beep(sound[i], 200);
			Sleep(1000);		//1초 쉼표
		}
	}

	return 0;
}
/* 한국시간을 24시 형태로 표현하는 함수 */
int menu1()
{
	struct tm korea_time;

	time_t ti;

	while (1)
	{

		system("cls");
		time(&ti);
		korea_time = *localtime(&ti);

		TAB6 printf("  한국 시간    \n");
		line();
		TAB6 printf("(C)만든이:정빈\n");
		line();
		TAB4 printf("\t☞ %d 시 ", korea_time.tm_hour);
		printf("☞ %d 분 ", korea_time.tm_min);
		printf("☞ %d 초 \n", korea_time.tm_sec);
		printf("\n");
		TAB4 printf("    ※종료하실때는 Ctrl_C 를 눌러주세요.\n");
		Sleep(1000);

	}
	system("PAUSE");
	system("cls");
	main();
	return 0;
}
/* 타이머 함수 */
int menu2()
{
	system("cls");

	int minutes = 0;
	int seconds = 0;

	line();
	TAB4 printf("\t시간을 입력해주세요 ?분 ?초");
	NextLine
		line();
	printf("입력 : ");
	scanf_s("%d %d", &minutes, &seconds);


	while (minutes || seconds)
	{
		system("cls");
		NextLine
			line();
		TAB6 printf("%d분 %d초\t", minutes, seconds--);
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
	TAB6 printf("%d분 %d초\n", minutes, seconds--);
	line();
	alarm();
	TAB4 printf("\t     알람시간 종료!\n");
	alarm();
	system("PAUSE");
	system("cls");
	main();
	return 0;
}
/* 스탑워치 함수 */
int menu3() {


	stopwatch(1); // 1을 인수로 넣으면 타이머가 켜짐
	TAB4 puts("    타이머 ON! 아무키나 누르면 종료");

	// 유저가 아무 키나 누를 때까지 무한정 대기
	_getch(); // _getch() 는 getch() 의 보안 강화 버전


	stopwatch(0); // 0을 넣으면 타이머가 꺼지고 시간 문자열을 버퍼에 설정
	TAB4 printf("    타이머 OFF! 경과 시간은: [%s]\n", timerBuffer);

	system("PAUSE");
	system("cls");
	main();
	return 0;
}

void stopwatch(int onOff) {
	static int oldTime; // stopwatch 함수가 종료되어도 값을 기억하는 "정적 지역 변수"

	if (onOff == 1) { // 타이머 켜기
		oldTime = (int)time(NULL);
	}

	if (onOff == 0) { // 타이머 끄고, 시분초를 timerBuffer 에 저장
		secToHHMMSS((int)time(NULL) - oldTime, timerBuffer, sizeof(timerBuffer));
	}

}


void secToHHMMSS(int secs, char* s, size_t size) { // 정수로 된 초(sec)를 입력 받아, "06:17:20" 등의 형식의 문자열로 시분초를 배열에 저장
	int hour, min, sec;

	sec = secs % 60;
	min = secs / 60 % 60;
	hour = secs / 3600;

	sprintf_s(s, size, "%02d:%02d:%02d", hour, min, sec);
}

/*프로그램 소스 끝*/
