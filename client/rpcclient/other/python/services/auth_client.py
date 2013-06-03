#! /usr/bin/python

import xmlrpclib
import hashlib 
# To use sha1

#s = xmlrpclib.ServerProxy('http://localhost:8001/hb/www/gw/rpc.php')
#s = xmlrpclib.ServerProxy('http://localhost/hb/gw/rpc.php')
s = xmlrpclib.ServerProxy('http://hb.lulli.net/rpc/gw.php')

password="root"
sha1_pass = hashlib.sha1(password).hexdigest()
#print "UserID =[" + s.auth.login('root', sha1_pass) + "]"
print  s.test.connection
