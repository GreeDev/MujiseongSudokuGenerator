#ifndef GWAJAE_RANDOM_H
#define GWAJAE_RANDOM_H

#include <random>

struct Random{
    std::mt19937 mt;

    Random(){
        std::random_device rd;
        mt = std::mt19937(rd());
    }
    Random(int seed){
        mt = std::mt19937(seed);
    }
    unsigned int Get(){
        return mt();
    }
    int Get(int min, int max){
        std::uniform_int_distribution<> dist(min, max);
        return dist(mt);
    }
};

#endif //GWAJAE_RANDOM_H
