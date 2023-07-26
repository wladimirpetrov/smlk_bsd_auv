# Install script for directory: /local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/src/avl_bsd_translator

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install" TYPE PROGRAM FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install" TYPE PROGRAM FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install/setup.bash;/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install" TYPE FILE FILES
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/setup.bash"
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install/setup.sh;/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install" TYPE FILE FILES
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/setup.sh"
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install/setup.zsh;/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install" TYPE FILE FILES
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/setup.zsh"
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/install" TYPE FILE FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/avl_bsd_translator/msg" TYPE FILE FILES
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/src/avl_bsd_translator/msg/HeartbeatMsg.msg"
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/src/avl_bsd_translator/msg/ActionMsg.msg"
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/src/avl_bsd_translator/msg/ResponseMsg.msg"
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/src/avl_bsd_translator/msg/CommandMsg.msg"
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/src/avl_bsd_translator/msg/DeviceMsg.msg"
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/src/avl_bsd_translator/msg/PassthroughMsg.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/avl_bsd_translator/cmake" TYPE FILE FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/avl_bsd_translator-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/devel/.private/avl_bsd_translator/include/avl_bsd_translator")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/devel/.private/avl_bsd_translator/share/roseus/ros/avl_bsd_translator")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/devel/.private/avl_bsd_translator/share/common-lisp/ros/avl_bsd_translator")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/devel/.private/avl_bsd_translator/share/gennodejs/ros/avl_bsd_translator")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/devel/.private/avl_bsd_translator/lib/python3/dist-packages/avl_bsd_translator")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/devel/.private/avl_bsd_translator/lib/python3/dist-packages/avl_bsd_translator")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/avl_bsd_translator.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/avl_bsd_translator/cmake" TYPE FILE FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/avl_bsd_translator-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/avl_bsd_translator/cmake" TYPE FILE FILES
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/avl_bsd_translatorConfig.cmake"
    "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/catkin_generated/installspace/avl_bsd_translatorConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/avl_bsd_translator" TYPE FILE FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/src/avl_bsd_translator/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/avl_bsd_translator" TYPE DIRECTORY FILES "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/src/avl_bsd_translator/include/avl_bsd_translator/" FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/\\.svn$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2_ws/build/avl_bsd_translator/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
