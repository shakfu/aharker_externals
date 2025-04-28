MAX_VERSION := 9
PACKAGE_NAME := aharker_externals
PACKAGE := "$(HOME)/Documents/Max\ $(MAX_VERSION)/Packages/$(PACKAGE_NAME)"

ifeq ($(OS),Darwin)
    GENERATOR := "Xcode"
else
    GENERATOR := "Visual Studio 16 2019" # Windows_NT
endif


.PHONY: all build macos macos_universal windows dev clean reset sync link setup

all: build

build:
	@mkdir -p build && \
		cd build && \
		cmake .. -G $(GENERATOR) && \
		cmake --build . --config Release

build/venv/Library/lib/mkl_core.lib:
	python source/scripts/install_mkl.py

windows: build/venv/Library/lib/mkl_core.lib
	@mkdir -p build && \
		cd build && \
		cmake .. && \
		cmake --build . --config Release

macos:
	@mkdir -p build && \
		cd build && \
		cmake .. -GXcode && \
		cmake --build . --config Release


macos_universal:
	@mkdir -p build && \
		cd build && \
		cmake .. -GXcode -DMACOS_UNIVERSAL=ON && \
		cmake --build . --config Release

dev:
	@mkdir -p build && \
		cd build && \
		cmake .. && \
		cmake --build . --config Release

clean:
	@rm -f build/CMakeCache.txt

reset:
	@rm -rf build externals

sync:
	@echo "updating submodule(s)"
	@git submodule init
	@git submodule update

link:
	@if ! [ -L "$(PACKAGE)" ]; then \
		ln -s "$(shell pwd)" "$(PACKAGE)" ; \
		echo "... symlink created" ; \
	else \
		echo "... symlink already exists" ; \
	fi

setup: sync link

