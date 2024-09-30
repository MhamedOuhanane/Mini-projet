#include<stdio.h>
#define n1 10000
#define n2 15

typedef struct
{
    char nom[n2];
    char numero[n2];
    char adress[n2];
}Contact;

void Ajouter_Contact();
void Modifier_Contact(Contact A[] ,int a);
int Rechercher_Contact();
void Supprimer_Contact(Contact A[] ,int a);
void Afficher_Tous(Contact A[]);
void clearBuffer();

Contact Personne[n1];
int j ;

int main()
{
    Contact Personne[n1];
    
    int a ,n, c ;
    c = Rechercher_Contact(Personne);
    do
    {
        j = 0;
        printf("---Menu---\n\n");
        printf("1.Ajouter un Contact.\n");
        printf("2.Modifier les informations d'un Contact.\n");
        printf("3.Supprimer un Contact.\n");
        printf("4.Afficher Tous les Contacts.\n");
        printf("5.Rechercher un contact par son nom.\n");
        printf("6.Sortir.\n");
        printf("Donner votre choix ? \n ");
        scanf("%d",&n);
        clearBuffer();
        switch (n)
        {
        case 1 :
            Ajouter_Contact(Personne);
            break;
        case 2 :
            if (c == 0)
            {
                printf("Le carnet de contacts est vide!\n");
            }

            Modifier_Contact(Personne , c);
            break;
        case 3 :
            Supprimer_Contact(Personne , c);
            break;
        case 4 :
            Afficher_Tous(Personne);
            break;
        case 5:
            if (c == 0)
            {
                printf("Le carnet de contacts est vide!\n");
            }
            else
            {
                /* code */
            }
            
            break;
            case 6:
                return 0; 
        }
    } while (1);
    return 0;
}
void Ajouter_Contact(Contact A[])
{
    j++;
    printf("Entrer le nom du Contact a ajouter : ");
    scanf("%s",A[j].nom);
    clearBuffer();
    printf("Entrer le numero de telephone du Contact a ajouter : ");
    scanf("%s",A[j].numero);
    clearBuffer();
    printf("Entrer l'adress du Contact a ajouter : ");
    scanf("%s",A[j].adress);
    clearBuffer();
}

void Modifier_Contact(Contact A[] ,int a)
{
    Contact B;
    printf("Saisir le nom du nouvelle Contact : ");
    scanf("%s",B.nom);
    clearBuffer();
    printf("Saisir le numero de telephone du nouvelle Contact : ");
    scanf("%s",B.numero);
    clearBuffer();
    printf("Saisir l'adress du nouvelle Contact : ");
    scanf("%s",B.adress);
    clearBuffer();

    strcpy(A[a].nom, B.nom);
    strcpy(A[a].numero, B.numero);
    strcpy(A[a].adress, B.adress);
}

void Supprimer_Contact(Contact A[] , int a)
{
    for (int i = a ; i <= j-1; i++)
    {
        strcpy(A[i].nom , A[i+1].nom);
        strcpy(A[i].numero , A[i+1].numero);
        strcpy(A[i].adress , A[i+1].adress);
    }
    j--;
}

void Afficher_Tous(Contact A[])
{
    if (j == 0)
    {
        printf("Le carnet de contacts est vide!\n");
    }
    else
    {
        for (int i = 1; i < j; i++)
        {
            printf("Le Contact %d est: \n",i+1);
            printf("Nom : %s",A[i].nom);
            printf("Nom : %s",A[i].numero);
            printf("Nom : %s",A[i].adress);
        }
        
    }
    
}

int Rechercher_Contact(Contact A[])
{
    char name[n2];
    printf("Entrez le nom souhaite : ");
    scanf("%s",name);
    clearBuffer();
    if (j == 0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < j; i++)
        {
            if (strcmp(A[i].nom , name))
            {
                return i;
                break;
            }
        }
    }
}



void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}