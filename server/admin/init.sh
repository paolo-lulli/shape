#! /bin/sh

# Create DataBase

cd ../db;
./create_db.pl


# Create  log directory

touch ../logs/query.log
touch ../logs/error.log
touch ../logs/info.log
touch ../logs/debug.log

chmod 666 ../logs/*.log
