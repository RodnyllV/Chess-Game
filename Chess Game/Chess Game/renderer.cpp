void renderBackground() {
	unsigned int* pixel = (unsigned int*)currentRenderState.memory;

	for (int y = 0; y < currentRenderState.height; y++) {
		for (int x = 0; x < currentRenderState.width; x++) {
			*pixel++ = 0x000000;
		}
	}
}

void clearScreen(unsigned int color) {
	unsigned int* pixel = (unsigned int*)currentRenderState.memory;

	for (int y = 0; y < currentRenderState.height; y++) {
		for (int x = 0; x < currentRenderState.width; x++) {
			*pixel++ = color;
		}
	}
}

void drawRectByPixels(int x0, int y0, int x1, int y1, unsigned int color) {
	x0 = clamp(x0, 0, currentRenderState.width); x1 = clamp(x1, x0, currentRenderState.width);
	y0 = clamp(y0, 0, currentRenderState.height); y1 = clamp(y1, y0, currentRenderState.height);

	for (int y = y0; y < y1; y++) {
		unsigned int* pixel = (unsigned int*)currentRenderState.memory + x0 + y * currentRenderState.width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}
	}
}

void drawRectByScreenSize(double x0, double y0, double x1, double y1, unsigned int color) {
	int absoluteScreenSizeX = currentRenderState.width, absoluteScreenSizeY = currentRenderState.height;

	drawRectByPixels(x0 * absoluteScreenSizeX, y0 * absoluteScreenSizeY, x1 * absoluteScreenSizeX, y1 * absoluteScreenSizeY, color);
}
