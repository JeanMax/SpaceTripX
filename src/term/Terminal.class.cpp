// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Terminal.class.cpp                                        (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Terminal.class.hpp"


/*
** constructor
*/
Terminal::Terminal()
{
	DEBUG("Terminal constructed (default).");

	setlocale(LC_ALL, "");
    initscr();
    this->in.init_curses();
    this->out.init_curses();
}


/*
** destructor
*/
Terminal::~Terminal(void)
{
	DEBUG("Terminal destructed.");

    endwin();
}


/*
** getter/setter
*/
Input           &Terminal::input()  { return this->in; }
Output          &Terminal::output() { return this->out; }
