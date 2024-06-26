#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "head.h"



void renderSignup() {
    int y = 6;  // 커서의 y값을 저장
    int cursor;  // 입력된 키보드 값을 저장
    MEMBER m1 = { "", "", "", "" };
    //구조체 포인터 저장
    MEMBER* pm = &m1;

   
    //비밀번호 *표시를 위해 하나 더 선언
    char ptPw[30] = { 0 };
    char ptChPw[30] = { 0 };
    int i = 0;   //인덱스를 0으로 저장

    //회원가입 요청후 처리 상태를 저장 할 정수 변수
    int status = 0;
    //1 : 성공
    //2 : 사용중인 이메일
    //3 : 비밀번호가 일치 하지 않음
    //4 : 빈칸이 있음

    // 맨 처음 호출 되었을때 렌더링
    gotoxy(87, y);
    printf("◀");
    gotoxy(59, 1);
    printf("회원가입");
    gotoxy(33, 6);
    printf("이름");
    gotoxy(50, 6);
    printf("│");
    gotoxy(50, 5);
    printf("┌─────────────────────────────────┐");
    gotoxy(50, 7);
    printf("└─────────────────────────────────┘");
    gotoxy(84, 6);
    printf("│");

    gotoxy(33, 9);
    printf("이메일");
    gotoxy(50, 9);
    printf("│");
    gotoxy(50, 8);
    printf("┌─────────────────────────────────┐");
    gotoxy(50, 10);
    printf("└─────────────────────────────────┘");
    gotoxy(84, 9);
    printf("│");

    gotoxy(33, 12);
    printf("비밀번호");
    gotoxy(50, 12);
    printf("│");
    gotoxy(50, 11);
    printf("┌─────────────────────────────────┐");
    gotoxy(50, 13);
    printf("└─────────────────────────────────┘");
    gotoxy(84, 12);
    printf("│");

    gotoxy(33, 15);
    printf("비밀번호 확인");
    gotoxy(50, 15);
    printf("│");
    gotoxy(50, 14);
    printf("┌─────────────────────────────────┐");
    gotoxy(50, 16);
    printf("└─────────────────────────────────┘");
    gotoxy(84, 15);
    printf("│");

    gotoxy(60, 18);
    printf("가입");

    gotoxy(60, 21);
    printf("뒤로");

    while (1) {
        if (_kbhit()) {  // 키보드 입력이 있는지 확인
            cursor = _getch();  // 입력된 키를 읽음
            if (cursor == 0 || cursor == 224) {
                // 확장 키 입력 처리 (화살표 키 등)
                cursor = _getch(); // 확장 키의 실제 값을 읽음
                switch (cursor) {
                case 72: // 위쪽 화살표
                    if (y > 6) {
                        gotoxy(87, y);
                        printf("  "); // 현재 위치의 화살표 지우기
                        y -= 3;
                        i = 0;   //인덱스 초기화
                    }
                    break;
                case 80: // 아래쪽 화살표
                    if (y < 21) {
                        gotoxy(87, y);
                        printf("  "); // 현재 위치의 화살표 지우기
                        y += 3;
                        i = 0;   //인덱스 초기화
                    }
                    break;
                }
                gotoxy(87, y);
                printf("◀");
            }
            else {
                // 일반 키 입력 처리
                switch (cursor) {
                case 13: // 엔터
                    if (y == 21) {
                        system("cls");

                        return;
                    }
                    else if (y == 18) {
                        gotoxy(45, 25);
                        //이전의 메세지 지우기 
                        printf("                                         ");
                        status = signup(pm);
                        //회원가입 요청후 반환 값에 따라 메세지 출력
                        switch (status) {
                        case 1:
                            gotoxy(55, 25);
                            printf("회원가입 성공");
                            Sleep(2000);
                            system("cls");
                            return;
                            break;
                        case 2:
                            gotoxy(50, 25);
                            printf("이미 사용중인 이메일입니다.");
                            break;
                        case 3:
                            gotoxy(50, 25);
                            printf("비밀번호가 일치하지 않습니다.");
                            break;
                        case 4:
                            gotoxy(55, 25);
                            printf("빈칸이 있습니다.");
                            break;
                        }
                    }
                    break;
                case 8:   //BackSpace가 들어왔을때 모든 항목 초기화
                    printf("%c", cursor);
                    for (int j = 0; j < sizeof(m1.name); j++) {
                        m1.name[j] = 0;
                        m1.email[j] = 0;
                        m1.pw[j] = 0;
                        m1.chPw[j] = 0;
                        ptPw[j] = 0;
                        ptChPw[j] = 0;
                    }
                    y = 6;
                    system("cls");
                    //재렌더링
                    gotoxy(87, y);
                    printf("◀");
                    gotoxy(59, 1);
                    printf("회원가입");
                    gotoxy(33, 6);
                    printf("이름");
                    gotoxy(50, 6);
                    printf("│");
                    gotoxy(50, 5);
                    printf("┌─────────────────────────────────┐");
                    gotoxy(50, 7);
                    printf("└─────────────────────────────────┘");
                    gotoxy(84, 6);
                    printf("│");

                    gotoxy(33, 9);
                    printf("이메일");
                    gotoxy(50, 9);
                    printf("│");
                    gotoxy(50, 8);
                    printf("┌─────────────────────────────────┐");
                    gotoxy(50, 10);
                    printf("└─────────────────────────────────┘");
                    gotoxy(84, 9);
                    printf("│");

                    gotoxy(33, 12);
                    printf("비밀번호");
                    gotoxy(50, 12);
                    printf("│");
                    gotoxy(50, 11);
                    printf("┌─────────────────────────────────┐");
                    gotoxy(50, 13);
                    printf("└─────────────────────────────────┘");
                    gotoxy(84, 12);
                    printf("│");

                    gotoxy(33, 15);
                    printf("비밀번호 확인");
                    gotoxy(50, 15);
                    printf("│");
                    gotoxy(50, 14);
                    printf("┌─────────────────────────────────┐");
                    gotoxy(50, 16);
                    printf("└─────────────────────────────────┘");
                    gotoxy(84, 15);
                    printf("│");

                    gotoxy(60, 18);
                    printf("가입");

                    gotoxy(60, 21);
                    printf("뒤로");
                    break;
                default: // 다른 입력은 이름에 추가
                    if (y == 6 && strlen(m1.name) < 29) {
                        m1.name[i] = cursor;
                        m1.name[i + 1] = '\0';    
                        gotoxy(52, 6);
                        printf("%-29s", m1.name);  // 최대 19글자까지 표시
                    }
                    else if (y == 9 && strlen(m1.email) < 29) {
                        m1.email[i] = cursor;
                        m1.email[i + 1] = '\0';
                        gotoxy(52, 9);
                        printf("%-29s", m1.email);
                    }
                    else if (y == 12 && strlen(m1.pw) < 29) {
                        m1.pw[i] = cursor;
                        m1.pw[i + 1] = '\0';
                        ptPw[i] = '*';
                        ptPw[i + 1] = '\0';
                        gotoxy(52, 12);
                        printf("%-29s", ptPw);
                    }
                    else if (y == 15 && strlen(m1.chPw) < 19) {
                        m1.chPw[i] = cursor;
                        m1.chPw[i + 1] = '\0';
                        ptChPw[i] = '*';
                        ptChPw[i + 1] = '\0';
                        gotoxy(52, 15);
                        printf("%-29s", ptChPw);
                    }
                    i++;
                    break;
                }
            }
        }
    }
}
