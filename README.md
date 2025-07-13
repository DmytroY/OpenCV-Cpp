# Using OpenCV with C++

## Prerequisites
1) OpenCV library should be installed.
2) Add to Path environment variable path to ....\OpenCV-MinGW-Build\include and ....\OpenCV-MinGW-Build\x64\mingw\bin
3) Compilation should be done with explicit including OpenCV libraries. it is example of command:
```
g++ -o 2_filtering.exe 2_filtering.cpp -IC:\DY\Programs\OpenCV-MinGW-Build\include -IC:\DY\Programs\OpenCV-MinGW-Build\include\opencv4 -LC:\DY\Programs\OpenCV-MinGW-Build\x64\mingw\lib -lopencv_core455 -lopencv_imgcodecs455 -lopencv_highgui455 -lopencv_imgproc455
```
to simplify compilation routine I described those libraries in tasks.json file so VScode use it during build process. 

## Source code files description
### 0. Start
* 0-1-version.cpp - to check OpenCV successfully installed
* 0-2-imshow.cpp - open and display image
### 1. Image filtering
* 1-1-blures-bilateral.cpp - comparation of bilateral filter, Gauss blur and median blur.
* 1-2-erosion-dilation.cpp - erosion and delation of image with different kernel size.
* 1-3-sobel_laplace.cpp - Sobel operator to detect the edges. You can investigate the influence of the arguments (dx, dy, kernel, scale and delta) on the result and compare with laplacian oparator result.
* 1-4-filted2D.cpp - convolution with custom kernels. Blur, edge detection, sharpness enhancement, motion blur, e.t.c.
### 2. Drawing
* 2-1-rectangle.cpp - drawing rectangles
* 2-2-circle-line.cpp - drawing circles, lines and arrowed lines
* 2-3-clipline.cpp - functions which returns true if line intersect rectangle area