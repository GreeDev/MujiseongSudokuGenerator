#ifndef GWAJAE_SUDOKU_GAME_GENERATOR_H
#define GWAJAE_SUDOKU_GAME_GENERATOR_H

#include "sudoku_solver.h"

namespace Sudoku {

    class SudokuGameGenerator: private Sudoku::SudokuSolver{
        std::vector<std::vector<int>> game;
        std::vector<std::vector<int>> solution;

        const std::vector<int> pos = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
                , 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62
                , 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,};
    public:

        bool Generate(int empty_cell, int seed = 0, int gen_try = 1){
            game.resize(9);
            std::vector<int> empty = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for(std::vector<int>& row : game){
                row = empty;
            }
            if(seed){
                SetSeed(seed);
            }
            SetGame(game);
            Solve();

            solution = GetSolution();

            std::mt19937 shf(seed);

            while(gen_try-- > 0){
                int chk = 3;
                game = solution;
                std::vector<int> p = pos;
                std::shuffle(p.begin(), p.end(), shf);
                for(int i = 0; i < empty_cell; i++){
                    game[p[i] / 9][p[i] % 9] = 0;
                }
                while(chk){
                    SetGame(game);
                    Solve();
                    if(solution != GetSolution())
                        break;
                    chk--;
                }
                if(chk == 0)
                    return true;
            }
            return false;
        }
        std::vector<std::vector<int>> GetGame(){
            return game;
        }
        std::vector<std::vector<int>> GetGameSolution(){
            return solution;
        }
    };
} // Sudoku

#endif //GWAJAE_SUDOKU_GAME_GENERATOR_H
