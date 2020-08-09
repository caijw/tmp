eglCreatePbufferSurface(display, config, PBufAttribs);

GLint size;
size = esContext->width * esContext->height * 4;
GLubyte *data = (GLubyte *)malloc(size);
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
glReadPixels(0, 0, esContext->width, esContext->height, GL_RGB, GL_UNSIGNED_BYTE, data);

//save image
GLubyte *pPixelData;
pPixelData = (GLubyte *)malloc(picWidth * picHeight * 4); //分配内存
if (pPixelData == 0)
    return 0;
glReadBuffer(GL_FRONT);                                                         //保存窗口渲染的结果
glPixelStorei(GL_UNPACK_ALIGNMENT, 4);                                          //解压窗口数据结构
glReadPixels(0, 0, picWidth, picHeight, GL_RGBA, GL_UNSIGNED_BYTE, pPixelData); //存储像素数据

cv::Mat img;
std::vector<cv::Mat> imgPlanes;
img.create(picHeight, picWidth, CV_8UC3); //确定图片通道和尺寸
cv::split(img, imgPlanes);                //将图像按照通道数拆分，三个单通道序列

for (int i = 0; i < picHeight; i++)
{
    unsigned char *plane0Ptr = imgPlanes[0].ptr<unsigned char>(i); //B
    unsigned char *plane1Ptr = imgPlanes[1].ptr<unsigned char>(i); //G
    unsigned char *plane2Ptr = imgPlanes[2].ptr<unsigned char>(i); //R
    //opencv里面以BGR存储的，而Mac上opengl是RGBA，所以需要改变顺序保存
    for (int j = 0; j < picWidth; j++)
    {
        int k = 4 * (i * picWidth + j);   //RGBA数据结构，不需要A，跳过，所以步长乘以4
        plane2Ptr[j] = pPixelData[k];     //R
        plane1Ptr[j] = pPixelData[k + 1]; //G
        plane0Ptr[j] = pPixelData[k + 2]; //B
    }
}
cv::merge(imgPlanes, img);                  //合并多通道图像
cv::flip(img, img, 0);                      // 反转图像，因为opengl和opencv的坐标系y轴是相反的
cv::cvtColor(img, img, cv::COLOR_RGB2GRAY); //转换为灰度图
cv::namedWindow("openglGrab");
cv::imshow("openglGrab", img);
cv::waitKey();

cv::imwrite("/Users/xxx/Documents/result/10.17/结果/" + num + ".jpg", img); //保存图片