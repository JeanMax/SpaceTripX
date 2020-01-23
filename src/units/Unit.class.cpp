// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Unit.class.cpp                                            (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Unit.class.hpp"

const Point Unit::base_vectors[MAX_DIRECTIONS] = {
    Point(-1, -1), Point(0, -1), Point(1, -1),
    Point(-1, 0),  Point(0, 0),  Point(1, 0),
    Point(-1, 1),  Point(0, 1),  Point(1, 1),
};


/*
** constructor
*/
Unit::Unit(
    const int new_x, const int new_y,
    std::vector<std::string> new_sprite
):
    Rectangle(
        new_x,
        new_y,
        static_cast<int>(new_sprite[0].size()),
        static_cast<int>(new_sprite.size())
    ),
    sprite(new_sprite)
{
	DEBUG("Unit constructed (default).");
}

Unit::Unit(Unit const &copy):
    Rectangle(copy.x, copy.y, copy.w, copy.h),
    sprite(copy.sprite)
{
	DEBUG("Unit constructed (copy).");
}


/*
** destructor
*/
Unit::~Unit(void)
{
	DEBUG("Unit destructed.");
}


/*
** operator overload
*/
Unit           &Unit::operator=(Unit const &copy)
{
	DEBUG("Unit operator= called.");

    this->x = copy.x;
    this->y = copy.y;
    this->w = copy.w;
    this->h = copy.h;

	return *this;
}


/*
** public
*/
Unit            &Unit::move(enum direction new_direction)
{
    *this += Unit::base_vectors[new_direction];

    return *this;
}

Unit            &Unit::kill(void)
{
    this->life = 0;

    return *this;
}

bool            Unit::is_alive(void) const
{
    return this->life > 0;
}
