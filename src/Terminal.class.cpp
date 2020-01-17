// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Terminal.class.cpp                                        (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '    |    //
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

	setlocale(LC_ALL, "");  // handle special symbol as 卐
    initscr(); //init ncurses
    cbreak();
	noecho();

    nonl();
    intrflush(stdscr, false);
    keypad(stdscr, true);  // add special chars as F{1-12}

    timeout(READ_KEY_TIMEOUT_MS);
	curs_set(false);

    this->_game_win = newwin(GAME_HEIGHT, GAME_WIDTH, 0, 0);
    this->_score_win = newwin(SCORE_HEIGHT, SCORE_WIDTH, GAME_HEIGHT, 0);
}


/*
** destructor
*/
Terminal::~Terminal(void)
{
	DEBUG("Terminal destructed.");

    delwin(this->_game_win);
    delwin(this->_score_win);
    endwin();
}


/*
** public
*/
char            Terminal::read_key(void)
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

void            Terminal::clear(void)
{
    wclear(this->_game_win);
    wclear(this->_score_win);
}

void            Terminal::refresh(void)
{
    box(this->_game_win, 0, 0);
    box(this->_score_win, 0, 0);
    wrefresh(this->_game_win);
    wrefresh(this->_score_win);
}

/*
** getter/setter
*/
char            Terminal::get_last_key(void) const { return this->_last_key; }
