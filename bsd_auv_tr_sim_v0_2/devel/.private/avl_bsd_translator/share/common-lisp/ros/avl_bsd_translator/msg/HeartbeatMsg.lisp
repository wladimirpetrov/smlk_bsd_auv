; Auto-generated. Do not edit!


(cl:in-package avl_bsd_translator-msg)


;//! \htmlinclude HeartbeatMsg.msg.html

(cl:defclass <HeartbeatMsg> (roslisp-msg-protocol:ros-message)
  ((HEARTBEAT_STATUS
    :reader HEARTBEAT_STATUS
    :initarg :HEARTBEAT_STATUS
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_UMODEM_SYNC
    :reader HEARTBEAT_UMODEM_SYNC
    :initarg :HEARTBEAT_UMODEM_SYNC
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_IRIDIUM_STR
    :reader HEARTBEAT_IRIDIUM_STR
    :initarg :HEARTBEAT_IRIDIUM_STR
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_MISSION_MODE
    :reader HEARTBEAT_MISSION_MODE
    :initarg :HEARTBEAT_MISSION_MODE
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_FSD_MISSION_STATE
    :reader HEARTBEAT_FSD_MISSION_STATE
    :initarg :HEARTBEAT_FSD_MISSION_STATE
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_FSD_CURRENT_ACTION
    :reader HEARTBEAT_FSD_CURRENT_ACTION
    :initarg :HEARTBEAT_FSD_CURRENT_ACTION
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_FSD_TOTAL_ACTIONS
    :reader HEARTBEAT_FSD_TOTAL_ACTIONS
    :initarg :HEARTBEAT_FSD_TOTAL_ACTIONS
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_BSD_MISSION_STATE
    :reader HEARTBEAT_BSD_MISSION_STATE
    :initarg :HEARTBEAT_BSD_MISSION_STATE
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_BSD_CURRENT_ACTION
    :reader HEARTBEAT_BSD_CURRENT_ACTION
    :initarg :HEARTBEAT_BSD_CURRENT_ACTION
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_BSD_TOTAL_ACTIONS
    :reader HEARTBEAT_BSD_TOTAL_ACTIONS
    :initarg :HEARTBEAT_BSD_TOTAL_ACTIONS
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_GPS_SATS
    :reader HEARTBEAT_GPS_SATS
    :initarg :HEARTBEAT_GPS_SATS
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_NAV_INITIALIZED
    :reader HEARTBEAT_NAV_INITIALIZED
    :initarg :HEARTBEAT_NAV_INITIALIZED
    :type cl:fixnum
    :initform 0)
   (HEARTBEAT_ROLL
    :reader HEARTBEAT_ROLL
    :initarg :HEARTBEAT_ROLL
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_PITCH
    :reader HEARTBEAT_PITCH
    :initarg :HEARTBEAT_PITCH
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_YAW
    :reader HEARTBEAT_YAW
    :initarg :HEARTBEAT_YAW
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_WX
    :reader HEARTBEAT_WX
    :initarg :HEARTBEAT_WX
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_WY
    :reader HEARTBEAT_WY
    :initarg :HEARTBEAT_WY
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_WZ
    :reader HEARTBEAT_WZ
    :initarg :HEARTBEAT_WZ
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_AX
    :reader HEARTBEAT_AX
    :initarg :HEARTBEAT_AX
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_AY
    :reader HEARTBEAT_AY
    :initarg :HEARTBEAT_AY
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_AZ
    :reader HEARTBEAT_AZ
    :initarg :HEARTBEAT_AZ
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_VN
    :reader HEARTBEAT_VN
    :initarg :HEARTBEAT_VN
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_VE
    :reader HEARTBEAT_VE
    :initarg :HEARTBEAT_VE
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_VD
    :reader HEARTBEAT_VD
    :initarg :HEARTBEAT_VD
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_DEPTH
    :reader HEARTBEAT_DEPTH
    :initarg :HEARTBEAT_DEPTH
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_HEIGHT
    :reader HEARTBEAT_HEIGHT
    :initarg :HEARTBEAT_HEIGHT
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_RPM
    :reader HEARTBEAT_RPM
    :initarg :HEARTBEAT_RPM
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_VOLTAGE
    :reader HEARTBEAT_VOLTAGE
    :initarg :HEARTBEAT_VOLTAGE
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_FSD_ACTION_PERCENT
    :reader HEARTBEAT_FSD_ACTION_PERCENT
    :initarg :HEARTBEAT_FSD_ACTION_PERCENT
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_BSD_ACTION_PERCENT
    :reader HEARTBEAT_BSD_ACTION_PERCENT
    :initarg :HEARTBEAT_BSD_ACTION_PERCENT
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_GPS_LAT
    :reader HEARTBEAT_GPS_LAT
    :initarg :HEARTBEAT_GPS_LAT
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_GPS_LON
    :reader HEARTBEAT_GPS_LON
    :initarg :HEARTBEAT_GPS_LON
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_GPS_ALT
    :reader HEARTBEAT_GPS_ALT
    :initarg :HEARTBEAT_GPS_ALT
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_NAV_LAT
    :reader HEARTBEAT_NAV_LAT
    :initarg :HEARTBEAT_NAV_LAT
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_NAV_LON
    :reader HEARTBEAT_NAV_LON
    :initarg :HEARTBEAT_NAV_LON
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_NAV_ALT
    :reader HEARTBEAT_NAV_ALT
    :initarg :HEARTBEAT_NAV_ALT
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_NAV_YAW_STD
    :reader HEARTBEAT_NAV_YAW_STD
    :initarg :HEARTBEAT_NAV_YAW_STD
    :type cl:float
    :initform 0.0)
   (HEARTBEAT_NAV_AVG_POS_ERR
    :reader HEARTBEAT_NAV_AVG_POS_ERR
    :initarg :HEARTBEAT_NAV_AVG_POS_ERR
    :type cl:float
    :initform 0.0))
)

(cl:defclass HeartbeatMsg (<HeartbeatMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HeartbeatMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HeartbeatMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name avl_bsd_translator-msg:<HeartbeatMsg> is deprecated: use avl_bsd_translator-msg:HeartbeatMsg instead.")))

(cl:ensure-generic-function 'HEARTBEAT_STATUS-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_STATUS-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_STATUS-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_STATUS instead.")
  (HEARTBEAT_STATUS m))

(cl:ensure-generic-function 'HEARTBEAT_UMODEM_SYNC-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_UMODEM_SYNC-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_UMODEM_SYNC-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_UMODEM_SYNC instead.")
  (HEARTBEAT_UMODEM_SYNC m))

(cl:ensure-generic-function 'HEARTBEAT_IRIDIUM_STR-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_IRIDIUM_STR-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_IRIDIUM_STR-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_IRIDIUM_STR instead.")
  (HEARTBEAT_IRIDIUM_STR m))

(cl:ensure-generic-function 'HEARTBEAT_MISSION_MODE-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_MISSION_MODE-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_MISSION_MODE-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_MISSION_MODE instead.")
  (HEARTBEAT_MISSION_MODE m))

(cl:ensure-generic-function 'HEARTBEAT_FSD_MISSION_STATE-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_FSD_MISSION_STATE-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_FSD_MISSION_STATE-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_FSD_MISSION_STATE instead.")
  (HEARTBEAT_FSD_MISSION_STATE m))

(cl:ensure-generic-function 'HEARTBEAT_FSD_CURRENT_ACTION-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_FSD_CURRENT_ACTION-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_FSD_CURRENT_ACTION-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_FSD_CURRENT_ACTION instead.")
  (HEARTBEAT_FSD_CURRENT_ACTION m))

(cl:ensure-generic-function 'HEARTBEAT_FSD_TOTAL_ACTIONS-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_FSD_TOTAL_ACTIONS-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_FSD_TOTAL_ACTIONS-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_FSD_TOTAL_ACTIONS instead.")
  (HEARTBEAT_FSD_TOTAL_ACTIONS m))

(cl:ensure-generic-function 'HEARTBEAT_BSD_MISSION_STATE-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_BSD_MISSION_STATE-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_BSD_MISSION_STATE-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_BSD_MISSION_STATE instead.")
  (HEARTBEAT_BSD_MISSION_STATE m))

(cl:ensure-generic-function 'HEARTBEAT_BSD_CURRENT_ACTION-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_BSD_CURRENT_ACTION-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_BSD_CURRENT_ACTION-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_BSD_CURRENT_ACTION instead.")
  (HEARTBEAT_BSD_CURRENT_ACTION m))

(cl:ensure-generic-function 'HEARTBEAT_BSD_TOTAL_ACTIONS-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_BSD_TOTAL_ACTIONS-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_BSD_TOTAL_ACTIONS-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_BSD_TOTAL_ACTIONS instead.")
  (HEARTBEAT_BSD_TOTAL_ACTIONS m))

(cl:ensure-generic-function 'HEARTBEAT_GPS_SATS-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_GPS_SATS-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_GPS_SATS-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_GPS_SATS instead.")
  (HEARTBEAT_GPS_SATS m))

(cl:ensure-generic-function 'HEARTBEAT_NAV_INITIALIZED-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_NAV_INITIALIZED-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_NAV_INITIALIZED-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_NAV_INITIALIZED instead.")
  (HEARTBEAT_NAV_INITIALIZED m))

(cl:ensure-generic-function 'HEARTBEAT_ROLL-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_ROLL-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_ROLL-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_ROLL instead.")
  (HEARTBEAT_ROLL m))

(cl:ensure-generic-function 'HEARTBEAT_PITCH-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_PITCH-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_PITCH-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_PITCH instead.")
  (HEARTBEAT_PITCH m))

(cl:ensure-generic-function 'HEARTBEAT_YAW-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_YAW-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_YAW-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_YAW instead.")
  (HEARTBEAT_YAW m))

(cl:ensure-generic-function 'HEARTBEAT_WX-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_WX-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_WX-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_WX instead.")
  (HEARTBEAT_WX m))

(cl:ensure-generic-function 'HEARTBEAT_WY-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_WY-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_WY-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_WY instead.")
  (HEARTBEAT_WY m))

(cl:ensure-generic-function 'HEARTBEAT_WZ-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_WZ-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_WZ-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_WZ instead.")
  (HEARTBEAT_WZ m))

(cl:ensure-generic-function 'HEARTBEAT_AX-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_AX-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_AX-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_AX instead.")
  (HEARTBEAT_AX m))

(cl:ensure-generic-function 'HEARTBEAT_AY-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_AY-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_AY-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_AY instead.")
  (HEARTBEAT_AY m))

(cl:ensure-generic-function 'HEARTBEAT_AZ-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_AZ-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_AZ-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_AZ instead.")
  (HEARTBEAT_AZ m))

(cl:ensure-generic-function 'HEARTBEAT_VN-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_VN-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_VN-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_VN instead.")
  (HEARTBEAT_VN m))

(cl:ensure-generic-function 'HEARTBEAT_VE-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_VE-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_VE-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_VE instead.")
  (HEARTBEAT_VE m))

(cl:ensure-generic-function 'HEARTBEAT_VD-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_VD-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_VD-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_VD instead.")
  (HEARTBEAT_VD m))

(cl:ensure-generic-function 'HEARTBEAT_DEPTH-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_DEPTH-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_DEPTH-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_DEPTH instead.")
  (HEARTBEAT_DEPTH m))

(cl:ensure-generic-function 'HEARTBEAT_HEIGHT-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_HEIGHT-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_HEIGHT-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_HEIGHT instead.")
  (HEARTBEAT_HEIGHT m))

(cl:ensure-generic-function 'HEARTBEAT_RPM-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_RPM-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_RPM-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_RPM instead.")
  (HEARTBEAT_RPM m))

(cl:ensure-generic-function 'HEARTBEAT_VOLTAGE-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_VOLTAGE-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_VOLTAGE-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_VOLTAGE instead.")
  (HEARTBEAT_VOLTAGE m))

(cl:ensure-generic-function 'HEARTBEAT_FSD_ACTION_PERCENT-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_FSD_ACTION_PERCENT-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_FSD_ACTION_PERCENT-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_FSD_ACTION_PERCENT instead.")
  (HEARTBEAT_FSD_ACTION_PERCENT m))

(cl:ensure-generic-function 'HEARTBEAT_BSD_ACTION_PERCENT-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_BSD_ACTION_PERCENT-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_BSD_ACTION_PERCENT-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_BSD_ACTION_PERCENT instead.")
  (HEARTBEAT_BSD_ACTION_PERCENT m))

(cl:ensure-generic-function 'HEARTBEAT_GPS_LAT-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_GPS_LAT-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_GPS_LAT-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_GPS_LAT instead.")
  (HEARTBEAT_GPS_LAT m))

(cl:ensure-generic-function 'HEARTBEAT_GPS_LON-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_GPS_LON-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_GPS_LON-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_GPS_LON instead.")
  (HEARTBEAT_GPS_LON m))

(cl:ensure-generic-function 'HEARTBEAT_GPS_ALT-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_GPS_ALT-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_GPS_ALT-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_GPS_ALT instead.")
  (HEARTBEAT_GPS_ALT m))

(cl:ensure-generic-function 'HEARTBEAT_NAV_LAT-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_NAV_LAT-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_NAV_LAT-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_NAV_LAT instead.")
  (HEARTBEAT_NAV_LAT m))

(cl:ensure-generic-function 'HEARTBEAT_NAV_LON-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_NAV_LON-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_NAV_LON-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_NAV_LON instead.")
  (HEARTBEAT_NAV_LON m))

(cl:ensure-generic-function 'HEARTBEAT_NAV_ALT-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_NAV_ALT-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_NAV_ALT-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_NAV_ALT instead.")
  (HEARTBEAT_NAV_ALT m))

(cl:ensure-generic-function 'HEARTBEAT_NAV_YAW_STD-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_NAV_YAW_STD-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_NAV_YAW_STD-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_NAV_YAW_STD instead.")
  (HEARTBEAT_NAV_YAW_STD m))

(cl:ensure-generic-function 'HEARTBEAT_NAV_AVG_POS_ERR-val :lambda-list '(m))
(cl:defmethod HEARTBEAT_NAV_AVG_POS_ERR-val ((m <HeartbeatMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader avl_bsd_translator-msg:HEARTBEAT_NAV_AVG_POS_ERR-val is deprecated.  Use avl_bsd_translator-msg:HEARTBEAT_NAV_AVG_POS_ERR instead.")
  (HEARTBEAT_NAV_AVG_POS_ERR m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HeartbeatMsg>) ostream)
  "Serializes a message object of type '<HeartbeatMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_STATUS)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_UMODEM_SYNC)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_IRIDIUM_STR)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_MISSION_MODE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_FSD_MISSION_STATE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_FSD_CURRENT_ACTION)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_FSD_TOTAL_ACTIONS)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_BSD_MISSION_STATE)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_BSD_CURRENT_ACTION)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_BSD_TOTAL_ACTIONS)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_GPS_SATS)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_NAV_INITIALIZED)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_ROLL))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_PITCH))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_YAW))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_WX))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_WY))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_WZ))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_AX))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_AY))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_AZ))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_VN))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_VE))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_VD))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_DEPTH))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_HEIGHT))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_RPM))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_VOLTAGE))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_FSD_ACTION_PERCENT))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_BSD_ACTION_PERCENT))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_GPS_LAT))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_GPS_LON))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_GPS_ALT))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_NAV_LAT))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_NAV_LON))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_NAV_ALT))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_NAV_YAW_STD))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'HEARTBEAT_NAV_AVG_POS_ERR))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HeartbeatMsg>) istream)
  "Deserializes a message object of type '<HeartbeatMsg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_STATUS)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_UMODEM_SYNC)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_IRIDIUM_STR)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_MISSION_MODE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_FSD_MISSION_STATE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_FSD_CURRENT_ACTION)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_FSD_TOTAL_ACTIONS)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_BSD_MISSION_STATE)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_BSD_CURRENT_ACTION)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_BSD_TOTAL_ACTIONS)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_GPS_SATS)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'HEARTBEAT_NAV_INITIALIZED)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_ROLL) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_PITCH) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_YAW) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_WX) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_WY) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_WZ) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_AX) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_AY) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_AZ) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_VN) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_VE) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_VD) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_DEPTH) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_HEIGHT) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_RPM) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_VOLTAGE) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_FSD_ACTION_PERCENT) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_BSD_ACTION_PERCENT) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_GPS_LAT) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_GPS_LON) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_GPS_ALT) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_NAV_LAT) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_NAV_LON) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_NAV_ALT) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_NAV_YAW_STD) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'HEARTBEAT_NAV_AVG_POS_ERR) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HeartbeatMsg>)))
  "Returns string type for a message object of type '<HeartbeatMsg>"
  "avl_bsd_translator/HeartbeatMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HeartbeatMsg)))
  "Returns string type for a message object of type 'HeartbeatMsg"
  "avl_bsd_translator/HeartbeatMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HeartbeatMsg>)))
  "Returns md5sum for a message object of type '<HeartbeatMsg>"
  "ac1c7d62091790946cc68f56d9855dd5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HeartbeatMsg)))
  "Returns md5sum for a message object of type 'HeartbeatMsg"
  "ac1c7d62091790946cc68f56d9855dd5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HeartbeatMsg>)))
  "Returns full string definition for message of type '<HeartbeatMsg>"
  (cl:format cl:nil "#===============================================================================~%# Autonomous Vehicle Library Backseat Driver~%#~%# Description: Defines a ROS message that contains a heartbeat~%#===============================================================================~%~%~%uint8 HEARTBEAT_STATUS~%uint8 HEARTBEAT_UMODEM_SYNC~%uint8 HEARTBEAT_IRIDIUM_STR~%~%uint8 HEARTBEAT_MISSION_MODE~%uint8 HEARTBEAT_FSD_MISSION_STATE~%uint8 HEARTBEAT_FSD_CURRENT_ACTION~%uint8 HEARTBEAT_FSD_TOTAL_ACTIONS~%uint8 HEARTBEAT_BSD_MISSION_STATE~%uint8 HEARTBEAT_BSD_CURRENT_ACTION~%uint8 HEARTBEAT_BSD_TOTAL_ACTIONS~%uint8 HEARTBEAT_GPS_SATS~%uint8 HEARTBEAT_NAV_INITIALIZED~%~%float64 HEARTBEAT_ROLL~%float64 HEARTBEAT_PITCH~%float64 HEARTBEAT_YAW~%float64 HEARTBEAT_WX~%float64 HEARTBEAT_WY~%float64 HEARTBEAT_WZ~%float64 HEARTBEAT_AX~%float64 HEARTBEAT_AY~%float64 HEARTBEAT_AZ~%float64 HEARTBEAT_VN~%float64 HEARTBEAT_VE~%float64 HEARTBEAT_VD~%float64 HEARTBEAT_DEPTH~%float64 HEARTBEAT_HEIGHT~%float64 HEARTBEAT_RPM~%float64 HEARTBEAT_VOLTAGE~%float64 HEARTBEAT_FSD_ACTION_PERCENT~%float64 HEARTBEAT_BSD_ACTION_PERCENT~%float64 HEARTBEAT_GPS_LAT~%float64 HEARTBEAT_GPS_LON~%float64 HEARTBEAT_GPS_ALT~%float64 HEARTBEAT_NAV_LAT~%float64 HEARTBEAT_NAV_LON~%float64 HEARTBEAT_NAV_ALT~%float64 HEARTBEAT_NAV_YAW_STD~%float64 HEARTBEAT_NAV_AVG_POS_ERR~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HeartbeatMsg)))
  "Returns full string definition for message of type 'HeartbeatMsg"
  (cl:format cl:nil "#===============================================================================~%# Autonomous Vehicle Library Backseat Driver~%#~%# Description: Defines a ROS message that contains a heartbeat~%#===============================================================================~%~%~%uint8 HEARTBEAT_STATUS~%uint8 HEARTBEAT_UMODEM_SYNC~%uint8 HEARTBEAT_IRIDIUM_STR~%~%uint8 HEARTBEAT_MISSION_MODE~%uint8 HEARTBEAT_FSD_MISSION_STATE~%uint8 HEARTBEAT_FSD_CURRENT_ACTION~%uint8 HEARTBEAT_FSD_TOTAL_ACTIONS~%uint8 HEARTBEAT_BSD_MISSION_STATE~%uint8 HEARTBEAT_BSD_CURRENT_ACTION~%uint8 HEARTBEAT_BSD_TOTAL_ACTIONS~%uint8 HEARTBEAT_GPS_SATS~%uint8 HEARTBEAT_NAV_INITIALIZED~%~%float64 HEARTBEAT_ROLL~%float64 HEARTBEAT_PITCH~%float64 HEARTBEAT_YAW~%float64 HEARTBEAT_WX~%float64 HEARTBEAT_WY~%float64 HEARTBEAT_WZ~%float64 HEARTBEAT_AX~%float64 HEARTBEAT_AY~%float64 HEARTBEAT_AZ~%float64 HEARTBEAT_VN~%float64 HEARTBEAT_VE~%float64 HEARTBEAT_VD~%float64 HEARTBEAT_DEPTH~%float64 HEARTBEAT_HEIGHT~%float64 HEARTBEAT_RPM~%float64 HEARTBEAT_VOLTAGE~%float64 HEARTBEAT_FSD_ACTION_PERCENT~%float64 HEARTBEAT_BSD_ACTION_PERCENT~%float64 HEARTBEAT_GPS_LAT~%float64 HEARTBEAT_GPS_LON~%float64 HEARTBEAT_GPS_ALT~%float64 HEARTBEAT_NAV_LAT~%float64 HEARTBEAT_NAV_LON~%float64 HEARTBEAT_NAV_ALT~%float64 HEARTBEAT_NAV_YAW_STD~%float64 HEARTBEAT_NAV_AVG_POS_ERR~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HeartbeatMsg>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
     1
     1
     1
     1
     1
     1
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HeartbeatMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'HeartbeatMsg
    (cl:cons ':HEARTBEAT_STATUS (HEARTBEAT_STATUS msg))
    (cl:cons ':HEARTBEAT_UMODEM_SYNC (HEARTBEAT_UMODEM_SYNC msg))
    (cl:cons ':HEARTBEAT_IRIDIUM_STR (HEARTBEAT_IRIDIUM_STR msg))
    (cl:cons ':HEARTBEAT_MISSION_MODE (HEARTBEAT_MISSION_MODE msg))
    (cl:cons ':HEARTBEAT_FSD_MISSION_STATE (HEARTBEAT_FSD_MISSION_STATE msg))
    (cl:cons ':HEARTBEAT_FSD_CURRENT_ACTION (HEARTBEAT_FSD_CURRENT_ACTION msg))
    (cl:cons ':HEARTBEAT_FSD_TOTAL_ACTIONS (HEARTBEAT_FSD_TOTAL_ACTIONS msg))
    (cl:cons ':HEARTBEAT_BSD_MISSION_STATE (HEARTBEAT_BSD_MISSION_STATE msg))
    (cl:cons ':HEARTBEAT_BSD_CURRENT_ACTION (HEARTBEAT_BSD_CURRENT_ACTION msg))
    (cl:cons ':HEARTBEAT_BSD_TOTAL_ACTIONS (HEARTBEAT_BSD_TOTAL_ACTIONS msg))
    (cl:cons ':HEARTBEAT_GPS_SATS (HEARTBEAT_GPS_SATS msg))
    (cl:cons ':HEARTBEAT_NAV_INITIALIZED (HEARTBEAT_NAV_INITIALIZED msg))
    (cl:cons ':HEARTBEAT_ROLL (HEARTBEAT_ROLL msg))
    (cl:cons ':HEARTBEAT_PITCH (HEARTBEAT_PITCH msg))
    (cl:cons ':HEARTBEAT_YAW (HEARTBEAT_YAW msg))
    (cl:cons ':HEARTBEAT_WX (HEARTBEAT_WX msg))
    (cl:cons ':HEARTBEAT_WY (HEARTBEAT_WY msg))
    (cl:cons ':HEARTBEAT_WZ (HEARTBEAT_WZ msg))
    (cl:cons ':HEARTBEAT_AX (HEARTBEAT_AX msg))
    (cl:cons ':HEARTBEAT_AY (HEARTBEAT_AY msg))
    (cl:cons ':HEARTBEAT_AZ (HEARTBEAT_AZ msg))
    (cl:cons ':HEARTBEAT_VN (HEARTBEAT_VN msg))
    (cl:cons ':HEARTBEAT_VE (HEARTBEAT_VE msg))
    (cl:cons ':HEARTBEAT_VD (HEARTBEAT_VD msg))
    (cl:cons ':HEARTBEAT_DEPTH (HEARTBEAT_DEPTH msg))
    (cl:cons ':HEARTBEAT_HEIGHT (HEARTBEAT_HEIGHT msg))
    (cl:cons ':HEARTBEAT_RPM (HEARTBEAT_RPM msg))
    (cl:cons ':HEARTBEAT_VOLTAGE (HEARTBEAT_VOLTAGE msg))
    (cl:cons ':HEARTBEAT_FSD_ACTION_PERCENT (HEARTBEAT_FSD_ACTION_PERCENT msg))
    (cl:cons ':HEARTBEAT_BSD_ACTION_PERCENT (HEARTBEAT_BSD_ACTION_PERCENT msg))
    (cl:cons ':HEARTBEAT_GPS_LAT (HEARTBEAT_GPS_LAT msg))
    (cl:cons ':HEARTBEAT_GPS_LON (HEARTBEAT_GPS_LON msg))
    (cl:cons ':HEARTBEAT_GPS_ALT (HEARTBEAT_GPS_ALT msg))
    (cl:cons ':HEARTBEAT_NAV_LAT (HEARTBEAT_NAV_LAT msg))
    (cl:cons ':HEARTBEAT_NAV_LON (HEARTBEAT_NAV_LON msg))
    (cl:cons ':HEARTBEAT_NAV_ALT (HEARTBEAT_NAV_ALT msg))
    (cl:cons ':HEARTBEAT_NAV_YAW_STD (HEARTBEAT_NAV_YAW_STD msg))
    (cl:cons ':HEARTBEAT_NAV_AVG_POS_ERR (HEARTBEAT_NAV_AVG_POS_ERR msg))
))
