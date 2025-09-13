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
* 0-3-img_data.cpp - data parameters: depth of datatype, type of datatype, size of image, channels.
A Mapping of Type to Numbers in OpenCV

| | C1 | C2 | C3 | C4
|---|---|---|---|---|
|CV_8U|	0|	8|	16|	24
|CV_8S|	1|	9|	17|	25
|CV_16U| 2|	10|	18|	26
|CV_16S| 3|	11|	19|	27
|CV_32S| 4|	12|	20|	28
|CV_32F| 5|	13|	21|	29
|CV_64F| 6|	14|	22|	30

* 0-4-comLineParser.cpp - parse comand line arguments to provide path to image file

### 1. Filtration
* 1-1-blures-bilateral.cpp - comparation of bilateral filter, Gauss blur and median blur.
* 1-2-erosion-dilation.cpp - erosion and delation of image with different kernel size.
* 1-3-sobel_laplace.cpp - Sobel operator to detect the edges. You can investigate the influence of the arguments (dx, dy, kernel, scale and delta) on the result and compare with laplacian oparator result.
* 1-4-filted2D.cpp - convolution with custom kernels. Blur, edge detection, sharpness enhancement, motion blur, e.t.c.

### 2. Drawing and text
* 2-1-rectangle.cpp - drawing rectangles
* 2-2-circle-line.cpp - drawing circles, lines and arrowed lines
* 2-3-clipline.cpp - functions which returns true if line intersect rectangle area
* 2-4-ellipse.cpp - usage of cv::ellipse() and cv::ellipse2Poly()
* 2-5-text.cpp - usage of putText() and getTextSize()
* 2-6-poly.cpp - drawing polygon line and filled polygons

### 3. Geometric
* 3-1-resize.cpp - resize image by resulting size or by proportions
* 3-2-perspective.cpp - changin geometry of image based on moving of key points.
* 3-3-remap.cpp - creating by pixel matrice of rules for transform source image to resulting image by moving pixels or calculating destination pixel based on source pixels group.
* 3-4-comvertMaps - preparing map of image transformation for fast remap
* 3-5-polar.cpp - transform image from linear to polar coordinates and back
* 3-6-crop.cpp - crop image based on left top corner, based on center, based on user selection

### 4. pixel value manipulation
* 4-1-trhreshold.cpp - intensity based manipulation, threshold based on fixed level.
* 4-2-adaptive_thr.cpp - threshold based on nearest pixels values.
* 4-3-integral - sum of pixel values, can be used for detecting bright regions
* 4-4-distance.cpp - using distanceTransform to specify regions nearest to 0-value pixels
* 4-5-blend.cpp - blending two images, manipulating with weights to make part of image transparent.
* 4-6-grabcut - defining foreground/background with grabcut algorothm, 4-6-grabcut-array.cpp is an example on simple array data,  4-6-grabcut-picture.cpp is using grabcut with real picture
* 4-7-floodfill.cpp flood image based on pixel color

### 5. Color models
* 5-1-cvtcolor.cpp - converting to another color model
* 5-2-color2plane.cpp - convertation from BRG to YUV, split YUV to separate channels, assemble it back to BGR
* 5-3-bayer.cpp - convertion from Bayer color filter format (used by most camera censors) to standard BGR.
* 5-4-colormap.cpp - convert grayscale image to colored one so human eye can easily distinguish image elements.
* 5-5-equalizeH.cpp - using equalizeHist() to enhance contrast and fix white ballance.
* 5-6-calchist_1ch.cpp - calculating and drawing histogram for one-channel grayscale image
* 5-6-calchist_3ch.cpp - calculating and drawing histogram for RGB
* 5-7-compareH.cpp - comparing histohrams of 2 images