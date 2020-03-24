#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

typedef long long int bigint;

void my_itoa(char *buffer,bigint num){
  snprintf(buffer,MAX,"%lld",num);
}

bigint reorder(bigint num){
  char *strnum = malloc(sizeof(char)*20);
  my_itoa(strnum,num);
  int len = strlen(strnum);
  char temp;  

  for(int i=0;i<len-1;i++){
    for(int j=i+1;j<len;j++){
      if (strnum[i]<strnum[j]){
        temp = strnum[i];
        strnum[i] = strnum[j];
        strnum[j] = temp;
      }
    }
  }

  return atoll(strnum);
}

void allnums(bigint num,bigint arr[4]){
  arr[0] = num+1;
  arr[1] = num-1;
  arr[2] = num*num;
  arr[3] = reorder(num);
  return;
}

typedef struct queuenode NODE;
typedef struct queue QUEUE;

struct queuenode{
  bigint data;
  int steps;
  NODE* next;
};

struct queue{
  NODE* first;
  NODE* last;
};

NODE* newnode(bigint k,int steps){
  NODE* temp = malloc(sizeof(NODE));
  temp->data = k;
  temp->steps = steps;
  temp->next = NULL;
  return temp;
}

QUEUE* newqueue(){
  QUEUE* q = malloc(sizeof(QUEUE));
  q->first=q->last=NULL;
  return q;
}

NODE* dequeue(QUEUE* q){
  if (q->first == NULL)
    return NULL;

  NODE* temp = q->first;
  q->first = q->first->next;
  
  if (q->first == NULL)
    q->last = NULL;

  return temp;
}

void enqueue(QUEUE* q,bigint k,int steps){
  NODE *n = newnode(k,steps);

  if (q->last == NULL){
    q->first = q->last = n;
    return;
  }

  q->last->next = n;
  q->last = n;
}

int isEmpty(QUEUE *q){
  if (q->first==NULL)
    return 1;
  return 0;
}

int main(){
  QUEUE *q = newqueue();
  bigint curr = 0;
  enqueue(q,curr,0);
  bigint target;
  printf("ENTER THE TARGET NUMBER:");
  scanf("%lld",&target);
  putchar('\n');
  int prevsteps = 0;
  NODE *temp;

  bigint nums[4];
  while (curr != target){

    temp = dequeue(q);
    curr = temp->data;
    prevsteps = temp->steps;

//    printf("%lld\n",curr);
    allnums(curr,nums);
    for(int i=0;i<4;i++){
      enqueue(q,nums[i],prevsteps+1);
    }
  }
  printf("It takes %d steps to get to the number %lld.\n",temp->steps,curr);
}
