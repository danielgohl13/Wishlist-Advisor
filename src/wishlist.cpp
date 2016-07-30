#include "../wishlist.h"

void Game::setPrice(float price){
    this->price = price;
}

float Game::getPrice(){
    return this->price;
}

void Wishlist::addList(Game game){
    gamesList.push_back(game);
}
