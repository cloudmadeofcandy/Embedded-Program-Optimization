import glob
import os
import re
import sys

sub_name = re.compile(r"(\w+)_u.c", flags=re.I).sub

work_dir = r"C:\Code\C_Optimization\lab3"

for old_path in glob.glob(os.path.join(work_dir, r"*_u.c")):
    dirname, old_name = os.path.split(old_path)
    new_name = sub_name("\\1_o.c", old_name)
    new_path = os.path.join(dirname, new_name)
    print(old_name)
    try:
        os.rename(old_path, new_path)
    except OSError as exc:
        print(exc)