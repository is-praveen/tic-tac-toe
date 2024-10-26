#include<stdio.h>
#include<stdlib.h>
void display(int arr[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        printf("+-----+-----+-----+\n|");
        for(j=0;j<3;j++)
        {
            if(arr[i][j]==1)
                printf("  O  |");
            else if(arr[i][j]==2)
                printf("  X  |");
            else
                printf("     |");
        }
        printf("\n");
    }
    printf("+-----+-----+-----+\n");
}


int checkOverride(int arr[][3], int m, int n)
{
    if(m>3 || n>3 || m<1 || n<1)
    {
        printf("Please Enter value between 1-3 !!\n");
        return 1;
    }
    else
    {
        if(arr[m-1][n-1]!=0)
        {
            printf("player already inserted value\n");
            return 1;
        }
        else 
            return 0;
    }
}

int checkWin(int arr[][3], int p)
{
    int i;
    for(i=0;i<3;i++)
    {
        if(arr[i][0]==p && arr[i][1]==p && arr[i][2]==p || arr[0][i]==p && arr[1][i]==p && arr[2][i]==p)
        {
            printf("\nPlayer %d is WON",p);
            return 1;
        }
    }
    if(arr[0][0]==p && arr[1][1]==p && arr[2][2]==p || arr[0][2]==p && arr[1][1]==p && arr[2][0]==p)
    {
        printf("\nPlayer %d is WON",p);
        return 1;
    }
    return 0;   
}

void playerToPlayer()
{
    int i=0;
    int m,n;
    int player;
    int arr[3][3]={0};
    printf("Game Start Now!!!\n");
    while(i<9)
    {
        player=(i%2)+1;
        printf("\nPlayer %d\n",player);
        do{
            printf("Enter position: ");
            scanf("%d%d",&m,&n);
        }while(checkOverride(arr,m,n));
        arr[m-1][n-1
        ]=player;
        display(arr);
        if(i>3 && checkWin(arr,player))
            break;
        i++;
    }
    if(i==9)
        printf("Game is Tied");
    printf("\n\nGame is over!!");


}

void getval(int arr[][3],int *m,int *n)
{
    int i,j,k=-1;   // K is traverse from 0 to random
    
    int random=rand()%9;    //random box between  0 to 8
    for(i = 0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            k++; //traversing
            if(k==random && arr[i][j] == 0) //check the box is empty and return the cordinates
            {
                *m = i+1;
                *n = j+1;
                return;
            }
            else if(random == k){ //initialize if box  not found 
                k = 0;
                random = rand()%9;
                i=0;
                j=0;
            }
        }
    }
}

void playerToRobot()
{
    int i=0;
    int m,n;
    int player;
    int arr[3][3]={0};
    printf("Game Start Now!!!\n");
    while(i<9)
    {
        player=(i%2)+1;
        printf("\nPlayer %d\n",player);
        if(i%2==0)
        {
            do{
                    printf("Enter position: ");
                    scanf("%d%d",&m,&n);
            }while(checkOverride(arr,m,n));
        }
        else
        {
            getval(arr,&m,&n);
            printf("Robot position: %d %d\n",m,n);
        }
        arr[m-1][n-1]=player;
        display(arr);
        if(i>3 && checkWin(arr,player))
            break;
        i++;
    }
    if(i==9)
        printf("Game is Tied");
    printf("\n\nGame is over!!");
}

int main()
{
    int ch=0;
    int choice;
    do{
        printf("\n1. player to player");
        printf("\n2. player to robot");
        printf("\n3. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                playerToPlayer();
                break;
            case 2:
                playerToRobot();
                break;
            case 3:
                printf("Game over!!");
                exit(0);
            default:
                printf("please Enter a valid option.");

        }
        choice=0;
        do{
            printf("\n1. Replay");
            printf("\n2. Back");
            printf("\n\nEnter your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    if(ch==1)
                        playerToPlayer();
                    else
                        playerToRobot();
                    break;
                case 2:
                    break;
                default:
                    printf("please Enter a valid option.");
            }
        }while(choice!=2);
    }while(ch!=3);
    return 0;
}