
(cl:in-package :asdf)

(defsystem "avl_bsd_translator-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ActionMsg" :depends-on ("_package_ActionMsg"))
    (:file "_package_ActionMsg" :depends-on ("_package"))
    (:file "CommandMsg" :depends-on ("_package_CommandMsg"))
    (:file "_package_CommandMsg" :depends-on ("_package"))
    (:file "DeviceMsg" :depends-on ("_package_DeviceMsg"))
    (:file "_package_DeviceMsg" :depends-on ("_package"))
    (:file "HeartbeatMsg" :depends-on ("_package_HeartbeatMsg"))
    (:file "_package_HeartbeatMsg" :depends-on ("_package"))
    (:file "PassthroughMsg" :depends-on ("_package_PassthroughMsg"))
    (:file "_package_PassthroughMsg" :depends-on ("_package"))
    (:file "ResponseMsg" :depends-on ("_package_ResponseMsg"))
    (:file "_package_ResponseMsg" :depends-on ("_package"))
  ))