# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "avl_bsd_translator: 6 messages, 0 services")

set(MSG_I_FLAGS "-Iavl_bsd_translator:/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(avl_bsd_translator_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg" NAME_WE)
add_custom_target(_avl_bsd_translator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "avl_bsd_translator" "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg" ""
)

get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg" NAME_WE)
add_custom_target(_avl_bsd_translator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "avl_bsd_translator" "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg" ""
)

get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg" NAME_WE)
add_custom_target(_avl_bsd_translator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "avl_bsd_translator" "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg" ""
)

get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg" NAME_WE)
add_custom_target(_avl_bsd_translator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "avl_bsd_translator" "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg" ""
)

get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg" NAME_WE)
add_custom_target(_avl_bsd_translator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "avl_bsd_translator" "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg" ""
)

get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg" NAME_WE)
add_custom_target(_avl_bsd_translator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "avl_bsd_translator" "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_cpp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_cpp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_cpp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_cpp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_cpp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/avl_bsd_translator
)

### Generating Services

### Generating Module File
_generate_module_cpp(avl_bsd_translator
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/avl_bsd_translator
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(avl_bsd_translator_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(avl_bsd_translator_generate_messages avl_bsd_translator_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_cpp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_cpp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_cpp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_cpp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_cpp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_cpp _avl_bsd_translator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(avl_bsd_translator_gencpp)
add_dependencies(avl_bsd_translator_gencpp avl_bsd_translator_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS avl_bsd_translator_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_eus(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_eus(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_eus(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_eus(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_eus(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/avl_bsd_translator
)

### Generating Services

### Generating Module File
_generate_module_eus(avl_bsd_translator
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/avl_bsd_translator
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(avl_bsd_translator_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(avl_bsd_translator_generate_messages avl_bsd_translator_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_eus _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_eus _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_eus _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_eus _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_eus _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_eus _avl_bsd_translator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(avl_bsd_translator_geneus)
add_dependencies(avl_bsd_translator_geneus avl_bsd_translator_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS avl_bsd_translator_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_lisp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_lisp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_lisp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_lisp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_lisp(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/avl_bsd_translator
)

### Generating Services

### Generating Module File
_generate_module_lisp(avl_bsd_translator
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/avl_bsd_translator
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(avl_bsd_translator_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(avl_bsd_translator_generate_messages avl_bsd_translator_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_lisp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_lisp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_lisp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_lisp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_lisp _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_lisp _avl_bsd_translator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(avl_bsd_translator_genlisp)
add_dependencies(avl_bsd_translator_genlisp avl_bsd_translator_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS avl_bsd_translator_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_nodejs(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_nodejs(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_nodejs(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_nodejs(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_nodejs(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/avl_bsd_translator
)

### Generating Services

### Generating Module File
_generate_module_nodejs(avl_bsd_translator
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/avl_bsd_translator
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(avl_bsd_translator_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(avl_bsd_translator_generate_messages avl_bsd_translator_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_nodejs _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_nodejs _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_nodejs _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_nodejs _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_nodejs _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_nodejs _avl_bsd_translator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(avl_bsd_translator_gennodejs)
add_dependencies(avl_bsd_translator_gennodejs avl_bsd_translator_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS avl_bsd_translator_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_py(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_py(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_py(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_py(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator
)
_generate_msg_py(avl_bsd_translator
  "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator
)

### Generating Services

### Generating Module File
_generate_module_py(avl_bsd_translator
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(avl_bsd_translator_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(avl_bsd_translator_generate_messages avl_bsd_translator_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/HeartbeatMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_py _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ActionMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_py _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/ResponseMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_py _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/CommandMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_py _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/DeviceMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_py _avl_bsd_translator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/local/vol00/home/vpetrov/dev/smlk_bsd_auv/bsd_auv_tr_sim_v0_2/src/avl_bsd_translator/msg/PassthroughMsg.msg" NAME_WE)
add_dependencies(avl_bsd_translator_generate_messages_py _avl_bsd_translator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(avl_bsd_translator_genpy)
add_dependencies(avl_bsd_translator_genpy avl_bsd_translator_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS avl_bsd_translator_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/avl_bsd_translator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/avl_bsd_translator
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(avl_bsd_translator_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/avl_bsd_translator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/avl_bsd_translator
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(avl_bsd_translator_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/avl_bsd_translator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/avl_bsd_translator
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(avl_bsd_translator_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/avl_bsd_translator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/avl_bsd_translator
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(avl_bsd_translator_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/avl_bsd_translator
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(avl_bsd_translator_generate_messages_py std_msgs_generate_messages_py)
endif()
