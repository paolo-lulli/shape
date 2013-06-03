#! /usr/bin/python

import xmlrpclib
import hashlib 
# To use sha1

#s = xmlrpclib.ServerProxy('http://localhost:8001/hb/www/gw/rpc.php')
s = xmlrpclib.ServerProxy('http://localhost/hb/gw/rpc.php')

registry = s.registry.get('9D5E4FEF-062E-47E2-BBB3-7F21C7DE96D5')
#print "Registry =[" + registry + "]"

print registry['9D5E4FEF-062E-47E2-BBB3-7F21C7DE96D5']['role']
