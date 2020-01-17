// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Rectangle.class.hpp                                       (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#ifndef RECTANGLE_CLASS_HPP
# define RECTANGLE_CLASS_HPP

# include "log.hpp"
# include "Point.class.hpp"


class Rectangle: public Point
{
    public:
        Rectangle(
            const int x = 0, const int y = 0,
            const int w = 1, const int h = 1
        );
        Rectangle(Rectangle const &copy);
        ~Rectangle(void);
        Rectangle &operator=(Rectangle const &copy);

        bool include(Point const &r) const;
        bool touch(Rectangle const &u) const;

        Rectangle &set_coord(const int x, const int y);
        Rectangle &set_size(const int w, const int h);

        // double distance(Point const &rhs);  // in Point
        // TODO: this is a bit tricky with w/h

        // int x, y;  // in Point
        int w, h;
};


#endif //RECTANGLE_CLASS_HPP
