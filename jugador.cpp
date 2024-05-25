#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void DrawMap(int HeroPosY,int HeroPosX,char GameMap[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(i != HeroPosY)
            {
                cout << GameMap[i][j];
            } else
            {
                if(j != HeroPosX){
                    cout << GameMap[i][j];
                }else{
                    cout << 'H';
                }
            }
        }
        cout << endl;
       
    }
}

void GameSave(int HeroPosY, int HeroPosX) {
    ofstream MyFile("GameMap.txt");
    if (MyFile.is_open()) {
        MyFile << HeroPosY << endl << HeroPosX << endl;
        MyFile.close();
    }
}

void LoadingGame(int& HeroPosY, int& HeroPosX) {
    ifstream MyFile("GameMap.txt");
    if (MyFile.is_open()) {
        MyFile >> HeroPosY >> HeroPosX;
        MyFile.close();
        cout << HeroPosY << endl;
        cout << HeroPosX << endl;
    } else {
        cout << "Los datos guardados no se cargaron correctamente" << endl;
    }
}
int main(){

    char GameMap[5][5] = 
    { 
        {'>',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ','<'}
    };

    int HeroPosY = 0, HeroPosX = 0;
    bool isGameOver = false;
    char input = ' ';
    int opc = ' ';
    ifstream SavGame("Game.txt");
    int FilaDatosGame = 0;

    cout << "1. New Game " << endl;
    cout << "2. Load Game " << endl;
    cin >> opc;
        switch (opc)
        {
        case 1:
        while(isGameOver == false){   
            DrawMap(HeroPosY,HeroPosX,GameMap);
            cin >> input;
        
            if(input == 'd')
            {
                HeroPosX += 1;
            } 
            else if (input == 'a')
            {
                HeroPosX -= 1;
            }
            else if (input == 'w')
            {
                HeroPosY -= 1;
            }
            else if (input == 's')
            {
                HeroPosY += 1;
            } 
            else if (input == 'p')
            {
                isGameOver = true;
            }
            else if (input == 'g')
            {
                GameSave(HeroPosY,HeroPosX);
            }
            
            DrawMap(HeroPosY,HeroPosX,GameMap);
        }
            break;
        case 2:
            LoadingGame(HeroPosY, HeroPosX);
            while(isGameOver == false){
            
	        HeroPosX = HeroPosX;
		    HeroPosY = HeroPosY;
            DrawMap(HeroPosY,HeroPosX,GameMap);
            cin >> input;
        
            if(input == 'd')
            {
                HeroPosX += 1;
            } 
            else if (input == 'a')
            {
                HeroPosX -= 1;
            }
            else if (input == 'w')
            {
                HeroPosY -= 1;
            }
            else if (input == 's')
            {
                HeroPosY += 1;
            } 
            else if (input == 'p')
            {
                isGameOver = true;
            }
            else if (input == 'g')
            {
                GameSave(HeroPosY,HeroPosX);    
            }
            DrawMap(HeroPosY,HeroPosX,GameMap);
        }
        break;
            
        
    }

    return 0;
}