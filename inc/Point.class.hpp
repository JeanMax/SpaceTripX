// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Point.class.hpp                                           (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

# include <math.h>
# include "log.hpp"


class Point
{
    public:
        Point(double x = 0., double y = 0.);
        Point(Point const &copy);
        ~Point(void);
        Point &operator=(Point const &copy);

        Point &set_coord(double x, double y);
        double distance(Point const &rhs);

        double x;
        double y;
};


#endif //POINT_CLASS_HPP
