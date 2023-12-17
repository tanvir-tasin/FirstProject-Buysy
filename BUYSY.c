#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct product
{
    int num;
    int price;

} products;
int main()
{
    products product[6];
    char yes[5] = "yes";

    char s1[5];

    char welcome[20] = "WELCOME TO BUYSY";
    int l = strlen(welcome);
    for (int i = 0; i < 3; i++)
    {
        if (i == 1)
        {
            for (int j = 0; j < 30; j++)
                printf(" ");

            printf("*       ");
            printf("%s", welcome);
            for (int j = 0; j < 29 - (l + 8); j++)
                printf(" ");
            printf("*");
        }

        else
        {
            for (int j = 0; j < 30; j++)
                printf("\033[1;33m ");
            for (int j = 0; j < 30; j++)
                printf("*");
        }

        printf("\n");
    }

    printf("\n\nWOULD YOU LIKE TO SHARE YOUR NAME WITH US?\n");
    printf("\n\nANSWER:");
    fflush(stdin);

    gets(s1);
    int flag = 1;
    int n = 0;
    while (n < 4)
    {
        if (s1[n] != yes[n])
        {

            flag = 0;
            break;
        }
        n++;
    }
    if (flag == 1)
    {
        printf("\n");
        printf("please enter your name: ");
        char s2[20];
        gets(s2);
        for (int i = 0; s2[i] != '\0'; i++)
            s2[i] = toupper(s2[i]);
        printf("\n\n\n\t\t\t\tHELLLOO %s :)\n ", s2);
    }
    else
    {
        printf("\n\n\n\t\t\t\t\tHELLO there :)\n");
    }
    printf("\n\t\t\t******Here is our product list******\n");
    printf("\n\n");

    fflush(stdin);
    FILE *fp;
    fp = fopen("menu.txt", "r");

    char st[10];

    while (!feof(fp))
    {
        fgets(st, 5, fp);
        printf("%s", st);
    }
    fclose(fp);
    FILE *f1 = fopen("price.txt", "r");
    for (int x = 0; x < 6; x++)
        fscanf(f1, "%d %d", &product[x].num, &product[x].price);
    fclose(f1);
    printf("\nIf you want to buy then select the product number=>>\n");
    int a, b, sum = 0;

    scanf("%d", &a);
    while (a != 0)
    {
        printf("enter quantity: ");
        scanf("%d", &b);
        sum += (b * product[a - 1].price);
        printf("\nWanna buy more? If yes please select product number if no then press 0:  ");

        scanf("%d", &a);
    }
    printf("\n\n\n\tTotal ammount is=>>>> %d: ", sum);
    printf("\n\nYou want to pay via card or cash?");
    char s6[5];
    fflush(stdin);
    gets(s6);
    for(int v=0;s6[v]!='\0';v++)
    s6[v]=toupper(s6[v]);


    printf("\n\nNOW PAY VIA %s ;)",s6);
    printf(" \n\n\nwait! listen. Please come again :)");
    return 0;
}
