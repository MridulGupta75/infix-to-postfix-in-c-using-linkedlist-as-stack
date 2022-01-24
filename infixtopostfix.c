#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node*next;
     char info;
}nt;
void insert(nt**l,char x)
{
    // int x;
    // printf("enter the info to be inserted\n");
    // scanf("%d",&x);
    nt*p=(nt*)malloc(sizeof(nt));
    p->info=x;
    if(*l==NULL)
    {
        *l=p;
        p->next=NULL;
    }
    else{
        p->next=*l;
        *l=p;
    }

}
// void disp(nt*l)
// {
//     while(l!=NULL)
//     {
//        printf("%c %c",l->info,l->next->info);
//        l=l->next;
//     }
// }

void pop(nt**l)
{
    nt*temp=*l;
    (*l)=(*l)->next;
    free (temp);
}
int getpre(char ch)
{
    if(ch=='+'||ch=='-')
    return 0;
    else if(ch=='/'||ch=='*'||ch=='%')
    return 1;
    else
    return 2;
}
int main()
{
 nt*l=NULL;
 char ch[100];
 char exp[100];
 char t;
 int c=0;
 printf("Enter the exp\n");
scanf("%s",ch);
 insert(&l,'#');
 for(int i=0;ch[i]!='\0';i++)
 {

     if((ch[i]>='A'&&ch[i]<='Z')||(ch[i]>='a'&&ch[i]<='z'))
      exp[c++]=ch[i];
      else{
          if(ch[i]=='('||(l->info)=='#')
          insert(&l,ch[i]);
         else if(ch[i]==')')
         {
             while(1)
             {
                  if(l->info=='(')
                   {
                       pop(&l);
                       break;
                   }
                 exp[c++]=l->info;
                   pop(&l);
                  
             }
         }
          else{
          
          int chu=getpre(ch[i]);
          int chu1=getpre(l->info);
          if(chu1<chu)
          insert(&l,ch[i]);
          else
          {
              while(1)
              {
                   chu1=getpre(l->info);
                  if(l->info=='('||l->info=='#')
                  {
                      insert(&l,ch[i]);
                       break;
                  }
                   else if(chu1<chu)
                  { insert(&l,ch[i]);
                  break;}
                   exp[c++]=l->info;
                   pop(&l);
                  
                   

              }
              
          }
      }
      }
 }
 
 while(1)
 {
     if(l->info=='#')
     {
         pop(&l);
         break;
     }
     exp[c++]=l->info;
     pop(&l);
     
 }
 exp[c++]='\0';
 printf("Postfix Expression\n");
 puts(exp);
 
 return 0;
}