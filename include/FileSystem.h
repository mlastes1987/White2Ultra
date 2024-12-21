#ifndef __FILE_SYSTEM_H
#define __FILE_SYSTEM_H

#include "swan/swantypes.h"

namespace w2u {
    extern "C" {
        b32 ReadDataFromFile(const char* fileName, const u32 fileSize, u8 *buffer);

        u8 ReadByteFromFile(const char* fileName, const u32 fileSize, const u32 idx);
    }
}

#endif