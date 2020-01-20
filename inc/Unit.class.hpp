// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Unit.class.hpp                                            (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
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
    UP = 0,
    LEFT = 1,
    RIGHT = 2,
    DOWN = 3
};
# define MAX_DIRECTIONS 4


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
};


#endif //UNIT_CLASS_HPP
