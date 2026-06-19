# To change the cuda arch, edit Makefile.am and run ./build.sh

extracflags="-march=native -D_REENTRANT -falign-functions=16 -falign-jumps=16 -falign-labels=16"

CUDA_CFLAGS="-O3 -lineno -Xcompiler -Wall -D_FORCE_INLINES -ccbin g++-11" \
	./configure CC=gcc-11 CXX=g++-11 CXXFLAGS="-O3 $extracflags" \
	LDFLAGS="-L/usr/local/cuda/lib64/stubs" \
	--with-cuda=/usr/local/cuda --with-nvml=libnvidia-ml.so

