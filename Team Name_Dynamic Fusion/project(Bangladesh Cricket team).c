#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max_Size 100
#define T 30

struct Bangladesh_Cricket_Team{
    char name[Max_Size];
    int age;
    char type[T];
    int Total_Match;
    int Total_Run;
    int Highest_Run;
};

void Player_Information(struct Bangladesh_Cricket_Team info[], int n);
void all_info(struct Bangladesh_Cricket_Team info[],char name[Max_Size], int n);
int Most_Experienced_Player(struct Bangladesh_Cricket_Team most[], int n);
void New_Player(struct Bangladesh_Cricket_Team info[], int n);
void Top_Score(struct Bangladesh_Cricket_Team info[], int n);
void Hard_hitter(struct Bangladesh_Cricket_Team info[], int n);
float Average_rate(int Total_Run,int Total_Match, int n);
void Highest_run(struct Bangladesh_Cricket_Team info[], int n);
void Show_mvp(struct Bangladesh_Cricket_Team info[], int n);
float mvp(int Age,int Total_Match,int Total_Run, int Highest_Run, int n);
void All_rounders(struct Bangladesh_Cricket_Team info[], int n);


    //A. Showing All Players

void Player_Information(struct Bangladesh_Cricket_Team info[], int n)
{
    int i;
    FILE *file;
    file = fopen("Player_info.txt","w");
    for(i=0; i<n; i++)
    {
        printf("%d %s", i+1, info[i].name);
        fprintf(file,"%d. %s", i+1, info[i].name);
    }
    fclose(file);
    printf("\n");
}

    //B. Showing A Particular player information (Provide Player Name)

void all_info(struct Bangladesh_Cricket_Team info[],char name[Max_Size], int n)
{
    int i;
    //printf("in allinfo\n");
    int strlength = strlen(name);
    //printf("String length: %d\n",strlength);
    for(i=0; i<n; i++)
    {
        if( strncmp( name, info[i].name, strlength) == 0)
        {
            //printf("Name : %s",info[i].name);
            printf("Age : %d\n", info[i].age);
            printf("Type : %s", info[i].type);
            printf("Total match : %d\n", info[i].Total_Match);
            printf("Total run : %d\n", info[i].Total_Run);
            printf("Hight run : %d\n", info[i].Highest_Run);

        }
    }
    printf("\n");
}

    //C. Showing the MOST Experienced Player (MEP)

int Most_Experienced_Player(struct Bangladesh_Cricket_Team most[], int n)
{
    int index,max,i;
    index = 0;
    max = most[0].Total_Match;
    for (i=1; i<n; i++)
    {
        if( max < most[i].Total_Match)
        {
            index = i;
            max = most[i].Total_Match;
        }
    }
    return index;
}

    //D. Showing the New Comer Player (NCP)

void New_Player(struct Bangladesh_Cricket_Team info[], int n )
{

    int i, index = info[0].age, indexage = 0;

    for(i=1; i<n; i++)
    {
        if(index> info[i].age)
        {

            index = info[i].age;
            indexage = i;
        }

    }
    printf("New comer player name is : %s\n", info[indexage].name);
}

    //E. Showing the Top Scorer Player (TSP)

void Top_Score(struct Bangladesh_Cricket_Team info[], int n)
{

    int i, index = 0, indextotal = info[0].Total_Run;
    for (i=1; i<n; i++)
    {
        if( indextotal < info[i].Total_Run)
        {
            index = i;
            indextotal = info[i].Total_Run;

        }
    }
    printf("Top score player name is : %s\n", info[index].name);
}

    //F. Showing the Hard Hitter Player (HHP)


void Hard_hitter(struct Bangladesh_Cricket_Team info[], int n)
{

    int i, index = 0;
    float indexRate = Average_rate(info[0].Total_Run, info[0].Total_Match, n);
    for( i = 1; i<n; i++)
    {

        if(indexRate < Average_rate(info[i].Total_Run, info[i].Total_Match, n))
        {

            index = i;
            indexRate = Average_rate(info[i].Total_Run, info[i].Total_Match, n);

        }
    }
    printf("Hard hitter player name is : %s\n", info[index].name);
}

float Average_rate(int Total_Run, int Total_Match, int n  )
{

    float Avg;

    Avg= (Total_Run*1.0)/(Total_Match);

    return Avg;
}


    //G. Showing the Highest Run Taker Player (HRTP)

void Highest_run(struct Bangladesh_Cricket_Team info[],int n)
{

    int i, index =0, indexHighest_run = info[0].Highest_Run;
    for (i=1; i<n; i++)
    {
        if(indexHighest_run < info[i].Highest_Run)
        {
            index = i;
            indexHighest_run = info[i].Highest_Run;

        }
    }
    printf("Highest run taker player is : %s\n", info[index].name);

}

    //H. Showing the MOST Valuable Player (MVP)

void Show_mvp(struct Bangladesh_Cricket_Team info[],int n)
{
    int i, index = 0;
    float index_mvp = mvp( info[0].age, info[0].Total_Match, info[0].Total_Run, info[0].Highest_Run,n);

    for(i=1; i<n; i++)
    {
        if(index_mvp < mvp( info[i].age, info[i].Total_Match, info[i].Total_Run, info[i].Highest_Run,n ))
        {
            index =i ;
            index_mvp = mvp( info[i].age, info[i].Total_Match, info[i].Total_Run, info[i].Highest_Run,n);
        }
    }
    printf("MVP : %s\n", info[index].name);
}

float mvp(int Age, int Total_Match, int Total_Run, int Highest_Run, int n)
{

    float Rate;
    Rate = Age + Total_Match + Total_Run + Highest_Run + (Total_Run*1.0)/(Total_Match) + (Highest_Run*1.0)/(Age) ;
    return Rate;
}


    // I. Showing the All rounders

void All_rounders(struct Bangladesh_Cricket_Team info[], int n)
{

    int i, All, a=1;
    for(i=0; i<n; i++)
    {
        All = strncmp(info[i].type, "All rounder", 10);
        if(All == 0)
        {
            printf("%d %s", a++, info[i].name);
        }
    }
    printf("\n");
}



int main(){


    printf("\t\t\t\t\t\t Welcome To Bangladesh Cricket Team.\n\n\n");

    char choice;
    int N;
    char name[Max_Size];
    FILE *file;
    file= fopen("input.txt","r");

    //N= fgetc(file);
    fscanf(file,"%d", &N);
    printf("%d\n",N);
    int n = N;
    N = fgetc(file);
    N = fgetc(file);

    struct Bangladesh_Cricket_Team Player[N];

     int i;
    for(i=0 ; i<N ; i++){
        fgets(Player[i].name,Max_Size,file);
        printf("%s",Player[i].name);

        fscanf(file,"%d",&Player[i].age);
        printf("%d\n",Player[i].age);
        N=fgetc(file);//fflush(file);
        fgets(Player[i].type,Max_Size,file);
        printf("%s",Player[i].type);

        fscanf(file,"%d",&Player[i].Total_Match);
        printf("%d\n",Player[i].Total_Match);

        fscanf(file,"%d",&Player[i].Total_Run);
        printf("%d\n",Player[i].Total_Run);

        fscanf(file,"%d",&Player[i].Highest_Run);
        printf("%d\n",Player[i].Highest_Run);
        printf("\n");
        N=fgetc(file);
        N=fgetc(file);
    }

    while(1){
        puts("A. Show all players");
        puts("B. Show a particular player information (Provide Player Name)");
        puts("C. Show the most experienced player (MEP)");
        puts("D. Show the new comer player (NCP)");
        puts("E. Show the top scorer player (TSP)");
        puts("F. Show the hard hitter player (HHP)");
        puts("G. Show the highest run taker player (HRTP)");
        puts("H. Show the most valuable player (MVP)");
        puts("I. Show the all rounders");
        puts("J. Exit/Quit");



        printf("Enter a choice : ");
        scanf("%c",&choice);
        choice = toupper(choice);
        if(choice=='J')
        {break;}

        switch(choice){

        case 'A':
            Player_Information(Player, n);
            break;
        case 'B':
            printf("Enter player name:");
            scanf(" %[^\n]",&name);
            all_info(Player,name,n);
            break;
        case 'C':
            printf("Most experience player name is : %s\n",Player[Most_Experienced_Player(Player, n)].name);
            break;
        case 'D':
            New_Player(Player,n);
            break;
        case 'E':
            Top_Score(Player,n);
            break;
        case 'F':
            Hard_hitter(Player,n);
            break;
        case 'G':
           Highest_run(Player,n);
            break;
        case 'H':
            Show_mvp(Player,n);
            break;
        case 'I':
            All_rounders(Player,n);
            break;
        default :
            puts("Error!Please Try Again!\n\n");
            break;
        }

        //fflush(file);
        scanf("%*c",&choice);
        fclose(file);

    }
    puts("\n\nThank you\n\n");


    return 0;

}

        //Program Ends
