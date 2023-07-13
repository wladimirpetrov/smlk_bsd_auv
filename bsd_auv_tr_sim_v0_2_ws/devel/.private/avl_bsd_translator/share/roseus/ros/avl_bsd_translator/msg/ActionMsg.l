;; Auto-generated. Do not edit!


(when (boundp 'avl_bsd_translator::ActionMsg)
  (if (not (find-package "AVL_BSD_TRANSLATOR"))
    (make-package "AVL_BSD_TRANSLATOR"))
  (shadow 'ActionMsg (find-package "AVL_BSD_TRANSLATOR")))
(unless (find-package "AVL_BSD_TRANSLATOR::ACTIONMSG")
  (make-package "AVL_BSD_TRANSLATOR::ACTIONMSG"))

(in-package "ROS")
;;//! \htmlinclude ActionMsg.msg.html


(defclass avl_bsd_translator::ActionMsg
  :super ros::object
  :slots (_ACTION_TYPE _MODE _NAMES _TYPES _VALUES ))

(defmethod avl_bsd_translator::ActionMsg
  (:init
   (&key
    ((:ACTION_TYPE __ACTION_TYPE) "")
    ((:MODE __MODE) 0)
    ((:NAMES __NAMES) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:TYPES __TYPES) (make-array 0 :initial-element 0 :element-type :char))
    ((:VALUES __VALUES) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _ACTION_TYPE (string __ACTION_TYPE))
   (setq _MODE (round __MODE))
   (setq _NAMES __NAMES)
   (setq _TYPES __TYPES)
   (setq _VALUES __VALUES)
   self)
  (:ACTION_TYPE
   (&optional __ACTION_TYPE)
   (if __ACTION_TYPE (setq _ACTION_TYPE __ACTION_TYPE)) _ACTION_TYPE)
  (:MODE
   (&optional __MODE)
   (if __MODE (setq _MODE __MODE)) _MODE)
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
    ;; string _ACTION_TYPE
    4 (length _ACTION_TYPE)
    ;; uint8 _MODE
    1
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
     ;; string _ACTION_TYPE
       (write-long (length _ACTION_TYPE) s) (princ _ACTION_TYPE s)
     ;; uint8 _MODE
       (write-byte _MODE s)
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
   ;; string _ACTION_TYPE
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _ACTION_TYPE (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _MODE
     (setq _MODE (sys::peek buf ptr- :char)) (incf ptr- 1)
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

(setf (get avl_bsd_translator::ActionMsg :md5sum-) "26d51459ba77981700e1646ecfd1099d")
(setf (get avl_bsd_translator::ActionMsg :datatype-) "avl_bsd_translator/ActionMsg")
(setf (get avl_bsd_translator::ActionMsg :definition-)
      "#===============================================================================
# Autonomous Vehicle Library Backseat Driver
#
# Description: Defines a ROS message that contains an action
#===============================================================================

string ACTION_TYPE
uint8 MODE
string[] NAMES
uint8[] TYPES
string[] VALUES

")



(provide :avl_bsd_translator/ActionMsg "26d51459ba77981700e1646ecfd1099d")


