#ifndef _H_PLAYER
#define _H_PLAYER

#include <stdint.h>

// Represents the state of a character
typedef struct Character {
    // Character size and model bitfield
    // 1st octet is unreserved
    // 2nd octet is reserved for character id
    // 3rd octet is reserved for character height
    // 4th octet is reserved for chatacter width
    int64_t size;
    // Character health (current and max), armor
    // 1st octet is unreserved
    // 2nd octet is reserved for character armor
    // 3rd octet is reserved for character maximum health
    // 4th octet is reserved for charecter current health
    int64_t ha;   // health and armor
    // Character damage stats
    // first three octets are unreserved
    // 4th octet is reserved for character damage
    int64_t dmg;
    // Character movement speed
    double speed;
} Character;

// --- Character model

#define CH_WIDTH(c)    (c->ha & 0xFFFF)         // Get character cur health
#define CH_HEIGHT(c)   ((c->ha >> 8) & 0xFFFF)  // Get character max health
#define CH_MODEL_ID(c) ((c->ha >> 16) & 0xFFFF) // Get character armor

// !-- Character model

#define CH_ATTACK(c) (c->dmg & 0xFFFF)          // Get character attack 

// --- Health and Armor getting

#define CH_CURHP(c) (c->ha & 0xFFFF)            // Get character cur health
#define CH_MAXHP(c) ((c->ha >> 8) & 0xFFFF)     // Get character max health
#define CH_ARMOR(c) ((c->ha >> 16) & 0xFFFF)    // Get character armor
#define CH_SPEED(c) (c->speed)                  // Get character speed

// !-- Health and Armot getting

// --- Character fields setting

#define CH_SIZE(id, width, height) ((id << 16) | (height << 8) | width)
#define CH_HA(h, a) ((h << 16) | a)

// !-- Character fields setting

#endif