#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

//funcion para guardar los  datos
void GameGuard(int HeroPosX, int HeroPosY) {
	ofstream SaveGamex("GameWar.txt");
	if (SaveGamex.is_open())
	{
		SaveGamex << HeroPosX ;
		SaveGamex << HeroPosY;	}
	else {
		cout << "No se guardaron bien los datos" << endl;
	}

};

//funcion cargar mapa en pantalla
void GameScreen(char Mapa[5][5], int HeroPosX, int HeroPosY) {

	for (int Fila = 0; Fila < 5; Fila++)
	{
		cout << " " << endl;
		for (int Columna = 0; Columna < 5; Columna++)
		{
			if (Fila != HeroPosX) {
				cout << Mapa[Fila][Columna];

			}
			else
			{
				if (Columna != HeroPosY) {

					cout << Mapa[Fila][Columna];
				}
				else
				{
					cout << 'H';
				}

			}
		}
	}
	
};
//funcion para los controles de movimiento.
void Gamecontrols(char& HeroWalk, int& HeroPosX, int& HeroPosY, char Mapa[5][5]) {
	while (HeroWalk != 't')
	{
		cin >> HeroWalk;
		if (HeroWalk == 'a') {

			HeroPosY = HeroPosY - 1;
		}
		else if (HeroWalk == 'd')
		{
			HeroPosY = HeroPosY + 1;

		}
		else if (HeroWalk == 'w')
		{
			HeroPosX = HeroPosX - 1;
		}
		else if (HeroWalk == 's')
		{
			HeroPosX = HeroPosX + 1;
		}

		GameScreen(Mapa, HeroPosX, HeroPosY);
		GameGuard(HeroPosX, HeroPosY);

	}
	
	
};

//carga datos guardados de partidas
void LoadingGame(int& HeroPosX, int& HeroPosY) {
	
	string DatosGame;
	ifstream SaveGame("GameWar.txt");
	if (SaveGame.is_open())
	{
		getline(SaveGame, DatosGame);		
		HeroPosX = DatosGame[0] - '0';
		HeroPosY = DatosGame[1] - '0';
		cout << HeroPosX;
		cout << HeroPosY;		
	}
	else
	{
		cout << "Los datos guardados no se cargaron correctamente" << endl;

	}
	cout << " " << endl;

};




void Start()
{
	
	cout << " ######  ########    ###    ########  ########" << endl;
	cout << "##    ##    ##      ## ##   ##     ##    ##   " << endl;
	cout << "##          ##     ##   ##  ##     ##    ##   " << endl;
	cout << " ######     ##    ##     ## ########     ##   " << endl;
	cout << "      ##    ##    ######### ##   ##      ##   " << endl;
	cout << "##    ##    ##    ##     ## ##    ##     ##   " << endl;
	cout << " ######     ##    ##     ## ##     ##    ##   " << endl;


};

int main()
{
	cout << "   _////         _/       _//       _//_////////" << endl;
	cout << " _/    _//      _/ //     _/ _//   _///_//      " << endl;
	cout << "_//            _/  _//    _// _// _ _//_// " << endl;
	cout << "_//           _//   _//   _//  _//  _//_//////" << endl;
	cout << "_//   _////  _////// _//  _//   _/  _//_// " << endl;
	cout << " _//    _/  _//       _// _//       _//_// " << endl;
	cout << "  _/////   _//         _//_//       _//_////////" << endl;

	//variables
	char opcion = ' ';
	char HeroWalk= ' ';
	int HeroPosX = 0, HeroPosY = 0;
	char Mapa[5][5] = { //siempre sera nuestro mapa de inicio
		{'1','1','1','1','1'},
		{'1','1','1','1','1'},
		{'1','1','1','1','1'},
		{'1','1','1','1','1'},
		{'1','1','1','1','1'}


	};
	ifstream SaveGame("Game.txt");
	int FilaDatosGame = 0;
	string DatosGame = " ";
	

	//_______________________________
	cout << "(N)ueva Partida" << endl;
	cout << "(C)argar Ultima partida"<<endl;
	cout << "(S)alir" << endl;
	cin >> opcion;    
	switch (opcion)
	{
	case 'N':
	case 'n':
		
		Start();		
		cout << " " << endl;
		cout << "presione (a) para ir a la Izquierda" << endl;
		cout << "presione (d) para ir a la Derecha" << endl;
		cout << "presione (w) para ir a  Arriba" << endl;
		cout << "presione (s) para ir a Abajo" << endl;
		cout << "presione (t) para salir y guardar" << endl;
		GameScreen(Mapa, HeroPosX, HeroPosY);
		Gamecontrols (HeroWalk, HeroPosX, HeroPosY, Mapa);	
		
		break;
    
	case 'C':
	case 'c':

		
		LoadingGame(HeroPosX, HeroPosY);
	    HeroPosX = HeroPosX;
		HeroPosY = HeroPosY;
		Start();
		GameScreen(Mapa, HeroPosX, HeroPosY);
		Gamecontrols(HeroWalk, HeroPosX, HeroPosY, Mapa);
			
		break;

	case 'S':
	case 's':
		cout << "Gracias por jugar";
		break;

	default:
		cout << "Opcion no valida" << endl;
		break;
	}

	
	
	return 0;
}