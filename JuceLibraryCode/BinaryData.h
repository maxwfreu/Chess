/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   bishop_png;
    const int            bishop_pngSize = 1389;

    extern const char*   king_png;
    const int            king_pngSize = 1189;

    extern const char*   knight_png;
    const int            knight_pngSize = 1331;

    extern const char*   pawn_png;
    const int            pawn_pngSize = 881;

    extern const char*   queen_png;
    const int            queen_pngSize = 1518;

    extern const char*   rook_png;
    const int            rook_pngSize = 508;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 6;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) noexcept;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8) noexcept;
}
