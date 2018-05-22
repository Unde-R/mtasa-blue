/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        core/CDynamicLibrary.h
 *  PURPOSE:     Dynamic library handling class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#ifdef WIN32
#include <windows.h>
#endif

typedef void (*FuncPtr_t)();

class CDynamicLibrary
{
public:
    CDynamicLibrary(void);
    ~CDynamicLibrary(void);

    bool Load(const char* szFilename);
    void Unload(void);
    bool IsLoaded(void);

    FuncPtr_t GetProcedureAddress(const char* szProcName);
    bool      CheckMtaVersion(const char* szLibName);

private:
    #ifdef WIN32
    HMODULE m_hModule;
    #else
    void* m_hModule;
    #endif
};
