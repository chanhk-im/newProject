#include "credit.h"



T_Record* credit[MAX_CREDIT]; 
int _count = 0;

int c_is_available(){
    int i;
    for(i=0; i<MAX_CREDIT; i++){
        if(credit[i]==NULL){
	#ifdef DEBUG  
            printf("[DEBUG] %d struct available\n", 10-i);
        #endif
	 return 1;
	}
    }
    return 0;
}

int c_first_available(){
    int i;
    for(i=0; i<MAX_CREDIT; i++){
        if(credit[i]==NULL) return i;
    }
    return -1;
}

int c_count(){
	#ifdef DEBUG  
            printf("[DEBUG] present record: %d\n ", _count);
        #endif
    return _count;
}

void c_create(int s, char* cl, char* cd, char* n, float c, float g){
    int index = c_first_available();
    credit[index] = (T_Record*)malloc(sizeof(T_Record));
    T_Record* p = credit[index];
    p->semester = s;
    strcpy(p->class, cl);  
    strcpy(p->code, cd);
    strcpy(p->name, n);
    p->credit = c;
    p->grade = g;
    _count++;
	#ifdef DEBUG  
            printf("[DEBUG] create %d %s %s %s %.1f %.1f\n ", s, cl, cd, n, c, g);
        #endif
}

T_Record* c_search_by_name(char* n){
    int i;
    for(i=0; i<MAX_CREDIT; i++){
        if(credit[i] && strcmp(credit[i]->name, n)==0){	
	#ifdef DEBUG  
            printf("[DEBUG] search name %s\n", n);
        #endif
	 return credit[i];
	}
    }
    return NULL;
}

void c_update(T_Record* p, int s, char* cl, char* cd, float c, float g){
    p->semester =s;
    strcpy(p->class, cl);
    strcpy(p->code, cd);
    p->credit = c;
    p->grade = g;
	#ifdef DEBUG  
            printf("[DEBUG] %s is updated\n", p->name);
        #endif
}

void c_delete(T_Record* p){
    int i, index;
    for(i=0; i<MAX_CREDIT; i++)
        if(credit[i]==p) {
            index=i;
            break;
        }
	#ifdef DEBUG  
            printf("[DEBUG] %s is deleted\n", p->name);
        #endif
    free(p);
    credit[index] = NULL;
    _count--;
}

char* c_to_string(T_Record* p){
    static char str[150];
    sprintf(str, "%d학기 / %s / [%s] / %s / %.1f학점 / 성적:%.1f ", p->semester, p->class , p->code, p->name, p->credit, p->grade);
	#ifdef DEBUG  
    		printf("[DEBUG] %d %s %s %s %.1f %.1f is recorded \n ", p->semester, p->class , p->code, p->name, p->credit, p->grade);
        #endif
    return str;
}

void c_get_all(T_Record* a[]){
    int i, c=0;
    for(i=0; i<MAX_CREDIT; i++){
        if(credit[i]){
            a[c]=credit[i];
            c++;
        }
    }
	#ifdef DEBUG  
            printf("[DEBUG] get %d record\n", c);
        #endif
}


void c_sort(T_Record* p, int n){
	int i, j;
	T_Record tmp;
	
	for(i=n; i>1; i--){
		for(j=1; j< i; j++){
			if(p[j-1].semester > p[j].semester){
				tmp = p[j-1];
				p[j-1] = p[j];
				p[j] = tmp;
			}
		}
	}
}

char* c_getname(T_Record* p){
    return p->name;
}

char* c_getclass(T_Record* p){
    return p->class;
}

char* c_getcode(T_Record* p){
    return p->code;
}

int c_getsemester(T_Record* p){
    return p->semester;
}

float c_getcredit(T_Record* p){
    return p->credit;
}

float c_getgrade(T_Record* p){
    return p->grade;
}

void c_init(){
    int i;
    for(i=0; i<MAX_CREDIT; i++){
        if(credit[i]!=NULL) {
            free(credit[i]);
        }
        credit[i] = NULL;
    }
	#ifdef DEBUG  
            printf("[DEBUG] ALL record deleted\n");
        #endif
    _count = 0;
} 

char* c_to_string_file(T_Record* p){
    static char str[150];
    sprintf(str,"%d %s %s %s %.1f %.1f ", p->semester, p->class , p->code, p->name, p->credit, p->grade);
   
	#ifdef DEBUG  
  		printf("[DEBUG] %d %s %s %s %.1f %.1f save in file \n", p->semester, p->class , p->code, p->name, p->credit, p->grade);
        #endif
	return str;
}

