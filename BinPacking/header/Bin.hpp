#if !defined  _BINPACKING_BIN
#define _BINPACKING_BIN

    #include "../../Util/Game.hpp"
    #include <vector>

    namespace binpacking {

        class Bin {
            protected:
                std::vector<Game *> items;
                float maxSize;
                float currentSize;

            public:
                Bin(float maxSize);

                bool addItem(Game *item);
                Game *at(unsigned int index);

                int length();
                float getSize();
                float getMaxSize();
        };
    }

#endif
