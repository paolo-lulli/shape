#! /usr/bin/python

import xmlrpclib

#s = xmlrpclib.ServerProxy('http://localhost:8001/hb/www/gw/rpc.php')
s = xmlrpclib.ServerProxy('http://lulli.net/rpc/crud.php')

# Print list of available methods
print s.system.listMethods()
#print s.test.connection()

#print s.user.getnick('9D5E4FEF-062E-47E2-BBB3-7F21C7DE96D5')

