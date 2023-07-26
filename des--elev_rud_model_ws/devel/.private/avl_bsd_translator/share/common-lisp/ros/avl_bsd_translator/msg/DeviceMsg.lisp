; Auto-generated. Do not edit!


(cl:in-package avl_bsd_translator-msg)


;//! \htmlinclude DeviceMsg.msg.html

(cl:defclass <DeviceMsg> (roslisp-msg-protocol:ros-message)
  ((DEVICE_NAME
    :reader DEVICE_NAME
    :initarg :DEVICE_NAME
    :type cl:string
    :initform "")
   (NAMES
    :reader NAMES
    :initarg :NAMES
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (TYPES
    :reader TYPES
    :initarg :TYPES
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0))
   (VALUES
    :reader VALUES
    :initarg :VALUES
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass DeviceMsg (<DeviceMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DeviceMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DeviceMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name avl_bsd_translator-msg:<DeviceMsg> is deprecated: use avl_bsd_translator-msg:DeviceMsg instead.")))

(cl:ensure-generic-function 'DEVICE_NAME-val :lambda-list '(m))
(cl:defmethod DEVICE_NAME-val ((m <DeviceMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:DEVICE_NAME-val is deprecated.  Use avl_bsd_translator-msg:DEVICE_NAME instead.")
  (DEVICE_NAME m))

(cl:ensure-generic-function 'NAMES-val :lambda-list '(m))
(cl:defmethod NAMES-val ((m <DeviceMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:NAMES-val is deprecated.  Use avl_bsd_translator-msg:NAMES instead.")
  (NAMES m))

(cl:ensure-generic-function 'TYPES-val :lambda-list '(m))
(cl:defmethod TYPES-val ((m <DeviceMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:TYPES-val is deprecated.  Use avl_bsd_translator-msg:TYPES instead.")
  (TYPES m))

(cl:ensure-generic-function 'VALUES-val :lambda-list '(m))
(cl:defmethod VALUES-val ((m <DeviceMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:VALUES-val is deprecated.  Use avl_bsd_translator-msg:VALUES instead.")
  (VALUES m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DeviceMsg>) ostream)
  "Serializes a message object of type '<DeviceMsg>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'DEVICE_NAME))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'DEVICE_NAME))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'NAMES))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'NAMES))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'TYPES))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'TYPES))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'VALUES))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'VALUES))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DeviceMsg>) istream)
  "Deserializes a message object of type '<DeviceMsg>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'DEVICE_NAME) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'DEVICE_NAME) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'NAMES) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'NAMES)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'TYPES) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'TYPES)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'VALUES) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'VALUES)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DeviceMsg>)))
  "Returns string type for a message object of type '<DeviceMsg>"
  "avl_bsd_translator/DeviceMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DeviceMsg)))
  "Returns string type for a message object of type 'DeviceMsg"
  "avl_bsd_translator/DeviceMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DeviceMsg>)))
  "Returns md5sum for a message object of type '<DeviceMsg>"
  "ac0218f626191d446efaa61422be9692")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DeviceMsg)))
  "Returns md5sum for a message object of type 'DeviceMsg"
  "ac0218f626191d446efaa61422be9692")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DeviceMsg>)))
  "Returns full string definition for message of type '<DeviceMsg>"
  (cl:format cl:nil "#===============================================================================~%# Autonomous Vehicle Library Backseat Driver~%#~%# Description: Defines a ROS message that contains a device message~%#===============================================================================~%~%string DEVICE_NAME~%string[] NAMES~%uint8[] TYPES~%string[] VALUES~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DeviceMsg)))
  "Returns full string definition for message of type 'DeviceMsg"
  (cl:format cl:nil "#===============================================================================~%# Autonomous Vehicle Library Backseat Driver~%#~%# Description: Defines a ROS message that contains a device message~%#===============================================================================~%~%string DEVICE_NAME~%string[] NAMES~%uint8[] TYPES~%string[] VALUES~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DeviceMsg>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'DEVICE_NAME))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'NAMES) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'TYPES) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'VALUES) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DeviceMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'DeviceMsg
    (cl:cons ':DEVICE_NAME (DEVICE_NAME msg))
    (cl:cons ':NAMES (NAMES msg))
    (cl:cons ':TYPES (TYPES msg))
    (cl:cons ':VALUES (VALUES msg))
))
