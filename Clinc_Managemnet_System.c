#include<stdio.h>
#include"STD_TYPES.h"
#include<stdlib.h> 
#include <string.h>
 
void admin(void);
void user(void); 
void add(void);
u32 existid(u32 a);
void print(void);
void edit(void);
void cancel(void);
void addslot(s8 slot1[6]);
void removeslot(s8 slot2[6]);
void printslots(void);
void viewrecord(void);


 

typedef struct patient
{
	u32 id;
	u32 age;
	s8 name[21];	 
	s8 gander[7];
	s8 slot[6];
	struct patient *next;
}patient;
 
typedef struct slots
{
	s8 slot[6];
	struct slots *next;
}slots;

 
 
patient *head=NULL; 
patient *tail=NULL;
slots *head1=NULL;
slots *tail1=NULL;
s32 max=0;
 

int main()
{
	u32 choose,i=0,pass;
	s8 time[6];
	//making slot 
	strcpy(time, "2:30");
	addslot(time);
	strcpy(time, "3:00");
	addslot(time);
	strcpy(time, "3:30");
	addslot(time);
	strcpy(time, "4:00");
	addslot(time);
	strcpy(time, "4:30");
	addslot(time);
	do 
	{
	    printf("\n1-admin\n2-user\n3-Exit\nyour choice:");
	    scanf("%u",&choose);
	    switch(choose)
	    {
            case 1: 
            for( i = 0;i < 3; i++)
	        {
		        printf("Please write Password:");
		        scanf("%u",&pass);
		        if(pass ==1234)
		        {
			        printf("\n#welcome#\n"); 
			        admin();
			        break;
		        }
		        else 
		        {
		            printf("\n#Wrong password,please try again#\n\n");
		        }
	        }
	        if(i==3)
	        {
	            printf("\n#you entered pass 3 times wrong#\n\n");
	            return 0;
	        }
	        break;
	        case 2:
            user();
	        break; 
            case 3:
            break;	
	    }
	}while(choose!=3);
}




void admin (void)
{
    u32 x;
	do
	{
		printf("\n1-Add patient ");
	    printf("\n2-Edit patient");
	    printf("\n3-Reseve slots");
	    printf("\n4-Cancel reservation ");
	    printf("\n5-go back");
	    printf("\nType your choice:");
	   
	    scanf("%u",&x);
		switch(x)
	    {
		    case 1:
		    add();
		    break;
		    case 2:
		    edit();
		    break;
		    case 3:
		    print();
		    break;
		    case 4:
		    cancel();
		    break;
		    case 5:
		    break;
		    default:printf("\nwrong choice");
	    }
	}while(x!=5);
	
}	





void user(void)
{
	u32 x;
	do
	{
		printf("\n1-view patient record");
	    printf("\n2-Reseve slots");
		printf("\n3-go back");
		printf("\nyour choice:");
		scanf("%u",&x);
		switch(x)
	    {
		    case 1:
		    viewrecord();
		    break;
		    case 2:
		    print();
		    break;
		    case 3:
		    break;
		    default:
			printf("\nwrong choice");
			break;
		}
	}while(x!=3);
}




void add(void)
{
	if (max<5)
	{	 
	    u32 a,b=0;
	    while(b!=1)
	    {
		    printf("\nEnter ID:");
	        scanf("%u",&a);
		    b=existid(a);
		    if(b==1)
		    {
		    	break;
		    }
		    else if(b==2)
		    {
			    printf("\n#already existed ID try another one#\n");
		    }	
	    }
	    if (head==NULL)
	    {
	        patient *ptr=(patient*) malloc(sizeof(patient));
		    head=ptr;
		    tail=ptr;
		    ptr->next=NULL;
		    ptr->id=a;
		    printf("\nEnter his name:");
		    scanf("%s",ptr->name);
		    printf("\nEnter his gander:");
		    scanf("%s",ptr->gander);
		    printf("\nEnter his age:");
		    scanf("%u",&ptr->age);
		    printslots();
		    scanf("%s",ptr->slot);
		    removeslot(ptr->slot);
		    max++;
		}
	    else
	    {
		    patient *ptr=(patient*) malloc(sizeof(patient));
	        ptr->next=NULL;
		    tail->next=ptr;
		    tail=ptr;
		    ptr->id=a;
		    printf("\nEnter his name:");
		    scanf("%s",ptr->name);
		    printf("\nEnter his gander:");
		    scanf("%s",ptr->gander);
		    printf("\nEnter his age:");
		    scanf("%u",&ptr->age);
		    printslots();
		    scanf("%s",ptr->slot);
		    removeslot(ptr->slot);
		    max++;
	    }  
	}
	else
	{
		printf("\n#full reservation#\n");
	}
}
 
 
 


 
u32 existid(u32 a)
{
    u32 b;
	if(head==NULL)
	{
		b=1;
	}
	else
	{
		patient *mover;
		mover=head;
		while(mover!=NULL)
		{
			if(mover->id==a)
			{
				b=2;
			}
			else if(mover->next==NULL)
			{
				b=1;
			}	
			mover=mover->next;
		}
	}
	return b;
}
 
 
void print(void)
{
	if (head==NULL)
	{
		printf("\n#there is no reservation#\n");
	}
	else
	{
		patient *mover;
		mover=head;
		printf("today's resevations:-\n");
		while(mover!=NULL)
		{
			printf("ID:%u\n",mover->id);
            printf("Name:%s\n",mover->name);			
			printf("slot:%s\n",mover->slot);
			mover=mover->next;
		}
	}
}
 
 
 
 
 
void edit(void)
{
	u32 id,b,c=0;
	patient *mover;
    mover=head;
	printf("\nplease enter the id:");
	scanf("%u",&id);
	if(head==NULL)
	{
		printf("\n#there is no reservation#\n");
	}
	else
	{
		while(mover!=NULL)
		{
			if(mover->id==id)
			{
				c=1;
				break;
			}
			else if(mover->next==NULL)
			{
				printf("\nincorrect ID");
			}	
			mover=mover->next;
		}
	}
	if(c==1)
	{
		printf("\n1-edit the name");
	    printf("\n2-edit the gander");
	    printf("\n3-edit the age");
		printf("\n4-edit the slot");
	    printf("\nyour choice:");
	    scanf("%u",&b);
	    switch(b)
	    {
	        case 1:
			{
	            s8 name1[21];	 
			    printf("\nenter the name:");
			    scanf("%s",name1);
			    strcpy(mover->name, name1);
			}
			break;
	        case 2:
	        {
				s8 gander1[7];
			    printf("\nenter the gander:");
			    scanf("%s",gander1);
			    strcpy(mover->gander, gander1);
			}
			break;
	        case 3:
			{
				u32 age1;
			    printf("\nenter the age:");
			    scanf("%u",&age1);
			    mover->age=age1;
			}
			break;
			case 4:
			{
				s8 time1[6];
			    printslots();
		        scanf("%s",time1);
			    addslot(mover->slot);
			    strcpy(mover->slot,time1);
			    removeslot(time1);
			}
			break;
        }
	 }	 
}
 
 
void cancel(void)
{
	u32 id,c=0;
	s8 time[6];
	patient *mover=head;
	patient *mover1=head;
	if(head==NULL)
	{
	    printf("\n#there is no reservation#\n");
	}
	else
	{
		printf("\nplease enter the id:");
	    scanf("%u",&id);
        if(head->id==id&&head->next==NULL)
        {
			strcpy(time, head->slot);
	        addslot(time);
            free(head);
		    head=NULL;
		    tail=NULL;
		    max--;
	    }
	    else if(head->id==id&&head->next!=NULL)
	    {
			strcpy(time, mover->slot);
	        addslot(time);
		    head=head->next;
		    free(mover);
		    mover=NULL;
		    max--;
	    } 
	    else
	    {
		    mover1=mover1->next;
            while(mover1!=NULL)
		    {
		        if (mover1->id==id)
			    {
				    c=1;
					break; 
			    }
			    mover1=mover1->next;
			    mover=mover->next;
		    } 
		    if(c==1)
		    {
				strcpy(time, mover1->slot);
	            addslot(time);
			    mover->next=mover1->next;
			    if (mover1 == tail) 
			    {
                    tail = mover;
                }
			    free(mover1);
			    mover=NULL;
			    mover1=NULL;
			    max--;
		    }
		    else
		    {
			    printf("\n#incorrect id#\n");
		    }
		  
	    }
	}
	
}



void addslot(s8 slot1[6])
{
    if(head1==NULL)
	{
		slots *ptr=(slots*) malloc(sizeof(slots));
		head1=ptr;
		tail1=ptr;
		ptr->next=NULL;
		strcpy(ptr->slot, slot1);
	}
	else
	{
		slots *ptr=(slots*) malloc(sizeof(slots));
	    ptr->next=NULL;
		strcpy(ptr->slot, slot1);
		tail1->next=ptr;
		tail1=ptr;
	}
}
 
 
void removeslot(s8 slot2[6])  
{
	slots *mover=head1;
	slots *mover1=mover->next;
    if(head1->next==NULL&&strcmp(head1->slot, slot2)==0)
	{
	    free(head1);
        head=NULL;		
	}  
	else if(head1->next!=NULL&&strcmp(head1->slot, slot2)==0)
	{
		head1=mover->next;
	    free(mover);
		mover=NULL;
	}
	else
	{
		while(mover1!=NULL)
		{
			if(mover1->slot==slot2)
			{	
                break;		
			}
			mover=mover->next;
			mover1=mover1->next;
		}
		mover->next=mover1->next;
		if(tail1==mover1)
		{
			tail1=mover;
		}
		free(mover1);
		mover=NULL;
		mover1=NULL;
	}
}



void printslots(void)
{
	slots *mover=head1;
	printf("choose one of these slots:\n");
	while(mover!=NULL)
	{
		printf("%s\n",mover->slot);
		mover=mover->next;
    }
}



void viewrecord(void)
{
	u32 id,c=0;
	patient *mover;
    mover=head;
	
	if(head==NULL)
	{
		printf("\n#there is no reservation#\n");
	}
	else
	{
		printf("\nplease enter the id:");
	    scanf("%u",&id);
		while(mover!=NULL)
		{
			if(mover->id==id)
			{
			    c=1;
				break;
			}
			else if(mover->next==NULL)
			{
				printf("\nincorrect ID");
			}	
			mover=mover->next;
		}
	}
    if(c==1)
    {
		printf("\nID:%u",mover->id);
		printf("\nname:%s",mover->name);
		printf("\nage:%u",mover->age);
		printf("\ngander:%s",mover->gander);
		printf("\nslot:%s",mover->slot);
	}		
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

