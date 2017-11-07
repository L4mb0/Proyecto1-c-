#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void subirdenivel (int&nivel, int&atk, int&dfs, int&spd, int&xpmax, int&vida)
{
	nivel += 1;
	atk += rand() % 3;
	dfs += rand() % 3;
	spd += rand() % 3;
	xpmax = xpmax*1.5;
	vida += rand() % 5;
}

int experiencia (int atke, int dfse, int spde )
{
    int xp = 0;
    xp = (atke+dfse+spde)/3;
    return xp;
}



void ataque (int atk, int dfse, int&vidae)
{
	int poder;
	poder = atk - dfse;
	if (poder <= 0)
		vidae -= 1;
	else
		vidae -= poder;

}

void enemigo (int&atke, int&dfse, int&spde, int&vida)
{
	atke += rand() % 3;
	dfse += rand() % 3;
	spde += rand() % 3;
	vida += rand() % 6;
}



