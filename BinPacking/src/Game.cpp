#include "../BinPacking.hpp"
using namespace binpacking;

Game::Game(){}

Game::Game(int order, float price, String name){
    this->setOrder(order)
        ->setPrice(price)
        ->setName(name);
}

int Game::getOrder(){
    return this->order;
}

float Game::getPrice(){
    return this->price;
}

String Game::getName(){
    return this->name;
}

Game *Game::setOrder(int order){
    this->order = order;
    return this;
}

Game *Game::setPrice(float price){
    this->price = price;
    return this;
}

Game *Game::setName(String name){
    this->name = name;
    return this;
}
