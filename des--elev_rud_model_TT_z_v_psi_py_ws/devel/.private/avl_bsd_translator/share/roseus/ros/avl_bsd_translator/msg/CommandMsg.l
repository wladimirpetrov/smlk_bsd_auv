;; Auto-generated. Do not edit!


(when (boundp 'avl_bsd_translator::CommandMsg)
  (if (not (find-package "AVL_BSD_TRANSLATOR"))
    (make-package "AVL_BSD_TRANSLATOR"))
  (shadow 'CommandMsg (find-package "AVL_BSD_TRANSLATOR")))
(unless (find-package "AVL_BSD_TRANSLATOR::COMMANDMSG")
  (make-package "AVL_BSD_TRANSLATOR::COMMANDMSG"))

(in-package "ROS")
;;//! \htmlinclude CommandMsg.msg.html


(defclass avl_bsd_translator::CommandMsg
  :super ros::object
  :slots (_COMMAND_NAME _NAMES _TYPES _VALUES ))

(defmethod avl_bsd_translator::CommandMsg
  (:init
   (&key
    ((:COMMAND_NAME __COMMAND_NAME) "")
    ((:NAMES __NAMES) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:TYPES __TYPES) (make-array 0 :initial-element 0 :element-type :char))
    ((:VALUES __VALUES) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _COMMAND_NAME (string __COMMAND_NAME))
   (setq _NAMES __NAMES)
   (setq _TYPES __TYPES)
   (setq _VALUES __VALUES)
   self)
  (:COMMAND_NAME
   (&optional __COMMAND_NAME)
   (if __COMMAND_NAME (setq _COMMAND_NAME __COMMAND_NAME)) _COMMAND_NAME)
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
    ;; string _COMMAND_NAME
    4 (length _COMMAND_NAME)
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
     ;; string _COMMAND_NAME
       (write-long (length _COMMAND_NAME) s) (princ _COMMAND_NAME s)
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
   ;; string _COMMAND_NAME
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _COMMAND_NAME (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
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

(setf (get avl_bsd_translator::CommandMsg :md5sum-) "90b8ee5c95edfe3031b61b3ce483a6c9")
(setf (get avl_bsd_translator::CommandMsg :datatype-) "avl_bsd_translator/CommandMsg")
(setf (get avl_bsd_translator::CommandMsg :definition-)
      "#===============================================================================
# Autonomous Vehicle Library Backseat Driver
#
# Description: Defines a ROS message that contains a command
#===============================================================================

string COMMAND_NAME
string[] NAMES
uint8[] TYPES
string[] VALUES

")



(provide :avl_bsd_translator/CommandMsg "90b8ee5c95edfe3031b61b3ce483a6c9")


