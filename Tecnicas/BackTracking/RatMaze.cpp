#include <bits/stdc++.h>
using namespace std;

// Tamaño del laberinto
#define N 4
  
vector<vector<int>> maze;
vector<vector<int>> solution(N, vector<int>(N, 0));

void printSolution(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<solution[i][j]<<" ";
        cout<<endl;
    }
}

bool isValid(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1;
}
  
bool solveMaze(int x, int y){
    // Si ya se llego al destino y es valido lo retornamos
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        solution[x][y] = 1;
        return true;
    }
    // Checa si maze[x][y] es valido
    if (isValid(x, y)) {
        // Checa si la celda actual ya es parte de la solucion
        if (solution[x][y] == 1)
            return false;
        // Marca la celda como parte de la solucion
        solution[x][y] = 1;
        //Nos movemos en la direccion de X (para abajo)
        if (solveMaze(x + 1, y))
            return true;
        // Si abajo no funciono nos movemos para arriba
        if (solveMaze(x - 1, y))
            return true;
        // Si abajo y arriba no funcionaron nos movemos a la derecha
        if (solveMaze(x, y + 1))
            return true;
        // Si lo anterior no funciono nos movemos a la izquierda
        if (solveMaze(x, y - 1))
            return true;
        // Si ningun movimiento funcino entonces desmarcamos la celda
        // como parte de la solucion
        solution[x][y] = 0;
        return false;
    }
    return false;
}
  
int main(){
    maze = { { 1, 0, 0, 0 },
             { 1, 1, 1, 1 },
             { 1, 0, 0, 1 },
             { 1, 1, 1, 1 } 
           };

    if (solveMaze(0, 0) == false) {
        cout<<"No hay solucion";
    }else{
        printSolution();
    }
    return 0;
}