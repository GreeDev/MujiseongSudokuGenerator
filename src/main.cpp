#include "sudoku/sudoku_solver.h"
#include "sudoku/sudoku_game_generator.h"
#include <iostream>

Sudoku::SudokuGameGenerator sudokuGameGenerator;

void PrintGame(const std::vector<std::vector<int>>& game){
    for(const std::vector<int>& g : game){
        for(int x : g)
            std::cout << x << " ";
        std::cout << std::endl;
    }
}

int main(){
    int T = 10000;
    int t = T;
    int suc = 0;
    while(t--){
        suc += sudokuGameGenerator.Generate(45, 0, 60);
        if(t % 1000 == 0)
            std::cout << "gen: " << t << std::endl;
    }
    std::cout << 100. * suc / T;
    return 0;
    PrintGame(sudokuGameGenerator.GetGame());
    std::cout << " ---- " << std::endl;
    PrintGame(sudokuGameGenerator.GetGameSolution());

    return 0;
}
