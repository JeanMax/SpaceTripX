// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Player.class.hpp                                          (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include "log.hpp"
# include "Unit.class.hpp"

# define PLAYER_SPRITE {                        \
    " ^ ", \
    "^^^", \
}


class Player: public Unit
{
    public:
        Player(const int x = 0, const int y = 0);
        ~Player(void);


        // int x, y;                         // in Point
        // int w, h;                         // in Rectangle
        // std::vector<std::string> sprite;  // in Unit
        // enum direction direction;         // in Unit
        enum action action = NO_ACTION;
};


#endif //PLAYER_CLASS_HPP
