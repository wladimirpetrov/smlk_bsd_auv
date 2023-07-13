; Auto-generated. Do not edit!


(cl:in-package avl_bsd_translator-msg)


;//! \htmlinclude PassthroughMsg.msg.html

(cl:defclass <PassthroughMsg> (roslisp-msg-protocol:ros-message)
  ((ORIGIN_ID
    :reader ORIGIN_ID
    :initarg :ORIGIN_ID
    :type cl:fixnum
    :initform 0)
   (TARGET_ID
    :reader TARGET_ID
    :initarg :TARGET_ID
    :type cl:fixnum
    :initform 0)
   (CHANNEL
    :reader CHANNEL
    :initarg :CHANNEL
    :type cl:fixnum
    :initform 0)
   (INTERFACE
    :reader INTERFACE
    :initarg :INTERFACE
    :type cl:fixnum
    :initform 0)
   (DATA
    :reader DATA
    :initarg :DATA
    :type cl:string
    :initform ""))
)

(cl:defclass PassthroughMsg (<PassthroughMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PassthroughMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PassthroughMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name avl_bsd_translator-msg:<PassthroughMsg> is deprecated: use avl_bsd_translator-msg:PassthroughMsg instead.")))

(cl:ensure-generic-function 'ORIGIN_ID-val :lambda-list '(m))
(cl:defmethod ORIGIN_ID-val ((m <PassthroughMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:ORIGIN_ID-val is deprecated.  Use avl_bsd_translator-msg:ORIGIN_ID instead.")
  (ORIGIN_ID m))

(cl:ensure-generic-function 'TARGET_ID-val :lambda-list '(m))
(cl:defmethod TARGET_ID-val ((m <PassthroughMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:TARGET_ID-val is deprecated.  Use avl_bsd_translator-msg:TARGET_ID instead.")
  (TARGET_ID m))

(cl:ensure-generic-function 'CHANNEL-val :lambda-list '(m))
(cl:defmethod CHANNEL-val ((m <PassthroughMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:CHANNEL-val is deprecated.  Use avl_bsd_translator-msg:CHANNEL instead.")
  (CHANNEL m))

(cl:ensure-generic-function 'INTERFACE-val :lambda-list '(m))
(cl:defmethod INTERFACE-val ((m <PassthroughMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:INTERFACE-val is deprecated.  Use avl_bsd_translator-msg:INTERFACE instead.")
  (INTERFACE m))

(cl:ensure-generic-function 'DATA-val :lambda-list '(m))
(cl:defmethod DATA-val ((m <PassthroughMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:DATA-val is deprecated.  Use avl_bsd_translator-msg:DATA instead.")
  (DATA m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PassthroughMsg>) ostream)
  "Serializes a message object of type '<PassthroughMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ORIGIN_ID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'TARGET_ID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'CHANNEL)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'INTERFACE)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'DATA))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'DATA))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PassthroughMsg>) istream)
  "Deserializes a message object of type '<PassthroughMsg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ORIGIN_ID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'TARGET_ID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'CHANNEL)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'INTERFACE)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'DATA) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'DATA) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PassthroughMsg>)))
  "Returns string type for a message object of type '<PassthroughMsg>"
  "avl_bsd_translator/PassthroughMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PassthroughMsg)))
  "Returns string type for a message object of type 'PassthroughMsg"
  "avl_bsd_translator/PassthroughMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PassthroughMsg>)))
  "Returns md5sum for a message object of type '<PassthroughMsg>"
  "68cb8a05d5ebb8373e58b01f1c0af317")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PassthroughMsg)))
  "Returns md5sum for a message object of type 'PassthroughMsg"
  "68cb8a05d5ebb8373e58b01f1c0af317")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PassthroughMsg>)))
  "Returns full string definition for message of type '<PassthroughMsg>"
  (cl:format cl:nil "#===============================================================================~%# Autonomous Vehicle Library Backseat Driver~%#~%# Description: Defines a message that contains a passthrough message~%#===============================================================================~%~%uint8 ORIGIN_ID~%uint8 TARGET_ID~%uint8 CHANNEL~%uint8 INTERFACE~%string DATA~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PassthroughMsg)))
  "Returns full string definition for message of type 'PassthroughMsg"
  (cl:format cl:nil "#===============================================================================~%# Autonomous Vehicle Library Backseat Driver~%#~%# Description: Defines a message that contains a passthrough message~%#===============================================================================~%~%uint8 ORIGIN_ID~%uint8 TARGET_ID~%uint8 CHANNEL~%uint8 INTERFACE~%string DATA~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PassthroughMsg>))
  (cl:+ 0
     1
     1
     1
     1
     4 (cl:length (cl:slot-value msg 'DATA))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PassthroughMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'PassthroughMsg
    (cl:cons ':ORIGIN_ID (ORIGIN_ID msg))
    (cl:cons ':TARGET_ID (TARGET_ID msg))
    (cl:cons ':CHANNEL (CHANNEL msg))
    (cl:cons ':INTERFACE (INTERFACE msg))
    (cl:cons ':DATA (DATA msg))
))
