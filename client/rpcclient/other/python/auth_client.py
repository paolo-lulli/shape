#! /usr/bin/python

import xmlrpclib
import hashlib 
# To use sha1

#s = xmlrpclib.ServerProxy('http://localhost:8001/hb/www/gw/rpc.php')
#s = xmlrpclib.ServerProxy('http://localhost/hb/gw/rpc.php')
s = xmlrpclib.ServerProxy('http://lulli.net/rpc/crud.php')

password="admin"
sha1_pass = hashlib.sha1(password).hexdigest()
print "UserID =[" + s.auth.login('admin', sha1_pass) + "]"
