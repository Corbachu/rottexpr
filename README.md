Welcome to EDGEROTT!
---------------------
* Fork of [rottexpr](https://github.com/LTCHIPS/rottexpr "rottexpr") to further integrate and enhance ROTT backend support into [EDGE](https://github.com/3dfxdev/EDGE "EDGE").

![](https://a.fsdn.com/con/app/proj/edge2/screenshots/edgelogo6.png)
## Port of rottexpr to EDGE

#### EDGE is an advanced OpenGL source port spawned from the DOOM engine, with focus on easy development and expansion for modders and end-users.

# (C) 1999-2022 The EDGE Team & [Contributors](https://github.com/3dfxdev/hyper3DGE/blob/master/AUTHORS.md)
# (C) 2022 LTCHIPS and the rottexpr Team
##### Uses GPL-licensed technology from id Tech 1-4 (C) 1997-2011 id Software, LLC
##### Uses GPL-licensed technology from Rise of the Triad (C) 1995-2002 Apogee Software
##### DOSDoom originally developed by Chi Hoang and the DOSDoom Team, (C) 1997-1999
#### All code licensed under the [GPLv2 (or greater)](http://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)
# See our EDGE Wiki (http://3dfxdev.net/edgewiki/index.php/Main_Page)

# Support
* Visit the [EDGE forums](http://tdgmods.net/smf) and get involved with the
community and the various projects for the engine.
* The [EDGEWiki](http://3dfxdev.net/edgewiki) is also a great resource for
editing documentation and other information related to the engine.

(C) 1999 - 2022 [Isotope SoftWorks](https://www.facebook.com/IsotopeSoftWorks/) and Contributors (The EDGE Team). All Rights Reserved.

---

# Currently In-Progress

* Remove Makefile support, use CMake instead
* Total refactor of code, to follow EDGE conventions (file renames to better organize code, merge/removal of unused files, swap places/names of many functions)
* Convert codebase to C++ (98/2011 at least), and completely get rid of the wonky "private" headers (prefixed with _)
* Remove/strip/convert many local functions to use EPI backend instead

# Goals
* RENDERER: Convert rendering/SDL2 code to OpenGL-only
* MODS: Update WAD code to EDGE, and using physfs, enable archive support for EPK/PK3 for mods and main EDGE.epk data (following EDGE EPK standards)

# rottexpr Readme
Based off of the icculus Rise of the Triad source port
(can be found here: https://icculus.org/rott/)

This source port of Rise of the Triad features the following:

Now runs off of SDL2!  
Support for resolutions from 320x200 all the way to 3840x2160  
Adaptive HUD positioning (no more status bar being off to the side)  
HUD scaling (HUD scaling for bottomless HUD coming later)  
Support for bordered and borderless windowed modes

New gameplay options:

* Blitzguards being outfitted with any weapon from the missile/magic weapon
  arsenal! Yes, that means Blitzguards can use excalibats too!
* You can now pick up ammo from dropped missile weapons!
* A special respawning enemy game mode called ZomROTT, where you have to gib
  your enemies to keep them from coming back!
* Toggleable Auto Aim
* Auto Aim for Missile Weapons
* ...and more

And all of the improvements made in the icculus source port...

To run the game you'll need the following things:

`SDL2.dll` (https://www.libsdl.org/download-2.0.php)

`SDL2_mixer.dll` (https://www.libsdl.org/projects/SDL_mixer/)

And the files:

```
DEMO1_3.DMO
DEMO2_3.DMO
DEMO3_3.DMO
DEMO4_3.DMO
REMOTE1.RTS
```

And

```
DARKWAR.RTC
DARKWAR.RTL
DARKWAR.WAD
```

Or

```
HUNTBGIN.RTC
HUNTBGIN.RTL
HUNTBGIN.WAD
```

Place all those files in the same directory as `rott.exe`.


BUILDING:

To build the project, you'll need the SDL2.0 development libraries
(https://www.libsdl.org/download-2.0.php) as well as the SDL_mixer developement
libaries (https://www.libsdl.org/projects/SDL_mixer/, under Binary).

For linux users, just install the following two packages using `apt-get`

```
libsdl2-dev
libsdl2-mixer-dev
```

Before running make on the project, double check the first few lines of the
`Makefile` and make sure you build the right version.

I used MinGW with gcc to build the project.

## Custom resolutions

If your preferred screen resolution doesn't show up in the screen resolution
menu, launch the game with argument "resolution *x*", and enter your screen
resolution dimensions in the fields marked by *.

## Issues with higher resolutions

`rottexpr` is capable of running at higher resolutions than the original release
of RotT, however this comes with a few issues.

1. Being able to see through walls when up against them/shrooms stretched screen
   effect. For this issue, visit "ADJUST FOCAL WIDTH" under "VISUAL OPTIONS",
   and raise the value until the issue disappears.
		
2. The game refuses to run at anything higher than 4k. 4k resolution is
   currently the limit set in code.
