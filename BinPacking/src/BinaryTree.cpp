#include "../BinPacking.hpp"
using namespace binpacking;

/* ************* Construtores ************* */
void BinaryTree::init(Game *item, float size){
    this->size = size;
    this->setItem(item)
        ->setLeft(NULL)
        ->setRight(NULL);
}

void BinaryTree::destroy(){
    if(this->hasLeft()) delete this->left;
    if(this->hasRight()) delete this->right;
    if(!this->isEmpty()) this->setItem(NULL);
}

BinaryTree::BinaryTree(float size){
    this->init(NULL, size);
}

BinaryTree::BinaryTree(Game *item, float size){
    this->init(item, size);
}

BinaryTree::~BinaryTree(){
    this->destroy();
}

/* ************* Operações ************* */

BinaryTree *BinaryTree::insert(Game *item, float maxSize){

    if(this->isEmpty()){
        this->setItem(item);
        return this;
    }

    if(this->fits(item)){
        BinaryTree *node = this;

        while(node->hasLeft()){
            node = node->getLeft();
            node->updateSize(item);
        }

        node->setLeft(new BinaryTree(item, this->getSize()));
        this->updateSize(item);

        return node->getLeft();
    }

    if(this->hasRight()){
        return this->getRight()->insert(item, maxSize);
    }
    else{
        this->setRight(new BinaryTree(item, maxSize));
        return this->getRight();
    }

}

/* ************* Setters ************* */

BinaryTree *BinaryTree::setLeft(BinaryTree *node){
    this->left = node;
    return this;
}

BinaryTree *BinaryTree::setRight(BinaryTree *node){
    this->right = node;
    return this;
}

BinaryTree *BinaryTree::setItem(Game *item){
    this->item = item;
    this->updateSize(item);
    return this;
}

void BinaryTree::updateSize(Game *item){
    if(item != NULL) this->size -= item->getPrice();
}

/* ************* Getters ************* */

Game *BinaryTree::getItem(){
    return this->item;
}

float BinaryTree::getSize(){
    return this->size;
}

BinaryTree *BinaryTree::getLeft(){
    return this->left;
}

BinaryTree *BinaryTree::getRight(){
    return this->right;
}

/* ************* Checkers ************* */

bool BinaryTree::fits(Game *item){
    return this->size >= item->getPrice();
}

bool BinaryTree::hasLeft(){
    return this->left != NULL;
}

bool BinaryTree::hasRight(){
    return this->right != NULL;
}

bool BinaryTree::isLeaf(){
    return !this->hasLeft() && !this->hasRight();
}

bool BinaryTree::isEmpty(){
    return this->item == NULL;
}

/* ************* Outros ************* */

void printSpaces(int spaces){
    for(int i = 1; i <= spaces; i++)
		out->put((i == spaces) ? " - " : "  ");
}

void BinaryTree::print(){
    this->print(0);
}

void BinaryTree::print(int spaces){

    out->put("(")
       ->put(this->getItem()->getOrder())
       ->put(", ")
       ->put(this->getSize())
       ->put(")", true);


    if(this->hasLeft()){
        printSpaces(spaces + 1);
        out->put("L");
        this->getLeft()->print(spaces + 1);
    }

    if(this->hasRight()){
        printSpaces(spaces + 1);
        out->put("R");
        this->getRight()->print(spaces + 1);
    }
}
