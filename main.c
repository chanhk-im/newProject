#include "credit.h"

// 애플리케이션용 함수 원형
void create_record();
void read_record();
void update_record();
void delete_record();
void list_record();
void sp_read_record(); // 특정 수강종류에 대한 과목만을 출력
void average_record(); // 현재까지 수강한 모든 과목들의 평균 출력
void sort_record(); // 현재까지 수강한 과목들을 학기순으로 정렬
void storage_record(); // 모든 레코드 내용을 적절한 형식의 보고서 파일로 저장
void read_storage_record(); // 모든 레코드 내용을 데이터 파일 형태로 저장


int main(){
    int menu;
    while(1){
        printf("\nMenu : 1.Create 2.Read 3.Update 4.Delete 5.List 6.SP_Read 7.Average 8.Sort 9.Storage_record 11.read _Storage_record 0.Quit > ");
        scanf("%d", &menu);
        printf("\n");
        switch(menu){
            case 1: 
                create_record();
                break;
            case 2: 
                read_record();
                break;
            case 3: 
                update_record();
                break;
            case 4: 
                delete_record();
                break;
            case 5: 
                list_record();
                break;
            case 6: 
                sp_read_record();
                break;
            case 7: 
                average_record();
                break;
            case 8: 
                sort_record();
                break;
            case 9: 
                storage_record();
                break;
            case 11: 
                read_storage_record();
		break;
            case 0: 
            default: 
                return 0;
        }
    }
    return 0;
}

void create_record(){
    char name[30], class[20], code[20];
    int semester;
    float credit, grade;
    int max = c_is_available();
    if(max==1){
        printf("Enter a new lecture's info.\n");
        printf("Semester > ");
        scanf("%d", &semester);
        printf("class > ");
        scanf("%s", class);
        printf("code > ");
        scanf("%s", code); // search_by_code 만들어야됨.
        printf("name> ");
        scanf("%s", name);
            if(c_search_by_name(name)) {
                printf("Duplicated name!\n");
                return;
            }
        printf("Credit > ");
        scanf("%f", &credit);
        printf("Grade > ");
        scanf("%f", &grade); 
        c_create(semester, class, code, name, credit, grade);
         }
    else
    {
        printf("There is no space \n");
    }
}

void read_record(){
    T_Record* records[MAX_CREDIT];
    c_get_all(records);
    char name[20];
    printf("Enter the name > ");
    scanf("%s", name);
    T_Record *p = c_search_by_name(name);
    if(c_search_by_name(name)) {
            printf("Lecture info.\n");
            printf("Semester : %d \n", c_getsemester(p));
            printf("Class : %s \n", c_getclass(p));
            printf("Code : %s \n", c_getcode(p));
            printf("Name : %s \n", c_getname(p));
            printf("Credit : %.1f \n", c_getcredit(p));
            printf("Grade : %.1f \n", c_getgrade(p));
        }
    else
        printf("No such lecture \n"); 
}

void update_record(){
	char name[20], class[20], code[20];
	int semester;
	float credit, grade;  
   	printf("Enter a lecture name > ");
    	scanf("%s", name);

    T_Record* p = c_search_by_name(name);
    if(p) {
        printf("Enter a updated info.\n");
        printf("Semester > ");
	scanf("%d", &semester);	
        printf("Class > ");
        scanf("%s", class);
        printf("Code > ");
        scanf("%s", code);
        printf("Credit > ");
        scanf("%f", &credit);
        printf("Grade > ");
        scanf("%f", &grade);

        c_update(p,semester, class, code, credit, grade);
    }
    else {
        printf("No such lecture\n");
    }
}

void delete_record(){
	char name[20];
    printf("Enter a name > ");
    scanf("%s", name);

    T_Record* p = c_search_by_name(name);
    if(p) {
        c_delete(p);
        printf("The record is deleted!\n");
    }
    else {
        printf("No such lecture!\n");
    }
}

void list_record(){
    printf("All records.\n");
    int size = c_count();
    T_Record* records[MAX_CREDIT];
    c_get_all(records);
    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        printf("%d. %s\n", i+1, c_to_string(p));
    }
}

void sp_read_record(){
	 T_Record* records[MAX_CREDIT];
   	 c_get_all(records);
    	int size = c_count();
   	int sem;
	int count=0;
   	 printf("Enter the specific semester.");
    	scanf("%d", &sem);
    	for(int i=0; i<size; i++){
       		T_Record* p = records[i];
        	if(p->semester==sem){
			count++;
           		printf("%d. %s\n", count, c_to_string(p));
       		 }    
    	}
}

void average_record(){
	T_Record* records[MAX_CREDIT];
   	c_get_all(records);
   	int size = c_count();
    	float sum=0;
    	float average=0;
     	 for(int i=0; i<size; i++){
         	T_Record* p = records[i];
        	sum += p->grade;    
    	 }	
    	average = sum/size;
    	printf("Average Credit is %.2f.", average);
}
void sort_record(){
	T_Record* records[MAX_CREDIT];
   	c_get_all(records);
	int size = c_count();
	T_Record* p = records[0];
	c_sort(p, size);
}
void storage_record(){
    T_Record* records[MAX_CREDIT];
    c_get_all(records);
    int size = c_count();
    FILE* f = fopen("credit.txt", "w");
    printf("All record. \n");
    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        fprintf(f, "%s\n", c_to_string_file(p));
    }
    fclose(f);
}

void read_storage_record(){
    printf("All data will be deleted and new records will be reloaded.\n");
    printf("1.Yes 0.No > ");
    int yesno;
    scanf("%d", &yesno);
    if (yesno == 0) return;
    c_init();

    FILE* f = fopen("credit.txt", "r");
    char name[30], class[20], code[20];
    int semester;
    float credit, grade;

    while(!feof(f)){
        if(!c_is_available()) {
            printf("There is no space!\n");
            break;
        }
        int n = fscanf(f,"%d %s %s %s %f %f", &semester ,class, code, name, &credit, &grade);
        if (n<6) break;
        if(c_search_by_name(name)) {
            printf("Duplicated name(%s)! loading.\n", name);
            continue;
        }
        c_create(semester, class, code, name, credit, grade);
    }
    printf("%d records are read from file!\n", c_count());    
    fclose(f);
}

