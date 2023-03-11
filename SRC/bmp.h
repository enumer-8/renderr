#ifndef BMP_H
#define BMP_H

// bitmap structs go here

#include <stdint.h>

typedef struct {

  uint16_t type;            // signature of file
  uint32_t size;            // size of file in bytes
  uint16_t reserved1;       // reserved
  uint16_t reserved2;       // reserved
  uint32_t pixeloffset;     // starting address of image data
  
} __attribute__((packed)) FILEHEADER;


typedef struct {

  uint32_t size;            // header size in bytes
  uint32_t width;           // width of file in bytes
  uint32_t height;          // height of file in bytes;
  uint16_t colorplanes;     // 1 color plane
  uint32_t pixeloffset;     // starting address of image data
  uint32_t comp_method      // compression method used
  uint32_t image_size       // raw bitmap size
  int32_t  h_ppm            // horizontal resolution, pixels/meter 
  int32_t  v_ppm            // vertical resolution, pixels/meter
  uint32_t palette          // number of colors used in the palette
  uint32_t important_colors // number of important colors used

} __attribute__((packed)) BITMAPINFOHEADER;

#endif
