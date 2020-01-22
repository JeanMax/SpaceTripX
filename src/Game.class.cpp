// ************************************************************************** //
//                                                              _.._..,_,_    //
//   Game.class.cpp                                            (          )   //
//                                                              ]~,'-.-~~[    //
//   By: mc <mc.maxcanal@gmail.com>                           .=])' (;  ([    //
//                                                            | ]:)   '  [    //
//     "THE BEER-WARE LICENSE" (Revision 42):                 | ]  :: '  [    //
//   As long as you retain this notice you can do whatever    '=]): .)  ([    //
//   you want with this stuff. If we meet some day, and you     |:: '   :|    //
//   think this is worth it, you can buy me a beer in return.    ~~----~~     //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"


/*
** constructor
*/
Game::Game(const int n_players) : _n_players(n_players)
{
    int i, offset;

	DEBUG("Game constructed (default).");

    // init player count
    for (i = n_players; i < MAX_PLAYERS; i++) {
        this->players[i].kill();
    }

    // init players positions
    offset = GAME_WIDTH / (n_players + 1) - 2;
    for (i = 0; i < n_players; i++) {
        this->players[i].set_coord(
            offset * (i + 1) + (i + 1),
            GAME_HEIGHT - 3
        );

        this->players[i].sprite[1][1] = '1' + i;
    }

    // init particles positions
    for (i = 0; i < MAX_PARTICLES; i++) {
        this->particles[i].set_coord(
            this->_random.generate(),
            this->_random.generate()
        );
    }

    // init monsters positions
    for (i = 0; i < MAX_MONSTERS; i++) {
        this->monsters[i].kill();
    }
}


/*
** destructor
*/
Game::~Game(void)
{
	DEBUG("Game destructed.");
}


/*
** public
*/
void            Game::play_turn(void)
{
    Point prev_pos;
    int i;

    // move players
    for (i = 0; i < this->_n_players; i++) {
        if (!this->players[i].is_alive()) {
            continue;
        }

        prev_pos = this->players[i];
        this->players[i].play_turn();
        if (this->players[i].outside(this->_map)) {
            this->players[i].set_coord(prev_pos.x, prev_pos.y);
        }
    }


    // move particles
    for (i = 0; i < MAX_PARTICLES; i++) {
        this->particles[i].play_turn();
        if (this->particles[i].outside(this->_map)) {
            this->particles[i].set_coord(this->_random.generate(), 1);
        }
    }


    // move monsters
    for (i = 0; i < MAX_MONSTERS; i++) {
        if (!this->monsters[i].is_alive()) {
            continue;
        }

        if (!(this->_turns % 4)) { // don't move monsters too fast
            this->monsters[i].play_turn();

            // you should not let monsters escape!
            if (this->monsters[i].outside(this->_map)) {
                DEBUG("monster escaped!");
                this->monsters[i].kill();
                for (int j = 0; j < this->_n_players; j++) {
                    if (this->players[j].is_alive()) {
                        this->players[j].score += 1;
                    }
                }
            }
        }

        // handle collisions monster/player
        for (int j = 0; j < this->_n_players; j++) {
            if (this->players[j].is_alive()
                    && this->players[j].touch(this->monsters[i])) {
                DEBUG("player #" << j + 1 << " collided a monster!");
                this->monsters[i].life -= 1;
                this->players[j].life -= 1;
                // this->players[j].score += 1;
                this->players[j].direction = NO_DIRECTION;
            }
        }

    }


    // add monsters (waves)
    this->_turns += 1;
    if (this->_turns % MONSTER_WAVE_INTERVAL) {
        return;
    }

    // int n_monsters = ((this->_turns - 1) / MONSTER_WAVE_INTERVAL) % 5 + 1;
    int n_monsters = (this->_random.generate() % 5) + 1;

    DEBUG("New monster wave (" << n_monsters << ")");

    for (int n_monsters_left = n_monsters; n_monsters_left > 0; n_monsters_left--) {
        for (i = 0; i < MAX_MONSTERS; i++) {
            if (!this->monsters[i].is_alive()) {
                this->monsters[i].life = 1;

                this->monsters[i].set_coord(
                    n_monsters == 1 ?
                        this->_random.generate() % (GAME_WIDTH - this->monsters[i].w - 2):
                        GAME_WIDTH / n_monsters * n_monsters_left - this->monsters[i].w - 2,
                    1
                );
                DEBUG(
                    "monster at ("
                    << this->monsters[i].x << ", "
                    << this->monsters[i].y << ")"
                );
                break;
            }
        }
    }
}

bool            Game::over(void) const
{
    for (int i = 0; i < this->_n_players; i++) {
        if (this->players[i].is_alive()) {
            return false;
        }
    }

    return true;
}
