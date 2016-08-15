#if !defined  _BINPACKING_BINARYTREE
#define _BINPACKING_BINARYTREE

    #include "Game.hpp"

    namespace binpacking {

        class BinaryTree {

            protected:

                float size;
                Game *item;
                BinaryTree *left;
                BinaryTree *right;

                void init(Game *item, float size);
                void destroy();

                BinaryTree *setLeft(BinaryTree *node);
                BinaryTree *setRight(BinaryTree *node);
                BinaryTree *setItem(Game *item);
                void updateSize(Game *item);

            public:

                BinaryTree(float size);
                BinaryTree(Game *item, float size);
                ~BinaryTree();

                BinaryTree *insert(Game *item, float maxSize);

                Game *getItem();
                float getSize();
                BinaryTree *getLeft();
                BinaryTree *getRight();

                bool fits(Game *item);
                bool hasLeft();
                bool hasRight();
                bool isLeaf();
                bool isEmpty();

                void print();
        };
    }

#endif
