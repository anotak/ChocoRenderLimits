//
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//    PC speaker interface.
//

#ifdef _WIN32

#include "SDL.h"
#include "SDL_thread.h"
#include <windows.h>

#include "pcsound.h"
#include "pcsound_internal.h"

static SDL_Thread *sound_thread_handle;
static int sound_thread_running;
static pcsound_callback_func callback;

static int SoundThread(void *unused)
{
    int frequency;
    int duration;
    
    while (sound_thread_running)
    {
        callback(&duration, &frequency);

        if (frequency != 0) 
        {
            Beep(frequency, duration);
        }
        else
        {
            Sleep(duration);
        }
    }
    
    return 0;    
}

static int PCSound_Win32_Init(pcsound_callback_func callback_func)
{
    BOOL result;

    // Temporarily disabled - the Windows scheduler is strange and 
    // stupid.
   
    return 0;


    // Beep() ignores its arguments on win9x, so this driver will
    // not work there.
    
    // ano - previously this included a check for that, but i can't get it
    // to compile anymore bc it's deprecated, so i guess i'm breaking pre-NT
    // support

    // Start a thread to play sound.

    callback = callback_func;
    sound_thread_running = 1;

    sound_thread_handle =
        SDL_CreateThread(SoundThread, "PC speaker thread", NULL);

    return 1;
}

static void PCSound_Win32_Shutdown(void)
{
    sound_thread_running = 0;
    SDL_WaitThread(sound_thread_handle, NULL);
}

pcsound_driver_t pcsound_win32_driver = 
{
    "Windows",
    PCSound_Win32_Init,
    PCSound_Win32_Shutdown,
};

#endif /* #ifdef _WIN32 */

