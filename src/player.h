#ifndef _H_PLAYER
#define _H_PLAYER

#include <stdint.h>

// Represents the state of a Player character
typedef struct Player {
    int32_t size; // width and height
    int32_t ha;   // health and armor
    double speed;
} Player;

#define SIZE(w, h) ((w << 16) | h)
#define HA(h, a) ((h << 16) | a)

Player p = {
    .size = SIZE(20, 40),
    .ha = HA(100, 10),
    .speed = 1.0
};

#define Player_Health p.ha >> 16
#define Player_Armor p.ha & 0xFFFF
#define Player_Speed p.speed

#endif