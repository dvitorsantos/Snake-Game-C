#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h> srand(time(NULL));
#include <time.h>
FILE *ponteiroArquivo;
char frase[100];
struct cadastro{
    char nome [50];
    int points;
    };
     struct cadastro aux;
void inserir(){
    ponteiroArquivo=(fopen("arquivo.txt","a"));
    printf("Digite seu nome:\n");
    fgets (aux.nome , 50 , stdin);
    fprintf(ponteiroArquivo,"%s %d pts\n",aux.nome, aux.points);
}
void exibir()                              //exibe rank
{
    ponteiroArquivo=(fopen("arquivo.txt" , "r"));
    while(fgets(frase, 100, ponteiroArquivo) !=NULL)
    {
        printf("%s", frase);
    }
}
   int foodx=20, foody=20, velo=200, o=1, pontos;
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
void comida()
{
        srand(time(NULL));
    foodx=(rand() % 50)+3;
    foody=(rand() % 20)+3;
    gotoxy(foodx, foody);
    printf("%c", 219);
    pontos=pontos+1;
    velo=velo-20;
    if (velo<10) velo=velo+20;
    o++;
    gotoxy(64, 10);
    printf("Pontuacao: %d", pontos);
}
void menu()
{
    int i;
     for (i=2; i<59; i++) //paredes
    {
        gotoxy(i, 2);
        printf("%c", 219);
    }
      for (i=2; i<25; i++)
    {
        gotoxy(2, i);
        printf("%c", 219);
    }
       for (i=2; i<25; i++)
    {
        gotoxy(59, i);
        printf("%c", 219);
    }
       for (i=2; i<59; i++)
    {
        gotoxy(i, 24);
        printf("%c", 219);
    }
    gotoxy(10, 10);                                //Menu do jogo, com as escolhas
    printf("APERTE 'A' PARA INICIAR O JOGO");
    gotoxy(10, 12);
    printf("APERTE 'B' PARA VER AS REGRAS");
    gotoxy(10, 14);
    printf("APERTE 'C' PARA VER O RANK");
}
void regras()                                    //Regras do jogo
{
    gotoxy(10, 10);
    printf("1. NAO BATA NA PAREDE\n");
    gotoxy(10, 11);
    printf("2. NAO ACERTE O RABO DA COBRA");
    gotoxy(10, 13);
    printf("3. DIVIRTA-SE!\n");
    gotoxy(10, 14);
}
void jogo()
{
     time_t t=10;
    char tecla;
    int cx[200]={20}, cy[200]={20}, d, p, x, i;
    for (i=2; i<59; i++)                          //paredes do jogo
    {
        gotoxy(i, 2);
        printf("%c", 219);
    }
      for (i=2; i<26; i++)
    {
        gotoxy(2, i);
        printf("%c", 219);
    }
       for (i=2; i<26; i++)
    {
        gotoxy(59, i);
        printf("%c", 219);
    }
       for (i=2; i<59; i++)
    {
        gotoxy(i, 25);
        printf("%c", 219);
    }
    while (tecla!='o')
    {
        while (tecla!='o' && !(kbhit()))
        {
            for(x=o;x>0;x--)              //funcao para crescer a cobra
            {   cx[x]=cx[x-1];
                cy[x]=cy[x-1];
            }
            if (d==0) cx[0]--;            //movimentacao da cobra
            if (d==1) cy[0]--;
            if (d==2) cx[0]++;
            if (d==3) cy[0]++;
            gotoxy(cx[o], cy[o]);
            printf(" ");                  //apaga o rastro
            gotoxy(cx[0], cy[0]);
            printf("%c", 219);            //printa a cabeca da cobra
            Sleep(velo);
              if ((cx[0]==foodx) && (cy[0]==foody))
              {
                  comida();               //spawna comida e adiciona pontuação
              }
for(x=2;x<o;x++)                          //primeira condição de morte
{   if(cx[0]==cx[x]&&cy[0]==cy[x])tecla='o';
}
              if (cx[0]==2 || cx[0]==59 || cy[0]==2 || cy[0]==24) tecla='o'; //segunda condição de morte
        }
        if (tecla!='o') tecla=getch();
        if (tecla=='a') d=0;
        if (tecla=='w') d=1;
        if (tecla=='d') d=2;
        if (tecla=='s') d=3;
         if (cx[0]==2 || cx[0]==59 || cy[0]==2 || cy[0]==24) tecla='o'; //segunda condição de morte
    }
    gotoxy(64, 12);
    printf("Voce morreu!");
    Sleep(400);
    o=1;
    velo=200;
    aux.points=pontos;                  //armazenando a pontuação para o arquivo
    pontos=0;
    system("cls");
}
int main()
{
    system("color 3f");
    char selecionar, a='a';
    while(a=='a'){                    //opções de menu
        system("cls");
        menu();
        selecionar=getch();
        system("cls");
    if(selecionar=='a'){
        comida();
        jogo();
        system("cls");
        inserir();}
    if(selecionar=='c'){
        system("cls");
        exibir();
        system("pause");}
    if(selecionar=='b'){
        system("cls");
        regras();
        system("pause");
    }
    fclose(ponteiroArquivo);
}
}

