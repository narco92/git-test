#ifndef __READWRITEPNG_H__
#define __READWRITEPNG_H__

#include <png.h>

#ifdef __cplusplus 
extern "C" {
#endif
  
  typedef struct ImagePNG ImagePNG;
  
  struct ImagePNG{
    int width, height;
    png_byte color_type;
    png_byte bit_depth;
    png_bytep *row_pointers;
  };

  extern void read_png_file   (const char *, ImagePNG *);
  extern void write_png_file  (const char *, ImagePNG *);

#ifdef __cplusplus
} // extern C
#endif

#endif
