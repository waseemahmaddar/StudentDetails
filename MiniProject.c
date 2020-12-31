
/*      
                             ASSIGNMENT NO: 01
  PREPARED BY:
 
  WASEEM AHMAD DAR
         ROLL NO: 17CO54
         
   PROF: TABRAIZ
  
   PROBLEM DEFINATION : Implement the Mini Project of Student Database using Linked list for following requirements: 
          
    a. Creation of Student Database in memory containing student ID, Name
       Address, Contact No and Date of Birth .
    b. Insertion, Deletion of student record for a given student ID.
    c. searching of the student record.
  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stud
{
 int rn,id,ph;
 char add[30],na[20],d[15],in[5];
 struct stud *next;
}*h=NULL,*p,*q,*t,*ts;

void add()
{
  p =(struct stud *)malloc(sizeof(struct stud));
  printf("\nEnter the First name of Student : ");
  scanf("%s",p->in);
  printf("\nEnter the Last Name of Student : ");
  scanf("%s",p->na);
  printf("\nEnter the ID of Student : ");
  scanf("%d",&p->id);
  printf("\nEnter the Roll No. of Student : ");
  scanf("%d",&p->rn);
  printf("\nEnter the Ph No. of Student : ");
  scanf("%d",&p->ph);
  printf("\nEnter the Address of Student : ");
  scanf("%s",p->add);
  printf("\nEnter the D.O.B. of Student(dd/mm/yyyy) : ");
  scanf("%s",p->d);

  p->next=NULL;

  if(h==NULL)
  {
   h=p;
  }
  else
  {
    q=h;
    while(q->next!=NULL)  //TREVERSING TILL LAST STUDENT/NODE
    q=q->next;
    q->next=p;
  }
  //ts++;
}

void addAt(int r)      //FUNCTION FOR ADDING OF STUDENTS DATA AT THE GIVEN POSITION
{
 q=h;
 while(q->rn!=r || q==NULL)
  q=q->next;
 if(q->rn==r)
 {
  p =(struct stud *)malloc(sizeof(struct stud));     // CREATION OF NODE 
  printf("\nEnter the First name of Student : ");
  scanf("%s",p->in);
  printf("\nEnter the Last Name of Student : ");
  scanf("%s",p->na);
  printf("\nEnter the ID of Student : ");
  scanf("%d",&p->id);
  printf("\nEnter the Roll No. of Student : ");
  scanf("%d",&p->rn);
  printf("\nEnter the Ph No. of Student : ");
  scanf("%d",&p->ph);
  printf("\nEnter the Address of Student : ");
  scanf("%s",p->add);
  printf("\nEnter the D.O.B. of Student(dd/mm/yyyy) : ");
  scanf("%s",p->d);
  p->next=q->next;
  q->next=p;
  //ts++;
 }
 else
 {
  printf("\n\nRecord Not Found.");
 }
}


void delAt(int r)     // FUNCTION FOR DELETING THE STUDENT DATA/NODE
{
	struct stud *prev;
	 q=h;
	 prev=h;	  

	 while(q->rn!=r && q!=NULL){
		 printf("\nInside While");
		 prev=q;
		 q=q->next;
	  }
	  
	 if(q->rn==r)
	 {
		 if(q==h)
			h=q->next;
		 else		
			prev->next=q->next;	
		 free(q);
		 printf("\n\nRecord Deleted.");
		//  ts--;
	 }
	 else
	 {
			printf("\n\nRecord Not Found.");
	 }
}
 void  search(char ni[5])     /*FUNCTION FOR SEARCH THE GIVEN STUDENT NODE*/
{
 int flag=0;
 q=h;
 while(q!=NULL)
 {
  if(strcmp(q->in,ni)==0)
  {
  flag=1;
  printf("\n\nFirst name of Student :   %s ",q->in);
  printf("\n\nLast Name of Student : %s ",q->na);
  printf("\n\nID of Student :        %d ",q->id);
  printf("\n\nRoll No. of Student :  %d",q->rn);
  printf("\n\nPh No. of Student :    %d",q->ph);
  printf("\n\nAddress of Student :   %s",q->add);
  printf("\n\nD.O.B. of Student :    %s",q->d);
  printf("\n\n\n");
  }
  q=q->next;
 }
 if(flag==0)
  printf("\n\nNo Match Found.");
}


void disp()
{
 p=h;
 while(p!=NULL)
 {
  printf("\nFirst name of Student :   %s ",p->in);
  printf("\nName of Student :      %s ",p->na);
  printf("\nID of Student :        %d ",p->id);
  printf("\nRoll No. of Student :  %d",p->rn);
  printf("\nPh No. of Student :    %d",p->ph);
  printf("\nAddress of Student :   %s",p->add);
  printf("\nD.O.B. of Student :    %s",p->d);
  printf("\n\n");
  p=p->next;
 }
}

int main()
{
 int ch=0,r;
 char ni[5];
 while(1)   // INFINITE WHILE LOOP
 {
  printf("\n1.Add the Record.\n\n2.Add Record at Locn.\n\n3.Delete Record.");
  printf("\n\n4.Search Record.");
  printf("\n\n5.Display\n\n6.Exit");
  printf("\n\nEnter the Choice: ");
  scanf("%d",&ch);
   switch(ch)     // SWITCH CASE FOR CALLING DIFFERNT FUNCTIONS
   {
    case 1:
    add();
    break;

    case 2:
    printf("\nEnter the Roll No. : ");
    scanf("%d",&r);
    addAt(r);
    break;

    case 3:
    printf("\nEnter the Roll No. : ");
    scanf("%d",&r);
    delAt(r);
    break;
    case 4:
    printf("\nEnter the First name : ");
    scanf("%s",ni);
    search(ni);
    break;
    case 5:
    disp();
    break;
    case 6:
    exit(0);
   }
 }
}
