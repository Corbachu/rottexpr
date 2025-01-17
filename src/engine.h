/*
Copyright (C) 1994-1995  Apogee Software, Ltd.
Copyright (C) 2002-2015  icculus.org, GNU/Linux port
Copyright (C) 2017-2018  Steven LeVesque

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef _engine_public
#define _engine_public

#include "i_video.h"
//***************************************************************************
//
// ENGINE.C
//
//***************************************************************************

typedef struct
{
    int      offset;
    int      wallheight;
    int      ceilingclip;
    int      floorclip;
    int      texture;
    int      lump;
    int      posttype;
    int      alttile;
} wallcast_t;
extern wallcast_t posts[MAXSCREENWIDTH+4];//bna++ JUST MAKE IT MAX RES
//extern wallcast_t posts[642];//bna++
//extern wallcast_t posts[321];

extern int lasttilex;
extern int lasttiley;

void Refresh ( void );

#define IsWindow(x,y)       (MAPSPOT((x),(y),2)==13)

#endif
