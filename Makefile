include ./build.cfg

###########################################################################

# MOST GENERAL SETUP

###########################################################################

#
# Fix Installation Configuration Variables
#
include ${BASE}/install/etc/server.cfg
include ${BASE}/install/etc/local_server.cfg
include ${BASE}/install/etc/local_client.cfg
#include ./install/etc/server.cfg
#include ./install/etc/local_server.cfg
#include ./install/etc/local_client.cfg



############################################################################
all: bundle

dist: build 
	mkdir -p ./dist/packages
	tar cvfz ./dist/packages/${PROJECT}-${VERSION}-server-frontend.tar.gz -C ./build/${PROJECT}-${VERSION}-server-frontend .
	tar cvfz ./dist/packages/${PROJECT}-${VERSION}-server-backend.tar.gz -C  ./build/${PROJECT}-${VERSION}-server-backend  .
	tar cvfz ./dist/packages/${PROJECT}-${VERSION}-server-gateway.tar.gz -C  ./build/${PROJECT}-${VERSION}-server-gateway  .
	tar cvfz ./dist/packages/${PROJECT}-${VERSION}-client-local.tar.gz -C    ./build/${PROJECT}-${VERSION}-client-local    .
	tar cvfz ./dist/packages/${PROJECT}-${VERSION}-client-rpc.tar.gz -C      ./build/${PROJECT}-${VERSION}-client-rpc      .
	#tar cvfz ./dist/${PROJECT}-${VERSION}-shared.tar.gz -C          	      ./build/${PROJECT}-${VERSION}-shared          .
tree:
	#mkdir -p ./dist/${PROJECT}-${VERSION}-${VERSION}-
	mkdir -p ./build/${PROJECT}-${VERSION}-server-frontend
	mkdir -p ./build/${PROJECT}-${VERSION}-server-backend
	mkdir -p ./build/${PROJECT}-${VERSION}-server-gateway
	##mkdir -p ./build/${PROJECT}-${VERSION}-server-shared
	mkdir -p ./build/${PROJECT}-${VERSION}-server-web
	mkdir -p ./build/${PROJECT}-${VERSION}-client-local
	mkdir -p ./build/${PROJECT}-${VERSION}-client-rpc
	#mkdir -p ./build/${PROJECT}-${VERSION}-shared

build: clean tree 
	# Distribute shared dir on all sub-projects 
	cp -r ${BASE}/shared	        ./build/${PROJECT}-${VERSION}-server-backend
	cp -r ${BASE}/shared	        ./build/${PROJECT}-${VERSION}-server-gateway
	cp -r ${BASE}/shared	        ./build/${PROJECT}-${VERSION}-server-frontend
	cp -r ${BASE}/shared	        ./build/${PROJECT}-${VERSION}-client-local
	cp -r ${BASE}/shared	        ./build/${PROJECT}-${VERSION}-client-rpc
	cp -r ${BASE}/server/rpc      ./build/${PROJECT}-${VERSION}-server-frontend
	cp -r ${BASE}/server/conf     ./build/${PROJECT}-${VERSION}-server-backend
	cp -r ${BASE}/server/logs     ./build/${PROJECT}-${VERSION}-server-backend
	cp -r ${BASE}/server/kernel   ./build/${PROJECT}-${VERSION}-server-backend
	cp -r ${BASE}/server/admin    ./build/${PROJECT}-${VERSION}-server-backend
	cp -r ${BASE}/server/openssl  ./build/${PROJECT}-${VERSION}-server-backend
	cp -r ${BASE}/server/db       ./build/${PROJECT}-${VERSION}-server-backend
	cp -r ${BASE}/server/gateway  ./build/${PROJECT}-${VERSION}-server-gateway
	cp -r ${BASE}/server/web      ./build/${PROJECT}-${VERSION}-server-web
	cp -r ${BASE}/client/local    ./build/${PROJECT}-${VERSION}-client-local
	mkdir    ./build/${PROJECT}-${VERSION}-client-local/conf
	mkdir    ./build/${PROJECT}-${VERSION}-client-local/conf/Linux
	mkdir    ./build/${PROJECT}-${VERSION}-client-local/conf/FreeBSD
	mkdir    ./build/${PROJECT}-${VERSION}-client-local/conf/Darwin
	cp  ${BASE}/client/local/conf/local.inc          ./build/${PROJECT}-${VERSION}-client-local/conf
	cp  ${BASE}/client/local/conf/Linux/local.inc    ./build/${PROJECT}-${VERSION}-client-local/conf/Linux
	cp  ${BASE}/client/local/conf/FreeBSD/local.inc  ./build/${PROJECT}-${VERSION}-client-local/conf/FreeBSD
	cp  ${BASE}/client/local/conf/Darwin/local.inc   ./build/${PROJECT}-${VERSION}-client-local/conf/Darwin
	mkdir    ./build/${PROJECT}-${VERSION}-client-rpc/conf
	mkdir    ./build/${PROJECT}-${VERSION}-client-rpc/conf/Linux
	mkdir    ./build/${PROJECT}-${VERSION}-client-rpc/conf/FreeBSD
	mkdir    ./build/${PROJECT}-${VERSION}-client-rpc/conf/Darwin
	cp  -r ${BASE}/client/local/conf/*          ./build/${PROJECT}-${VERSION}-client-rpc/conf #rpcclient is both local and rpc
	cp  -r ${BASE}/client/rpcclient/conf/*      ./build/${PROJECT}-${VERSION}-client-rpc/conf #rpcclient is both local and rpc
	cp  -r ${BASE}/client/rpcclient             ./build/${PROJECT}-${VERSION}-client-rpc

bundle: dist
	mkdir -p ./build/bundle
	mkdir -p ./dist/bundles
	mkdir -p ./build/bundle/server_xmlrpc
	cp 	./dist/packages/${PROJECT}-${VERSION}-server-backend.tar.gz        ./build/bundle/server_xmlrpc
	cp 	./dist/packages/${PROJECT}-${VERSION}-server-frontend.tar.gz       ./build/bundle/server_xmlrpc
	cp 	./dist/packages/${PROJECT}-${VERSION}-server-gateway.tar.gz        ./build/bundle/server_xmlrpc
	tar cvfz ./dist/bundles/${PROJECT}-${VERSION}-bundle-server-xmlrpc.tar.gz       -C ./build/bundle 			server_xmlrpc  
	mkdir ./build/bundle/client_local
	cp 	./dist/packages/${PROJECT}-${VERSION}-client-local.tar.gz          ./build/bundle/client_local
	cp 	./dist/packages/${PROJECT}-${VERSION}-server-backend.tar.gz        ./build/bundle/client_local
	tar cvfz  ./dist/bundles/${PROJECT}-${VERSION}-bundle-local.tar.gz               -C ./build/bundle			client_local   
	mkdir     ./build/bundle/client_xmlrpc
	cp 	./dist/packages/${PROJECT}-${VERSION}-client-rpc.tar.gz            ./build/bundle/client_xmlrpc
	tar cvfz ./dist/bundles/${PROJECT}-${VERSION}-bundle-client-xmlrpc.tar.gz       -C ./build/bundle			client_xmlrpc  
	mkdir ./build/bundle/full
	cp 	./dist/packages/${PROJECT}-${VERSION}-client-rpc.tar.gz            ./build/bundle/full
	cp 	./dist/packages/${PROJECT}-${VERSION}-client-local.tar.gz          ./build/bundle/full
	cp 	./dist/packages/${PROJECT}-${VERSION}-server-backend.tar.gz        ./build/bundle/full
	cp 	./dist/packages/${PROJECT}-${VERSION}-server-frontend.tar.gz       ./build/bundle/full
	cp 	./dist/packages/${PROJECT}-${VERSION}-server-gateway.tar.gz        ./build/bundle/full
	tar cvfz ./dist/bundles/${PROJECT}-${VERSION}-bundle-full.tar.gz                -C ./build/bundle			full           

install-remote: build
	rsync -a ./build/${PROJECT}-${VERSION}-server-frontend/    ${REMOTE_FRONTEND_USER}"@"${REMOTE_FRONTEND_MACHINE}:${REMOTE_FRONTEND_INSTALL_DIR}
	rsync -a ./build/${PROJECT}-${VERSION}-server-backend/     ${REMOTE_BACKEND_USER}"@"${REMOTE_BACKEND_MACHINE}:${REMOTE_BACKEND_INSTALL_DIR} 
	# Gateway in the same dir as of backend on server
	rsync -a ./build/${PROJECT}-${VERSION}-server-gateway/     ${REMOTE_GATEWAY_USER}"@"${REMOTE_GATEWAY_MACHINE}:${REMOTE_GATEWAY_INSTALL_DIR} 
	rsync -a ./build/${PROJECT}-${VERSION}-server-web/web/     ${REMOTE_WEB_USER}"@"${REMOTE_WEB_MACHINE}:${REMOTE_WEB_INSTALL_DIR} 
	rsync -a ./build/${PROJECT}-${VERSION}-client-local/       ${REMOTE_BACKEND_USER}"@"${REMOTE_BACKEND_MACHINE}:${REMOTE_BACKEND_INSTALL_DIR} 
	rsync -a ./build/${PROJECT}-${VERSION}-client-rpc/         ${REMOTE_BACKEND_USER}"@"${REMOTE_BACKEND_MACHINE}:${REMOTE_BACKEND_INSTALL_DIR} 


update-web: update-build
	rsync -a ./build/${PROJECT}-${VERSION}-server-web/web/     ${REMOTE_WEB_USER}"@"${REMOTE_WEB_MACHINE}:${REMOTE_WEB_INSTALL_DIR} 

update-local-web: update-build
	cp -r ./build/${PROJECT}-${VERSION}-server-web/web/     ${LOCAL_WEB_INSTALL_DIR} 

install-local-client: build
	#cp -r ./build/${PROJECT}-${VERSION}-client-local/       ${LOCAL_CLIENT_INSTALL_DIR} # Do not work without server
	cp -r ./build/${PROJECT}-${VERSION}-client-rpc/*         ${LOCAL_RPCCLIENT_INSTALL_DIR}

install-local-server: build 
	cp -r ./build/${PROJECT}-${VERSION}-server-frontend/*    ${LOCAL_FRONTEND_INSTALL_DIR}
	cp -r ./build/${PROJECT}-${VERSION}-server-backend/*     ${LOCAL_BACKEND_INSTALL_DIR}
	cp -r ./build/${PROJECT}-${VERSION}-server-gateway/*     ${LOCAL_GATEWAY_INSTALL_DIR}
	#cp -r ./build/${PROJECT}-${VERSION}-server-web/         ${LOCAL_WEB_INSTALL_DIR}
	cp -r ./build/${PROJECT}-${VERSION}-server-web/web/*    ${LOCAL_WEB_INSTALL_DIR}
	cp -r ./build/${PROJECT}-${VERSION}-client-local/*       ${LOCAL_CLIENT_INSTALL_DIR}
	cp -r ./build/${PROJECT}-${VERSION}-client-rpc/*         ${LOCAL_CLIENT_INSTALL_DIR} # Xmlrpc in the same dir as Local

echo: 
	echo "LOCAL_BACKEND_INSTALL_DIR=${LOCAL_BACKEND_INSTALL_DIR}"
	echo "LOCAL_GATEWAY_INSTALL_DIR=${LOCAL_GATEWAY_INSTALL_DIR}"
	echo "LOCAL_FRONTEND_INSTALL_DIR=${LOCAL_FRONTEND_INSTALL_DIR}"
	echo "LOCAL_WEB_INSTALL_DIR=${LOCAL_WEB_INSTALL_DIR}"
	echo "LOCAL_CLIENT_INSTALL_DIR=${LOCAL_CLIENT_INSTALL_DIR}"
clean: 
	rm -fr ./build/*; rm -fr ./dist/*
# - 2 - Local Server (localhost)
#


