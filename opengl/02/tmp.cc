eglCreatePbufferSurface(display, config, PBufAttribs);

GLint size;
size = esContext->width * esContext->height * 4;
GLubyte *data = (GLubyte *)malloc(size);
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
glReadPixels(0, 0, esContext->width, esContext->height, GL_RGB, GL_UNSIGNED_BYTE, data);