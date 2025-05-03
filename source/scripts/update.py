#!/usr/bin/env python3

"""update.py

Retrieves an upstream repo and applies per-directory updates.
"""

import os
import subprocess
from pathlib import Path
from typing import Optional

REPO = "https://github.com/AlexHarker/AHarker_Externals.git"
BRANCH = "cmake-htl"
WORK_DIR = Path("build/new")
SRC_DIR = WORK_DIR / 'src' / 'source'
DST_DIR = Path('source')

cmd = os.system

def get_upstream():
	cmd(f"rm -rf {WORK_DIR}")
	cmd(f"mkdir -p {WORK_DIR}")
	cmd(f"git clone --depth=1 -b {BRANCH} {REPO} {WORK_DIR}/src")


def update_source(src_dir, dst_dir: Optional[str] = None):
	src = SRC_DIR / src_dir
	if dst_dir:
		dst = DST_DIR / dst_dir
	else:
		dst = DST_DIR / src_dir.replace(' ', '-')

	skiplist = ['CMakeLists.txt']
	for root, dirs, files in os.walk(src):
		# print(root, dirs, files)
		for f in files:
			if f in skiplist:
				continue
			root = Path(root)
			src_path = root / f
			relative_path = src_path.relative_to(src)
			dst_path = dst / relative_path
			# print(src_path, '->', dst_path)
			if src_path.is_file() and dst_path.is_file():
				_cp_cmd = f"cp {src_path} {dst_path}"
				print(_cp_cmd)
				cmd(_cp_cmd)





def main():
	get_upstream()
	update_source('conversion')
	update_source('convolution')
	update_source('descriptors')
	update_source('dynamic suite')
	update_source('gesture suite')
	update_source('ibuffer suite')
	update_source('miscellaneous')
	update_source('random numbers')
	update_source('sample accurate suite')
	update_source('threading')
	update_source('utility')
	update_source('vMSP')



if __name__ == '__main__':
	main()
