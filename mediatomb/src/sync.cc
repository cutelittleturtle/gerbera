/*  Mysql_storage.cc - this file is part of MediaTomb.

    Copyright (C) 2005 Gena Batyan <bgeradz@deadlock.dhs.org>,
                       Sergey Bostandzhyan <jin@deadlock.dhs.org>

    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "sync.h"

using namespace zmm;

Mutex::Mutex(bool recursive) : Object()
{
    int res;
    pthread_mutex_init(&mutex_struct, NULL);    
    if (recursive)
    {
        pthread_mutexattr_t mutex_attr;
        res = pthread_mutexattr_init(&mutex_attr);
        res = pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE_NP);
        pthread_mutex_init(&mutex_struct, &mutex_attr);
        pthread_mutexattr_destroy(&mutex_attr);
    }
}
Mutex::~Mutex()
{
    pthread_mutex_destroy(&mutex_struct);
}
void Mutex::lock()
{
    pthread_mutex_lock(&mutex_struct);
}
void Mutex::unlock()
{
    pthread_mutex_unlock(&mutex_struct);
}
