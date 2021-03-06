///////////////////////////////////////////////////////////////////////////////
//
// 版权所有 (c) 2011 - 2012
//
// 原始文件名称     : MiniFilterFunction.h
// 工程名称         : AntinvaderDriver
// 创建时间         : 2011-04-2
//
//
// 描述             : 关于微过滤驱动的通用函数头文件
//
// 更新维护:
//  0000 [2011-04-2]  最初版本.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ntdef.h>
#include <ntifs.h>
#include <fltKernel.h>

#include "CallbackRoutine.h"

////////////////////////
//      宏定义
////////////////////////

// 申请新的缓冲区内存标志
#define MEM_TAG_READ_BUFFER                     'read'
#define MEM_TAG_WRITE_BUFFER                    'writ'
#define MEM_TAG_DIRECTORY_CONTROL_BUFFER        'dirc'

// 申请新缓冲的缓冲用途
typedef enum _ALLOCATE_BUFFER_TYPE
{
    Allocate_BufferRead = 1,        // 读缓冲
    Allocate_BufferWrite,           // 写缓冲
    Allocate_BufferDirectoryControl
} ALLOCATE_BUFFER_TYPE;

BOOLEAN AllocateAndSwapToNewMdlBuffer(
    __in PFLT_IO_PARAMETER_BLOCK pIoParameterBlock,
    __in PVOLUME_CONTEXT pvcVolumeContext,
    __inout PULONG pulNewBuffer,
    __inout_opt PMDL *dpMemoryDescribeList,
    __inout_opt PULONG pulOriginalBuffer,
    __inout_opt PULONG pulDataLength,
    __in ALLOCATE_BUFFER_TYPE ulFlag
);

VOID FreeAllocatedMdlBuffer(
    __in ULONG ulBuffer,
    __in ALLOCATE_BUFFER_TYPE ulFlag
);
