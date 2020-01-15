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
        Point(int x = 0, int y = 0);
        Point(Point const &copy);
        ~Point(void);
        Point &operator=(Point const &copy);

        bool  operator==(Point const &rhs);
        Point operator+(Point const &rhs);
        Point operator-(Point const &rhs);
        void  operator+=(Point const &rhs);
        void  operator-=(Point const &rhs);

        Point &set_coord(int x, int y);
        double distance(Point const &rhs);

        int x, y;
};


#endif //POINT_CLASS_HPP
