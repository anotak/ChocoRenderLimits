#pragma once

// ano - let's just collect these in here bc its easier to deal with than trying to
// include every random .h
// https://doomwiki.org/wiki/Static_limits


#define MAXDRAWSEGS		256

// Screen width and height.

#define SCREENWIDTH  320
#define SCREENHEIGHT 200

#define MAXOPENINGS	SCREENWIDTH*64
#define MAXVISPLANES	128

#define MAXSPECIALCROSS             8

#define MAXVISSPRITES    128

#define MAXSEGS_OLD 32

#define SAVEGAMESIZE	0x2c000