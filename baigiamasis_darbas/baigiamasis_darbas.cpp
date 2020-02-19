// baigiamasis_darbas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"											//naudojamos bibliotekos
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;										//naudojama klase

HWND myconsole = GetConsoleWindow();
HDC langas = GetDC(myconsole);

struct kulka 
{
	int y;
	int x;
	bool patikrinimas;
};

struct gyvybes
{
	int y;
	int x;
	COLORREF spalva;
};

int figuros_plotis = 60, figuros_aukstis = 20;
static COLORREF sp_pilka = RGB (120,119,119);
static COLORREF sp_juoda = RGB (0,0,0);
COLORREF sp_pilka2 = RGB (160,143,122);

void valdomas_ob (int koordinate_x, int koordinate_y, COLORREF spalva)			// valdomo objekto piesimas
{

	COLORREF sp_juoda = RGB (0,0,0);
	
	for (int x = 0; x < figuros_plotis; x++)			//kunas
	{
		for (int y = 0; y< figuros_aukstis; y++)
		{
			SetPixel(langas, koordinate_x + x, koordinate_y+ y, spalva);
		}
	}

	for (int x = 0; x < figuros_plotis/5; x++)			//ausis
	{
		for (int y = 0; y< figuros_aukstis/4; y++)
		{
			SetPixel(langas, koordinate_x+figuros_plotis/10 + x, koordinate_y - y, spalva);
		}
	}

	for (int x = 0; x < figuros_plotis/20; x++)			//uodega
	{
		for (int y = 0; y< figuros_aukstis/10*4; y++)
		{
			SetPixel(langas, koordinate_x+figuros_plotis + x, koordinate_y+figuros_aukstis/10 + y, spalva);
		}
	}

	for (int x = 0; x < figuros_plotis/20*3; x++)			//kojos
	{
		for (int y = 0; y<figuros_aukstis/10*4 ; y++)
		{
			SetPixel(langas, koordinate_x+figuros_plotis/10 + x, koordinate_y+figuros_aukstis + y, spalva);
			SetPixel(langas, koordinate_x+figuros_plotis/10*8 + x, koordinate_y+figuros_aukstis + y, spalva);
		}
	}

	for (int x = 0; x < figuros_plotis/30; x++)			//akys
	{
		for (int y = 0; y<figuros_aukstis/10*2 ; y++)
		{
			SetPixel(langas, koordinate_x+figuros_plotis/20 + x, koordinate_y+figuros_aukstis/10 + y, sp_pilka);
			SetPixel(langas, koordinate_x+figuros_plotis/20*4 + x, koordinate_y+figuros_aukstis/10 + y, sp_pilka);
		}
	}

	for (int x = 0; x < figuros_plotis/30*4; x++)			//burna
	{
		for (int y = 0; y<figuros_aukstis/10; y++)
		{
			SetPixel(langas, koordinate_x+figuros_plotis/10 + x, koordinate_y+figuros_aukstis/10*6 + y, sp_pilka);
		}
	}
}

void ob_tankas (int ob_koordinate_x, int ob_koordinate_y, int objekto_aukstis, int objekto_plotis, COLORREF spalva)			// objekto "tankas" piesimas
{

	for (int x = 0; x <= objekto_plotis; x++)		//pirma pakopa
	{
		for (int y = 0; y < objekto_aukstis; y++)
		{
			SetPixel(langas, ob_koordinate_x + x, ob_koordinate_y - y, spalva); 
		}
	}

	for (int x = 0; x <= objekto_plotis/1.5; x++)		//antra pakopa
	{
		for (int y = 0; y < objekto_aukstis; y++)
		{
			SetPixel(langas, ob_koordinate_x+objekto_plotis/12*2 + x, ob_koordinate_y-objekto_aukstis - y, spalva); 
		}
	}

	for (int x = 0; x <= objekto_plotis/3; x++)		//trecia pakopa
	{
		for (int y = 0; y < objekto_aukstis; y++)
		{
			SetPixel(langas, ob_koordinate_x+objekto_plotis/12*4 + x, ob_koordinate_y-objekto_aukstis*2 - y, spalva); 
		}
	}

	for (int x = 0; x <= objekto_plotis; x++)		//..
	{
		for (int y = 0; y < objekto_aukstis; y++)
		{
			SetPixel(langas, ob_koordinate_x +objekto_plotis/12*4 + x,ob_koordinate_y-objekto_aukstis*2 - y, spalva); 
		}
	}
}

void sovinys (int koordinate_x, int koordinate_y, COLORREF spalva)									// kulkos/sovinio piesimas
{
	int ob_ilgis = 7, ob_plotis = 7;

	for (int i  = 0; i < ob_ilgis; i++)
	{
		for(int j = i; j < ob_plotis; j++)
		{
			SetPixel (langas, koordinate_x + i, koordinate_y +j, spalva);
			SetPixel (langas, koordinate_x + i, (koordinate_y + ob_plotis*2-2) -j, spalva);
			SetPixel (langas, koordinate_x - i, koordinate_y +j, spalva);
			SetPixel (langas, koordinate_x - i, (koordinate_y + ob_plotis*2-2) -j, spalva);
		}
	}
}

void zaidimo_ribos (int prad_x, int prad_y, int gal_x, int gal_y, COLORREF spalva)		//zaidimo lango piesimas
{

	for (int i = 0; i < gal_x; i++)			//zaidimo lango piesimas
	{
		for (int j = 0; j < gal_y; j++)
		{
			SetPixel(langas, prad_x+i,prad_y+j, sp_pilka);
		}
	}

	for (int x = 0; x < gal_x; x++)															//rezultato lango spalvinimas
	{
		for (int y = 0; y < gal_y/10; y++)
		{
			SetPixel(langas,prad_x+x,prad_y+y, spalva);
		}
	}

	for (int x = 0; x < gal_x; x++)						//ribos x
	{	
		SetPixel (langas, prad_x + x, prad_y, sp_juoda);
		SetPixel (langas, prad_x + x, gal_y, sp_juoda);
		SetPixel (langas, prad_x + x, gal_y/10,sp_juoda);
	}

	for (int y = 0; y < gal_y; y++)					//ribos y
	{
		SetPixel (langas, prad_x, prad_y + y, sp_juoda);
		SetPixel (langas, gal_x, prad_y + y, sp_juoda);
	}
}

void gyvybes_piesimas (int koordinate_x, int koordinate_y,COLORREF spalva)				//Gyvybes piesimas
{

	int tasko_ilgis = 15;
	int gyvybiu_sk = 4;
	int koordinate_x2 = 0;
	
		for (int x = 0; x < tasko_ilgis; x++)
		{
			for(int y = x; y < tasko_ilgis; y++)
			{
				SetPixel(langas, koordinate_x+koordinate_x2 + x, koordinate_y+y, spalva);
				SetPixel(langas, koordinate_x+koordinate_x2 - x, koordinate_y+y, spalva);		
			}
		}
		for (int x = 0; x <tasko_ilgis; x++)
		{
			for(int y = x; y < tasko_ilgis; y++)
			{
				SetPixel(langas, koordinate_x+koordinate_x2 + x, koordinate_y+tasko_ilgis+4-y, spalva);
				SetPixel(langas, koordinate_x+koordinate_x2 - x, koordinate_y+tasko_ilgis+4-y, spalva);	
			}
		}
}

bool koordinaciu_tikrinimas (int valdomas_x, int valdomas_y, int gaudomas_x,int gaudomas_y, int ribos_x, int ribos_y)					// sovinio interakcija su valdomu ob
{
	if ((valdomas_x + figuros_plotis > gaudomas_x) && (valdomas_x < gaudomas_x + figuros_plotis) && (valdomas_y < gaudomas_y + figuros_aukstis) && (valdomas_y + figuros_aukstis) > gaudomas_y)
	{	
		return true;
	}
return false;
}

int _tmain(int argc, _TCHAR* argv[])		// pagr. funkcija
{
	system ("cls");	// ekrano isvalymas

	//naudojami kintamieji

	int objekto_tankas_aukstis = 10, objekto_tankas_plotis = 50;				//tanko aukstis/plotis
	int valdomas_ob_x = 530, valdomas_ob_y = 150;								// valdomo pradines koordinates
	int ob_koordinate_tankas_x = 10, ob_koordinate_tankas_y = 90;				//tanko pradines koordinates
	int sovinio_x = 90, sovinio_y = 60;										// sovinio pradines koordinates
	int pelnyto_tasko_x = 450, pelnyto_tasko_y = 5;								//pelnyto tasko prad koord
	const int prad_zaidimo_koordinate_x = 0, prad_zaidimo_koordinate_y = 0;		// consoles pradzios taskai
	const int gal_zaidimo_koordinate_x = 499, gal_zaidimo_koordinate_y = 399;	// consoles plotis/ilgis
	int klavisas=0;
	int zingsnis = 10;											
	int tanku_sk = 5;
	int gyvybiu_sk=3, soviniu_sk = 5;
	int nr = 3;
	kulka masyvas [6];
	gyvybes gyvybe [3];
	int kelintas=8, tarpas=40;
	COLORREF sp_balta = RGB (255,255,255);
	COLORREF sp_geltona2 = RGB (255,255,0);
	COLORREF sp_geltona = RGB (255, 255, 255);

	zaidimo_ribos(prad_zaidimo_koordinate_x, prad_zaidimo_koordinate_y, gal_zaidimo_koordinate_x, gal_zaidimo_koordinate_y, sp_pilka2);
	valdomas_ob(valdomas_ob_x, valdomas_ob_y, sp_geltona);
	
	for (int i = 1; i <= gyvybiu_sk; i++)					//gyvybiu piesimas
				{
					gyvybe[i].x = pelnyto_tasko_x;
					gyvybe[i].y = pelnyto_tasko_y;
					gyvybe[i].spalva = sp_geltona2;
					gyvybes_piesimas(gyvybe[i].x,gyvybe[i].y, gyvybe[i].spalva);
					pelnyto_tasko_x += 70;
				}

	for (int i = 0; i <= tanku_sk; i++)					//pradines sovinio koordinates
	{
			masyvas[i].x = sovinio_x;
			masyvas[i].y = sovinio_y;
			masyvas[i].patikrinimas = false;
			sovinio_y += tarpas;
	}

	for (int i = 0; i<tanku_sk; i++)					//tanku isdestymas
	{
		ob_tankas (ob_koordinate_tankas_x, ob_koordinate_tankas_y, objekto_tankas_aukstis,objekto_tankas_plotis,sp_juoda);
		ob_koordinate_tankas_y += tarpas;
		ob_tankas (ob_koordinate_tankas_x, ob_koordinate_tankas_y, objekto_tankas_aukstis,objekto_tankas_plotis,sp_juoda);
	}

	while (klavisas!=27)			//kol nepaspaude "esc" klaviso
	{
		while(!_kbhit())			// kol nepaspaude jokio klaviso
		{
			Sleep(100);

			for (int i = 0; i <= tanku_sk; i ++)
			{
				if (masyvas[i]. patikrinimas == true)								//tikrinama ar sovinys nekerta zaidimo ribu
				{

					if ((valdomas_ob_x + figuros_plotis > masyvas[i].x) && (valdomas_ob_x < masyvas[i].x + 7) && (valdomas_ob_y + figuros_aukstis+5 > masyvas[i].y) && (valdomas_ob_y-5 < masyvas[i].y + 7))
					{
						gyvybe[nr].spalva = sp_pilka2;
						gyvybes_piesimas(gyvybe[nr].x,gyvybe[nr].y, gyvybe[nr].spalva);
						nr--;
						sovinys (masyvas[i].x,masyvas[i].y,sp_pilka);
						masyvas[i].patikrinimas = false;
						masyvas[i].x = 90;
						masyvas[i].y = 60 + tarpas*(i+1);

						if (nr == 0)
						{
							return 0;
						}
					}
				}
			}

			for (int i = 0; i <= tanku_sk; i++)												//tikrinama ar ar sovinys nepataike i valdoma objekta
			{
				if (masyvas[i].patikrinimas == true)
				{
					if(masyvas[i].x + 14 < gal_zaidimo_koordinate_x)
					{
								sovinys (masyvas[i].x,masyvas[i].y,sp_pilka);
								masyvas[i].x += zingsnis;
								sovinys (masyvas[i].x,masyvas[i].y,sp_balta);
								 if (masyvas[i].x + 10 > gal_zaidimo_koordinate_x)
										{
											sovinys (masyvas[i].x,masyvas[i].y,sp_pilka);
											masyvas[i].patikrinimas = false;
											masyvas[i].x = 90;
											masyvas[i].y = 60 + tarpas*i;
										}
					}				
				}
			}
		}
						
	klavisas = _getch();

//valdomo objekto valdymas

	switch (klavisas)
	{
	case 75:
		if (valdomas_ob_x-objekto_tankas_plotis-figuros_plotis/2>prad_zaidimo_koordinate_x)			//kairen											
		{
		valdomas_ob(valdomas_ob_x, valdomas_ob_y, sp_pilka); 
		valdomas_ob_x -= 10;
		valdomas_ob(valdomas_ob_x, valdomas_ob_y, sp_geltona);
		}
	break;
	case 77:
		if (valdomas_ob_x+figuros_plotis+10<gal_zaidimo_koordinate_x)								//desinen
		{
		valdomas_ob(valdomas_ob_x, valdomas_ob_y, sp_pilka); 
		valdomas_ob_x += 10;
		valdomas_ob(valdomas_ob_x, valdomas_ob_y, sp_geltona);
		}
	break;
	case 72:																					   // aukstyn
		if (valdomas_ob_y -figuros_aukstis*2 > prad_zaidimo_koordinate_y)
		{
		valdomas_ob(valdomas_ob_x, valdomas_ob_y, sp_pilka);
		valdomas_ob_y -= 10;
		valdomas_ob(valdomas_ob_x, valdomas_ob_y, sp_geltona);		
		}
	break;
	case 80:																						// zemyn
		if (valdomas_ob_y + figuros_aukstis*1.5 < gal_zaidimo_koordinate_y)
		{
		valdomas_ob(valdomas_ob_x, valdomas_ob_y, sp_pilka);
		valdomas_ob_y += 10;
		valdomas_ob(valdomas_ob_x, valdomas_ob_y, sp_geltona);
		}
	break;

//patranku isovimas
	case 49:																						//tanko parinkimas(1)
		{
			kelintas=0;
			masyvas[kelintas].patikrinimas = true;
		}
	break;
	case 50:																						//tanko parinkimas(2)
		{
			kelintas=1;
			masyvas[kelintas].patikrinimas = true;
		}
	break;
	case 51:																						//tanko parinkimas(3)
		{
			kelintas=2;
			masyvas[kelintas].patikrinimas = true;
		}
	break;
	case 52:																						//tanko parinkimas(4)
		{
			kelintas=3;
			masyvas[kelintas].patikrinimas = true;
		}
	break;
	case 53:																						//tanko parinkimas(5)
		{
			kelintas=4;
			masyvas[kelintas].patikrinimas = true;
		}
	break;
	case 54:																						//tanko parinkimas(6)
		{
			kelintas=5;
			masyvas[kelintas].patikrinimas = true;
		}
	break;
	default:
		break;
	}
	}

	system("pause");
	return 0;
}