#include <iostream>
#include <cstdlib>
#include <ctime>

typedef struct _list list;
#define MAXCODE 100
#define MAXDIP 10

struct _list {
  int code;
  list * next;
};

list * create_list(int num) {
  int * a = new int[num];
  /* initialize random seed: */
  //srand (time(NULL));
  for (int i = 0; i < num; i++) {
    a[i] = rand()%MAXCODE + 1;
    for (int j = 0; j < i; j++) {
      if (a[i] == a[j]) { i--; break;}
    }
  }
  list * res = NULL;
  for (int i = 0; i < num; i++) {
    res = new list{a[i], res};
  }
  delete [] a;
  return res;
}

list * create_enter_exit_stamps(list * const employees, const int t = 5) {
  list * res = NULL;
  for (int k = t; k >= 0; k--) {
    for (list * d = employees; d != NULL; d = d->next) {
      if (rand()%2 == 0) {
        res = new list{d->code, res};
      }
    }
  }
  return res;
}

void print_list(list * l, const char * prefix) {
  std::cout << prefix;
  for( ; l != NULL; l = l->next)
    std::cout << " " << l->code;
  std::cout << std::endl;
}

list * extract_warnings(list * employees, list * enterStamps, list * exitStamps);

int main() {
  srand(unsigned(time(0)));
	srand(0); //comment this line to obtain a deterministic behavior

  list * employees = create_list(MAXDIP);
  print_list(employees, "List of employees:");
  list * enterStamps = create_enter_exit_stamps(employees);
  print_list(enterStamps, "List of enter stamps:");
  list * exitStamps = create_enter_exit_stamps(employees);
  print_list(exitStamps, "List of exit stamps:");

  list * extractedWarnings = extract_warnings(employees, enterStamps, exitStamps);
  print_list(extractedWarnings, "Extracted Warnings:");

}

int count_in_list(list * lis, int codeIn) {
  int ret=0;
  for( ; lis != NULL; lis = lis->next){
    //lis->code;
    if (lis->code==codeIn) {
      ret++;
    }
  }
  return ret; 
}


void insert_first(list** p, int val) { 
	list* q = new list;
	q->code = val;
	q->next = (*p);
    (*p)=q;
	
}

list * extract_warnings(list * employees, list * enterStamps, list * exitStamps){
  
  list * warns = NULL;

  int countedEn=0,countedEx=0;

  for( ; employees != NULL; employees = employees->next){
      countedEn=count_in_list(enterStamps, employees->code);
      countedEx=count_in_list(exitStamps, employees->code);
      if (countedEn != countedEx) {
          insert_first(&warns,employees->code);
      }
  }

  return warns;
}
