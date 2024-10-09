# QueryHouse-Framwork
## based on https://github.com/s3team/Squirrel

# Build Step
1. ```git clone https://github.com/dpp0900/QueryHouse-Framework ~/QueryHouse-Framework```
2. ```cd ~/QueryHouse-Framework```
3. ```git submodule update --init```
4. if you want to run with oracle
4.1 ```./install_oracle.sh```
4. if you want to disable oracle
4. ```./oracle_enable_disable_compile.sh``` -> it will echo changed status
5. ```./build.sh```
5. ```./db_driver_run.sh```