// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Monster.class.hpp                                         (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef MONSTER_CLASS_HPP
# define MONSTER_CLASS_HPP

# include "log.hpp"
# include "Unit.class.hpp"

# define MONSTER_SPRITE {   \
        "|-o-|",            \
    }


class Monster: public Unit
{
    public:
        Monster(const int x = 0, const int y = 0);
        ~Monster(void);

        void play_turn(void);

        // int x, y;                         // in Point
        // int w, h;                         // in Rectangle
        // std::vector<std::string> sprite;  // in Unit
        // enum direction direction;         // in Unit
};


#endif //MONSTER_CLASS_HPP
