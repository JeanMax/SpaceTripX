// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Input.class.cpp                                           (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Input.class.hpp"


/*
** constructor
*/
Input::Input()
{
	DEBUG("Input constructed (default).");
}

Input::Input(Input const &copy)
{
	DEBUG("Input constructed (copy).");

	this->_last_key = copy._last_key;
}


/*
** destructor
*/
Input::~Input(void)
{
	DEBUG("Input destructed.");
}


/*
** operator overload
*/
Input          &Input::operator=(Input const &copy)
{
	DEBUG("Input operator= called.");

	this->_last_key = copy._last_key;

	return *this;
}


/*
** public
*/
char            Input::read_key(void)
{
	int key = getch();

	if (key == ERR) {
        this->_last_key = NOT_A_KEY;
        return this->_last_key;
    }

    flushinp();
    this->_last_key = static_cast<char>(key);

	return this->_last_key;
}


/*
** getter/setter
*/
char            Input::get_last_key(void) const { return this->_last_key; }
