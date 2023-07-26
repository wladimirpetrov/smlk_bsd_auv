;; Auto-generated. Do not edit!


(when (boundp 'avl_bsd_translator::HeartbeatMsg)
  (if (not (find-package "AVL_BSD_TRANSLATOR"))
    (make-package "AVL_BSD_TRANSLATOR"))
  (shadow 'HeartbeatMsg (find-package "AVL_BSD_TRANSLATOR")))
(unless (find-package "AVL_BSD_TRANSLATOR::HEARTBEATMSG")
  (make-package "AVL_BSD_TRANSLATOR::HEARTBEATMSG"))

(in-package "ROS")
;;//! \htmlinclude HeartbeatMsg.msg.html


(defclass avl_bsd_translator::HeartbeatMsg
  :super ros::object
  :slots (_HEARTBEAT_STATUS _HEARTBEAT_UMODEM_SYNC _HEARTBEAT_IRIDIUM_STR _HEARTBEAT_MISSION_MODE _HEARTBEAT_FSD_MISSION_STATE _HEARTBEAT_FSD_CURRENT_ACTION _HEARTBEAT_FSD_TOTAL_ACTIONS _HEARTBEAT_BSD_MISSION_STATE _HEARTBEAT_BSD_CURRENT_ACTION _HEARTBEAT_BSD_TOTAL_ACTIONS _HEARTBEAT_GPS_SATS _HEARTBEAT_NAV_INITIALIZED _HEARTBEAT_ROLL _HEARTBEAT_PITCH _HEARTBEAT_YAW _HEARTBEAT_WX _HEARTBEAT_WY _HEARTBEAT_WZ _HEARTBEAT_AX _HEARTBEAT_AY _HEARTBEAT_AZ _HEARTBEAT_VN _HEARTBEAT_VE _HEARTBEAT_VD _HEARTBEAT_DEPTH _HEARTBEAT_HEIGHT _HEARTBEAT_RPM _HEARTBEAT_VOLTAGE _HEARTBEAT_FSD_ACTION_PERCENT _HEARTBEAT_BSD_ACTION_PERCENT _HEARTBEAT_GPS_LAT _HEARTBEAT_GPS_LON _HEARTBEAT_GPS_ALT _HEARTBEAT_NAV_LAT _HEARTBEAT_NAV_LON _HEARTBEAT_NAV_ALT _HEARTBEAT_NAV_YAW_STD _HEARTBEAT_NAV_AVG_POS_ERR ))

(defmethod avl_bsd_translator::HeartbeatMsg
  (:init
   (&key
    ((:HEARTBEAT_STATUS __HEARTBEAT_STATUS) 0)
    ((:HEARTBEAT_UMODEM_SYNC __HEARTBEAT_UMODEM_SYNC) 0)
    ((:HEARTBEAT_IRIDIUM_STR __HEARTBEAT_IRIDIUM_STR) 0)
    ((:HEARTBEAT_MISSION_MODE __HEARTBEAT_MISSION_MODE) 0)
    ((:HEARTBEAT_FSD_MISSION_STATE __HEARTBEAT_FSD_MISSION_STATE) 0)
    ((:HEARTBEAT_FSD_CURRENT_ACTION __HEARTBEAT_FSD_CURRENT_ACTION) 0)
    ((:HEARTBEAT_FSD_TOTAL_ACTIONS __HEARTBEAT_FSD_TOTAL_ACTIONS) 0)
    ((:HEARTBEAT_BSD_MISSION_STATE __HEARTBEAT_BSD_MISSION_STATE) 0)
    ((:HEARTBEAT_BSD_CURRENT_ACTION __HEARTBEAT_BSD_CURRENT_ACTION) 0)
    ((:HEARTBEAT_BSD_TOTAL_ACTIONS __HEARTBEAT_BSD_TOTAL_ACTIONS) 0)
    ((:HEARTBEAT_GPS_SATS __HEARTBEAT_GPS_SATS) 0)
    ((:HEARTBEAT_NAV_INITIALIZED __HEARTBEAT_NAV_INITIALIZED) 0)
    ((:HEARTBEAT_ROLL __HEARTBEAT_ROLL) 0.0)
    ((:HEARTBEAT_PITCH __HEARTBEAT_PITCH) 0.0)
    ((:HEARTBEAT_YAW __HEARTBEAT_YAW) 0.0)
    ((:HEARTBEAT_WX __HEARTBEAT_WX) 0.0)
    ((:HEARTBEAT_WY __HEARTBEAT_WY) 0.0)
    ((:HEARTBEAT_WZ __HEARTBEAT_WZ) 0.0)
    ((:HEARTBEAT_AX __HEARTBEAT_AX) 0.0)
    ((:HEARTBEAT_AY __HEARTBEAT_AY) 0.0)
    ((:HEARTBEAT_AZ __HEARTBEAT_AZ) 0.0)
    ((:HEARTBEAT_VN __HEARTBEAT_VN) 0.0)
    ((:HEARTBEAT_VE __HEARTBEAT_VE) 0.0)
    ((:HEARTBEAT_VD __HEARTBEAT_VD) 0.0)
    ((:HEARTBEAT_DEPTH __HEARTBEAT_DEPTH) 0.0)
    ((:HEARTBEAT_HEIGHT __HEARTBEAT_HEIGHT) 0.0)
    ((:HEARTBEAT_RPM __HEARTBEAT_RPM) 0.0)
    ((:HEARTBEAT_VOLTAGE __HEARTBEAT_VOLTAGE) 0.0)
    ((:HEARTBEAT_FSD_ACTION_PERCENT __HEARTBEAT_FSD_ACTION_PERCENT) 0.0)
    ((:HEARTBEAT_BSD_ACTION_PERCENT __HEARTBEAT_BSD_ACTION_PERCENT) 0.0)
    ((:HEARTBEAT_GPS_LAT __HEARTBEAT_GPS_LAT) 0.0)
    ((:HEARTBEAT_GPS_LON __HEARTBEAT_GPS_LON) 0.0)
    ((:HEARTBEAT_GPS_ALT __HEARTBEAT_GPS_ALT) 0.0)
    ((:HEARTBEAT_NAV_LAT __HEARTBEAT_NAV_LAT) 0.0)
    ((:HEARTBEAT_NAV_LON __HEARTBEAT_NAV_LON) 0.0)
    ((:HEARTBEAT_NAV_ALT __HEARTBEAT_NAV_ALT) 0.0)
    ((:HEARTBEAT_NAV_YAW_STD __HEARTBEAT_NAV_YAW_STD) 0.0)
    ((:HEARTBEAT_NAV_AVG_POS_ERR __HEARTBEAT_NAV_AVG_POS_ERR) 0.0)
    )
   (send-super :init)
   (setq _HEARTBEAT_STATUS (round __HEARTBEAT_STATUS))
   (setq _HEARTBEAT_UMODEM_SYNC (round __HEARTBEAT_UMODEM_SYNC))
   (setq _HEARTBEAT_IRIDIUM_STR (round __HEARTBEAT_IRIDIUM_STR))
   (setq _HEARTBEAT_MISSION_MODE (round __HEARTBEAT_MISSION_MODE))
   (setq _HEARTBEAT_FSD_MISSION_STATE (round __HEARTBEAT_FSD_MISSION_STATE))
   (setq _HEARTBEAT_FSD_CURRENT_ACTION (round __HEARTBEAT_FSD_CURRENT_ACTION))
   (setq _HEARTBEAT_FSD_TOTAL_ACTIONS (round __HEARTBEAT_FSD_TOTAL_ACTIONS))
   (setq _HEARTBEAT_BSD_MISSION_STATE (round __HEARTBEAT_BSD_MISSION_STATE))
   (setq _HEARTBEAT_BSD_CURRENT_ACTION (round __HEARTBEAT_BSD_CURRENT_ACTION))
   (setq _HEARTBEAT_BSD_TOTAL_ACTIONS (round __HEARTBEAT_BSD_TOTAL_ACTIONS))
   (setq _HEARTBEAT_GPS_SATS (round __HEARTBEAT_GPS_SATS))
   (setq _HEARTBEAT_NAV_INITIALIZED (round __HEARTBEAT_NAV_INITIALIZED))
   (setq _HEARTBEAT_ROLL (float __HEARTBEAT_ROLL))
   (setq _HEARTBEAT_PITCH (float __HEARTBEAT_PITCH))
   (setq _HEARTBEAT_YAW (float __HEARTBEAT_YAW))
   (setq _HEARTBEAT_WX (float __HEARTBEAT_WX))
   (setq _HEARTBEAT_WY (float __HEARTBEAT_WY))
   (setq _HEARTBEAT_WZ (float __HEARTBEAT_WZ))
   (setq _HEARTBEAT_AX (float __HEARTBEAT_AX))
   (setq _HEARTBEAT_AY (float __HEARTBEAT_AY))
   (setq _HEARTBEAT_AZ (float __HEARTBEAT_AZ))
   (setq _HEARTBEAT_VN (float __HEARTBEAT_VN))
   (setq _HEARTBEAT_VE (float __HEARTBEAT_VE))
   (setq _HEARTBEAT_VD (float __HEARTBEAT_VD))
   (setq _HEARTBEAT_DEPTH (float __HEARTBEAT_DEPTH))
   (setq _HEARTBEAT_HEIGHT (float __HEARTBEAT_HEIGHT))
   (setq _HEARTBEAT_RPM (float __HEARTBEAT_RPM))
   (setq _HEARTBEAT_VOLTAGE (float __HEARTBEAT_VOLTAGE))
   (setq _HEARTBEAT_FSD_ACTION_PERCENT (float __HEARTBEAT_FSD_ACTION_PERCENT))
   (setq _HEARTBEAT_BSD_ACTION_PERCENT (float __HEARTBEAT_BSD_ACTION_PERCENT))
   (setq _HEARTBEAT_GPS_LAT (float __HEARTBEAT_GPS_LAT))
   (setq _HEARTBEAT_GPS_LON (float __HEARTBEAT_GPS_LON))
   (setq _HEARTBEAT_GPS_ALT (float __HEARTBEAT_GPS_ALT))
   (setq _HEARTBEAT_NAV_LAT (float __HEARTBEAT_NAV_LAT))
   (setq _HEARTBEAT_NAV_LON (float __HEARTBEAT_NAV_LON))
   (setq _HEARTBEAT_NAV_ALT (float __HEARTBEAT_NAV_ALT))
   (setq _HEARTBEAT_NAV_YAW_STD (float __HEARTBEAT_NAV_YAW_STD))
   (setq _HEARTBEAT_NAV_AVG_POS_ERR (float __HEARTBEAT_NAV_AVG_POS_ERR))
   self)
  (:HEARTBEAT_STATUS
   (&optional __HEARTBEAT_STATUS)
   (if __HEARTBEAT_STATUS (setq _HEARTBEAT_STATUS __HEARTBEAT_STATUS)) _HEARTBEAT_STATUS)
  (:HEARTBEAT_UMODEM_SYNC
   (&optional __HEARTBEAT_UMODEM_SYNC)
   (if __HEARTBEAT_UMODEM_SYNC (setq _HEARTBEAT_UMODEM_SYNC __HEARTBEAT_UMODEM_SYNC)) _HEARTBEAT_UMODEM_SYNC)
  (:HEARTBEAT_IRIDIUM_STR
   (&optional __HEARTBEAT_IRIDIUM_STR)
   (if __HEARTBEAT_IRIDIUM_STR (setq _HEARTBEAT_IRIDIUM_STR __HEARTBEAT_IRIDIUM_STR)) _HEARTBEAT_IRIDIUM_STR)
  (:HEARTBEAT_MISSION_MODE
   (&optional __HEARTBEAT_MISSION_MODE)
   (if __HEARTBEAT_MISSION_MODE (setq _HEARTBEAT_MISSION_MODE __HEARTBEAT_MISSION_MODE)) _HEARTBEAT_MISSION_MODE)
  (:HEARTBEAT_FSD_MISSION_STATE
   (&optional __HEARTBEAT_FSD_MISSION_STATE)
   (if __HEARTBEAT_FSD_MISSION_STATE (setq _HEARTBEAT_FSD_MISSION_STATE __HEARTBEAT_FSD_MISSION_STATE)) _HEARTBEAT_FSD_MISSION_STATE)
  (:HEARTBEAT_FSD_CURRENT_ACTION
   (&optional __HEARTBEAT_FSD_CURRENT_ACTION)
   (if __HEARTBEAT_FSD_CURRENT_ACTION (setq _HEARTBEAT_FSD_CURRENT_ACTION __HEARTBEAT_FSD_CURRENT_ACTION)) _HEARTBEAT_FSD_CURRENT_ACTION)
  (:HEARTBEAT_FSD_TOTAL_ACTIONS
   (&optional __HEARTBEAT_FSD_TOTAL_ACTIONS)
   (if __HEARTBEAT_FSD_TOTAL_ACTIONS (setq _HEARTBEAT_FSD_TOTAL_ACTIONS __HEARTBEAT_FSD_TOTAL_ACTIONS)) _HEARTBEAT_FSD_TOTAL_ACTIONS)
  (:HEARTBEAT_BSD_MISSION_STATE
   (&optional __HEARTBEAT_BSD_MISSION_STATE)
   (if __HEARTBEAT_BSD_MISSION_STATE (setq _HEARTBEAT_BSD_MISSION_STATE __HEARTBEAT_BSD_MISSION_STATE)) _HEARTBEAT_BSD_MISSION_STATE)
  (:HEARTBEAT_BSD_CURRENT_ACTION
   (&optional __HEARTBEAT_BSD_CURRENT_ACTION)
   (if __HEARTBEAT_BSD_CURRENT_ACTION (setq _HEARTBEAT_BSD_CURRENT_ACTION __HEARTBEAT_BSD_CURRENT_ACTION)) _HEARTBEAT_BSD_CURRENT_ACTION)
  (:HEARTBEAT_BSD_TOTAL_ACTIONS
   (&optional __HEARTBEAT_BSD_TOTAL_ACTIONS)
   (if __HEARTBEAT_BSD_TOTAL_ACTIONS (setq _HEARTBEAT_BSD_TOTAL_ACTIONS __HEARTBEAT_BSD_TOTAL_ACTIONS)) _HEARTBEAT_BSD_TOTAL_ACTIONS)
  (:HEARTBEAT_GPS_SATS
   (&optional __HEARTBEAT_GPS_SATS)
   (if __HEARTBEAT_GPS_SATS (setq _HEARTBEAT_GPS_SATS __HEARTBEAT_GPS_SATS)) _HEARTBEAT_GPS_SATS)
  (:HEARTBEAT_NAV_INITIALIZED
   (&optional __HEARTBEAT_NAV_INITIALIZED)
   (if __HEARTBEAT_NAV_INITIALIZED (setq _HEARTBEAT_NAV_INITIALIZED __HEARTBEAT_NAV_INITIALIZED)) _HEARTBEAT_NAV_INITIALIZED)
  (:HEARTBEAT_ROLL
   (&optional __HEARTBEAT_ROLL)
   (if __HEARTBEAT_ROLL (setq _HEARTBEAT_ROLL __HEARTBEAT_ROLL)) _HEARTBEAT_ROLL)
  (:HEARTBEAT_PITCH
   (&optional __HEARTBEAT_PITCH)
   (if __HEARTBEAT_PITCH (setq _HEARTBEAT_PITCH __HEARTBEAT_PITCH)) _HEARTBEAT_PITCH)
  (:HEARTBEAT_YAW
   (&optional __HEARTBEAT_YAW)
   (if __HEARTBEAT_YAW (setq _HEARTBEAT_YAW __HEARTBEAT_YAW)) _HEARTBEAT_YAW)
  (:HEARTBEAT_WX
   (&optional __HEARTBEAT_WX)
   (if __HEARTBEAT_WX (setq _HEARTBEAT_WX __HEARTBEAT_WX)) _HEARTBEAT_WX)
  (:HEARTBEAT_WY
   (&optional __HEARTBEAT_WY)
   (if __HEARTBEAT_WY (setq _HEARTBEAT_WY __HEARTBEAT_WY)) _HEARTBEAT_WY)
  (:HEARTBEAT_WZ
   (&optional __HEARTBEAT_WZ)
   (if __HEARTBEAT_WZ (setq _HEARTBEAT_WZ __HEARTBEAT_WZ)) _HEARTBEAT_WZ)
  (:HEARTBEAT_AX
   (&optional __HEARTBEAT_AX)
   (if __HEARTBEAT_AX (setq _HEARTBEAT_AX __HEARTBEAT_AX)) _HEARTBEAT_AX)
  (:HEARTBEAT_AY
   (&optional __HEARTBEAT_AY)
   (if __HEARTBEAT_AY (setq _HEARTBEAT_AY __HEARTBEAT_AY)) _HEARTBEAT_AY)
  (:HEARTBEAT_AZ
   (&optional __HEARTBEAT_AZ)
   (if __HEARTBEAT_AZ (setq _HEARTBEAT_AZ __HEARTBEAT_AZ)) _HEARTBEAT_AZ)
  (:HEARTBEAT_VN
   (&optional __HEARTBEAT_VN)
   (if __HEARTBEAT_VN (setq _HEARTBEAT_VN __HEARTBEAT_VN)) _HEARTBEAT_VN)
  (:HEARTBEAT_VE
   (&optional __HEARTBEAT_VE)
   (if __HEARTBEAT_VE (setq _HEARTBEAT_VE __HEARTBEAT_VE)) _HEARTBEAT_VE)
  (:HEARTBEAT_VD
   (&optional __HEARTBEAT_VD)
   (if __HEARTBEAT_VD (setq _HEARTBEAT_VD __HEARTBEAT_VD)) _HEARTBEAT_VD)
  (:HEARTBEAT_DEPTH
   (&optional __HEARTBEAT_DEPTH)
   (if __HEARTBEAT_DEPTH (setq _HEARTBEAT_DEPTH __HEARTBEAT_DEPTH)) _HEARTBEAT_DEPTH)
  (:HEARTBEAT_HEIGHT
   (&optional __HEARTBEAT_HEIGHT)
   (if __HEARTBEAT_HEIGHT (setq _HEARTBEAT_HEIGHT __HEARTBEAT_HEIGHT)) _HEARTBEAT_HEIGHT)
  (:HEARTBEAT_RPM
   (&optional __HEARTBEAT_RPM)
   (if __HEARTBEAT_RPM (setq _HEARTBEAT_RPM __HEARTBEAT_RPM)) _HEARTBEAT_RPM)
  (:HEARTBEAT_VOLTAGE
   (&optional __HEARTBEAT_VOLTAGE)
   (if __HEARTBEAT_VOLTAGE (setq _HEARTBEAT_VOLTAGE __HEARTBEAT_VOLTAGE)) _HEARTBEAT_VOLTAGE)
  (:HEARTBEAT_FSD_ACTION_PERCENT
   (&optional __HEARTBEAT_FSD_ACTION_PERCENT)
   (if __HEARTBEAT_FSD_ACTION_PERCENT (setq _HEARTBEAT_FSD_ACTION_PERCENT __HEARTBEAT_FSD_ACTION_PERCENT)) _HEARTBEAT_FSD_ACTION_PERCENT)
  (:HEARTBEAT_BSD_ACTION_PERCENT
   (&optional __HEARTBEAT_BSD_ACTION_PERCENT)
   (if __HEARTBEAT_BSD_ACTION_PERCENT (setq _HEARTBEAT_BSD_ACTION_PERCENT __HEARTBEAT_BSD_ACTION_PERCENT)) _HEARTBEAT_BSD_ACTION_PERCENT)
  (:HEARTBEAT_GPS_LAT
   (&optional __HEARTBEAT_GPS_LAT)
   (if __HEARTBEAT_GPS_LAT (setq _HEARTBEAT_GPS_LAT __HEARTBEAT_GPS_LAT)) _HEARTBEAT_GPS_LAT)
  (:HEARTBEAT_GPS_LON
   (&optional __HEARTBEAT_GPS_LON)
   (if __HEARTBEAT_GPS_LON (setq _HEARTBEAT_GPS_LON __HEARTBEAT_GPS_LON)) _HEARTBEAT_GPS_LON)
  (:HEARTBEAT_GPS_ALT
   (&optional __HEARTBEAT_GPS_ALT)
   (if __HEARTBEAT_GPS_ALT (setq _HEARTBEAT_GPS_ALT __HEARTBEAT_GPS_ALT)) _HEARTBEAT_GPS_ALT)
  (:HEARTBEAT_NAV_LAT
   (&optional __HEARTBEAT_NAV_LAT)
   (if __HEARTBEAT_NAV_LAT (setq _HEARTBEAT_NAV_LAT __HEARTBEAT_NAV_LAT)) _HEARTBEAT_NAV_LAT)
  (:HEARTBEAT_NAV_LON
   (&optional __HEARTBEAT_NAV_LON)
   (if __HEARTBEAT_NAV_LON (setq _HEARTBEAT_NAV_LON __HEARTBEAT_NAV_LON)) _HEARTBEAT_NAV_LON)
  (:HEARTBEAT_NAV_ALT
   (&optional __HEARTBEAT_NAV_ALT)
   (if __HEARTBEAT_NAV_ALT (setq _HEARTBEAT_NAV_ALT __HEARTBEAT_NAV_ALT)) _HEARTBEAT_NAV_ALT)
  (:HEARTBEAT_NAV_YAW_STD
   (&optional __HEARTBEAT_NAV_YAW_STD)
   (if __HEARTBEAT_NAV_YAW_STD (setq _HEARTBEAT_NAV_YAW_STD __HEARTBEAT_NAV_YAW_STD)) _HEARTBEAT_NAV_YAW_STD)
  (:HEARTBEAT_NAV_AVG_POS_ERR
   (&optional __HEARTBEAT_NAV_AVG_POS_ERR)
   (if __HEARTBEAT_NAV_AVG_POS_ERR (setq _HEARTBEAT_NAV_AVG_POS_ERR __HEARTBEAT_NAV_AVG_POS_ERR)) _HEARTBEAT_NAV_AVG_POS_ERR)
  (:serialization-length
   ()
   (+
    ;; uint8 _HEARTBEAT_STATUS
    1
    ;; uint8 _HEARTBEAT_UMODEM_SYNC
    1
    ;; uint8 _HEARTBEAT_IRIDIUM_STR
    1
    ;; uint8 _HEARTBEAT_MISSION_MODE
    1
    ;; uint8 _HEARTBEAT_FSD_MISSION_STATE
    1
    ;; uint8 _HEARTBEAT_FSD_CURRENT_ACTION
    1
    ;; uint8 _HEARTBEAT_FSD_TOTAL_ACTIONS
    1
    ;; uint8 _HEARTBEAT_BSD_MISSION_STATE
    1
    ;; uint8 _HEARTBEAT_BSD_CURRENT_ACTION
    1
    ;; uint8 _HEARTBEAT_BSD_TOTAL_ACTIONS
    1
    ;; uint8 _HEARTBEAT_GPS_SATS
    1
    ;; uint8 _HEARTBEAT_NAV_INITIALIZED
    1
    ;; float64 _HEARTBEAT_ROLL
    8
    ;; float64 _HEARTBEAT_PITCH
    8
    ;; float64 _HEARTBEAT_YAW
    8
    ;; float64 _HEARTBEAT_WX
    8
    ;; float64 _HEARTBEAT_WY
    8
    ;; float64 _HEARTBEAT_WZ
    8
    ;; float64 _HEARTBEAT_AX
    8
    ;; float64 _HEARTBEAT_AY
    8
    ;; float64 _HEARTBEAT_AZ
    8
    ;; float64 _HEARTBEAT_VN
    8
    ;; float64 _HEARTBEAT_VE
    8
    ;; float64 _HEARTBEAT_VD
    8
    ;; float64 _HEARTBEAT_DEPTH
    8
    ;; float64 _HEARTBEAT_HEIGHT
    8
    ;; float64 _HEARTBEAT_RPM
    8
    ;; float64 _HEARTBEAT_VOLTAGE
    8
    ;; float64 _HEARTBEAT_FSD_ACTION_PERCENT
    8
    ;; float64 _HEARTBEAT_BSD_ACTION_PERCENT
    8
    ;; float64 _HEARTBEAT_GPS_LAT
    8
    ;; float64 _HEARTBEAT_GPS_LON
    8
    ;; float64 _HEARTBEAT_GPS_ALT
    8
    ;; float64 _HEARTBEAT_NAV_LAT
    8
    ;; float64 _HEARTBEAT_NAV_LON
    8
    ;; float64 _HEARTBEAT_NAV_ALT
    8
    ;; float64 _HEARTBEAT_NAV_YAW_STD
    8
    ;; float64 _HEARTBEAT_NAV_AVG_POS_ERR
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _HEARTBEAT_STATUS
       (write-byte _HEARTBEAT_STATUS s)
     ;; uint8 _HEARTBEAT_UMODEM_SYNC
       (write-byte _HEARTBEAT_UMODEM_SYNC s)
     ;; uint8 _HEARTBEAT_IRIDIUM_STR
       (write-byte _HEARTBEAT_IRIDIUM_STR s)
     ;; uint8 _HEARTBEAT_MISSION_MODE
       (write-byte _HEARTBEAT_MISSION_MODE s)
     ;; uint8 _HEARTBEAT_FSD_MISSION_STATE
       (write-byte _HEARTBEAT_FSD_MISSION_STATE s)
     ;; uint8 _HEARTBEAT_FSD_CURRENT_ACTION
       (write-byte _HEARTBEAT_FSD_CURRENT_ACTION s)
     ;; uint8 _HEARTBEAT_FSD_TOTAL_ACTIONS
       (write-byte _HEARTBEAT_FSD_TOTAL_ACTIONS s)
     ;; uint8 _HEARTBEAT_BSD_MISSION_STATE
       (write-byte _HEARTBEAT_BSD_MISSION_STATE s)
     ;; uint8 _HEARTBEAT_BSD_CURRENT_ACTION
       (write-byte _HEARTBEAT_BSD_CURRENT_ACTION s)
     ;; uint8 _HEARTBEAT_BSD_TOTAL_ACTIONS
       (write-byte _HEARTBEAT_BSD_TOTAL_ACTIONS s)
     ;; uint8 _HEARTBEAT_GPS_SATS
       (write-byte _HEARTBEAT_GPS_SATS s)
     ;; uint8 _HEARTBEAT_NAV_INITIALIZED
       (write-byte _HEARTBEAT_NAV_INITIALIZED s)
     ;; float64 _HEARTBEAT_ROLL
       (sys::poke _HEARTBEAT_ROLL (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_PITCH
       (sys::poke _HEARTBEAT_PITCH (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_YAW
       (sys::poke _HEARTBEAT_YAW (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_WX
       (sys::poke _HEARTBEAT_WX (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_WY
       (sys::poke _HEARTBEAT_WY (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_WZ
       (sys::poke _HEARTBEAT_WZ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_AX
       (sys::poke _HEARTBEAT_AX (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_AY
       (sys::poke _HEARTBEAT_AY (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_AZ
       (sys::poke _HEARTBEAT_AZ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_VN
       (sys::poke _HEARTBEAT_VN (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_VE
       (sys::poke _HEARTBEAT_VE (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_VD
       (sys::poke _HEARTBEAT_VD (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_DEPTH
       (sys::poke _HEARTBEAT_DEPTH (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_HEIGHT
       (sys::poke _HEARTBEAT_HEIGHT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_RPM
       (sys::poke _HEARTBEAT_RPM (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_VOLTAGE
       (sys::poke _HEARTBEAT_VOLTAGE (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_FSD_ACTION_PERCENT
       (sys::poke _HEARTBEAT_FSD_ACTION_PERCENT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_BSD_ACTION_PERCENT
       (sys::poke _HEARTBEAT_BSD_ACTION_PERCENT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_GPS_LAT
       (sys::poke _HEARTBEAT_GPS_LAT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_GPS_LON
       (sys::poke _HEARTBEAT_GPS_LON (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_GPS_ALT
       (sys::poke _HEARTBEAT_GPS_ALT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_NAV_LAT
       (sys::poke _HEARTBEAT_NAV_LAT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_NAV_LON
       (sys::poke _HEARTBEAT_NAV_LON (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_NAV_ALT
       (sys::poke _HEARTBEAT_NAV_ALT (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_NAV_YAW_STD
       (sys::poke _HEARTBEAT_NAV_YAW_STD (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _HEARTBEAT_NAV_AVG_POS_ERR
       (sys::poke _HEARTBEAT_NAV_AVG_POS_ERR (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _HEARTBEAT_STATUS
     (setq _HEARTBEAT_STATUS (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_UMODEM_SYNC
     (setq _HEARTBEAT_UMODEM_SYNC (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_IRIDIUM_STR
     (setq _HEARTBEAT_IRIDIUM_STR (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_MISSION_MODE
     (setq _HEARTBEAT_MISSION_MODE (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_FSD_MISSION_STATE
     (setq _HEARTBEAT_FSD_MISSION_STATE (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_FSD_CURRENT_ACTION
     (setq _HEARTBEAT_FSD_CURRENT_ACTION (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_FSD_TOTAL_ACTIONS
     (setq _HEARTBEAT_FSD_TOTAL_ACTIONS (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_BSD_MISSION_STATE
     (setq _HEARTBEAT_BSD_MISSION_STATE (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_BSD_CURRENT_ACTION
     (setq _HEARTBEAT_BSD_CURRENT_ACTION (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_BSD_TOTAL_ACTIONS
     (setq _HEARTBEAT_BSD_TOTAL_ACTIONS (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_GPS_SATS
     (setq _HEARTBEAT_GPS_SATS (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _HEARTBEAT_NAV_INITIALIZED
     (setq _HEARTBEAT_NAV_INITIALIZED (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _HEARTBEAT_ROLL
     (setq _HEARTBEAT_ROLL (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_PITCH
     (setq _HEARTBEAT_PITCH (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_YAW
     (setq _HEARTBEAT_YAW (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_WX
     (setq _HEARTBEAT_WX (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_WY
     (setq _HEARTBEAT_WY (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_WZ
     (setq _HEARTBEAT_WZ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_AX
     (setq _HEARTBEAT_AX (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_AY
     (setq _HEARTBEAT_AY (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_AZ
     (setq _HEARTBEAT_AZ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_VN
     (setq _HEARTBEAT_VN (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_VE
     (setq _HEARTBEAT_VE (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_VD
     (setq _HEARTBEAT_VD (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_DEPTH
     (setq _HEARTBEAT_DEPTH (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_HEIGHT
     (setq _HEARTBEAT_HEIGHT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_RPM
     (setq _HEARTBEAT_RPM (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_VOLTAGE
     (setq _HEARTBEAT_VOLTAGE (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_FSD_ACTION_PERCENT
     (setq _HEARTBEAT_FSD_ACTION_PERCENT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_BSD_ACTION_PERCENT
     (setq _HEARTBEAT_BSD_ACTION_PERCENT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_GPS_LAT
     (setq _HEARTBEAT_GPS_LAT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_GPS_LON
     (setq _HEARTBEAT_GPS_LON (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_GPS_ALT
     (setq _HEARTBEAT_GPS_ALT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_NAV_LAT
     (setq _HEARTBEAT_NAV_LAT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_NAV_LON
     (setq _HEARTBEAT_NAV_LON (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_NAV_ALT
     (setq _HEARTBEAT_NAV_ALT (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_NAV_YAW_STD
     (setq _HEARTBEAT_NAV_YAW_STD (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _HEARTBEAT_NAV_AVG_POS_ERR
     (setq _HEARTBEAT_NAV_AVG_POS_ERR (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get avl_bsd_translator::HeartbeatMsg :md5sum-) "ac1c7d62091790946cc68f56d9855dd5")
(setf (get avl_bsd_translator::HeartbeatMsg :datatype-) "avl_bsd_translator/HeartbeatMsg")
(setf (get avl_bsd_translator::HeartbeatMsg :definition-)
      "#===============================================================================
# Autonomous Vehicle Library Backseat Driver
#
# Description: Defines a ROS message that contains a heartbeat
#===============================================================================


uint8 HEARTBEAT_STATUS
uint8 HEARTBEAT_UMODEM_SYNC
uint8 HEARTBEAT_IRIDIUM_STR

uint8 HEARTBEAT_MISSION_MODE
uint8 HEARTBEAT_FSD_MISSION_STATE
uint8 HEARTBEAT_FSD_CURRENT_ACTION
uint8 HEARTBEAT_FSD_TOTAL_ACTIONS
uint8 HEARTBEAT_BSD_MISSION_STATE
uint8 HEARTBEAT_BSD_CURRENT_ACTION
uint8 HEARTBEAT_BSD_TOTAL_ACTIONS
uint8 HEARTBEAT_GPS_SATS
uint8 HEARTBEAT_NAV_INITIALIZED

float64 HEARTBEAT_ROLL
float64 HEARTBEAT_PITCH
float64 HEARTBEAT_YAW
float64 HEARTBEAT_WX
float64 HEARTBEAT_WY
float64 HEARTBEAT_WZ
float64 HEARTBEAT_AX
float64 HEARTBEAT_AY
float64 HEARTBEAT_AZ
float64 HEARTBEAT_VN
float64 HEARTBEAT_VE
float64 HEARTBEAT_VD
float64 HEARTBEAT_DEPTH
float64 HEARTBEAT_HEIGHT
float64 HEARTBEAT_RPM
float64 HEARTBEAT_VOLTAGE
float64 HEARTBEAT_FSD_ACTION_PERCENT
float64 HEARTBEAT_BSD_ACTION_PERCENT
float64 HEARTBEAT_GPS_LAT
float64 HEARTBEAT_GPS_LON
float64 HEARTBEAT_GPS_ALT
float64 HEARTBEAT_NAV_LAT
float64 HEARTBEAT_NAV_LON
float64 HEARTBEAT_NAV_ALT
float64 HEARTBEAT_NAV_YAW_STD
float64 HEARTBEAT_NAV_AVG_POS_ERR

")



(provide :avl_bsd_translator/HeartbeatMsg "ac1c7d62091790946cc68f56d9855dd5")


