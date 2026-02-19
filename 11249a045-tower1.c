#include<stdio.h>
#include<conio.h>
void towers(int,char,char,char);
int main()
{
    int num;
    printf("enter the number of disks:");
    scanf("%d",&num);
    printf("the sequence of moves involved in towers of hanoi:/t");
    towers(num,'A','B','C');
    return 0;
}
void towers(int num, char source,char dest,char spare)
{
    if(num==1)
    {

        printf("move the disc 1 source %c to dest %c\n",source,dest);
        return;
    }
    towers(num-1,source,spare,dest);
    printf("move the disc %d source %c to dest %c\n",num,source,dest);
    towers(num-1,spare,dest,source);
}



