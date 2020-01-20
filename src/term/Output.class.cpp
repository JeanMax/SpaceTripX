// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Output.class.cpp                                          (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Output.class.hpp"


/*
** constructor
*/
Output::Output()
{
	DEBUG("Output constructed (default).");

    this->_game_win = newwin(GAME_HEIGHT, GAME_WIDTH, 0, 0);
    this->_score_win = newwin(SCORE_HEIGHT, SCORE_WIDTH, GAME_HEIGHT, 0);
}


/*
** destructor
*/
Output::~Output(void)
{
	DEBUG("Output destructed.");

    delwin(this->_game_win);
    delwin(this->_score_win);
}


/*
** public
*/
void            Output::clear(void) const
{
    wclear(this->_game_win);
    wclear(this->_score_win);
}

void            Output::refresh(void) const
{
    box(this->_game_win, 0, 0);
    box(this->_score_win, 0, 0);
    wrefresh(this->_game_win);
    wrefresh(this->_score_win);
}

void            Output::print_unit(const Unit &u) const
{
    for (int i = 0; i < u.h; i++) {
        mvwprintw(
            this->_game_win,
            u.y + i,
            u.x,
            u.sprite[i].c_str()
       );
    }
}
