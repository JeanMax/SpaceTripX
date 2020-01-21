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

    this->in = new Input();
    this->out = new Output();
}


/*
** destructor
*/
Terminal::~Terminal(void)
{
	DEBUG("Terminal destructed.");

    delete this->in;
    delete this->out;

    endwin();
}
