# Try to find WiringPi
# Once done, this will define
#
#  WiringPi_FOUND - system has WiringPi
#  WiringPi_INCLUDE_DIRS - the WiringPi include directories
#  WiringPi_LIBRARIES - link these to use WiringPi

include(LibFindMacros)

# Dependencies
libfind_package(WiringPi Threads)

# Include dir
find_path(WiringPi_INCLUDE_DIR
    NAMES wiringPi.h
    PATHS ${WiringPi_PKGCONF_INCLUDE_DIRS}
    )

# Finally the library itself
find_library(WiringPi_LIBRARY
    NAMES wiringPi
    PATHS ${WiringPi_PKGCONF_LIBRARY_DIRS}
    )

set(RT_LIBS "-lrt")
set(CRYPT_LIBS "-lcrypt")

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(WiringPi_PROCESS_INCLUDES WiringPi_INCLUDE_DIR)
set(WiringPi_PROCESS_LIBS WiringPi_LIBRARY CMAKE_THREAD_LIBS_INIT RT_LIBS CRYPT_LIBS)
libfind_process(WiringPi)
