WHERE	!= uname

ALLOPENCVLIBS = " opencv_calib3d opencv_core opencv_features2d 				\
						opencv_flann opencv_highgui opencv_imgcodecs 				\
						opencv_imgproc opencv_ml opencv_objdetect opencv_photo 	\
						opencv_shape opencv_stitching opencv_superres 				\
						opencv_video opencv_videoio opencv_videostab				\
"
DEFAULT_LIB_INSTALL_PATH +=../lib
INSTALL_DIR = ../bin

CPPFLAGS += -g --std=c++14 -Wunused-value
CFLAGS	+= -g
INCLUDE_DIR +=-I/usr/include -I/usr/include -I. -I../include -I /usr/include/eigen3 -I/usr/include/opencv4
LIBS_DIR +=-L/usr/lib -L. -L/usr/local/lib -L$(DEFAULT_LIB_INSTALL_PATH)
LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
IMAGE_LIB += -limage
IMAGE_LIB_NAME += libimage.so
LIBNAME += $(DEFAULT_LIB_INSTALL_PATH)/$(IMAGE_LIB_NAME)
SHARED_LDFLAGS=-Wl,-rpath,$(DEFAULT_LIB_INSTALL_PATH)
BINS = info_image open_image waitkey show_image mouse mouse2 mouse3 work_image Sobel_Demo Sobel_Demo_main_ORIGINAL  Blur Erode_e_Dilate Erode_e_Dilate_original Gaussian_Blurring Laplacian Comparacoes_dos_Borrados_LEGAL BilateralFilter BilateralFilter3_Yt  ExecuteEsse B bgr2gray list_mouse_events effect_image bgr2hsv types avg filtros draw

.cpp.o: ../include/image.hpp

	clang++ -o $@ -c $< $(INCLUDE_DIR) $(CPPFLAGS)

all: $(IMAGE_LIB_NAME) $(BINS)

$(IMAGE_LIB_NAME): image_lib.cpp ../include/image.hpp 

	clang++ -o $(IMAGE_LIB_NAME) image_lib.cpp -fPIC -shared 	\
				$(INCLUDE_DIR) $(LIBS_DIR)
	@- cp $(IMAGE_LIB_NAME) $(DEFAULT_LIB_INSTALL_PATH)

open_image: open_image.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 

show_image: show_image.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
work_image: work_image.o $(IMAGE_LIB_NAME)

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) \
							$(LIBS) $(IMAGE_LIB) $(SHARED_LDFLAGS)
	
waitkey: waitkey.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	

info_image: info_image.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) \
							$(LIBS) $(IMAGE_LIB) $(SHARED_LDFLAGS) 
	

mouse: mouse.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
mouse2: mouse2.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
mouse3: mouse3.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
list_mouse_events: list_mouse_events.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
Sobel_Demo: Sobel_Demo.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 

Sobel_Demo_main_ORIGINAL: Sobel_Demo_main_ORIGINAL.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 

Blur: Blur.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 

Erode_e_Dilate: Erode_e_Dilate.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 

Erode_e_Dilate_original: Erode_e_Dilate_original.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 

Gaussian_Blurring: Gaussian_Blurring.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 

Laplacian: Laplacian.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
	

Comparacoes_dos_Borrados_LEGAL: Comparacoes_dos_Borrados_LEGAL.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 

BilateralFilter: BilateralFilter.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 

BilateralFilter3_Yt: BilateralFilter3_Yt.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 



ExecuteEsse: ExecuteEsse.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS)

B: B.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS)

effect_image: effect_image.o $(IMAGE_LIB_NAME)

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) \
							$(LIBS) $(IMAGE_LIB) $(SHARED_LDFLAGS) 
	
bgr2hsv: bgr2hsv.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
bgr2gray: bgr2gray.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
types: types.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
avg: avg.o

	clang++ -o $@ $>  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	
filtros: filtros.o $(IMAGE_LIB_NAME)

	clang++ -o $@  filtros.o  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS) 
	

draw: draw.o $(IMAGE_LIB_NAME)

	clang++ -o $@  draw.o  $(CPPFLAGS)  $(INCLUDE_DIR) $(LIBS_DIR) $(LIBS)
	
clean:

	@echo -n Cleaning ...
	@touch  $(BINS)
	@touch $(LIBNAME) $(IMAGE_LIB_NAME)
	@touch a.o a.core a.out
	@- rm $(BINS)
	@- rm $(LIBNAME) $(IMAGE_LIB_NAME)
	@- rm *.o
	@- rm *core
	@- rm a.out
	@echo . Done.



