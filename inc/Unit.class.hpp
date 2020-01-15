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


class Unit: public Point
{
    public:
        Unit(int x = 0, int y = 0, int w = 0, int h = 0);
        Unit(Unit const &copy);
        ~Unit(void);
        Unit &operator=(Unit const &copy);

        Unit &set_coord(int x, int y);
        Unit &set_size(int w, int h);
        Unit &set_dim(int x, int y, int w, int h);
        // double distance(Point const &rhs);  // in Point

        // int x, y;  // in Point
        int w, h;
};


#endif //UNIT_CLASS_HPP
