#if !defined  _BINPACKING_WISHLISTGAME
#define _BINPACKING_WISHLISTGAME

    #include <string>

    namespace binpacking {

        class Game {

            protected:
                int order;
                float price;
                std::string name;

            public:

                Game();
                Game(int order, float price, std::string name);

                int getOrder();
                float getPrice();
                std::string getName();

                Game *setOrder(int order);
                Game *setPrice(float price);
                Game *setName(std::string name);
        };
    }

#endif
