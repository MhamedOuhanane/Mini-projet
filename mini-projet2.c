#include<stdio.h>

#define n1 10000
#define n2 25

typedef struct
{
    char nom[n2];
    char numero[n2];
    char adress[n2];
    char ID[n2];

}Contact;

void Ajouter_Contact();
void Modifier_Contact(Contact A[]);
int Rechercher_Contact();
void Supprimer_Contact(Contact A[]);
void Afficher_Tous(Contact A[]);
int recherche(Contact A[] , char B[]);

void cpy(char A[] ,char B[]);
int cmp(char A[] ,char B[]);
int len(char A[]);
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
        printf("3.Supprimer un Contact par son ID.\n");
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
     printf("Entrer l'ID du Contact a ajouter : ");
    scanf("%s",A[j+1].ID);   
    clearBuffer();
    j++;
}

void Modifier_Contact(Contact A[])
{
    Contact B;
    char b[n2];
    int a;
    
    printf("Entrer le nom ou l'ID de contact a modiffier : ");
    scanf("%s",b);
    clearBuffer();
    a = recherche(A , b);
    if(a != -1)
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
        printf("Saisir l'ID du nouvelle Contact : ");
        scanf("%s",B.ID);
        clearBuffer();

        cpy(A[a].nom, B.nom);
        cpy(A[a].numero, B.numero);
        cpy(A[a].adress, B.adress);
        cpy(A[a].ID , B.ID);
    }
}

void Supprimer_Contact(Contact A[])
{
    char B[n2];
    int a;
    printf("Donner le nom ou l'ID de contact a supprimer : ");
    scanf("%s",B);
    clearBuffer();
    a = recherche(A , B);
    if(a != -1)
    {
        j--;
        for (int i = a ; i <= j; i++)
        {
            cpy(A[i].nom , A[i+1].nom);
            cpy(A[i].numero , A[i+1].numero);
            cpy(A[i].adress , A[i+1].adress);
            cpy(A[i].ID , A[i+1].ID);
        }
    }
}

void Afficher_Tous(Contact A[])
{
    if (j == -1)
    {
        printf("Le carnet de contacts est vide!\n\n");
    }
    else
    {
        for (int i = 0; i <= j; i++)
        {
            printf("Le Contact %d est: \n",i+1);
            printf("Nom    : %s\n",A[i].nom);
            printf("Numero : %s\n",A[i].numero);
            printf("Adress : %s\n",A[i].adress);
            printf("ID     : %s\n\n",A[i].ID);
        }
        
    }
    
}

int Rechercher_Contact(Contact A[])
{
    char B[n2];
    int a ;
    printf("Entrez le nom ou l'ID de contact a souhaite : ");
    scanf("%s",B);
    clearBuffer();
    a = recherche(A , B);
    if (a != -1)
    {
        printf("Cette Contact existe dans %dieme ligne ,ses information : \n",a+1);
        printf("Nom    : %s\n",A[a].nom);
        printf("Numero : %s\n",A[a].numero);
        printf("Adress : %s\n",A[a].adress);
        printf("ID     : %s\n\n",A[a].ID);
    }
}

int recherche(Contact A[] , char B[])
{
    int a,i,c=0 ;
    for (i = 0; i <= j; i++)
    {
        if (cmp(A[i].nom , B) == 1 || cmp(A[i].ID , B) == 1)
        {
            a = i;
            c++;
        }
    }
    if (c == 1)
        return a;
    else if (c == 0)
    {    
        printf("Le contact n'existe pas dans le carnet.\n\n");
        return -1;
    }
    else 
    {
        printf("Il y a plusieur contacts ont le meme nom prevu.\nRechercher par ID du contact pas par nom .\n\n");
        return -1;
    }
}

void cpy(char A[] ,char B[])
{
    int i;
    for ( i = 0; i < n2; i++)
    {
        A[i] = B[i];
    }
    
}

int cmp(char A[] ,char B[])
{
    int i,a = 0;
    if (len(A) == len(B))
    {
        a = 1;
        for ( i = 0; i < len(A); i++)
        {
            if (A[i] != B[i])
            {
                a = 0;
                break;
            }
            
        }
        
    }
    return a;
}

int len(char A[])
{
    int i;
    for ( i = 0; i < n2; i++)
    {
        {
            if (A[i] == '\0')
            {
                break;
            }
        }
    }
    return i;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
