#include "../BinPacking.hpp"
using namespace binpacking;

BinCollection binpacking::doPacking(WishList wl, float binSize){
    return doPacking(wl, binSize, NULL);
}

BinCollection binpacking::doPacking(WishList wl, float binSize, BinaryTree **tree){

    BinCollection bc;
    BinaryTree *t = new BinaryTree(binSize);

    for(int i = 0; i < wl.size(); i++){
        if(wl[i]->getPrice() > binSize) continue;
        t->insert(wl[i], binSize);
    }

    BinaryTree *root = t;
    BinaryTree *node = NULL;
    Bin *b = NULL;

    while(root != NULL){

        b = new Bin(binSize);
        node = root;

        while(node != NULL){
            b->addItem(node->getItem());
            node = node->getLeft();
        }

        bc.push_back(b);
        root = root->getRight();
    }

    if(tree != NULL) *tree = t;
    else delete t;

    return bc;
}
