#include<stdio.h>
#include<string.h>

#define n1 10000
#define n2 15

typedef struct
{
    char nom[n2];
    char numero[n2];
    char adress[n2];
}Contact;

void Ajouter_Contact();
void Modifier_Contact(Contact A[]);
int Rechercher_Contact();
void Supprimer_Contact(Contact A[]);
void Afficher_Tous(Contact A[]);
int recherche(Contact A[] , char B[]);
int cmp(char A[] ,char B[]);
void clearBuffer();

Contact Personne[n1];
int j ;

int main()
{
    Contact Personne[n1];
    
    int a ,n ;
    j = -1;
    do
    {
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
            Modifier_Contact(Personne );
            break;
        case 3 :
            Supprimer_Contact(Personne);
            break;
        case 4 :
            Afficher_Tous(Personne);
            break;
        case 5:
            Rechercher_Contact(Personne);
            break;
            case 6:
                return 0; 
        }
    } while (1);
    return 0;
}
void Ajouter_Contact(Contact A[])
{
    printf("Entrer le nom du Contact a ajouter : ");
    scanf("%s",A[j+1].nom);
    clearBuffer();
    printf("Entrer le numero de telephone du Contact a ajouter : ");
    scanf("%s",A[j+1].numero);
    clearBuffer();
    printf("Entrer l'adress du Contact a ajouter : ");
    scanf("%s",A[j+1].adress);
    clearBuffer();
    j++;
}

void Modifier_Contact(Contact A[])
{
    Contact B;
    char b[n2];
    int a;
    
    printf("Entrer le nom de contact a modiffier : ");
    scanf("%s",b);
    clearBuffer();
    a = recherche(A , b);
    if (a == -1)
    {
        printf("Le contacts n'existe pas dans le carnet.\n");
    }
    else
    {
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
}

void Supprimer_Contact(Contact A[])
{
    char nom[n2];
    int a;
    printf("Donner le nom de contact a supprimer : ");
    scanf("%s",nom);
    clearBuffer();
    a = recherche(A , nom);
    if (a == -1)
    {
        printf("Le contacts n'existe pas dans le carnet.\n");
    }
    else{
        for (int i = a ; i <= j-1; i++)
        {
            strcpy(A[i].nom , A[i+1].nom);
            strcpy(A[i].numero , A[i+1].numero);
            strcpy(A[i].adress , A[i+1].adress);
        }
    }
    j--;
}

void Afficher_Tous(Contact A[])
{
    if (j == -1)
    {
        printf("Le carnet de contacts est vide!\n");
    }
    else
    {
        for (int i = 0; i <= j; i++)
        {
            printf("Le Contact %d est: \n",i+1);
            printf("Nom    : %s\n",A[i].nom);
            printf("numero : %s\n",A[i].numero);
            printf("adress : %s\n\n",A[i].adress);
        }
        
    }
    
}

int Rechercher_Contact(Contact A[])
{
    char name[n2];
    int a ;
    printf("Entrez le nom souhaite : ");
    scanf("%s",name);
    clearBuffer();
    a = recherche(A , name);
    if (a != -1)
    {
        printf("Le Contact %d : \n",a);
        printf("Nom    : %s\n",A[a].nom);
        printf("numero : %s\n",A[a].numero);
        printf("adress : %s\n",A[a].adress);
    }
    else
        printf("Le contacts n'existe pas dans le carnet.\n");
}

int recherche(Contact A[] , char B[])
{
    int a ;
    int i;
    a = -1;
    for (i = 0; i < j; i++)
    {
        if (cmp(A[i].nom , B) == 0)
        {
            a = i;
            break;
        }
    }
    if (a != -1)
        return a;
    else
        return 0;
    
}

int cmp(char A[] ,char B[])
{
    int i,a;
    if (strlen(A) == strlen(B))
    {
        a = 0;
        for ( i = 0; i < srtlen(A); i++)
        {
            if (A[i] != B[i])
            {
                a = 1;
                break;
            }
            
        }
        
    }
    return a;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}