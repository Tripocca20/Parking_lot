#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 2
#define M 2
#define P 2
struct car{
	int num;
	int arrival;
	int departure;
	struct car* next;
	struct car* prior;
};

typedef struct{
	car* elem;
	int size;
	int top;
}Park;


typedef struct{
	car* front;
	car* rear;
	int size;
}Lane;

void InitPark(Park *a);
void InitLane(Lane *a);
void Menu(Park *a,Lane*b);
void PushLane(Lane*l,int num,int atime);
void PushPark(Park*p,int num,int atime);
int SearchPark(int num,Park* p);
car* SearchLane(int num,Lane *l);
int LeaveLane(int num,int dtime,Lane*l);
int LeavePark(int num,Park*p,Lane*l,int dtime);
void DisplayPark(Park*p);
void DisplayLane(Lane*l);
void Exit(Park*p,Lane*l);

int main() {
	Park* p;
	Lane* l;
	p=(Park*)malloc(sizeof(Park));
	l=(Lane*)malloc(sizeof(Lane));
	InitLane(l);
	InitPark(p);
	Menu(p,l);
	return 0;
}

void InitPark(Park *a)
{
	a->elem=new car[N];
	a->size=N;
	a->top=-1;
}

void InitLane(Lane*a){
	a->front=a->rear=(car*)malloc(sizeof(car));
	a->front->next=a->front->prior=a->front;
	a->rear->next=a->rear->prior=a->front;
	a->size=0;
}

void Menu(Park *p,Lane* l){
	int flag=1;
	char ch;
	while(flag)
	{
		int temp1,temp2,temp;
		printf("---------------------ͣ��վģ��---------------------\n");
		printf("�����ʽ������/��ȥ,�������պ���,�ﵽ/��ȥ��ʱ�̣�\n");
		printf("�����루A:�����վ D�������վ P��������ʾͣ�������� W��������ʾ������� E�������˳�����\n");
		scanf("('%c',%d,%d)",&ch,&temp1,&temp2);
		switch (ch)
		{
		case 'A':
			{
				if(p->top==p->size-1)
				{
					if(l->size==M)
						{
							printf("�������\n");
						}
					else
						{
							PushLane(l,temp1,temp2);
						}

				}
				else{
					PushPark(p,temp1,temp2);
				}
				break;}
		case 'D':
		{
			temp=SearchPark(temp1,p);
			if(temp==-1)
			{
				LeaveLane(temp1,temp2,l);
			}
			else{
				LeavePark(temp,p,l,temp2);
			}
			break;
		}
		case 'E':
			Exit(p,l);
		case 'P':
		{
			DisplayPark(p);break;
		}
		case 'W':
		{
			DisplayLane(l);
		}
		default:
			break;
		}
		getchar();
	}
}

void PushLane(Lane*l,int num,int atime){
	car* a=(car*)malloc(sizeof(car));
	a->num=num;
	a->arrival=atime;
	a->next=NULL;
	a->prior=NULL;
	l->size++;
	a->prior=l->rear;
	a->next=l->front;
	l->rear->next=a;
	l->rear=a;
	l->rear->next=l->front;
	printf("�ó��Ѿ���������ǰ������%d�������Ŷ�\n",l->size-1);
}
void PushPark(Park*p,int num,int atime){
	car a;
	a.num=num;
	a.arrival=atime;
	a.next=NULL;
	p->top++;
	p->elem[p->top]=a;
	printf("�ó��Ѿ�����ͣ������ͣ��%d��λ\n",p->top+1);
}

int SearchPark(int num,Park* p){
	int i;
	for(i=0;i<=p->size-1;i++)
	{
		if (p->elem[i].num==num)
		{
			return i;
		}
		
	}
	return -1;
}

car* SearchLane(int num,Lane *l){
	car* a=(car*)malloc(sizeof(car));
	a->num=num;
	a->next=l->front->next;
	do
	{
		if(a->next->num!=num)
		{
		a->next=a->next->next;
		}
		else
			return a;
	}while(a->next!=l->front);
	free(a);
	return NULL;
}

int LeaveLane(int num,int dtime,Lane*l){
	car* a=(car*)malloc(sizeof(car));a=SearchLane(num,l);
	if(a==NULL)
		{printf("δ�ҵ��˳�\n");delete a;return -1;}
	else
	{
		printf("�ó��ڱ����ͣ��%d���ӣ����շ�0Ԫ\n",dtime-a->next->arrival);
		a->next->prior->next=a->next->next;
		a->next->next->prior=a->next->prior;
		if(a->next==l->rear)
			l->rear=a->next->prior;
		free(a->next);
		free(a);
		l->size--;
	}
	return 0;
}

int LeavePark(int num,Park*p,Lane*l,int dtime){
	car* a=(car*)malloc(sizeof(car));
	a->arrival=p->elem[num].arrival;
	a->num=p->elem[num].num;
	a->departure=dtime;
	for(int j=num;j<=p->top-1;j++)
	{
		p->elem[j]=p->elem[j+1];
	}
	if(l->size==0)
	{
		p->top--;
	}
	else
	{
		l->front->next->arrival=dtime;
		p->elem[p->top]=*l->front->next;
		l->front->next->next->prior=l->front;
		l->front->next=l->front->next->next;
		l->size--;
	}
	int time=a->departure-a->arrival;
	printf("�ó���ͣ����ͣ��%d���ӣ����շ�%dԪ\n",time,time*P);
	return 0;
}

void DisplayPark(Park*p){
	for(int i=0;i<=p->top;i++)
	{
		printf("%d��λ��ͣ���������ƺţ�%d\n",i+1,p->elem[i].num);
	}
	for (int i=p->top+1;i<=N-1;i++)
	{
		printf("%d��λĿǰ����\n",i+1);	
	}
}

void DisplayLane(Lane*l){
	if(l->size==0)
	{
		printf("���Ŀǰ����\n");
	}
	else
	{
		car* c;
		c=l->front->next;
		for(int i=1;;i++)
		{
			printf("%d��λ�ȴ����������ƺţ�%d\n",i,c->num);
			if(c==l->rear) break;
		}
	}
}

void Exit(Park*p,Lane*l){
	delete [] p->elem;
	p->top=-1;
	p->size=0;
	while(l->front)
	{
		l->rear=l->front->next;
		free(l->front);
		l->front=l->rear;
	}
}