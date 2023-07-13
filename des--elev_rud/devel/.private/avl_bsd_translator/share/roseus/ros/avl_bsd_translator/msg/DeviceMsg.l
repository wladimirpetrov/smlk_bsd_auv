;; Auto-generated. Do not edit!


(when (boundp 'avl_bsd_translator::DeviceMsg)
  (if (not (find-package "AVL_BSD_TRANSLATOR"))
    (make-package "AVL_BSD_TRANSLATOR"))
  (shadow 'DeviceMsg (find-package "AVL_BSD_TRANSLATOR")))
(unless (find-package "AVL_BSD_TRANSLATOR::DEVICEMSG")
  (make-package "AVL_BSD_TRANSLATOR::DEVICEMSG"))

(in-package "ROS")
;;//! \htmlinclude DeviceMsg.msg.html


(defclass avl_bsd_translator::DeviceMsg
  :super ros::object
  :slots (_DEVICE_NAME _NAMES _TYPES _VALUES ))

(defmethod avl_bsd_translator::DeviceMsg
  (:init
   (&key
    ((:DEVICE_NAME __DEVICE_NAME) "")
    ((:NAMES __NAMES) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:TYPES __TYPES) (make-array 0 :initial-element 0 :element-type :char))
    ((:VALUES __VALUES) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _DEVICE_NAME (string __DEVICE_NAME))
   (setq _NAMES __NAMES)
   (setq _TYPES __TYPES)
   (setq _VALUES __VALUES)
   self)
  (:DEVICE_NAME
   (&optional __DEVICE_NAME)
   (if __DEVICE_NAME (setq _DEVICE_NAME __DEVICE_NAME)) _DEVICE_NAME)
  (:NAMES
   (&optional __NAMES)
   (if __NAMES (setq _NAMES __NAMES)) _NAMES)
  (:TYPES
   (&optional __TYPES)
   (if __TYPES (setq _TYPES __TYPES)) _TYPES)
  (:VALUES
   (&optional __VALUES)
   (if __VALUES (setq _VALUES __VALUES)) _VALUES)
  (:serialization-length
   ()
   (+
    ;; string _DEVICE_NAME
    4 (length _DEVICE_NAME)
    ;; string[] _NAMES
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _NAMES)) 4
    ;; uint8[] _TYPES
    (* 1    (length _TYPES)) 4
    ;; string[] _VALUES
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _VALUES)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _DEVICE_NAME
       (write-long (length _DEVICE_NAME) s) (princ _DEVICE_NAME s)
     ;; string[] _NAMES
     (write-long (length _NAMES) s)
     (dolist (elem _NAMES)
       (write-long (length elem) s) (princ elem s)
       )
     ;; uint8[] _TYPES
     (write-long (length _TYPES) s)
     (princ _TYPES s)
     ;; string[] _VALUES
     (write-long (length _VALUES) s)
     (dolist (elem _VALUES)
       (write-long (length elem) s) (princ elem s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _DEVICE_NAME
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _DEVICE_NAME (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string[] _NAMES
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _NAMES (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _NAMES i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; uint8[] _TYPES
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _TYPES (make-array n :element-type :char))
     (replace _TYPES buf :start2 ptr-) (incf ptr- n))
   ;; string[] _VALUES
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _VALUES (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _VALUES i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;;
   self)
  )

(setf (get avl_bsd_translator::DeviceMsg :md5sum-) "ac0218f626191d446efaa61422be9692")
(setf (get avl_bsd_translator::DeviceMsg :datatype-) "avl_bsd_translator/DeviceMsg")
(setf (get avl_bsd_translator::DeviceMsg :definition-)
      "#===============================================================================
# Autonomous Vehicle Library Backseat Driver
#
# Description: Defines a ROS message that contains a device message
#===============================================================================

string DEVICE_NAME
string[] NAMES
uint8[] TYPES
string[] VALUES

")



(provide :avl_bsd_translator/DeviceMsg "ac0218f626191d446efaa61422be9692")


