#!/bin/bash
START_TIME=$(date +%s)
BASE_DIR=~/QueryHouse

sudo apt-get update && \
sudo apt-get -y install make cmake build-essential vim sudo git \
    clang libmysqlclient-dev ninja-build pkg-config clang-format \
    libpq-dev libyaml-cpp-dev lld llvm bison python3-fire apt-transport-https \
    curl software-properties-common gnutls-dev ltrace

sudo apt-get -y install make cmake build-essential vim sudo git \
    clang ninja-build pkg-config clang-format libpq-dev llvm libyaml-cpp-dev zlib1g-dev \
    libreadline8 libreadline-dev bison flex python3-fire

APT_END_TIME=$(date +%s)

#AFL 빌드
if [ ! -d "$BASE_DIR/afl_bld" ]; then
    mkdir -p $BASE_DIR/afl_bld
    cp -r AFLplusplus/* afl_bld/
fi

cd $BASE_DIR/afl_bld
cp -r ../AFLplusplus/src/* ./src
LLVM_CONFIG=llvm-config-14 make -j20

AFL_END_TIME=$(date +%s)


# MySQL 빌드 및 설치
# if [ ! -d "$BASE_DIR/mysql_afl_bld" ]; then
#     mkdir -p $BASE_DIR/mysql_afl_bld
# fi

# cd $BASE_DIR/mysql_afl_bld
# CC=$BASE_DIR/afl_bld/afl-clang-fast CXX=$BASE_DIR/afl_bld/afl-clang-fast++ cmake $BASE_DIR/mysql/ -DDOWNLOAD_BOOST=1 -DWITH_BOOST=../boost -DWITH_DEBUG=1 -DCPACK_MONOLITHIC_INSTALL=1 -DWITH_UNIT_TESTS=OFF
# make -j20
# sudo cmake --install . --prefix /usr/local/mysql/
# sudo chown $USER:$USER /usr/local/mysql/ -R

# cd /usr/local/mysql/
# if [ ! -d "mysql-files" ]; then
#     mkdir mysql-files
#     chmod 750 mysql-files
# fi

# AFL_IGNORE_PROBLEMS=1 bin/mysqld --initialize-insecure --user=$USER
# MYSQL_END_TIME=$(date +%s)

# # PostgreSQL 빌드 및 설치
# kill $(ps aux | grep 'postgres -D /usr/local/pgsql/data' | awk '{print $2}')

# if [ ! -d "$BASE_DIR/postgres_afl_bld" ]; then
#     mkdir -p $BASE_DIR/postgres_afl_bld
# fi

# cd $BASE_DIR/postgres_afl_bld
# $BASE_DIR/postgres/configure --prefix=/usr/local/pgsql
# sudo make -j4
# sudo make install
# rm -rf /usr/local/pgsql/data/*
# sudo mkdir /usr/local/pgsql/data
# sudo chown $USER /usr/local/pgsql/data

# /usr/local/pgsql/bin/initdb -D /usr/local/pgsql/data
# POSTGRES_END_TIME=$(date +%s)

# SQLite 빌드 및 설치
if [ ! -d "$BASE_DIR/sqlite_afl_bld" ]; then
    mkdir -p $BASE_DIR/sqlite_afl_bld
fi

cd $BASE_DIR/sqlite_afl_bld

CC=$BASE_DIR/afl_bld/afl-clang-fast CXX=$BASE_DIR/afl_bld/afl-clang-fast++ CFLAGS="-DSQLITE_THREADSAFE=0 -DSQLITE_ENABLE_LOAD_EXTENSION=0 -DSQLITE_NO_SYNC -DSQLITE_DEBUG -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_RTREE -DSQLITE_OMIT_RANDOMNESS -fsanitize=address" $BASE_DIR/sqlite/configure --enable-all --disable-shared --disable-static
CC=$BASE_DIR/afl_bld/afl-clang-fast CXX=$BASE_DIR/afl_bld/afl-clang-fast++ make -j20
sudo make install
SQLITE_END_TIME=$(date +%s)

# driver 빌드
cd $BASE_DIR
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -Wno-dev -DORACLE=ON
cmake --build build -j

DRIVER_END_TIME=$(date +%s)

# 빌드 및 설치 시간 출력
echo "APT: $((APT_END_TIME - START_TIME))s"
echo "AFL: $((AFL_END_TIME - APT_END_TIME))s"
echo "MYSQL: $((MYSQL_END_TIME - APT_END_TIME))s"
echo "POSTGRES: $((POSTGRES_END_TIME - MYSQL_END_TIME))s"
echo "SQLITE: $((SQLITE_END_TIME - POSTGRES_END_TIME))s"
echo "DRIVER: $((DRIVER_END_TIME - SQLITE_END_TIME))s"
echo "TOTAL: $((DRIVER_END_TIME - START_TIME))s"

