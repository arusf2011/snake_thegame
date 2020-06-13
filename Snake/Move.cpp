#include "MyForm.h"
#include "pch.h"
#include <stdlib.h>
#include <stdio.h>

using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System;

void move(float s_coor[100][2], int direction, float f[2], int* score)
{
	for (int i = *score+1; i > 0; --i)
	{
		s_coor[i][0] = s_coor[i - 1][0];
		s_coor[i][1] = s_coor[i - 1][1];
	}
	// Zmiana kierunku
	if (direction == 0) s_coor[0][0] += 5;
	if (direction == 1) s_coor[0][1] -= 5;
	if (direction == 2) s_coor[0][0] -= 5;
	if (direction == 3) s_coor[0][1] += 5;

	//Generowanie owocow
	if ((s_coor[0][0] == f[0]) && s_coor[0][1] == f[1])
	{
		*score++;
		f[0] = (rand()*525) % 21;
		f[1] = (rand()*700) % 28;
	}

	// Nieskoczone przewijanie
	if (s_coor[0][0] > 525)
		s_coor[0][0] = 0;
	else if (s_coor[0][0] < 0)
		s_coor[0][0] = 525;
	if (s_coor[0][1] > 700)
		s_coor[0][1] = 0;
	else if (s_coor[0][1] < 0)
		s_coor[0][1] = 700;
}