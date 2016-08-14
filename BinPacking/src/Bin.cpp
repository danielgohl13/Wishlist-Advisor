#include "../BinPacking.hpp"
using namespace binpacking;

Bin::Bin(float maxSize){
    this->maxSize = maxSize;
    this->currentSize = 0;
}

bool Bin::addItem(Game *item){
    if(this->getSize() + item->getPrice() > this->getMaxSize()) return false;

    this->items.push_back(item);
    this->currentSize += item->getPrice();
    return true;
}

Game *Bin::at(unsigned int index){
    if(index > this->length()) return NULL;
    return this->items[index];
}

unsigned int Bin::length(){
    return this->items.size();
}

float Bin::getSize(){
    return this->currentSize;
}

float Bin::getMaxSize(){
    return this->maxSize;
}
