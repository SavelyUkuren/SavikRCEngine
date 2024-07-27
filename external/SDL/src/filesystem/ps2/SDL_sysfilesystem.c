/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2024 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "SDL_internal.h"

#include <sys/stat.h>
#include <unistd.h>

#ifdef SDL_FILESYSTEM_PS2

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* System dependent filesystem routines                                */

char *SDL_GetBasePath(void)
{
    char *retval = NULL;
    size_t len;
    char cwd[FILENAME_MAX];

    getcwd(cwd, sizeof(cwd));
    len = SDL_strlen(cwd) + 2;
    retval = (char *)SDL_malloc(len);
    SDL_snprintf(retval, len, "%s/", cwd);

    return retval;
}

/* Do a recursive mkdir of parents folders */
static void recursive_mkdir(const char *dir)
{
    char tmp[FILENAME_MAX];
    char *base = SDL_GetBasePath();
    char *p = NULL;
    size_t len;

    SDL_snprintf(tmp, sizeof(tmp), "%s", dir);
    len = SDL_strlen(tmp);
    if (tmp[len - 1] == '/') {
        tmp[len - 1] = 0;
    }

    for (p = tmp + 1; *p; p++) {
        if (*p == '/') {
            *p = 0;
            // Just creating subfolders from current path
            if (SDL_strstr(tmp, base) != NULL) {
                mkdir(tmp, S_IRWXU);
            }

            *p = '/';
        }
    }

    SDL_free(base);
    mkdir(tmp, S_IRWXU);
}

char *SDL_GetPrefPath(const char *org, const char *app)
{
    char *retval = NULL;
    size_t len;
    char *base = SDL_GetBasePath();
    if (!app) {
        SDL_InvalidParamError("app");
        return NULL;
    }
    if (!org) {
        org = "";
    }

    len = SDL_strlen(base) + SDL_strlen(org) + SDL_strlen(app) + 4;
    retval = (char *)SDL_malloc(len);

    if (*org) {
        SDL_snprintf(retval, len, "%s%s/%s/", base, org, app);
    } else {
        SDL_snprintf(retval, len, "%s%s/", base, app);
    }
    SDL_free(base);

    recursive_mkdir(retval);

    return retval;
}

/* TODO */
char *SDL_GetUserFolder(SDL_Folder folder)
{
    SDL_Unsupported();
    return NULL;
}

#endif /* SDL_FILESYSTEM_PS2 */
