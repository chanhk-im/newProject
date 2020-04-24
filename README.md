학점 관리 CRUD 프로젝트

<사용한 구조체>
typedef struct st_credit{
    int semester; 
    
    char classes[20];
    
    char code[20];
    
    char name[40];
    
    float credit;
    
    float grade;
} T_Record;

semester - 수강한 학기.

classes - 강의의 분류 ex) 교양, 컴퓨터공학, 경영학 등등.

code - 강의코드 ex) ISE10002, ECE20010 등.

name - 강의 제목 ex) 경영학입문, 데이터구조, oss.

credit - 학점 ex) 경영학입문 = 3학점 / 공동체리더십 훈련 = 0.5 학점.

grade - 본인의 성적 4.5 = A+ 4.0 = A ... 단 PF과목의 경우 Pass는 5.0 Fail은 1.0으로 입력한다.
 
<메뉴>
1. Create: 새로운 강의 레코드를 생성해주는 메뉴.
2. Read: 특정 강의의 제목을 입력받아 그에 대한 정보를 출력해주는 메뉴.
3. Update: 특정 강의의 제목을 입력받아 강의에 대한 정보를 업데이트(수정) 해주는 메뉴.
4. Delete: 특정 강의의 제목을 입력받아 그 강의에 대한 레코드를 삭제해주는 메뉴.
5. List: 현재 레코드에 저장되어있는 모든 강의에 대한 정보를 출력해주는 메뉴.
6. SP_Read: 특정 학기에 수강한 과목에 대한 정보만을 출력해주는 메뉴.
7. Average: 전체 학점의 평균을 계산해서 출력해주는 메뉴.
8. Sort: 전체 리스트를 학기순에 따라 제정렬해주는 메뉴.
9. Storage_record: 현재 레코드에 저장되어있는 강의정보들을 "credit.txt"파일에 저장해주는 메뉴
10. read _Storage_record: "credit.txt"파일에 저장되어있는 강의에 대한 정보들을 불러오는 메뉴.
	

<make 파일>
- make main: main 실행파일 생성.
- make main_debug: main 실행파일을 디버깅 모드로 생성.
- make clean: 실행파일과 오브젝트 파일을 제거.

<실행방법>
make main 명령어를 통해 컴파일 후
./main를 통해 실행.
