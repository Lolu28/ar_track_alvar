/*
 * This file is part of ALVAR, A Library for Virtual and Augmented Reality.
 *
 * Copyright 2007-2012 VTT Technical Research Centre of Finland
 *
 * Contact: VTT Augmented Reality Team <alvar.info@vtt.fi>
 *          <http://www.vtt.fi/multimedia/alvar.html>
 *
 * ALVAR is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with ALVAR; if not, see
 * <http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>.
 */

#include "Mutex_private.h"

#include <windows.h>

namespace alvar {

class MutexPrivateData
{
public:
    MutexPrivateData()
        : mCriticalSection()
    {
    }

    CRITICAL_SECTION mCriticalSection;
};

MutexPrivate::MutexPrivate()
    : d(new MutexPrivateData())
{
    InitializeCriticalSection(&d->mCriticalSection);
}

MutexPrivate::~MutexPrivate()
{
    DeleteCriticalSection(&d->mCriticalSection);
    delete d;
}

void MutexPrivate::lock()
{
    EnterCriticalSection(&d->mCriticalSection);
}

void MutexPrivate::unlock()
{
    LeaveCriticalSection(&d->mCriticalSection);
}

} // namespace alvar
