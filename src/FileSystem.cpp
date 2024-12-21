#include "FileSystem.h"
#include "nds/fs.h"

namespace w2u {
    extern "C" {
        b32 ReadDataFromFile(const char* fileName, const u32 fileSize, u8 *buffer) {
            FSFile file;
            b32 successful_read;
            finit(&file);
            if (!romfs_fopen(&file, fileName)) {
                // Type chart not found.
                return false;
            }
            successful_read = romfs_fread(&file, buffer, fileSize) == fileSize;
            romfs_fclose(&file);
            return successful_read;
        }

        u8 ReadByteFromFile(const char* fileName, const u32 fileSize, const u32 idx)
        {
            if (idx >= fileSize) {
                // Index is out of bounds.
                return 0;
            }
            FSFile file;
            finit(&file);
            if (!romfs_fopen(&file, fileName)) {
                // Type chart not found.
                return 0;
            }
            u8 output = 0;
            if (romfs_fseek(&file, idx, IO_SEEK_CUR)) {
                if (romfs_fread(&file, &output, 1) != 1) {
                    // Error while reading.
                    output = 0;
                }
            }
            romfs_fclose(&file);
            return output;
        }
    }
}