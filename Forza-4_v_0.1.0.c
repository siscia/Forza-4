#include <stdio.h>
#include <stdlib.h>

#define RIGHE 8
#define COLONNE 10


char griglia[RIGHE][COLONNE];

int posizione_in_plancia(int x, int y)
/*La funzione controlla che le coordinate siano all'interno della griglia*/
{
    if((x >= 0) && (x < RIGHE) && (y >= 0) && (y < COLONNE))
        return 1;
    else
        return 0;
}

int chiedi_mossa()
/*La funzione chiede all'utente in quale colonna vuole posizionare la propria pedina,
 e ritorna l'indice della colonna, tutto con input validato*/
{
    int pos;
    do{
    
        printf("Dove vuoi posizionare la pedina: ");
        scanf("%d" , &pos);
        if((pos<1) || (pos >10))
            printf("No, la posizione è fuori dalla plancia\n");

    }while((pos < 1) || (pos > 10) || (griglia[0][pos-1] != ' '));
    return pos-1;
}
 
int posiziona_pedina(int pos, char gio)
/*La funzione posiziona la pedina nella griglia e ritorna le y*/
{
    int col;
    
    if(griglia[COLONNE][pos] == ' ')
    {
        griglia[COLONNE][pos] = gio;
        return COLONNE-1;
    }
    else
    {
        for(col=0; col<COLONNE; col++)
        {
            if(griglia[col][pos] != ' '){
                griglia[col-1][pos] = gio;
                return col-1;
            }
        }
    }
    
}

        
int controllo_vittoria(int y, int x)
/*La funzione esegue vari controlli e ritorna 1 in caso di vittoria,
 * altrimenti torna 0*/
{
    if(controllo_colonna(x,y) == 1)
    {
        printf("Vittoria verticale\n");
        return 1;
    }
    if(controllo_riga(x,y) == 1)
    {
        printf("Vittoria in orizzontale\n");
        return 1;
    }
    if(controllo_diagonale_meno(x,y) == 1)
    {
        printf("Vittoria sulla diagonale\n");
        return 1;
    }
    if(controllo_diagonale_piu(x,y) == 1)
    {
        printf("Vittoria diagonale\n");
        return 1;
    }
    return 0;
}

void stampa_griglia()
/*La funzione stampa a schermo la griglia*/
{
    int cont=0;
    int r,c;
    for(r=0; r<RIGHE; r++)
    {
        for(c=0; c<COLONNE; c++)
            printf("|%c", griglia[r][c]);
        printf("|\n");
    }
}

void riempi_griglia()
/*La funzione riempi la griglia di caratteri nulli*/
{
    int r,c;
    for(r=0; r<RIGHE; r++)
    {
        for(c=0; c<COLONNE; c++)
            griglia[r][c] = ' ';

    }
}


int controllo_colonna(int x, int y)
/*questa funzione prende in input le coordinate del l'ultima mossa e controlla se e quante
pedine sono allineate nella riga aumentando e diminuedno solo le x
*/
{
    char g = griglia[x][y];
    int x_aux = x;
    int allineati = 1;

    //printf("Sta giocando %c\n", g);
    
    int uscita = 0;
    while((allineati <= 4) && (uscita != 1))
    {
        if((griglia[x_aux+1][y] == g) && (posizione_in_plancia(x_aux+1,y)))
        {
            allineati++;
            //printf("%d, ALLINEATI colonna\n", allineati);
            x_aux++;
        }
        else
         uscita = 1;
    }
uscita = 0;
    if(allineati >= 4)
    {
        return 1;
    }
    return 0;
}

int controllo_riga(int x, int y)
/*La funzione cerca nella griglia se sono presenti 4 pedine allineate orizzontalmente,
 * torna 1 in caso affermativo, e quindi in caso di vittoria, altrimeti torna 0*/
{
    char g = griglia[x][y];
    int y_aux = y;
    int allineati = 1;
    
    int uscita = 0;
    while((allineati <= 4) && (uscita != 1))
    {
        if((griglia[x][y_aux+1] == g) && (posizione_in_plancia(x,y_aux+1)))
        {
            
            allineati++;

            y_aux++;
        }
        else
         uscita = 1;
    }
    uscita = 0;
    while((allineati <= 4) && (uscita != 1))
    {
        if((griglia[x][y-1] == g) && (posizione_in_plancia(x,y-1)))
        {
            allineati++;
            y--;
        }
        else
         uscita = 1;
    }

    if(allineati >= 4)
        return 1;
    return 0;
}

int controllo_diagonale_meno(int x, int y)
/*La funzione esegue il solito controllo per la diagonale negativa*/
{
	char g = griglia[x][y];
	int x_aux = x;
	int y_aux = y;
	int allineati = 1;

	int uscita = 0;
	while((allineati <= 4) && (uscita != 1))
	{
		if((griglia[x_aux+1][y_aux+1] == g) && (posizione_in_plancia(x_aux+1,y_aux+1)))
		{
			allineati++;
			x_aux++;
			y_aux++;
		}
		else
			uscita = 1;
	}
    uscita = 0;
	while((allineati <= 4) && (uscita != 1))
	 {
		if((griglia[x-1][y-1] == g) && (posizione_in_plancia(x-1,y-1)))
		{
			allineati++;
			x--;
			y--;
		}
		else
			uscita = 1;
	}
	if(allineati>=4)
        return 1;
    return 0;
}
int controllo_diagonale_piu(int x, int y)
/*Solito controllo ma per la diagonale positiva */
{//ok
	char g = griglia[x][y];
	int x_aux = x;
	int y_aux = y;
	int allineati = 1;

	int uscita = 0;
	while((allineati <= 4) && (uscita != 1))
	{
		if(griglia[x_aux-1][y_aux+1] == g)
		{
			allineati++;
			x_aux--;
			y_aux++;
		}
		else
			uscita = 1;
	}
    uscita = 0;
	while((allineati <= 4) && (uscita != 1))
	 {
		if(griglia[x+1][y-1] == g)
		{
			allineati++;
			x++;
			y--;
		}
		else
			uscita = 1;
	}
	if(allineati>=4)
        return 1;
    return 0;
}



char seleziona_giocatore(int mossa)
/*La funzione seleziona chi deve giocare basandosi su un contatore*/
{
    if(mossa%2 == 0)
        return 'X';
    return 'O';
}

int ciclo()
/*Funzione principale del gioco, si basa su un ciclo infinito*/
{
    /*Inizializzo le variabili*/
    int mossa=0;
    char gio;
    int x;
    int y;
    stampa_griglia();//stampo la griglia vergine
    while(1)
    {
        mossa++;//aumento il contatore delle mosse
        if(mossa >= RIGHE*COLONNE)
            return -1;  //la plancia è piena, quindi la partita è finita
        gio = seleziona_giocatore(mossa);//decido chi deve giocare
        x = chiedi_mossa();//chiedo dove vuole posizionare la pedina
        y = posiziona_pedina(x, gio);//posiziono la pedina
        stampa_griglia();//stampo la griglia aggiornata
        if(controllo_vittoria(x,y) == 1) //in caso di vittoria, ritorno il vincitore
            return mossa%2; //1 è il primo giocatore, 0 il secondo 
    }
}

void presentazione()
{
    printf("Ciao e benvenuto nel nostro Forza-4,\n il gioco consiste nello allineare 4 pedine sia in verticale o in orizzontale o in diagonale,\nBUON DIVERTIMENTO\n\n");
}


int main()
{
    /*Inizializzo le variabili necessarie*/
    int vincitore;
    int rivincita;
    presentazione();
    char g1[30];
    char g2[30];
    
        /*Chiedo in input il nome dei due giocatori*/
        printf("Ciao primo giocatore, come ti chiami?: ");
        scanf("%s", g1);
        printf("Ciao secondo giocatore, come ti chiami?: ");
        scanf("%s", g2);
    
    do{ //inizia il ciclo per rigiocare più partite
        riempi_griglia(); //inizializzo la griglia
        vincitore = ciclo();//Lancio il ciclo principale ricercando un vincitore
        /*Analizzo il vincitore e mi compliemento*/
        if(vincitore == -1)
            printf("La partita è finita in parità\n");
        if(vincitore == 1)
            printf("Complimenti %s, hai vinto\n", g1);
        else
            printf("Complimenti %s, hai vinto\n", g2);
            
        do{//Chiedo se vogliono rigiocare, con input validato
            printf("Se volete rigiocare digitate 1, altrimenti 2...:");
            scanf("%d", &rivincita);
        }while((rivincita != 1) && (rivincita != 2));
            
    }while(rivincita==1);
    
    printf("\n");
    printf("BYE BYE\n");//saluto
    return 0;
}
