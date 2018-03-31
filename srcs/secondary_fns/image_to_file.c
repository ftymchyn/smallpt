
#include "smallpt.h"

void image_to_file(t_smallpt *pt, char *file)
{
	FILE 	*f = fopen(file, "w");
	t_color c;

  	fprintf(f, "P3\n%d %d\n%d\n", pt->sdl.width, pt->sdl.height, 255);
  	for (int i = 0; i < pt->sdl.width * pt->sdl.height; i++)
  	{
		c.val = pt->sdl.pixels[i];
    	fprintf(f,"%d %d %d ", c.byte[2], c.byte[1], c.byte[0]);
	}
}
