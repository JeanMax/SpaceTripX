// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Input.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2020/01/14 10:37:19 by mc                #+#    #+#             //
//   Updated: 2020/01/14 11:20:32 by mc               ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Input.class.hpp"


/*
** constructor
*/
Input::Input()
{
	DEBUG("Input constructed (default).");

    timeout(READ_KEY_TIMEOUT_MS);
	noecho();
	curs_set(false);
	setlocale(LC_ALL, "");  // handle special symbol as 卐
	keypad(stdscr, true);  // add special chars as F{1-12}
#ifndef NDEBUG
	raw();
#endif
}

Input::Input(Input const &copy)
{
	DEBUG("Input constructed (copy).");

	this->_last_key = copy.get_last_key();
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
Input       &Input::operator=(Input const &copy)
{
	DEBUG("Input operator= called.");

	this->_last_key = copy.get_last_key();

	return *this;
}


/*
** public
*/
char        Input::read_key(void)
{
	int key = getch();

	if (key == ERR) {
        this->_last_key = NOT_A_KEY;
        return this->_last_key;
    }

    flushinp();
    this->_last_key = static_cast<char>(key);

	// if (key == EXIT_KEY) {
	// 	endwin();
	// 	exit(EXIT_SUCCESS);
	// }

	return this->_last_key;
}


/*
** getter/setter
*/
char        Input::get_last_key(void) const { return this->_last_key; }
