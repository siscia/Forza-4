#include<stdio.h>


char griglia[2][2];

int main()
{
    controllo_riga(1,1);
}    

int controllo_vittoria(int x, int y)
{
    return 1;
}

int controllo_riga(int x, int y)
{
    /*questa funzione prende in input le coordinate del l'ultima mossa e controlla se e quante
    pedine sono allineate nella riga aumentando ediminuedno solo le x
    */
    char g = griglia[x][y];
    int x_aux = x;
    int allineati = 0; 
    
    
    int uscita = 0;   
    while((allineati < 4) && (uscita != 1))
    {
        if(griglia[x_aux+1][y] == g)
        {
            allineati++;
            x_aux++;
        }
        else
        	uscita = 1;
    }
	uscita = 0;
    while((allineati < 4) && (uscita != 1))
    {
        if(griglia[x-1][y] == g)
        {
            allineati++;
            x--;
        }
        else
        	uscita = 1;
    }
    return allineati;
}

int controllo_colonna(int x, int y)
{
	char g = griglia[x][y];
    int y_aux = y;
    int allineati = 0;   
    
    int uscita = 0; 
    while((allineati <= 4) && (uscita != 1))
    {
        if(griglia[x][y_aux+1] == g)
        {
            allineati++;
            y_aux++;
        }
        else
        	uscita = 1;
    }
    while((allineati <= 4) && (uscita != 1))
    {
        if(griglia[x][y-1] == g)
        {
            allineati++;
            y--;
        }
        else
        	uscita = 1;
    }
    return allineati;
}
