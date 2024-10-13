#!/bin/bash
AFL_DEBUG=1 __AFL_SHM_ID=1234 ~/QueryHouse/sqlite_afl_bld/sqlite3 2>&1 | grep "__afl_map_size" | tail -n 1 | cut -d"," -f8 | cut -d" " -f 3 > /tmp/mapsize
AFL_IGNORE_PROBLEMS=1 AFL_MAP_SIZE=$(cat /tmp/mapsize) python3 run.py sqlite data/fuzz_root/input