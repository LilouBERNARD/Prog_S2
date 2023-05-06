#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    int n; 
    Noeud* dernier; 
    // your code
};

struct DynaTableau{
    int* donnees;
    int index;
    int capacite;
};


void initialise(Liste* liste)
{
    liste->premier = NULL;
}

bool est_vide(const Liste* liste)
{
    if(liste->premier == NULL)
    {
        return true; 
    }
    return false;
}




void ajoute(Liste* liste, int valeur)
{
    Noeud* newNoeud = new Noeud;
    newNoeud->donnee = valeur;
    newNoeud->suivant = nullptr;

    if (liste->premier == nullptr)
    {
        liste->premier = newNoeud;
    }
    else
    {
        Noeud* dernier = liste->premier;
        while (dernier->suivant != nullptr)
        {
            dernier = dernier->suivant;
        }
        dernier->suivant = newNoeud;
    }
}



void affiche(const Liste* liste)
{
    if (liste->premier != nullptr)
    {
        Noeud* noeud = liste->premier;
        while (noeud != nullptr)
        {
            std::cout << noeud->donnee << std::endl;
            noeud = noeud->suivant;
        }
    }
}

int recupere(const Liste* liste, int n)
{
    Noeud* noeud = liste->premier;
    int i = 0;
    while (i < n)
    {
        noeud = noeud->suivant;
        i++;
    }
    return noeud->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* noeud = liste->premier;
    int i = 0;
    while (noeud->donnee != valeur)
    {
        noeud = noeud->suivant;
        i++;
    }
    return i + 1;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* noeud = liste->premier;
    int i = 0;
    while (i < n)
    {
        noeud = noeud->suivant;
        i++;
    }
    noeud->donnee = valeur;
}


void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->index < tableau->capacite)
    {
        tableau->donnees[tableau->index]=valeur;
        tableau->index ++;
    } 
    else 
    {
        
        tableau->capacite ++;
        
        int *ajoutdonnees = (int*)realloc(tableau->donnees, tableau->capacite*sizeof(int));

        if(ajoutdonnees!=NULL)
        {
            tableau->donnees = ajoutdonnees;
            tableau->donnees[tableau->index]=valeur;
            tableau->index++;
        } 
        else 
        {
            cout << "erreur allocation memoire" << endl;
        }
    }

    
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->donnees=(int*)malloc(capacite *sizeof(int));
    tableau->capacite=capacite;
    tableau->index=0;
}

bool est_vide(const DynaTableau* liste)
{
    if(liste->index==0)
    {
        return true;
    } 
    else 
    {
        return false;
    }    
}

void affiche(const DynaTableau* tableau)
{
    for(int i=0; i<tableau->index; i++)
    {
        cout << "Valeur :" << tableau->donnees[i] << endl;
    }



}

int recupere(const DynaTableau* tableau, int n)
{
    if(n>=0 && n<=tableau->index)
    {
        return tableau->donnees[n];
    } 
    else 
    {
        cout << "pas de valeur pour n" << endl;
    }
    return 0;
}

int cherche(const DynaTableau* tableau, int valeur)
{
    for(int i=0; i<tableau->index; i++)
    {
        if(tableau->donnees[i]==valeur)
        {
            return i;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if(n>=0 && n<=tableau->index)
    {
        tableau->donnees[n]=valeur;
    } 
    else 
    {
        cout << "pas de valeur pour n" << endl;
    }


}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    Noeud* actuel = liste->premier;
    int valeur = actuel->donnee;

    liste->premier=liste->premier->suivant;
    liste->n=liste->n-1;
    free(actuel);
    return valeur ;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    Noeud* actuel = liste->premier;
    Noeud *avantActuel = nullptr;
    
    while(actuel->suivant!=nullptr)
    {
        avantActuel=actuel;
        actuel=actuel->suivant;
    }
    
    int retour = actuel->donnee;
    
    if (liste->premier!=liste->dernier)
    {
    	avantActuel->suivant=nullptr;
	}

    liste->dernier=avantActuel;
    liste->n-=1;

    free(actuel);

    return retour;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
