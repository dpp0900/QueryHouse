"""
Run a fuzzing instance.
"""
import os
import fire
import uuid
from pathlib import Path

DBMS = ["sqlite", "mysql", "mariadb", "postgresql"]
ROOTPATH = Path(os.path.dirname(os.path.realpath(__file__)))


def get_mutator_so_path(database):
  if database == "mariadb":
    database = "mysql"
  return f"{ROOTPATH}/build/lib{database}_mutator.so"


def get_config_path(database):
  return f"{ROOTPATH}/data/config/config_{database}.yml"


def set_env(database):
  os.environ["AFL_CUSTOM_MUTATOR_ONLY"] = "1"
  os.environ["AFL_DISABLE_TRIM"] = "1"
  os.environ["AFL_FAST_CAL"] = "1"
  os.environ["AFL_CUSTOM_MUTATOR_LIBRARY"] = get_mutator_so_path(database)
  os.environ["SQUIRREL_CONFIG"] = get_config_path(database)
  os.environ["ORACLE_HOME"] = "/opt/oracle/product/23ai/dbhomeFree"
  os.environ["ORACLE_SID"] = "FREE"
  os.environ["ORACLE_BASE"] = "/opt/oracle"
  os.environ["LD_LIBRARY_PATH"] = os.environ["ORACLE_HOME"] + "/lib" + ":" + (os.environ["LD_LIBRARY_PATH"] if "LD_LIBRARY_PATH" in os.environ else "")
  os.environ["PATH"] = os.environ["ORACLE_HOME"] + "/bin" + ":" + os.environ["PATH"]
  # os.environ["AFL_NO_UI"] = "1"


def run(database, input_dir, output_dir=None, config_file=None, fuzzer=None):
  # Precondition checks
  if database not in DBMS:
    print(f"Unsupported database. The supported ones are {DBMS}")
    return

  if not output_dir:
    output_dir = "/tmp/fuzz"

  if not config_file:
    config_file = get_config_path(database)
  if not fuzzer:
    fuzzer = f"{ROOTPATH}/afl_bld/afl-fuzz"
  if not os.path.exists(config_file):
    print("Invalid path for config file")
  if not os.path.exists(fuzzer):
    print("Invalid path for afl-fuzz")

  set_env(database)

  output_id = str(uuid.uuid4())[:10]
  cmd = f"{fuzzer} -i {input_dir} -o {output_dir} -M {output_id} -t 60000 -- {ROOTPATH}/build/db_driver"
  print(cmd)
  os.system(cmd)


if __name__ == "__main__":
  fire.Fire(run)
