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
** key event handlers
*/
static void do_nothing(const int, void *)
{
    // nothing
}

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
            flushinp();
            return;
        }

        this->key_handler_map[key % MAX_KEYS](
            key,
            this->key_data_map[key % MAX_KEYS]
        );
    }
}

void            Input::reset_key_map(void)
{
    for (int i = 0; i < MAX_KEYS; i++) {
        this->key_handler_map[i] = do_nothing;
        this->key_data_map[i] = NULL;
    }

    this->key_handler_map[KEY_ESC] = on_exit;
    this->key_data_map[KEY_ESC] = this;

    this->key_handler_map[KEY_EXIT] = on_exit;
    this->key_data_map[KEY_EXIT] = this;

    this->key_handler_map[KEY_F(1)] = on_exit;
    this->key_data_map[KEY_F(1)] = this;
}

void            Input::add_key_event(key_event_handler *handler,
                                     int key, void *ptr)
{
    this->key_handler_map[key % MAX_KEYS] = handler;
    this->key_data_map[key % MAX_KEYS] = ptr;
}
