#change this line according to the target architecture
#TARGET := x86
TARGET := ve

INSTALLPATH := /opt/nec/nosupport/vstl/${TARGET}

JOBS := $(shell /usr/bin/nproc --all)

all:
	cd src/vstl/common; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS}
	cd src/vstl/seq/core; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS}
#	cd src/vstl/omp/core; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS}
	cd samples/seq; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS}

install:
	cd src/vstl/common; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS} install
	cd src/vstl/seq/core; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS} install
#	cd src/vstl/omp/core; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS} install
	cd samples/seq; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS} install

clean:
	cd src/vstl/common; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS} clean
	cd src/vstl/seq/core; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS} clean
#	cd src/vstl/omp/core; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS} clean
	cd samples/seq; ${MAKE} -f Makefile.${TARGET} INSTALLPATH=${INSTALLPATH} -j ${JOBS} clean
	${RM} *~
