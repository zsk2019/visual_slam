cmake_minimum_required( VERSION 2.8 )
project( useEigen )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-O3" )

# 添加Eigen头文件
# find_package(Eigen3 REQUIRED)
# if(Eigen3_FOUND)
# include_directories( ${Eigen3_INCLUDE_DIRS} )
# message( STATUS "  path is  ${Eigen3_INCLUDE_DIRS}")
include_directories( "/usr/include/eigen3" )
# endif(Eigen3_FOUND)

# in osx and brew install
# include_directories( /usr/local/Cellar/eigen/3.3.3/include/eigen3 )

add_executable( eigenMatrix eigenMatrix.cpp )
add_executable( eigen_test eigen_test.cpp )
