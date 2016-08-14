#if !defined  _WISHLIST
#define _WISHLIST

    #include "../Common/Common.hpp"
    #include <vector>

    class Game {

        protected:
            int order;
            float price;
            String name;

        public:

            Game();
            Game(int order, float price, String name);

            int getOrder();
            float getPrice();
            String getName();

            Game *setOrder(int order);
            Game *setPrice(float price);
            Game *setName(String name);
    };

    typedef std::vector<Game *> WishList;

#endif
