// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Rectangle.class.cpp                                       (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Rectangle.class.hpp"


/*
** constructor
*/
Rectangle::Rectangle(
    const int new_x, const int new_y,
    const int new_w, const int new_h
):
    Point(new_x, new_y),
    w(new_w),
    h(new_h)
{
	DEBUG("Rectangle constructed (default).");
}

Rectangle::Rectangle(Rectangle const &copy)
{
	DEBUG("Rectangle constructed (copy).");

    this->x = copy.x;
    this->y = copy.y;
    this->w = copy.w;
    this->h = copy.h;
}


/*
** destructor
*/
Rectangle::~Rectangle(void)
{
	DEBUG("Rectangle destructed.");
}


/*
** operator overload
*/
Rectangle           &Rectangle::operator=(Rectangle const &copy)
{
	DEBUG("Rectangle operator= called.");

    this->x = copy.x;
    this->y = copy.y;
    this->w = copy.w;
    this->h = copy.h;

	return *this;
}


/*
** public
*/
bool            Rectangle::include(Point const &p) const
{
    return !(
        p.x < this->x || p.x >= this->x + this->w ||
        p.y < this->y || p.y >= this->y + this->h
     );
}

bool            Rectangle::outside(Rectangle const &r) const
{
    return (
        this->x < r.x || this->x + this->w > r.x + r.w ||
        this->y < r.y || this->y + this->h > r.y + r.h
    );
}

bool            Rectangle::touch(Rectangle const &r) const
{
    return (
        r.x + r.w >= this->x && r.x <= this->x + this->w &&
        r.y + r.h >= this->y && r.y <= this->y + this->h
    );
}


/*
** getter/setter
*/
Rectangle           &Rectangle::set_coord(const int new_x, const int new_y)
{
    this->x = new_x;
    this->y = new_y;

	return *this;
}

Rectangle           &Rectangle::set_size(const int new_w, const int new_h)
{
    this->w = new_w;
    this->h = new_h;

	return *this;
}
