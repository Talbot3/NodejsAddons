# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := object_factory
DEFS_Debug := \
	'-DNODE_GYP_MODULE_NAME=object_factory' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION' \
	'-DDEBUG' \
	'-D_DEBUG'

# Flags passed to all source files.
CFLAGS_Debug := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++0x

INCS_Debug := \
	-I/home/goerver/.node-gyp/6.2.1/include/node \
	-I/home/goerver/.node-gyp/6.2.1/src \
	-I/home/goerver/.node-gyp/6.2.1/deps/uv/include \
	-I/home/goerver/.node-gyp/6.2.1/deps/v8/include

DEFS_Release := \
	'-DNODE_GYP_MODULE_NAME=object_factory' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION'

# Flags passed to all source files.
CFLAGS_Release := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++0x

INCS_Release := \
	-I/home/goerver/.node-gyp/6.2.1/include/node \
	-I/home/goerver/.node-gyp/6.2.1/src \
	-I/home/goerver/.node-gyp/6.2.1/deps/uv/include \
	-I/home/goerver/.node-gyp/6.2.1/deps/v8/include

OBJS := \
	$(obj).target/$(TARGET)/object_factory.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64

LIBS :=

$(obj).target/object_factory.node: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/object_factory.node: LIBS := $(LIBS)
$(obj).target/object_factory.node: TOOLSET := $(TOOLSET)
$(obj).target/object_factory.node: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,solink_module)

all_deps += $(obj).target/object_factory.node
# Add target alias
.PHONY: object_factory
object_factory: $(builddir)/object_factory.node

# Copy this to the executable output path.
$(builddir)/object_factory.node: TOOLSET := $(TOOLSET)
$(builddir)/object_factory.node: $(obj).target/object_factory.node FORCE_DO_CMD
	$(call do_cmd,copy)

all_deps += $(builddir)/object_factory.node
# Short alias for building this executable.
.PHONY: object_factory.node
object_factory.node: $(obj).target/object_factory.node $(builddir)/object_factory.node

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/object_factory.node

