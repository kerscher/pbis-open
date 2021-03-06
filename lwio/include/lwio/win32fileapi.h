/* Editor Settings: expandtabs and use 4 spaces for indentation
 * ex: set softtabstop=4 tabstop=8 expandtab shiftwidth=4: *
 * -*- mode: c, c-basic-offset: 4 -*- */

/*
 * Copyright Likewise Software
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the license, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser
 * General Public License for more details.  You should have received a copy
 * of the GNU Lesser General Public License along with this program.  If
 * not, see <http://www.gnu.org/licenses/>.
 *
 * LIKEWISE SOFTWARE MAKES THIS SOFTWARE AVAILABLE UNDER OTHER LICENSING
 * TERMS AS WELL.  IF YOU HAVE ENTERED INTO A SEPARATE LICENSE AGREEMENT
 * WITH LIKEWISE SOFTWARE, THEN YOU MAY ELECT TO USE THE SOFTWARE UNDER THE
 * TERMS OF THAT SOFTWARE LICENSE AGREEMENT INSTEAD OF THE TERMS OF THE GNU
 * LESSER GENERAL PUBLIC LICENSE, NOTWITHSTANDING THE ABOVE NOTICE.  IF YOU
 * HAVE QUESTIONS, OR WISH TO REQUEST A COPY OF THE ALTERNATE LICENSING
 * TERMS OFFERED BY LIKEWISE SOFTWARE, PLEASE CONTACT LIKEWISE SOFTWARE AT
 * license@likewisesoftware.com
 */



/*
 * Copyright (C) Likewise Software. All rights reserved.
 *
 * Module Name:
 *
 *        win32fileapi.h
 *
 * Abstract:
 *
 *        Likewise SMB Subsystem (LWIO)
 *
 *        Public API
 *
 * Author: Kaya Bekiroglu (kaya@likewisesoftware.com)
 */
#ifndef __WIN32_FILE_API_H__
#define __WIN32_FILE_API_H__

#include <lwio/io-types.h>

typedef struct _OVERLAPPED {
    // TODO-Use ULONG_PTR
    unsigned long Internal;
    unsigned long InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        };
        PVOID Pointer;
    };
    HANDLE hEvent;
} OVERLAPPED, *POVERLAPPED;

// TODO-Change definition
typedef struct _SECURITY_ATTRIBUTES
{
    DWORD dwUid;
    DWORD dwGid;
    DWORD mode;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES;

#ifndef LW_NO_THREADS

DWORD
GetLastError(
    VOID
    );

VOID
SetLastError(
    DWORD dwError
    );

BOOL
CallNamedPipeA(
    IN PCSTR pszNamedPipeName,
    IN PVOID pInBuffer,
    IN DWORD dwInBufferSize,
    OUT PVOID pOutBuffer,
    IN DWORD dwOutBufferSize,
    OUT PDWORD pdwBytesRead,
    IN DWORD dwTimeout
    );

BOOL
CallNamedPipeW(
    IN PCWSTR pwszNamedPipeName,
    IN PVOID pInBuffer,
    IN DWORD dwInBufferSize,
    OUT PVOID pOutBuffer,
    IN DWORD dwOutBufferSize,
    OUT PDWORD pdwBytesRead,
    IN DWORD dwTimeout
    );

HANDLE
CreateNamedPipeA(
    IN PCSTR pszName,
    IN DWORD dwOpenMode,
    IN DWORD dwPipeMode,
    IN DWORD dwMaxInstances,
    IN DWORD dwOutBufferSize,
    IN DWORD dwInBufferSize,
    IN DWORD dwDefaultTimeOut,
    IN OPTIONAL PSECURITY_ATTRIBUTES pSecurityAttributes
    );

HANDLE
CreateNamedPipeW(
    IN PCWSTR pwszName,
    IN DWORD dwOpenMode,
    IN DWORD dwPipeMode,
    IN DWORD dwMaxInstances,
    IN DWORD dwOutBufferSize,
    IN DWORD dwInBufferSize,
    IN DWORD dwDefaultTimeOut,
    IN OPTIONAL PSECURITY_ATTRIBUTES pSecurityAttributes
    );

BOOL
GetNamedPipeInfo(
    IN HANDLE hNamedPipe,
    OUT OPTIONAL PDWORD pdwFlags,
    OUT OPTIONAL PDWORD pdwOutBufferSize,
    OUT OPTIONAL PDWORD pdwInBufferSize,
    OUT OPTIONAL PDWORD pdwMaxInstances
    );

BOOL
ConnectNamedPipe(
    IN HANDLE hNamedPipe,
    IN OUT OPTIONAL POVERLAPPED pOverlapped
    );

BOOL
TransactNamedPipe(
    IN HANDLE hNamedPipe,
    IN PVOID pInBuffer,
    IN DWORD dwInBufferSize,
    OUT PVOID pOutBuffer,
    IN DWORD dwOutBufferSize,
    OUT PDWORD pdwBytesRead,
    IN OUT OPTIONAL POVERLAPPED pOverlapped
    );

BOOL
WaitNamedPipeA(
    IN PCSTR pszNamedPipeName,
    IN DWORD dwTimeOut
    );

BOOL
WaitNamedPipeW(
    IN PCWSTR pwszNamedPipeName,
    IN DWORD dwTimeOut
    );

BOOL
GetNamedPipeClientComputerNameA(
    IN HANDLE hNamedPipe,
    OUT PSTR pszClientComputerName,
    IN DWORD dwClientComputerNameLength
    );

BOOL
GetNamedPipeClientComputerNameW(
    IN HANDLE hNamedPipe,
    OUT PWSTR pwszClientComputerName,
    IN DWORD dwClientComputerNameLength
    );

BOOL
GetNamedPipeClientProcessId(
    IN HANDLE hNamedPipe,
    OUT PDWORD pdwClientProcessId
    );

BOOL
GetNamedPipeServerProcessId(
    IN HANDLE hNamedPipe,
    OUT PDWORD pdwServerProcessId
    );

BOOL
GetNamedPipeClientSessionId(
    IN HANDLE hNamedPipe,
    OUT PDWORD pdwClientSessionId
    );

BOOL
PeekNamedPipe(
    IN HANDLE hNamedPipe,
    OUT OPTIONAL PVOID pBuffer,
    IN DWORD dwBufferSize,
    OUT OPTIONAL PDWORD pdwBytesRead,
    OUT OPTIONAL PDWORD pdwTotalBytesAvail,
    OUT OPTIONAL PDWORD pdwBytesLeftThisMessage
    );

BOOL
DisconnectNamedPipe(
    IN HANDLE hNamedPipe
    );

HANDLE
CreateFileA(
    IN PCSTR pszFileName,
    IN DWORD dwDesiredAccess,
    IN DWORD dwSharedMode,
    IN PSECURITY_ATTRIBUTES pSecurityAttributes,
    IN DWORD dwCreationDisposition,
    IN DWORD dwFlagsAndAttributes,
    IN HANDLE hTemplateFile
    );

HANDLE
CreateFileW(
    IN PCWSTR pwszFileName,
    IN DWORD dwDesiredAccess,
    IN DWORD dwSharedMode,
    IN PSECURITY_ATTRIBUTES pSecurityAttributes,
    IN DWORD dwCreationDisposition,
    IN DWORD dwFlagsAndAttributes,
    IN HANDLE hTemplateFile
    );

BOOL
SetNamedPipeHandleState(
    IN HANDLE hPipe,
    IN OPTIONAL PDWORD pdwMode,
    IN OPTIONAL PDWORD pdwMaxCollectionCount,
    IN OPTIONAL PDWORD pdwMaxTimeout
    );

BOOL
ReadFile(
    IN HANDLE hFile,
    OUT PVOID pBuffer,
    IN DWORD dwNumberOfBytesToRead,
    OUT PDWORD pdwBytesRead,
    IN OUT OPTIONAL POVERLAPPED pOverlapped
    );

BOOL
WriteFile(
    IN HANDLE hFile,
    IN PVOID pBuffer,
    IN DWORD dwNumBytesToWrite,
    OUT PDWORD pdwNumBytesWritten,
    IN OUT OPTIONAL POVERLAPPED pOverlapped
    );

BOOL
CloseHandle(
    IN OUT HANDLE hFile
    );

#ifdef UNICODE
#define CallNamedPipe                    CallNamedPipeW
#define CreateNamedPipe                  CreateNamedPipeW
#define WaitNamedPipe                    WaitNamedPipeW
#define GetNamedPipeClientComputerName   GetNamedPipeClientComputerNameW
#define CreateFile                       CreateFileW
#else
#define CallNamedPipe                    CallNamedPipeA
#define CreateNamedPipe                  CreateNamedPipeA
#define WaitNamedPipe                    WaitNamedPipeA
#define GetNamedPipeClientComputerName   GetNamedPipeClientComputerNameA
#define CreateFile                       CreateFileA
#endif

#endif /* ! LW_NO_THREADS */

#endif /* __WIN32_FILE_API_H__ */
