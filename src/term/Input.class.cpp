// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Input.class.cpp                                           (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Input.class.hpp"

/*
** key event handlers
*/
static void on_exit(const int, void *input_ptr)
{
    static_cast<Input *>(input_ptr)->exit = true;
}


/*
** constructor
*/
Input::Input()
{
	DEBUG("Input constructed (default).");

    cbreak();
	noecho();

    nonl();
    intrflush(stdscr, false);
    keypad(stdscr, true);

	curs_set(false);
    nodelay(stdscr, TRUE);
    ESCDELAY = 0;
    this->reset_key_map();
}


/*
** destructor
*/
Input::~Input(void)
{
	DEBUG("Input destructed.");
}


/*
** public
*/
void            Input::read_keys(void)
{
    while (true) {
        int key = getch();

        if (key == ERR) {
            DEBUG(""); // DEBUG
            flushinp();
            return;
        }

        key = key % MAX_KEYS;
        if (this->_key_handler_map[key]) {
            this->_key_handler_map[key](key, this->_key_data_map[key]);
            DEBUG("key: " << key); // DEBUG
        }
    }
}

void            Input::reset_key_map(void)
{
    for (int i = 0; i < MAX_KEYS; i++) {
        this->_key_handler_map[i] = NULL;
        this->_key_data_map[i] = NULL;
    }

    this->_key_handler_map[KEY_ESC] = on_exit;
    this->_key_data_map[KEY_ESC] = this;

    this->_key_handler_map[KEY_EXIT] = on_exit;
    this->_key_data_map[KEY_EXIT] = this;
}

void            Input::add_key_event(key_event_handler *handler,
                                     int key, void *ptr)
{
    this->_key_handler_map[key % MAX_KEYS] = handler;
    this->_key_data_map[key % MAX_KEYS] = ptr;
}
