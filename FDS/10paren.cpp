#include<iostream>
using namespace std;

class stack
{
  public:
	   int top,max,ele;
	   char s[10];
	   stack()
	   {
	     top=-1;
	     max=10;
	   }

	  int IsEmpty();
	  int Isfull();
	  char gettop();
	  char pop();
	  void push(char);
	  void wellp();
};

int stack::IsEmpty()
{
  if(top==-1)
   return 1;
  else 
    return 0;
}

int stack::Isfull()
{
   if(top==(max-1))
      return 1;
   else
      return 0;
}

char stack::gettop()
{
  if(!IsEmpty())
    return s[top];
  else
    return -1;
}

char stack::pop()
{
  int t;
  if(!Isfull())
    {
       t==s[top];
       top--;
       return t;
    } 
  else
   {
      cout<<"\n Stack is underflow";
      return -1;
   }
}
void stack::push(char exp)
{

  if(!Isfull())
   {
     top=top+1;
     s[top]=exp;
   }
  else
   {  
      cout<<"\n Stack is overflow";
   }
 }
 
 void stack::wellp()
 {
   int i=0;
   int flag=0;
   char ch;
   char exp[20];
   cout<<"\n Enter expression:";
   cin>>exp;
   while(exp[i]!='\0')
   {
     ch=exp[i];
     switch(ch)
     {
       case '(' :
       case '[' :
       case '{' :   
                  push(ch);
                  break;
       case ')':
               
               if(!IsEmpty())                 
               {
                  if(gettop()=='(')
                    pop();
                  else
                    flag=1;
               }
               else
                 flag=1; 
               break;
       case ']': 
                if(!IsEmpty())
               {
               if(gettop()=='[' )
                 pop();
               else
                flag=1;
               }
               else
                 flag=1; 
               break; 
       case '}':
                if(!IsEmpty())
               {
               if(gettop()=='{' )
                 pop();
               else
                flag=1;
               }
               else
                 flag=1; 
               break;        
      }
      i++;
     }
     if(flag==0 && IsEmpty())
       cout<<"\nExpression is  Wellprenthesized";
     else
       cout<<"\nExpression is not Wellprenthesized";  
     
   cout<<"\n";
}

int main()
{
  stack s1;
  s1.wellp();
  return(0);
  
}
  
        
   
                    
