#include "nanosvg.h"
#include "nanosvgrast.h"

#define NANOSVG_IMPLEMENTATION

#include "nanosvg.h"
#include "nanosvgrast.h"

typedef struct img
{
    uint32_t w;
    uint32_t h;
    void *data;
} img_t;

img_t *render(const char *filename)
{
	NSVGimage *image = NULL;
	NSVGrasterizer *rast = NULL;
	img_t* img = NULL;
	int w, h;

	printf("parsing %s\n", filename);
	image = nsvgParseFromFile(filename, "px", 96.0f);
	if (image == NULL) {
		printf("Could not open SVG image.\n");
		goto error;
	}
	w = (int)image->width;
	h = (int)image->height;

	rast = nsvgCreateRasterizer();
	if (rast == NULL) {
		printf("Could not init rasterizer.\n");
		goto error;
	}

	img = malloc(w*h*4 + 8);
	if (img == NULL) {
		printf("Could not alloc image buffer.\n");
		goto error;
	}

	printf("rasterizing image %d x %d\n", w, h);
	nsvgRasterize(rast, image, 0,0,1, img->data, w, h, w*4);

	printf("writing svg.png\n");

    return img;
}
