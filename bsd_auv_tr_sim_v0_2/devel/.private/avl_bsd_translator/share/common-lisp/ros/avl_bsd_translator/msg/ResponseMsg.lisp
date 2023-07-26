; Auto-generated. Do not edit!


(cl:in-package avl_bsd_translator-msg)


;//! \htmlinclude ResponseMsg.msg.html

(cl:defclass <ResponseMsg> (roslisp-msg-protocol:ros-message)
  ((DESC
    :reader DESC
    :initarg :DESC
    :type cl:fixnum
    :initform 0)
   (NAME
    :reader NAME
    :initarg :NAME
    :type cl:string
    :initform "")
   (SOURCE
    :reader SOURCE
    :initarg :SOURCE
    :type cl:integer
    :initform 0)
   (RESULT
    :reader RESULT
    :initarg :RESULT
    :type cl:boolean
    :initform cl:nil)
   (DATA
    :reader DATA
    :initarg :DATA
    :type cl:string
    :initform ""))
)

(cl:defclass ResponseMsg (<ResponseMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ResponseMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ResponseMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name avl_bsd_translator-msg:<ResponseMsg> is deprecated: use avl_bsd_translator-msg:ResponseMsg instead.")))

(cl:ensure-generic-function 'DESC-val :lambda-list '(m))
(cl:defmethod DESC-val ((m <ResponseMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:DESC-val is deprecated.  Use avl_bsd_translator-msg:DESC instead.")
  (DESC m))

(cl:ensure-generic-function 'NAME-val :lambda-list '(m))
(cl:defmethod NAME-val ((m <ResponseMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:NAME-val is deprecated.  Use avl_bsd_translator-msg:NAME instead.")
  (NAME m))

(cl:ensure-generic-function 'SOURCE-val :lambda-list '(m))
(cl:defmethod SOURCE-val ((m <ResponseMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:SOURCE-val is deprecated.  Use avl_bsd_translator-msg:SOURCE instead.")
  (SOURCE m))

(cl:ensure-generic-function 'RESULT-val :lambda-list '(m))
(cl:defmethod RESULT-val ((m <ResponseMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:RESULT-val is deprecated.  Use avl_bsd_translator-msg:RESULT instead.")
  (RESULT m))

(cl:ensure-generic-function 'DATA-val :lambda-list '(m))
(cl:defmethod DATA-val ((m <ResponseMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:DATA-val is deprecated.  Use avl_bsd_translator-msg:DATA instead.")
  (DATA m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ResponseMsg>) ostream)
  "Serializes a message object of type '<ResponseMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'DESC)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'NAME))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'NAME))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'SOURCE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'SOURCE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'SOURCE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'SOURCE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'SOURCE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'SOURCE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'SOURCE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'SOURCE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'RESULT) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'DATA))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'DATA))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ResponseMsg>) istream)
  "Deserializes a message object of type '<ResponseMsg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'DESC)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'NAME) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'NAME) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'SOURCE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'SOURCE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'SOURCE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'SOURCE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'SOURCE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'SOURCE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'SOURCE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'SOURCE)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'RESULT) (cl:not (cl:zerop (cl:read-byte istream))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ResponseMsg>)))
  "Returns string type for a message object of type '<ResponseMsg>"
  "avl_bsd_translator/ResponseMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResponseMsg)))
  "Returns string type for a message object of type 'ResponseMsg"
  "avl_bsd_translator/ResponseMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ResponseMsg>)))
  "Returns md5sum for a message object of type '<ResponseMsg>"
  "f6a85287137e7f8b62777ed3e0afe18e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ResponseMsg)))
  "Returns md5sum for a message object of type 'ResponseMsg"
  "f6a85287137e7f8b62777ed3e0afe18e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ResponseMsg>)))
  "Returns full string definition for message of type '<ResponseMsg>"
  (cl:format cl:nil "#===============================================================================~%# Autonomous Vehicle Library Backseat Driver~%#~%# Description: Defines a message that contains a response from the vehicle~%#              computer~%#===============================================================================~%~%uint8 DESC~%string NAME~%uint64 SOURCE~%bool RESULT~%string DATA~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ResponseMsg)))
  "Returns full string definition for message of type 'ResponseMsg"
  (cl:format cl:nil "#===============================================================================~%# Autonomous Vehicle Library Backseat Driver~%#~%# Description: Defines a message that contains a response from the vehicle~%#              computer~%#===============================================================================~%~%uint8 DESC~%string NAME~%uint64 SOURCE~%bool RESULT~%string DATA~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ResponseMsg>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'NAME))
     8
     1
     4 (cl:length (cl:slot-value msg 'DATA))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ResponseMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'ResponseMsg
    (cl:cons ':DESC (DESC msg))
    (cl:cons ':NAME (NAME msg))
    (cl:cons ':SOURCE (SOURCE msg))
    (cl:cons ':RESULT (RESULT msg))
    (cl:cons ':DATA (DATA msg))
))
