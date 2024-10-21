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

# MySQL 빌드 및 설치
if [ ! -d "$BASE_DIR/mysql_bld" ]; then
    mkdir -p $BASE_DIR/mysql_bld
fi

cd $BASE_DIR/mysql_bld
cmake $BASE_DIR/mysql/ -DDOWNLOAD_BOOST=1 -DWITH_BOOST=../boost 
make -j20

sudo cmake --install . --prefix /usr/local/mysql/
sudo chown $USER:$USER /usr/local/mysql/ -R

cd /usr/local/mysql/
if [ ! -d "mysql-files" ]; then
    mkdir mysql-files
    chmod 750 mysql-files
fi

bin/mysqld --initialize-insecure --user=$USER
MYSQL_END_TIME=$(date +%s)

# PostgreSQL 빌드 및 설치
kill $(ps aux | grep 'postgres -D /usr/local/pgsql/data' | awk '{print $2}')

if [ ! -d "$BASE_DIR/postgres_bld" ]; then
    mkdir -p $BASE_DIR/postgres_bld
fi

cd $BASE_DIR/postgres_bld
$BASE_DIR/postgres/configure --prefix=/usr/local/pgsql
sudo make -j20
sudo make install
rm -rf /usr/local/pgsql/data/*
sudo mkdir /usr/local/pgsql/data
sudo chown $USER /usr/local/pgsql/data

/usr/local/pgsql/bin/initdb -D /usr/local/pgsql/data
POSTGRES_END_TIME=$(date +%s)

# SQLite 빌드 및 설치
if [ ! -d "$BASE_DIR/sqlite_bld" ]; then
    mkdir -p $BASE_DIR/sqlite_bld
fi

cd $BASE_DIR/sqlite_bld
$BASE_DIR/sqlite/configure --enable-all
make -j20
sudo make install
SQLITE_END_TIME=$(date +%s)

# CMake 빌드
cd $BASE_DIR
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -Wno-dev -DORACLE=ON
cmake --build build -j20

DRIVER_END_TIME=$(date +%s)

# 빌드 및 설치 시간 출력
echo "APT: $((APT_END_TIME - START_TIME))s"
echo "MYSQL: $((MYSQL_END_TIME - APT_END_TIME))s"
echo "POSTGRES: $((POSTGRES_END_TIME - MYSQL_END_TIME))s"
echo "SQLITE: $((SQLITE_END_TIME - POSTGRES_END_TIME))s"
echo "DRIVER: $((DRIVER_END_TIME - SQLITE_END_TIME))s"
echo "TOTAL: $((DRIVER_END_TIME - START_TIME))s"

