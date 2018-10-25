
#include <stdlib.h>
#include <stdio.h>
#include <readwritepng.h>

void process_png_file(ImagePNG *Image) {
  for(int y = 0; y < Image->height; y++) {
    png_bytep row = Image->row_pointers[y];
    for(int x = 0; x < Image->width; x++) {
      png_bytep px = &(row[x * 4]);
      // Do something awesome for each pixel here...
      //printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);
      px[1] = 255;
    }
  }
}

int main(int argc, char *argv[]) {
  ImagePNG Image;

  if(argc != 3) {
    fprintf(stderr, "Usage : %s <inputfile> <outputfile>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  read_png_file(argv[1], &Image);
  process_png_file(&Image);
  write_png_file(argv[2], &Image);
  return 0;
}

