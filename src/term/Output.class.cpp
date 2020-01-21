// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Output.class.cpp                                          (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
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

    this->_game_win = newwin(GAME_HEIGHT, GAME_WIDTH, SCORE_HEIGHT, 0);
    this->_score_win = newwin(SCORE_HEIGHT, SCORE_WIDTH, 0, 0);
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
            u.sprite[static_cast<size_t>(i)].c_str()
       );
    }

    // DEBUG
    int h, w;
    getmaxyx(stdscr, h, w);
    mvwprintw(this->_score_win, 1, 2, "stdscr: %dx%d", w, h);
    getmaxyx(this->_game_win, h, w);
    mvwprintw(this->_score_win, 2, 2, "this->_game_win: %dx%d", w, h);
    getmaxyx(this->_score_win, h, w);
    mvwprintw(this->_score_win, 3, 2, "this->_score_win: %dx%d", w, h);
    // DEBUG
}

bool            Output::is_too_small(void)
{
    if (COLS < GAME_WIDTH || LINES < GAME_HEIGHT) {
        ::clear();
        mvprintw(0, 0, "You need a bigger terminal :/");
        ::refresh();
        this->_is_too_small = true;
        return true;
    }

    if (this->_is_too_small) {
        wresize(this->_game_win, GAME_HEIGHT, GAME_WIDTH);
        wresize(this->_score_win, SCORE_HEIGHT, SCORE_WIDTH);
        this->_is_too_small = false;
    }

    return false;
}
