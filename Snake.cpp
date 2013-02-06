#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

#define MAXX 80
#define MAXY 24
#define MAXS 500

void main()
{

int X, Y, I, i, J, FIM, PONTA, APAGA, PONTOS;
int SNAKE[MAXS][2],PEDRAX,PEDRAY,TAMANHO;
char TECLA, OLDTECLA, VOLTATECLA, CURSOR;


textcolor(YELLOW);
//bgcolor(2);
clrscr();
gotoxy(15,12);
cprintf("SNAKE por FERNANDO GIL");

sound(300);
delay(400);

sound(400);
delay(200);

sound(500);
delay(200);

sound(400);
delay(400);

sound(300);
delay(400);

sound(400);
delay(300);

nosound();


randomize();

PEDRAX = 20;
PEDRAY = 12;

PONTA = PONTOS = 0;
TAMANHO = 5;
APAGA = PONTA - TAMANHO;

J = 0;
while (J < MAXS) {
	SNAKE[J][0] = 0;
	SNAKE[J][1] = 0;
	J++;
}

/*CURSOR = 178;*/
CURSOR = 219;
clrscr();


textcolor(LIGHTBLUE);
gotoxy(0,0);
cprintf("ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ");
for(i=1;i<23;i++) {
cprintf("Û                                                                              Û");
}
cprintf("ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß");

/*
X = 5;
Y = 23;

SNAKE[1][0] = X;
SNAKE[1][1] = Y;
*/

PONTA = 0;
while (PONTA < TAMANHO) {
	X = 2 + PONTA;
	Y = 23;
	SNAKE[PONTA][0] = X;
	SNAKE[PONTA][1] = Y;
	PONTA++;
	gotoxy(X,Y);
	textcolor(YELLOW);
	cprintf("%c",CURSOR);
}

textcolor(RED);
gotoxy(PEDRAX,PEDRAY);
cprintf("%c",CURSOR);


gotoxy(X,Y);
textcolor(YELLOW);
cprintf("%c",CURSOR);


FIM = 0;
TECLA = 'd';
do
{
	delay(50);

	I = kbhit();
	OLDTECLA = TECLA;
	if (I != 0) {
		VOLTATECLA = TECLA;
		TECLA = getch();
	}
	if (TECLA != 'w') {
		if (TECLA != 's') {
			if (TECLA != 'a') {
				if (TECLA != 'd') {
					if (TECLA != 27) {
						TECLA = OLDTECLA;
					}
				}
			}
		}
	}

	switch (TECLA) {
	case 'w':
		if (VOLTATECLA != 's') {
			Y = Y - 1;
		} else {
			Y = Y + 1;
			TECLA = 's';
		}
		break;
	case 's':
		if (VOLTATECLA != 'w') {
			Y = Y + 1;
		} else {
			Y = Y - 1;
			TECLA = 'w';
		}
		break;
	case 'd':
		if (VOLTATECLA != 'a') {
			X = X + 1;
		} else {
			X = X - 1;
			TECLA = 'a';
		}
		break;
	case 'a':
		if (VOLTATECLA != 'd') {
			X = X - 1;
		} else {
			X = X + 1;
			TECLA = 'd';
		}
		break;
	case 27:
		FIM = 1;
		break;
	}


	if (X > MAXX -1) {
		X = MAXX;
		FIM = 1;
	}

	if (X < 2) {
		X = 1;
		FIM = 1;
	}

	if (Y > MAXY -1) {
		Y = MAXY;
		FIM = 1;
	}

	if (Y < 2) {
		Y = 1;
		FIM = 1;
	}

	/*apaga*/

	/*gotoxy(2,2);
	cprintf("Ponta:%d Apaga:%d X:%d Y:%d  ",PONTA,APAGA,X,Y);*/

	if (PONTA == MAXS-1) {
		PONTA = 0;
	} else {
		PONTA = PONTA + 1;
	}

	if (X == PEDRAX && Y == PEDRAY) {
		sound(500);
		delay(100);
		nosound();
		APAGA = APAGA - 1;
		PONTOS = PONTOS + 1;
		PEDRAX = 0;
		while(PEDRAX == 0) {
			PEDRAX = random(38)+2;
			PEDRAY = random(21)+2;
			textcolor(RED);
			gotoxy(PEDRAX,PEDRAY);
			cprintf("%c",CURSOR);
			textcolor(YELLOW);
			J = 0;
			while(J < MAXS) {
				if (SNAKE[J][0] == X && SNAKE[J][1] == Y) {
				PEDRAX = 0;
				}
				J = J + 1;
			}
		}
	}

	if (APAGA == MAXS-1) {
		APAGA = 0;
	} else {
		APAGA = APAGA + 1;
	}

	/*gotoxy(2,4);
	printf("Ponta:%d Apaga:%d X:%d Y:%d  ",PONTA,APAGA,X,Y);*/

	SNAKE[PONTA][0] = X;
	SNAKE[PONTA][1] = Y;

	gotoxy(SNAKE[APAGA][0],SNAKE[APAGA][1]);
	cprintf(" ");
	if (APAGA >= 0) {
	SNAKE[APAGA][0] = 0;
	SNAKE[APAGA][1] = 0;
	}

	/*fim do apaga*/

	/*bateu*/

	J = 0;
	while(J < MAXS) {
		if (SNAKE[J][0] == X && SNAKE[J][1] == Y && J != PONTA) {
			FIM = 1;
		}
		J = J + 1;
	}

	/*fim do bateu*/


	gotoxy(X,Y);
	cprintf("%c",CURSOR);
	gotoxy(X,Y);

}
while (FIM != 1);

clrscr();

gotoxy(35,12);
textcolor(LIGHTGREEN);
cprintf("GAME OVER");

sound(300);
delay(200);
sound(150);
delay(400);
nosound();

getch();

clrscr();
gotoxy(35,12);
textcolor(LIGHTRED);
PONTOS = PONTOS * 3;
cprintf("%d PONTOS",PONTOS);


getch();

}
