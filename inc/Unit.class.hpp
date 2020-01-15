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

# include "log.hpp"
# include "Point.class.hpp"


enum direction
{
    UP = 0,
    LEFT = 1,
    RIGHT = 2,
    DOWN = 3
};
# define MAX_DIRECTIONS 4


Point g_base_vectors[MAX_DIRECTIONS] = {
             Point(0, 1),
    Point(-1, 0),    Point(1, 0),
            Point(0, -1),
};


class Unit: public Point
{
    public:
        Unit(int x = 0, int y = 0, int w = 0, int h = 0);
        Unit(Unit const &copy);
        ~Unit(void);
        Unit &operator=(Unit const &copy);

        Unit &move(enum direction direction);

        Unit &set_coord(int x, int y);
        Unit &set_size(int w, int h);
        Unit &set_dim(int x, int y, int w, int h);

        // double distance(Point const &rhs);  // in Point
        // TODO: this is a bit tricky with w/h

        // int x, y;  // in Point
        int w, h;
};


#endif //UNIT_CLASS_HPP
