#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CREDIT 50   // 저장할 수 있는 회원 레코드 최대 갯수

// 회원 정보 레코드의 데이터 타입을 정의함

typedef struct st_credit
{
    int semester;
    char class[20];
    char code[20];
    char name[40];
    float credit;
    float grade;
} T_Record;

int c_count(); // 현재 저장된 과목들의 수 가져오기
int c_pass();
int c_fail();
int c_first_available(); // 추가 할 수 있는 가장 빠른 배열의 위치 찾기
int c_is_available();
void c_get_all(T_Record* a[]); // 과목에 대한 정보가 들어있는 모든 레코드 포인터들의 배열      만들기
T_Record* c_search_by_name(char* n); // 이름이 일치하는 특정 과목 레코드 찾기
char* c_getname(T_Record* p);  // 특정 레코드의 과목이름 가져오기
char* c_getcode(T_Record* p); // 특정 레코드의 과목코드 가져오기
char* c_getclass(T_Record* p);  // 특정 레코드의 수강 종류 가져오기
char* c_to_string(T_Record* p);
int c_getsemester(T_Record* p);  // 특정 레코드의 학기정보 가져오기
float c_getcredit(T_Record* p);  // 특정 레코드의 학점 가져오기
float c_getgrade(T_Record* p);  // 특정 레코드의 성적 가져오기
void c_create(int s, char* cl, char* cd, char* n, float c, float g); // 수강과목에 신규 과목 추가
void c_update(T_Record* p, int s, char* cl, char* cd, float c, float g); // 특정과목의 정보 변경
void c_delete(T_Record* a); // 특정 과목 레코드의 정보제거
void c_sort(T_Record* a, int n); // 학기순으로 레코드들을 재배
void c_init();
char* c_to_string_file(T_Record* p);
