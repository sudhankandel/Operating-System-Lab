#include<stdio.h>
void main()
{
int buffer[10],bufsize,in,out,produce,consume,choice;
in=0,out=0,bufsize=10;
while(choice!=3)
{
printf("\n1. Produce");
printf("\n2. Consume");
printf("\n3. Exit");
printf("\n\nEnter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
if((in+1)%bufsize==out)
printf("\nBuffer is full");
else
{
printf("Enter the value ");
scanf("%d",&produce);
buffer[in]=produce;
in=(in+1)%bufsize;
}
break;
case 2:
if(in==out)
printf("\nBuffer is Empty");
else
{
consume=buffer[out];
printf("\nThe consumed value is %d",consume);
out=(out+1)%bufsize;
}
break;
}
}
}