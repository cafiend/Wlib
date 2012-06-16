/*

The MIT License (MIT)
Copyright (c) 2011 Derek Ingrouville, Julien Lord, Muthucumaru Maheswaran

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
*/

#ifndef _COMMAND_H
#define _COMMAND_H

#include "socket.h"

typedef struct _Command
{
    char *name;       /* Name of the command */
    char *params[12]; /* Parameters */
    char *command;    /* The full command */
    unsigned int param_count; /* Number of parameters */
    unsigned int max_params;
    char *pdata; /* Payload data */
} Command;

Command *command_format(const char *format, ...);
Command *command_format_json(const char *name,const char *format, ...);
void command_free(Command *cmd);

int command_send(Command *cmd, Socket *socket);

Command *command_read(Socket *socket);
char *command_read_payload(Socket *socket, Command *cmd);

#endif /* _COMMAND_H */

