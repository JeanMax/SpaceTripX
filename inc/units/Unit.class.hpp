// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Unit.class.hpp                                            (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef UNIT_CLASS_HPP
# define UNIT_CLASS_HPP

# include <string>
# include <vector>
# include "log.hpp"
# include "Rectangle.class.hpp"

# define AT(array, point) (array[point.y][point.x])


enum direction
{
    TOP_LEFT    = 0,  TOP          = 1,  TOP_RIGHT    = 2,
    LEFT        = 3,  NO_DIRECTION = 4,  RIGHT        = 5,
    BOTTOM_LEFT = 6,  BOTTOM       = 7,  BOTTOM_RIGHT = 8,
};
# define MAX_DIRECTIONS 9


enum action
{
    MOVE_TOP_LEFT     = 0,   MOVE_TOP     = 1,   MOVE_TOP_RIGHT     = 2,
    MOVE_LEFT         = 3,   NO_ACTION    = 4,   MOVE_RIGHT         = 5,
    MOVE_BOTTOM_LEFT  = 6,   MOVE_BOTTOM  = 7,   MOVE_BOTTOM_RIGHT  = 8,

    SHOOT_TOP_LEFT    = 9,   SHOOT_TOP    = 10,  SHOOT_TOP_RIGHT    = 11,
    SHOOT_LEFT        = 12,  SHOOT_SELF   = 13,  SHOOT_RIGHT        = 14,
    SHOOT_BOTTOM_LEFT = 15,  SHOOT_BOTTOM = 16,  SHOOT_BOTTOM_RIGHT = 17,
};
# define MAX_ACTIONS 18


class Unit: public Rectangle
{
    public:
        Unit(
            const int x = 1, const int y = 1,
            std::vector<std::string> sprite = {"0"}
        );
        Unit(Unit const &copy);
        ~Unit(void);
        Unit &operator=(Unit const &copy);

        Unit &move(const enum direction direction);

        // int x, y;  // in Point
        // int w, h;  // in Rectangle
        static const Point base_vectors[MAX_DIRECTIONS];

        std::vector<std::string> sprite;
        enum direction direction = NO_DIRECTION;
};


#endif //UNIT_CLASS_HPP
