;; Auto-generated. Do not edit!


(when (boundp 'avl_bsd_translator::PassthroughMsg)
  (if (not (find-package "AVL_BSD_TRANSLATOR"))
    (make-package "AVL_BSD_TRANSLATOR"))
  (shadow 'PassthroughMsg (find-package "AVL_BSD_TRANSLATOR")))
(unless (find-package "AVL_BSD_TRANSLATOR::PASSTHROUGHMSG")
  (make-package "AVL_BSD_TRANSLATOR::PASSTHROUGHMSG"))

(in-package "ROS")
;;//! \htmlinclude PassthroughMsg.msg.html


(defclass avl_bsd_translator::PassthroughMsg
  :super ros::object
  :slots (_ORIGIN_ID _TARGET_ID _CHANNEL _INTERFACE _DATA ))

(defmethod avl_bsd_translator::PassthroughMsg
  (:init
   (&key
    ((:ORIGIN_ID __ORIGIN_ID) 0)
    ((:TARGET_ID __TARGET_ID) 0)
    ((:CHANNEL __CHANNEL) 0)
    ((:INTERFACE __INTERFACE) 0)
    ((:DATA __DATA) "")
    )
   (send-super :init)
   (setq _ORIGIN_ID (round __ORIGIN_ID))
   (setq _TARGET_ID (round __TARGET_ID))
   (setq _CHANNEL (round __CHANNEL))
   (setq _INTERFACE (round __INTERFACE))
   (setq _DATA (string __DATA))
   self)
  (:ORIGIN_ID
   (&optional __ORIGIN_ID)
   (if __ORIGIN_ID (setq _ORIGIN_ID __ORIGIN_ID)) _ORIGIN_ID)
  (:TARGET_ID
   (&optional __TARGET_ID)
   (if __TARGET_ID (setq _TARGET_ID __TARGET_ID)) _TARGET_ID)
  (:CHANNEL
   (&optional __CHANNEL)
   (if __CHANNEL (setq _CHANNEL __CHANNEL)) _CHANNEL)
  (:INTERFACE
   (&optional __INTERFACE)
   (if __INTERFACE (setq _INTERFACE __INTERFACE)) _INTERFACE)
  (:DATA
   (&optional __DATA)
   (if __DATA (setq _DATA __DATA)) _DATA)
  (:serialization-length
   ()
   (+
    ;; uint8 _ORIGIN_ID
    1
    ;; uint8 _TARGET_ID
    1
    ;; uint8 _CHANNEL
    1
    ;; uint8 _INTERFACE
    1
    ;; string _DATA
    4 (length _DATA)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _ORIGIN_ID
       (write-byte _ORIGIN_ID s)
     ;; uint8 _TARGET_ID
       (write-byte _TARGET_ID s)
     ;; uint8 _CHANNEL
       (write-byte _CHANNEL s)
     ;; uint8 _INTERFACE
       (write-byte _INTERFACE s)
     ;; string _DATA
       (write-long (length _DATA) s) (princ _DATA s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _ORIGIN_ID
     (setq _ORIGIN_ID (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _TARGET_ID
     (setq _TARGET_ID (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _CHANNEL
     (setq _CHANNEL (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _INTERFACE
     (setq _INTERFACE (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _DATA
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _DATA (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get avl_bsd_translator::PassthroughMsg :md5sum-) "68cb8a05d5ebb8373e58b01f1c0af317")
(setf (get avl_bsd_translator::PassthroughMsg :datatype-) "avl_bsd_translator/PassthroughMsg")
(setf (get avl_bsd_translator::PassthroughMsg :definition-)
      "#===============================================================================
# Autonomous Vehicle Library Backseat Driver
#
# Description: Defines a message that contains a passthrough message
#===============================================================================

uint8 ORIGIN_ID
uint8 TARGET_ID
uint8 CHANNEL
uint8 INTERFACE
string DATA

")



(provide :avl_bsd_translator/PassthroughMsg "68cb8a05d5ebb8373e58b01f1c0af317")


