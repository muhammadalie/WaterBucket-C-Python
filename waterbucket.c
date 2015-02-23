#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
        int bucA;
        int bucB;
	int oldA;
	int oldB;
        struct node* next;
};
void push(struct node** headRef, int a,int b) {
	struct node* newNode = malloc(sizeof(struct node));
	newNode->bucA = a;
	newNode->bucB = b;
	newNode->oldA = 0;
        newNode->oldB = 0;

	newNode->next = *headRef;
	*headRef = newNode;
}
void ins(struct node* head,int a,int b,int c,int d){
	struct  node* h=head;
	while(h->next!=NULL) h=h->next;
	struct node* nh = malloc(sizeof(struct node));
	h->next = nh;
        nh->bucA = a;
        nh->bucB = b;
        nh->oldA = c;
        nh->oldB = d;

        nh->next = NULL;

}
struct node* find(struct node* h,int a,int b){
        if(h->next==0);
                if(h->bucA==a && h->bucB==b)return h;
        if(h->next!=0) find(h->next,a,b);
}

void play(struct node* h){
	struct node* m=h;
	while(m->next!=0){ m=m->next;
	}
	printf("[%d,%d]\n",m->bucA,m->bucB);
	while((m->bucA!=0)|(m->bucB!=0)){
		m=find(h,m->oldA,m->oldB);
		printf("[%d,%d]\n",m->bucA,m->bucB);
	}
}

int search(struct node* h,int a,int b){
	struct node*m =h;
        if(m->bucA==a &&m->bucB==b)return 1;
        if(m->next!=0) {
		search(m->next,a,b);
	}
}


struct node* getstate(struct node* h){
	if(h==NULL)	return NULL;
	struct node* state=h;
	state->next=NULL;
	return state;
}
int test(struct node* m,struct node* ne,int a[2],int val,int j,int k){
	int newA=a[0];
	int newB=a[1];
	if(search(m,newA,newB)!=1){
		ins(ne,newA,newB,j,k);
	}
	if(newA==val |newB==val){ return 1;}

}
int min(int a, int b){
	return(a<=b)? a:b;
}

void create(int aMax,int bMax,int val)
{
	struct node* m;
	push(&m,0,0);
	struct node* h;
	h=m;

	if(val>aMax && val>bMax){printf("value is biger than the bucket size");}
	else{
		while (1){
			struct node*  oldstate = h;
			int a[2];
			int aHas=oldstate->bucA;
			int bHas=oldstate->bucB;
			int j=aHas;
        		int k=bHas;

			a[0]=aMax;a[1]=bHas;
			if(test(m,oldstate,a,val,j,k)==1) break; // fill A from well

			a[0]=0;a[1]=bHas;
			if(test (m,oldstate, a,val,j,k)==1) break ;//empty A to well

			a[0]=aHas;a[1]=bMax;
			if(test (m,oldstate, a,val,j,k)==1) break ; // fill B from well

			a[0]=aHas;a[1]=0;
			if(test (m,oldstate, a,val,j,k)==1) break ;//empty B to well

			int howmuch = min(aHas, bMax-bHas);
			a[0]=aHas-howmuch;a[1]=bHas+howmuch;
			if(test (m,oldstate, a,val,j,k)==1) break ;// pour A to B

			howmuch = min(bHas, aMax-aHas);
			a[0]=aHas+howmuch;a[1]=bHas-howmuch;
			if(test (m,oldstate, a,val,j,k)==1) break ;// pour B to A

			j=aHas;
			k=bHas;
			if(h->next!=0)h=h->next;
		}

		play(m);
	}
}

main()
{
	struct node* h;
	create(7,11,3);

}

