#if !defined  _BINPACKING
#define _BINPACKING

    #include "../Common/Common.hpp"
    #include "header/Game.hpp"
    #include "header/BinaryTree.hpp"
    #include "header/Bin.hpp"

    namespace binpacking {
        typedef std::vector<Game *> WishList;
        typedef std::vector<Bin *> BinCollection;

        BinCollection binpacking::doPacking(WishList wl, float binSize);
        BinCollection binpacking::doPacking(WishList wl, float binSize, BinaryTree **tree);
    }

#endif
