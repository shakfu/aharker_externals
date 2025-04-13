MAX_VERSION := 9
PACKAGE_NAME := aharker_externals
PACKAGE := "$(HOME)/Documents/Max\ $(MAX_VERSION)/Packages/$(PACKAGE_NAME)"

.PHONY: all macos_native macos_universal dev clean reset setup

all: macos_native

macos_native:
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

setup:
	@git submodule init
	@git submodule update
	@if ! [ -L "$(PACKAGE)" ]; then \
		ln -s "$(shell pwd)" "$(PACKAGE)" ; \
		echo "... symlink created" ; \
	else \
		echo "... symlink already exists" ; \
	fi
