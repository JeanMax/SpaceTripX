// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Point.class.hpp                                           (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
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
        Point(const int x = 1, const int y = 1);
        Point(Point const &copy);
        ~Point(void);
        Point &operator=(Point const &copy);

        bool  operator==(Point const &rhs) const;
        Point operator+(Point const &rhs) const;
        Point operator-(Point const &rhs) const;
        void  operator+=(Point const &rhs);
        void  operator-=(Point const &rhs);

        Point &set_coord(const int x, const int y);
        double distance(Point const &rhs) const;

        int x, y;
};


#endif //POINT_CLASS_HPP
