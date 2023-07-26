;; Auto-generated. Do not edit!


(when (boundp 'avl_bsd_translator::ResponseMsg)
  (if (not (find-package "AVL_BSD_TRANSLATOR"))
    (make-package "AVL_BSD_TRANSLATOR"))
  (shadow 'ResponseMsg (find-package "AVL_BSD_TRANSLATOR")))
(unless (find-package "AVL_BSD_TRANSLATOR::RESPONSEMSG")
  (make-package "AVL_BSD_TRANSLATOR::RESPONSEMSG"))

(in-package "ROS")
;;//! \htmlinclude ResponseMsg.msg.html


(defclass avl_bsd_translator::ResponseMsg
  :super ros::object
  :slots (_DESC _NAME _SOURCE _RESULT _DATA ))

(defmethod avl_bsd_translator::ResponseMsg
  (:init
   (&key
    ((:DESC __DESC) 0)
    ((:NAME __NAME) "")
    ((:SOURCE __SOURCE) 0)
    ((:RESULT __RESULT) nil)
    ((:DATA __DATA) "")
    )
   (send-super :init)
   (setq _DESC (round __DESC))
   (setq _NAME (string __NAME))
   (setq _SOURCE (round __SOURCE))
   (setq _RESULT __RESULT)
   (setq _DATA (string __DATA))
   self)
  (:DESC
   (&optional __DESC)
   (if __DESC (setq _DESC __DESC)) _DESC)
  (:NAME
   (&optional __NAME)
   (if __NAME (setq _NAME __NAME)) _NAME)
  (:SOURCE
   (&optional __SOURCE)
   (if __SOURCE (setq _SOURCE __SOURCE)) _SOURCE)
  (:RESULT
   (&optional (__RESULT :null))
   (if (not (eq __RESULT :null)) (setq _RESULT __RESULT)) _RESULT)
  (:DATA
   (&optional __DATA)
   (if __DATA (setq _DATA __DATA)) _DATA)
  (:serialization-length
   ()
   (+
    ;; uint8 _DESC
    1
    ;; string _NAME
    4 (length _NAME)
    ;; uint64 _SOURCE
    8
    ;; bool _RESULT
    1
    ;; string _DATA
    4 (length _DATA)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _DESC
       (write-byte _DESC s)
     ;; string _NAME
       (write-long (length _NAME) s) (princ _NAME s)
     ;; uint64 _SOURCE
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _SOURCE (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _SOURCE) (= (length (_SOURCE . bv)) 2)) ;; bignum
              (write-long (ash (elt (_SOURCE . bv) 0) 0) s)
              (write-long (ash (elt (_SOURCE . bv) 1) -1) s))
             ((and (class _SOURCE) (= (length (_SOURCE . bv)) 1)) ;; big1
              (write-long (elt (_SOURCE . bv) 0) s)
              (write-long (if (>= _SOURCE 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _SOURCE s)(write-long (if (>= _SOURCE 0) 0 #xffffffff) s)))
     ;; bool _RESULT
       (if _RESULT (write-byte -1 s) (write-byte 0 s))
     ;; string _DATA
       (write-long (length _DATA) s) (princ _DATA s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _DESC
     (setq _DESC (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _NAME
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _NAME (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint64 _SOURCE
     
#+(or :alpha :irix6 :x86_64)
      (setf _SOURCE (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _SOURCE (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; bool _RESULT
     (setq _RESULT (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _DATA
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _DATA (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get avl_bsd_translator::ResponseMsg :md5sum-) "f6a85287137e7f8b62777ed3e0afe18e")
(setf (get avl_bsd_translator::ResponseMsg :datatype-) "avl_bsd_translator/ResponseMsg")
(setf (get avl_bsd_translator::ResponseMsg :definition-)
      "#===============================================================================
# Autonomous Vehicle Library Backseat Driver
#
# Description: Defines a message that contains a response from the vehicle
#              computer
#===============================================================================

uint8 DESC
string NAME
uint64 SOURCE
bool RESULT
string DATA

")



(provide :avl_bsd_translator/ResponseMsg "f6a85287137e7f8b62777ed3e0afe18e")


