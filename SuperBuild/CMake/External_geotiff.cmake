set(proj GEOTIFF)

if(NOT __EXTERNAL_${proj}__)
set(__EXTERNAL_${proj}__ 1)

message(STATUS "Setup libgeotiff...")

if(USE_SYSTEM_GEOTIFF)
  find_package ( GeoTIFF )
  message(STATUS "  Using libgeotiff system version")
else()
  SETUP_SUPERBUILD(PROJECT ${proj})
  message(STATUS "  Using GeoTIFF SuperBuild version")

  # declare dependencies
  ADDTO_DEPENDENCIES_IF_NOT_SYSTEM(${proj} TIFF PROJ JPEG ZLIB)

  INCLUDE_SUPERBUILD_DEPENDENCIES(${${proj}_DEPENDENCIES})
  # set proj back to its original value
  set(proj GEOTIFF)

  if(MSVC)
    ADD_SUPERBUILD_CMAKE_VAR(TIFF_INCLUDE_DIR)
    ADD_SUPERBUILD_CMAKE_VAR(TIFF_LIBRARY)
    ADD_SUPERBUILD_CMAKE_VAR(PROJ4_INCLUDE_DIR)
    ADD_SUPERBUILD_CMAKE_VAR(PROJ4_LIBRARY)
    ADD_SUPERBUILD_CMAKE_VAR(ZLIB_INCLUDE_DIR)
    ADD_SUPERBUILD_CMAKE_VAR(ZLIB_LIBRARY)
    ADD_SUPERBUILD_CMAKE_VAR(JPEG_INCLUDE_DIR)
    ADD_SUPERBUILD_CMAKE_VAR(JPEG_LIBRARY)
  endif()

  ExternalProject_Add(${proj}
    PREFIX ${proj}
    URL "http://download.osgeo.org/geotiff/libgeotiff/libgeotiff-1.4.1.tar.gz"
    URL_MD5 48bdf817e6e7a37671cc1f41b01e10fc
    SOURCE_DIR ${GEOTIFF_SB_SRC}
    BINARY_DIR ${GEOTIFF_SB_BUILD_DIR}
    INSTALL_DIR ${SB_INSTALL_PREFIX}
    DOWNLOAD_DIR ${DOWNLOAD_LOCATION}
    DEPENDS ${${proj}_DEPENDENCIES}
    CMAKE_CACHE_ARGS
    -DCMAKE_INSTALL_PREFIX:STRING=${SB_INSTALL_PREFIX}
    -DCMAKE_BUILD_TYPE:STRING=Release
    -DBUILD_SHARED_LIBS:BOOL=ON
    -DBUILD_TESTING:BOOL=OFF
    CMAKE_COMMAND ${SB_CMAKE_COMMAND}
    )

  set(_SB_${proj}_INCLUDE_DIR ${SB_INSTALL_PREFIX}/include)
  if(WIN32)
    set(_SB_${proj}_LIBRARY ${SB_INSTALL_PREFIX}/lib/geotiff_i.lib)
  elseif(UNIX)
    set(_SB_${proj}_LIBRARY ${SB_INSTALL_PREFIX}/lib/libgeotiff${CMAKE_SHARED_LIBRARY_SUFFIX})
  endif()

endif()
endif()
