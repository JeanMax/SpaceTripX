// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Point.class.cpp                                           (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Point.class.hpp"


/*
** constructor
*/
Point::Point(double new_x, double new_y)
{
	DEBUG("Point constructed (default).");

    this->x = new_x;
    this->y = new_y;
}

Point::Point(Point const &copy)
{
	DEBUG("Point constructed (copy).");

    this->x = copy.x;
    this->y = copy.y;
}


/*
** destructor
*/
Point::~Point(void)
{
	DEBUG("Point destructed.");
}


/*
** operator overload
*/
Point           &Point::operator=(Point const &copy)
{
	DEBUG("Point operator= called.");

    this->x = copy.x;
    this->y = copy.y;

	return *this;
}


/*
** public
*/
double          Point::distance(Point const &rhs)
{
    return sqrt(pow(rhs.x - this->x, 2) - pow(rhs.y - this->y, 2));
}


/*
** getter/setter
*/
Point           &Point::set_coord(double new_x, double new_y)
{
    this->x = new_x;
    this->y = new_y;

	return *this;
}
